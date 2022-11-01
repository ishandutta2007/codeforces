#include <bits/stdc++.h>
using namespace std;

int tab[20];
bitset<20>bs;

int N,l,r,x;

void rozluz(int q)
{
    for (int i = 0;i <= N;i++)
        bs[i] = 0;
    int i = 0;
    while (q)
    {
        if (q%2)
            bs[i] = 1;
        q /= 2;
        i++;
    }
}

bool sum()
{
    int odp = 0;
    int maxi = 0;
    int mini = 1000007;
    for (int i = 0;i < N;i++)
    {
        if (bs[i] == 1)
        {
            odp += tab[i];
            if (tab[i] > maxi)
                maxi = tab[i];
            if (tab[i] < mini)
                mini = tab[i];
        }
    }
    if (odp >= l && odp <= r && maxi-mini >= x)
        return true;
    else
        return false;
}


int main()
{
    scanf("%d%d%d%d",&N,&l,&r,&x);
    for (int i = 0;i < N;i++)
    {
        scanf("%d",&tab[i]);
    }
    int pp;
    int odp = 0;
    int il = 1;
    for (int i=  0;i < N;i++)
        il *= 2;
    for (int i = 1;i < il;i++)
    {
        rozluz(i);
        if (sum())
            odp++;
    }
    printf("%d",odp);
    return 0;
}