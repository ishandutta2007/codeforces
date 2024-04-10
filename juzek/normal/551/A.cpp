#include <bits/stdc++.h>
using namespace std;

int tab[2007];
pair<int,int> sorttab[2007];


int main()
{
    int N;
    scanf("%d",&N);
    int a;
    for (int i = 0;i < N;i++)
    {
        scanf("%d",&sorttab[i].first);
        sorttab[i].second = i;
    }
    sort(sorttab,sorttab+N);
    int m = 0;
    int newm = 0;
    for (int i = N-1;i >= 0;i--)
    {
        if (sorttab[i].first != sorttab[i+1].first)
        {
            m++;
            m += newm;
            newm = 0;
        }
        else
            newm++;
        tab[sorttab[i].second] = m;
    }
    for (int i = 0;i < N;i++)
    {
        printf("%d ",tab[i]);
    }
    return 0;
}