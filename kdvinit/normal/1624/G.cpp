/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int mxn = 2e5 + 100;

int parent[mxn];
int siz[mxn];

//use make_set, find_set and union_sets properly
void make_set(int v)
{
    parent[v] = v;
    siz[v] = 1;
}

int find_set(int v)
{
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

bool union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a == b) return true;
    if (siz[a] < siz[b]) swap(a, b);
    parent[b] = a;
    siz[a] += siz[b];
    return false;
}

const int N = 2e5 + 100;
int u[N], v[N], w[N];

vector<int> ord[31];
int pos[31]={0};
int n, m;

bool check()
{
    for(int i=1; i<=n; i++) make_set(i);

    int ep[m+1]={0};
    for(int i=1; i<=m; i++) ep[i]=1;

    for(int j=0; j<=30; j++)
    {
        if(pos[j]==1) continue;
        for(int x: ord[j]) ep[x]=0;
    }

    int cnt = 0;
    for(int i=1; i<=m; i++)
    {
        if(ep[i]==0) continue;
        int uu = u[i];
        int vv = v[i];
        if(union_sets(uu, vv)) continue;
        cnt++;
    }

    return (cnt==(n-1));
}

void solve()
{
    cin>>n>>m;
    for(int i=1; i<=m; i++) cin>>u[i]>>v[i]>>w[i];

    for(int j=0; j<=30; j++)
    {
        pos[j]=1;
        ord[j].clear();

        int num = 1<<j;
        for(int i=1; i<=m; i++)
        {
            if((w[i]&num)!=0) ord[j].push_back(i);
        }
    }

    int ans = 0;
    for(int j=30; j>=0; j--)
    {
        int num = 1<<j;
        pos[j]=0;
        if(check()) continue;
        pos[j]=1;
        ans+=num;
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}