#include<bits/stdc++.h>
using namespace std;

int tab[107][107];

void dodaj(int x1,int y1,int x2,int y2)
{
    for (int i = x1;i <= x2;i++)
    {
        for (int w = y1;w <= y2;w++)
            tab[x1][y1]++;
    }
}

int main()
{
    int N;
    scanf("%d",&N);
    int a,b,c,d;
    for (int i=  0;i < N;i++)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        dodaj(a,b,c,d);
    }
    int odp = 0;
    for (int i = 1;i <= 100;i++)
    {
        for (int w=  1;w <= 100;w++)
            odp += tab[i][w];
    }
    printf("%d",odp);
}