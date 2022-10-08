//Bartosz Kostka
//You are not prepared!

#include "bits/stdc++.h"

using namespace std;

pair <int, int> tab[10][8];
bool czy[10];
const int MAXN = 1007;

int dist(pair <int, int> a, pair <int, int> b)
{
    return abs(a.first-b.first)+abs(a.second-b.second);
}

int main()
{
    int n, m, k, s;
    scanf("%d%d%d%d", &n, &m, &k, &s);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            int a;
            scanf("%d", &a);
            pair <int, int> tmp;
            tmp.first = i;
            tmp.second = j;
            if(czy[a]==0)
            {
                czy[a] = 1;
                for(int k=0; k<8; k++)
                    tab[a][k] = tmp;
            }
            else
            {
                if(tab[a][0].first + tab[a][0].second < i+j)
                    tab[a][0] = tmp;
                if(tab[a][1].first + tab[a][1].second > i+j)
                    tab[a][1] = tmp;
                if(tab[a][2].first - tab[a][2].second < i-j)
                    tab[a][2] = tmp;
                if(tab[a][3].first - tab[a][3].second > i-j)
                    tab[a][3] = tmp;
                if(tab[a][4].first < i)
                    tab[a][4] = tmp;
                if(tab[a][5].first > i)
                    tab[a][5] = tmp;
                if(tab[a][6].second < j)
                    tab[a][6] = tmp;
                if(tab[a][7].second > j)
                    tab[a][7] = tmp;      
            }
        }
    //for(int i=1; i<=k; i++)
    //{
    //    for(int j=0; j<8; j++)
    //        printf("(%d %d) ", tab[i][j].first, tab[i][j].second);
    //    printf("\n");
    //}
    int prev, cur, maks = 0;
    scanf("%d", &prev);
    for(int i=1; i<s; i++)
    {
        scanf("%d", &cur);
        int odl = 0;
        for(int k=0; k<8; k++)
            for(int l=0; l<8; l++)
                odl = max(odl, dist(tab[prev][k], tab[cur][l]));
        maks = max(odl, maks);
        prev = cur;
    }
    printf("%d\n", maks);
    return 0;
}