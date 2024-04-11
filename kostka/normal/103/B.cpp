#include "bits/stdc++.h"

using namespace std;

const int MAXN = 107;
bool czy[MAXN];
vector <int> G[MAXN];

void dfs(int v)
{
    czy[v] = 1;
    for(auto w : G[v])
        if(czy[w]==0)
            dfs(w);
}

bool check(int n, int m)
{
    if(n!=m)
        return false;
    for(int i=1; i<=n; i++)
        if(czy[i]==0)
            return false;
    return true;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=0; i<m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    if(n<3)
    {
        puts("NO");
        return 0;
    }
    dfs(1);
    puts(check(n,m) ? "FHTAGN!" : "NO");
}