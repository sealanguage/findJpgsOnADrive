// get jpgs from recover file
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
int main(int nmOfArguments, string argValues[])
    {
    printf("%i %s\n", nmOfArguments, argValues[0]);
    // check to mmake sure we have argurments
    if (nmOfArguments == 2)
    {
        char* file = argValues[1];
        FILE* card = fopen(file, "r");
        if (!card)
        {
            printf("No file or nothing in file \n");
            fclose(card);
            return 1;
        }
        // define buffer
        unsigned char buffer[512];
        // keep count
        int imgcount = 0;
        while (fread (buffer, 512, 1, card) == 1)
        {
            // is this a jpg
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            {


                imgcount++;
            }
        }
        printf("Total numver of JPG images in file %i\n", imgcount);
        fclose(card);
        return 0;
    }
    else
    {
        printf("Usage: ./getJpg filename \n");
        return 1;
    }
}