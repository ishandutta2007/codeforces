/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int mxn = 2e5+5;
const int H = 30+5;

int parent[H][mxn];
int siz[H][mxn];
vector<int> adj[H][mxn];

//use make_set, find_set and union_sets properly
void make_set(int v, int h)
{
    parent[h][v] = v;
    siz[h][v] = 1;
}

int find_set(int v, int h)
{
    if (v == parent[h][v]) return v;
    return parent[h][v] = find_set(parent[h][v], h);
}

bool check(int a, int b, int h)
{
    a = find_set(a, h);
    b = find_set(b, h);
    return (a == b);
}

bool union_sets(int a, int b, int h)
{
    a = find_set(a, h);
    b = find_set(b, h);
    if (a == b) return true;
    if (siz[h][a] < siz[h][b]) swap(a, b);
    parent[h][b] = a;
    siz[h][a] += siz[h][b];
    return false;
}

void solve()
{
    int n, m;
    cin>>n>>m;

    for(int j=1; j<=30; j++)
    {
        for(int i=1; i<=n; i++) make_set(i, j);
    }

    int non1[n+1]={0};

    for(int i=1; i<=m; i++)
    {
        int a, b, w;
        cin>>a>>b>>w;

        if(w%2==0) { non1[a]=1; non1[b]=1; }

        for(int j=1; j<=30; j++)
        {
            if(w%2==0) { w/=2; continue; }

            union_sets(a, b, j);
            //adj[j][a].push_back(b);
            //adj[j][b].push_back(a);

            w/=2;
        }
    }

    int unon[n+1]={0};

    for(int j=2; j<=30; j++)
    {
        vector<int> grp[n+1];

        for(int i=1; i<=n; i++)
        {
            int pp = find_set(i, j);
            grp[pp].push_back(i);
        }

        for(int i=1; i<=n; i++)
        {
            int poso=0;

            for(int x: grp[i])
            {
                if(non1[x]==1) poso=1;
            }

            if(poso)
            {
                for(int x: grp[i]) unon[x]=1;
            }
        }
    }

    int q; cin>>q;
    while(q--)
    {
        int u, v;
        cin>>u>>v;

        int pos0=0;
        for(int j=1; j<=30; j++)
        {
            if(check(u, v, j))
            {
                pos0=1;
                break;
            }
        }

        if(pos0) { cout<<0<<endl; continue; }

        if(non1[u] || unon[u]) { cout<<1<<endl; continue; }

        cout<<2<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}