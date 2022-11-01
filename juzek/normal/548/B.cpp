#include <bits/stdc++.h>
using namespace std;

int maxi[507];
int tab[507][507];

int main()
{
    int N,M;
    int T;
    scanf("%d%d%d",&N,&M,&T);
    for (int i = 0; i < N;i++)
    {
        for (int w = 0;w < M;w++)
            scanf("%d",&tab[i][w]);
    }

    int il = 0;

    for (int i = 0;i < N;i++)
    {
        il = 0;
        for (int w = 0;w < M;w++)
        {
            if (tab[i][w] == 0)
                il = 0;
            else
                il++;
            maxi[i] = max(maxi[i],il);
        }
    }
    int a,b;
    int zet = 0;
    while (T--)
    {
        scanf("%d%d",&a,&b);
        a--,b--;
        tab[a][b] = !tab[a][b];
        il = 0;
        maxi[a] = 0;
        for (int i = 0;i < M;i++)
        {
            if (tab[a][i] == 0)
                il = 0;
            else
                il++;
            maxi[a] = max(maxi[a],il);
        }
        zet = 0;
        for (int i = 0;i < N;i++)
        {
            zet = max(maxi[i],zet);
        }
        printf("%d\n",zet);
    }
    return 0;
}