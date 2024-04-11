#include "bits/stdc++.h"

using namespace std;

vector <int> N, P, W[100007];

int n, m, k, l;

bool solve()
{
    if((int)N.size() < l)
        return false;
    for(int i=k; i<m; i++)
        W[i].push_back(N[i-k]);
    int reszta = (int)N.size()-l;
    if(reszta % 2)
        return false;
    if(reszta/2 + (int)P.size() < k)
        return false;
    int nr = 0;
    for(int i=0; i<(int)P.size(); i++)
    {
        W[nr%m].push_back(P[i]);
        nr++;   
    }
    for(int i=0; i<reszta; i+=2)
    {
        W[nr%m].push_back(N[i+l]);
        W[nr%m].push_back(N[i+l+1]);
        nr++;
    }
    return true;
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    l = m-k;
    for(int i=0; i<n; i++)
    {
        int a;
        scanf("%d", &a);
        if(a % 2)
            N.push_back(a);
        else
            P.push_back(a);
    }
    if(solve())
    {
        puts("YES");
        for(int i=0; i<m; i++)
        {
            printf("%d ", int(W[i].size()));
            for(int j=0; j<(int)W[i].size(); j++)
                printf("%d ", W[i][j]);
            printf("\n");
        }
    }
    else
        puts("NO");
    return 0;
}