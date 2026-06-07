#include <stdio.h>

#define ROWS 20
#define COLS 50

char canvas[ROWS][COLS];

void initCanvas()
{
    int i, j;

    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLS; j++)
        {
            canvas[i][j] = '_';
        }
    }
}

void drawRectangle(int row, int col, int width, int height)
{
    int i;

    for(i=col; i<col+width; i++)
    {
        canvas[row][i] = '*';
        canvas[row+height-1][i] = '*';
    }

    for(i=row; i<row+height; i++)
    {
        canvas[i][col] = '*';
        canvas[i][col+width-1] = '*';
    }
}

void displayCanvas()
{
    int i, j;

    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLS; j++)
        {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}
void drawLine(int row1, int col1, int row2, int col2)
{
    int i;

    if(row1 == row2)
    {
        for(i = col1; i <= row2; i++)
        {
            canvas[row1][i] = '*';
        }
    }
}
int main()
{
    int choice;
    int row, col, width, height;

    initCanvas();

    while(1)
    {
        printf("\n\n===== 2D Graphics Editor =====\n");
        printf("1. Display Canvas\n");
        printf("2. Draw Rectangle\n");
        printf("3. Draw Line\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                displayCanvas();
                break;

            case 2:
                printf("Enter row column width height: ");
                scanf("%d%d%d%d", &row, &col, &width, &height);

                drawRectangle(row, col, width, height);

                printf("Rectangle drawn successfully!\n");
                break;

            case 3:
                printf("Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}

