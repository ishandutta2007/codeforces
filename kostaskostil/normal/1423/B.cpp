
#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;

const int NMAX=1e5+100;

int n, m, k;
vector<int> g[2*NMAX];
int used[2*NMAX];
int l[2*NMAX];

void bfs()
{
    queue<int> q;
    for (int i=0; i<m+n; i++)
        l[i]=-1;
    for (int i=0; i<n; i++)
        if (used[i]==-1)
            q.push(i), l[i]=0;

    k=1e9;
    while (!q.empty())
    {
        int v=q.front();
        if (l[v]>=k)
            return;

        if (l[v]%2==0)
        {
            for (int i:g[v])
                if (l[i]==-1)
            {
                q.push(i);
                l[i]=l[v]+1;
                if (used[i]==-1)
                    k=l[i];
            }
        }
        else
            if (l[used[v]]==-1)
        {
            if (used[v]==-1)
                cout<<"WARNING\n";
            l[used[v]]=l[v]+1;
            q.push(used[v]);
        }

        q.pop();
    }
}

bool dfs(int v)
{
    if (v==-1)
        return true;
    for (int to:g[v])
        if ((used[to]==-1) or (l[used[to]]==l[v]-2))
            if (dfs(used[to]))
            {
                used[to]=v;
                used[v]=to;
                return true;
            }
    l[v]=-1;
    return false;
}

int N;
vector<pair<pair<int, int>, int> > edges;
bool isok(int val)
{
    n=N;
    m=N;

    for (int i=0; i<NMAX; i++)
        g[i].clear();
    for (auto pa:edges)
    {
        if (pa.se <= val)
        {
            int x, y;
            x=pa.fi.fi;
            y=pa.fi.se;
            g[x].pb(n+y);
            g[n+y].pb(x);
        }
    }
    for (int i=0; i<n+m; i++)
        used[i]=-1;
    memset(l, 0, sizeof(l));

    while (true)
    {
        bfs();
        if (k==1e9)
            break;
        for (int i=0; i<m+n; i++)
            if ((l[i]==k) and (used[i]==-1))
                dfs(i);
    }
    int q=0;
    for (int i=0; i<n; i++)
        if (used[i]!=-1)
            q++;

//    cout<<q<<"\n";
    return (q==n);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin>>N>>q;

    for (int i=0; i<q; i++)
    {
        int x, y, d;
        cin>>x>>y>>d;
        edges.pb({{x-1, y-1}, d});
    }

    int l=0;
    int r=1e9+100;

    if (!isok(r))
        cout<<"-1\n", exit(0);

    while(r-l>1)
    {
        int m = (l+r)/2;
        if (isok(m))
            r=m;
        else
            l=m;
    }
    cout<<r<<"\n";

    return 0;
}