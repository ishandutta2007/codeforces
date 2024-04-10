/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 2e5 + 10;

vector<int> adj[N];
int pos=0;
int fh[N];
int sor;
int pr[N];

void DFS(int chi, int par, int famh)
{
    if(fh[chi]==famh) return;
    if(chi==sor) return;

    if(fh[chi]!=-1)
    {
        vector<int> a, b;

        int xx=chi;
        while(xx!=-1)
        {
            a.push_back(xx);
            xx=pr[xx];
        }

        b.push_back(chi);
        xx=par;

        while(xx!=-1)
        {
            b.push_back(xx);
            xx=pr[xx];
        }

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        cout<<"Possible"<<endl;

        cout<<a.size()<<endl;
        for(int x: a) cout<<x<<" ";
        cout<<endl;

        cout<<b.size()<<endl;
        for(int x: b) cout<<x<<" ";
        cout<<endl;

        pos=1;
        return;
    }

    pr[chi]=par;
    fh[chi]=famh;

    if(pos==1) return;

    for(int x: adj[chi])
    {
        if(x==par) continue;
        if(pos==1) return;
        DFS(x, chi, famh);
    }

    if(pos==1) return;
}

void solve()
{
    int n, m, s;
    cin>>n>>m>>s;
    sor=s;

    for(int i=1; i<=n; i++)
    {
        adj[i].clear();
        fh[i]=-1;
        pr[i]=-1;
    }

    for(int i=1; i<=m; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    for(int x: adj[s])
    {
        DFS(x, s, x);
        if(pos==1) return;
    }

    cout<<"Impossible"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}