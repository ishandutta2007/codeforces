#include <bits/stdc++.h>
using namespace std;

char tab[57][57];

int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    for (int i = 0;i < N;i++)
        scanf("%s",tab[i]);
    int odp = 0;
    N--;
    M--;
    long long iloczyn = ('a'+10)*('f'+10)*('e'+10)*('c'+10);
    long long temp;
    for (int i = 0;i < N;i++)
    {
        for (int w = 0;w < M;w++)
        {
            temp = tab[i][w]+10;
            temp *= tab[i+1][w]+10;
            temp *= tab[i][w+1]+10;
            temp *= tab[i+1][w+1]+10;
            if (temp == iloczyn)
                odp++;
        }
    }
    printf("%d",odp);
}