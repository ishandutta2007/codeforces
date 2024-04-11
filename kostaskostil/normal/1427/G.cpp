#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

const int nmax=205;
typedef long long ll;
#define int ll

struct edge
{
    int to;
    int back;
    int flow;
};

int n;
vector<edge> g[nmax * nmax];
int a[nmax][nmax];


void addedge(int u, int v)
{
    int n1 = g[u].size();
    int n2 = g[v].size();
    g[u].pb({v, n2, 1});
    g[v].pb({u, n1, 1});
}

int vx(int i, int j)
{
    return n*i + j;
}

int isT[nmax * nmax];
int isS[nmax * nmax];
int l[nmax * nmax];
int st[nmax * nmax];

int dfs(int v, int flow=1e9)
{
    if (isT[v])
        return flow;

    for ( ; st[v]<int(g[v].size()); st[v]++)
    {
        auto& pa=g[v][st[v]];
        if (l[pa.to]==l[v]+1)
            if (pa.flow > 0)
            if (int var = dfs(pa.to, min(flow, pa.flow)))
            {
                pa.flow-=var;
                g[pa.to][pa.back].flow+=var;
                return var;
            }
    }
    return 0;
}

bool bfs(int vstart=-1)
{
    for (int i=0; i<n*n; i++)
        l[i]=-1, st[i]=0;
    queue<int> q;
    if (vstart==-1)
    {
        for (int i=0; i<n*n; i++)
            if (isS[i])
                q.push(i), l[i]=0;
    }
    else
        q.push(vstart), l[vstart]=0;
    while (!q.empty())
    {
        int v=q.front();
        q.pop();
        for (auto pa: g[v])
            if (l[pa.to]==-1)
            if (pa.flow > 0)
                l[pa.to]=l[v]+1, q.push(pa.to);
    }
    for (int i=0; i<n*n; i++)
        if (isT[i])
            if (l[i]!=-1)
                return true;
    return false;
};

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<pair<int, pair<int, int> > > border;
    cin>>n;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
        {
            cin>>a[i][j];
            if ((i==0) or (j==0) or (i==n-1) or (j==n-1))
                border.pb({a[i][j], {i, j}}), isT[vx(i, j)]=1;
        }
    sort(border.begin(), border.end());

    for (int i=0; i+1<n; i++)
        for (int j=0; j+1<n; j++)
            if (a[i][j]!=-1)
        {
            if (i!=0)
            if (a[i][j+1]!=-1)
                addedge(vx(i, j), vx(i, j+1));
            if (j!=0)
            if (a[i+1][j]!=-1)
                addedge(vx(i, j), vx(i+1, j));
        }

    int ans=0;
    int curflow=0;
    for (size_t i=0; i+1<border.size(); i++)
    {
        int v = vx(border[i].se.fi, border[i].se.se);

        if (!g[v].empty())
            if (g[v][0].flow > 1)
            {
                bfs(v);
                dfs(v, 1);
                curflow--;
            }
        isT[v]=0;
        isS[v]=1;
        while (bfs())
        {
            for (int i=0; i<n*n; i++)
                if (isS[i])
                    if (int nt=dfs(i))
                        curflow+=nt;
        }
        ans+=curflow*(border[i+1].fi - border[i].fi);
    }
    for (int i=0; i+1<n; i++)
        ans+=abs(a[0][i]-a[0][i+1]),
        ans+=abs(a[n-1][i]-a[n-1][i+1]),
        ans+=abs(a[i][0]-a[i+1][0]),
        ans+=abs(a[i][n-1]-a[i+1][n-1]);
    cout<<ans<<"\n";
}