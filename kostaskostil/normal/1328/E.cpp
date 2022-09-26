#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

const int nmax=200500;

int n, m;
vector<int> g[nmax];
int d[nmax];
int up[nmax];
int lca[nmax][20];

void dfs(int v, int p=-1, int l=0)
{
    up[v]=p;
    d[v]=l;
    for (int i:g[v])
        if (i!=p)
            dfs(i, v, l+1);
}

bool par(int v, int u)
{
    for (int j=19; j>=0; j--)
    {
        if (lca[v][j]!=-1)
            if (d[lca[v][j]]>=d[u])
                v=lca[v][j];

    }
    return (u==v);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for (int i=1; i<n; i++)
    {
        int x, y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1);
    for (int i=1; i<=n; i++)
        lca[i][0]=up[i];
    for (int j=1; j<20; j++)
        for (int i=1; i<=n; i++)
            lca[i][j]=(lca[i][j-1]==-1)?-1:lca[lca[i][j-1]][j-1];
    for (int i=1; i<=m; i++)
    {
        int k;
        cin>>k;
        vector<int> v;
        int s;
        cin>>s;
        v.pb(s);
        for (int j=1; j<k; j++)
        {
            int x;
            cin>>x;
            v.pb(x);
            if (d[x]>d[s])
                s=x;
        }
        for (int j=0; j<k; j++)
            if (v[j]!=s)
                if (v[j]!=1)
                v[j]=up[v[j]];
        bool f=true;
        for (int j=0; j<k; j++)
            if (!par(s, v[j]))
                f=false;
        if (f)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}