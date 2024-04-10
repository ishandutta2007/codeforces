/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 1;
vector<int> adj[N];

int child[N];

void get_child(int c,int p)
{
    int sum=1;
    for(int i=0;i<adj[c].size();i++)
    {
        int cc=adj[c][i];
        if(cc==p) continue;
        get_child(cc,c);
        sum+=child[cc];
    }
    child[c]=sum;
}

void solve()
{
    int n;
    cin>>n;

    for(int i=1;i<n;i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    get_child(1,-1);
    for(int i=1;i<=n;i++) cout<<i<<" -> "<<child[i]<<endl;

    return;
}

void solve2()
{
    int n, k;
    cin>>n>>k;
    int nk = n*k;

    int a[nk+1];
    for(int i=1;i<=nk;i++) cin>>a[i];
    sort(a+1,a+nk+1);
    int m = (n/2) + 1;
    int times=k;
    int pos=nk+1;
    int ans=0;
    while(times--)
    {
        pos-=m;
        ans+=a[pos];
        //cout<<pos<<" "<<a[pos]<<endl;
    }
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve2();
    //solve();
    return 0;
}