#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> g[300100];
int used[300100];

int dfs(int v)
{
    int c=1;
    used[v]=1;
    for (int i=0; i<g[v].size(); i++)
    {
        int q=g[v][i];
        if (used[q]==0)
        {
            c+=dfs(q);
        }
    }
    return c;
}

main()
{
    int n;
    int x,y;
    cin>>n>>x>>y;
    for (int i=1; i<n; i++)
    {
        int l1,l2;
        cin>>l1>>l2;
        g[l1].push_back(l2);
        g[l2].push_back(l1);
    }

    int c1=0;
    used[x]=1;
    for (int i=0; i<g[x].size(); i++)
    {
        int k=used[y];
        int c=dfs(g[x][i]);
        int k1=used[y];
        if (k==k1)
            c1+=c;
    }

    for (int i=1; i<=n; i++)
        used[i]=0;

    int c2=0;
    used[y]=1;
    for (int i=0; i<g[y].size(); i++)
    {
        int k=used[x];
        int c=dfs(g[y][i]);
        int k1=used[x];
        if (k==k1)
            c2+=c;
    }
    cout<<(n*(n-1)-(c1+1)*(c2+1))<<"\n";
    return 0;
}