#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

//#define int long long

using namespace std;

int n;
vector<int> g[500500];
vector<int> s[500500];

int d[500500];
void dfs_diam_1(int v, int p=-1, int l=0)
{
    d[v]=l;
    for (int i:g[v])
        if (i!=p)
            dfs_diam_1(i, v, l+1);
}
int diam_sz;
int diam[500500];
bool dfs_diam_2(int v, int to, int p=-1)
{
    if (v==to)
    {
        diam[v]=1;
        return true;
    }
    for (int i:g[v])
        if (i!=p)
            if (dfs_diam_2(i, to, v))
            {
                diam[v]=1;
                return true;
            }
    return false;
}

pair<int, int> diam_f()
{
    dfs_diam_1(1);
    int v=1;
    for (int i=2; i<=n; i++)
        if (d[i]>d[v])
            v=i;
    dfs_diam_1(v);
    int t=1;
    for (int i=2; i<=n; i++)
        if (d[i]>d[t])
            t=i;
    diam_sz=d[t];
    dfs_diam_2(v, t);
    return {v, t};
}

int dfs_depth(int v, int p=-1, int diam_l=0, int l=0)
{
    if (diam[v])
        l=0;
    int sx=0;
    for (int i=0; i<g[v].size(); i++)
    {
        int to=g[v][i];
        if (to!=p)
        {
            int x=dfs_depth(to, v, diam_l+diam[to], l+1);
            x++;
            sx=max(sx, x);
            s[v][i]=x;
        }
        else
        if (diam[v]==0)
        {
            s[v][i]=l+max(diam_l, diam_sz-diam_l);
        }
    }
    return sx;
}

void powers()
{
    pair<int, int> pa=diam_f();
    int v=pa.fi;
    int t=pa.se;
    dfs_depth(v);
    dfs_depth(t);
}

/*
10
1 2
2 3
3 4
3 5
2 6
6 7
10 9
8 9
10 6

15
1 2
2 3
3 4
3 5
2 6
6 7
10 9
8 9
10 6
11 3
12 5
13 7
14 9
15 1

5
5
3
4
3
2
2
1
1
1
1
1
1
1
1

16
2 1
3 1
4 2
5 3
6 4
7 3
8 7
9 6
10 5
11 4
12 1
13 1
14 1
15 14
16 15

6
6
4
4
3
3
2
1
1
1
1
1
1
1
1
1

*/

int max_0[500500];


void sort_(vector<int> &v)
{
    int mx=-1;
    for (int i:v)
        mx=max(mx, i);
    if (v.size()*log2(v.size())<mx*4)
    {
        sort(v.begin(), v.end());
        return;
    }
    vector<int> cnt;
    cnt.resize(mx+1);
    for (int i:v)
        cnt[i]++;
    int cur=0;
    for (int i=0; i<=mx; i++)
        for (int j=0; j<cnt[i]; j++)
            v[cur]=i, cur++;
}

void upd_edge(int u, int v)
{
    vector<int> sz;
    for (int i=0; i<g[v].size(); i++)
        if (g[v][i]!=u)
            sz.pb(s[v][i]);
    for (int i=0; i<g[u].size(); i++)
        if (g[u][i]!=v)
            sz.pb(s[u][i]);
    sort_(sz);
    for (int i=0; i<sz.size(); i++)
        max_0[sz[i]]=max<int>(max_0[sz[i]], (sz.size()-i));
}

int max_1[500500];
int max_x[500500];

void upd_vert(int v)
{
    vector<int> sz;
    for (int i=0; i<g[v].size(); i++)
        sz.pb(s[v][i]);

    sort_(sz);
    for (int i=0; i<sz.size(); i++)
    {
        max_1[sz[i]]=max<int>(max_1[sz[i]], (sz.size()-i));
        if ((i==sz.size()-1) or (sz[i+1]!=sz[i]))
            max_x[sz[i]+1]=max<int>(max_x[sz[i]+1], (sz.size())-i);
        max_0[sz[i]]=max<int>(max_0[sz[i]], sz.size()-i);
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));

    cin>>n;
    for (int i=1; i<n; i++)
    {
        int u, v;
        cin>>v>>u;
//        u=i+1;
//        v=1;
        g[v].pb(u);
        g[u].pb(v);
    }
    for (int i=1; i<=n; i++)
        s[i].resize(g[i].size());
    powers();
    vector<int> ans;
    ans.resize(n+1);

    for (int i=1; i<=n; i++)
        upd_vert(i);

    vector<pair<int, int> > ed;
    for (int i=1; i<=n; i++)
        for (int j:g[i])
            if (i<j)
                ed.pb({i, j});
    random_shuffle(ed.begin(), ed.end());

    for (auto pa:ed)
    {
        upd_edge(pa.fi, pa.se);
        if (clock()*1.0/CLOCKS_PER_SEC>4.0)
            break;
    }
    int mx=1;
    for (int i=n; i>=1; i--)
    {
        mx=max(mx, max_0[i]);
        if (2*i<=n)
            ans[2*i]=mx;
    }

    mx=1;
    for (int i=n; i>=1; i--)
    {
        mx=max(mx, max_1[i]);
        int x=max(mx, max_x[i]);
        if (2*i-1<=n)
            ans[2*i-1]=x;
    }

    for (int i=1; i<=n; i++)
        ans[1]=max<int>(ans[1], signed(g[i].size()+1));

    for (int i=1; i<=diam_sz; i++)
    {
        ans[i]=max<int>(ans[i], 2);
    }

    for (int i=1; i<=n; i++)
        cout<<ans[i]<<"\n";
}