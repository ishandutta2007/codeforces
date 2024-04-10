#include <bits/stdc++.h>
using namespace std;

int tab[5000007];

int podziel(int a,int b)
{
    int odp = 0;
    while (a%b == 0)
    {
        a /= b;
        odp++;
    }
    return odp;
}

int main()
{
    for (int i = 2;i < 5000000;i++)
    {
        if (tab[i] == 0)
        {
            for (int w = i;w <= 5000000;w+=i)
            {
                tab[w] += podziel(w,i);
            }
        }
    }
    for (int i = 2;i <= 5000000;i++)
    {
        if (tab[i] == 0)
            tab[i] = 1;
        tab[i] += tab[i-1];
    }
    printf("\n");
    int T;
    scanf("%d",&T);
    int a,b;
    while (T--)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",tab[a]-tab[b]);
    }
    return 0;
}