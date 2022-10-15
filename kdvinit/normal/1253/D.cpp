/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mxn=2e5+1;
int parent[mxn],siz[mxn];

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

void solve()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++) make_set(i);

    vector<int> adj[n+1];
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        union_sets(u,v);
    }
    
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int p=find_set(i);
        int j=i;
        while(i<=n && i-j!=siz[p])
        {
            if(find_set(i)!=find_set(j))
            {
                ans++;
                union_sets(i,j);
            }
            i++;
            p=find_set(j);
        }
        i--;
    }
    cout<<ans<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}