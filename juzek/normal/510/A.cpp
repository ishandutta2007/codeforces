#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    int k =0;
    for (int i = 0;i < N;i++)
    {
        k = i%4;
        if (k == 0 || k == 2)
        {
            for (int w = 0;w < M;w++)
            {
                printf("#");
            }
        }
        else if (k == 1)
        {
            for (int w = 1;w < M;w++)
                printf(".");
            printf("#");
        }
        else if (k == 3)
        {
            printf("#");
            for (int w = 1;w < M;w++)
                printf(".");
        }
        printf("\n");
    }

    return 0;
}