#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

#define int long long

using namespace std;

int n, m;
vector<int> g[200500];
vector<int> gt[200500];

int no(int x)
{
    if (x<=m)
        return x+m;
    return x-m;
}

void add_or(int x, int y)
{
//    cout<<"or: "<<x<<" "<<y<<"\n";
    g[no(x)].pb(y);
    g[no(y)].pb(x);
    gt[x].pb(no(y));
    gt[y].pb(no(x));
}

int l[100500];
vector<int> c[100500];

vector<int> ord;
int used[200500];
void dfs1(int v)
{
    used[v]=1;
    for (int i:g[v])
        if (used[i]==0)
            dfs1(i);
    ord.pb(v);
}

int comp[200500];
void dfs2(int v, int c)
{
    used[v]=1;
    for (int i:gt[v])
        if (used[i]==0)
            dfs2(i, c);
    comp[v]=c;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>l[i];
    for (int i=1; i<=m; i++)
    {
        int nx;
        cin>>nx;
        for (int j=1; j<=nx; j++)
        {
            int x;
            cin>>x;
            c[x].pb(i);
        }
    }
    for (int i=1; i<=n; i++)
    {
        if (l[i]==0)
            add_or(c[i][0], c[i][1]), add_or(no(c[i][0]), no(c[i][1]));
        else
            add_or(c[i][0], no(c[i][1])), add_or(no(c[i][0]), c[i][1]);
    }
    for (int i=1; i<=2*m; i++)
        if (used[i]==0)
            dfs1(i);
    for (int i=1; i<=2*m; i++)
        used[i]=0;
    int c=0;
    for (int i=2*m-1; i>=0; i--)
        if (used[ord[i]]==0)
            c++, dfs2(ord[i], c);
    for (int i=1; i<=m; i++)
        if (comp[i]==comp[m+i])
            cout<<"NO\n", exit(0);
    cout<<"YES\n";
    return 0;
}