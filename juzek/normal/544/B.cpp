#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,k;
    scanf("%d%d",&N,&k);
    int G = N*N;
    G++;
    if (G/2 < k)
    {
        printf("NO");
        return 0;
    }
    printf("YES\n");
    for (int i = 0;i < N;i++)
    {
        for (int w = 0;w < N;w++)
        {
            if (k)
            {
                if (i%2 == w%2)
                {
                    printf("L");
                    k--;
                }
                else
                    printf("S");
            }
            else
                printf("S");
        }
        printf("\n");
    }


    return 0;
}