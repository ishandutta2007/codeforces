/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 2e5 + 100;

vector<int> adj[N];
int a[N];
int b[N];
int r[N];
vector<int> pb;
int suma;
int sumb;

void DFS(int chi, int par)
{
    if(chi!=1)
    {
        suma+=a[chi];
        sumb+=b[chi];
        pb.push_back(sumb);

        int l=pb.size();
        if(suma<pb[0]) r[chi]=0;
        else if(suma>=pb[l-1]) r[chi]=l;
        else
        {
            int i = upper_bound(pb.begin(), pb.end(),suma) - pb.begin();
            r[chi]=i;
        }
    }

    for(auto x: adj[chi])
    {
        if(x==par) continue;
        DFS(x, chi);
    }

    if(chi!=1)
    {
        suma-=a[chi];
        sumb-=b[chi];
        pb.pop_back();
    }
}

void solve()
{
    int n;
    cin>>n;

    for(int i=1; i<=n; i++) adj[i].clear();

    for(int i=2; i<=n; i++)
    {
        int par; cin>>par;
        adj[par].push_back(i);
        adj[i].push_back(par);
        cin>>a[i]>>b[i];
    }

    pb.clear();
    suma=0; sumb=0;
    DFS(1, -1);

    for(int i=2; i<=n; i++) cout<<r[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}