//Bartosz Kostka
//You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 1007;
const int MAXK = 7;
int tab[MAXK][MAXN], odl[MAXN];
bool czy[MAXN];
vector <int> G[MAXN], S;

bool check(int a, int b, int k)
{
    for(int i=0; i<k; i++)
        if(tab[i][a] > tab[i][b])
            return false;
    return true;
}

void dfs(int v)
{
    czy[v] = 1;
    for(auto w : G[v])
        if(czy[w]==0)
            dfs(w);
    S.push_back(v);
}

int main()
{
    int n,k;
    scanf("%d%d", &n, &k);
    for(int i=0; i<k; i++)
    {
        for(int j=0; j<n; j++)
        {
            int a;
            scanf("%d", &a);
            tab[i][a-1] = j;
        }
    }
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(i!=j && check(i,j,k))
                G[i].push_back(j);
    for(int i=0; i<n; i++)
        if(czy[i]==0)
            dfs(i);
    reverse(S.begin(), S.end());
    int ans = 0;
    for(auto u : S)
    {
        for(auto w : G[u])
            odl[w] = max(odl[w], odl[u]+1);
        ans = max(odl[u],ans);
    }
    printf("%d\n", ans+1);
    return 0;
}