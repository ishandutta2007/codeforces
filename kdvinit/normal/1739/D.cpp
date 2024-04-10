/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int n, k;
const int N = 2e5 + 100;

vector<int> adj[N];
int h;
int mvs=0;

int DFS(int chi, int par)
{
    int cur=0;

    for(auto x: adj[chi])
    {
        if(x==par) continue;
        int xh = DFS(x, chi);
        cur = max(cur, xh+1);
    }

    if(cur==h-1 && par>1)
    {
        mvs++;
        cur=-1;
    }

    //cout<<chi<<" -> "<<cur<<endl;

    return cur;
}

bool check(int ch)
{
    h = ch;
    mvs=0;

    //cout<<ch<<" => "<<endl;
    DFS(1, -1);
    if(mvs>k) return false;
    else return true;
}

void solve()
{
    cin>>n>>k;
    for(int i=1; i<=n; i++) adj[i].clear();

    for(int i=2; i<=n; i++)
    {
        int u=i;
        int v; cin>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int l=0, r=n;

    while(l+1!=r)
    {
        int mid = (l+r)/2;
        if(check(mid)) r=mid;
        else l=mid;
    }

    cout<<r<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}