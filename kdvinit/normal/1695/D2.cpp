/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 2e5+100;

vector<int> adj[N];
int tmp;
int f3;

int DFS(int chi, int par)
{
    int cnt=0;
    int sum=0;
    int at1=0;
    int ths=0;

    if(adj[chi].size()>2 && f3==0)
    {
        ths=1;
        f3=1;
    }

    for(auto x: adj[chi])
    {
        if(x==par) continue;
        cnt++;

        int y=DFS(x, chi);
        if(y==1)
        {
            sum+=1;
        }
        else
        {
            at1=1;
        }
    }

    if(cnt==0) return 1;

    if(ths==1)
    {
        tmp+=(sum-1);
        return 2;
    }

    if(sum==0) return 2;

    if(sum==1)
    {
        if(at1==1) return 2;
        else return 1;
    }
    else
    {
        tmp+=(sum-1);
        return 2;
    }
}

void solve()
{
    int n;
    cin>>n;

    if(n==1) { cout<<0<<endl; return; }

    for(int i=1; i<=n; i++) adj[i].clear();

    for(int i=1; i<=n-1; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int d3e=0;
    for(int i=1; i<=n; i++)
    {
        if(adj[i].size()>2) { d3e=1; break; }
    }

    if(d3e==0) { cout<<1<<endl; return; }

    int ans = n;
    for(int i=1; i<=n; i++)
    {
        if(adj[i].size()>1) continue;
        tmp=1;
        f3=0;
        DFS(i, -1);
        ans = min(ans, tmp);
        break;
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