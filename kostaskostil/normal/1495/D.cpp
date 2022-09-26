#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
//#define int ll

int n, m;
vector<int> g[1000];
int l[1000][1000];

void bfs(int v)
{
    queue<int> q;
    for (int i=1; i<=n; i++)
        l[v][i]=-1;
    q.push(v);
    l[v][v]=0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i: g[u])
            if (l[v][i]==-1)
        {
            q.push(i);
            l[v][i]=l[v][u]+1;
        }
    }
}

int used[1000];
int f(int x, int y)
{
    for (int i=1; i<=n; i++)
        used[i]=0;
    used[x]=1;
    int v = y;
    while (v!=x)
    {
        used[v]=1;
        vector<int> pr;
        for (int i : g[v])
            if (l[x][i] == l[x][v] - 1)
                pr.pb(i);
        if (pr.size() != 1)
            return 0;
        v=pr[0];
    }

    ll ans = 1;
    for (int i = 1; i<=n; i++)
        if (!used[i])
    {
        int pr = 0;
        for (int j : g[i])
            if (l[x][j] == l[x][i]-1)
            if (l[y][j] == l[y][i]-1)
                pr++;
        ans*=pr;
        ans%=998244353;
    }
    return ans;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for (int x, y, i=1; i<=m; i++)
    {
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }

    for (int i=1; i<=n; i++)
        bfs(i);
    for (int i=1; i<=n; i++, cout<<"\n")
        for (int j=1; j<=n; j++)
            cout<<f(i, j)<<" ";

}