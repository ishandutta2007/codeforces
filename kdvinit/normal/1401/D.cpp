/*
K.D. Vinit
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define int     long long

int mod=1e9+7;

int gra_chi(vector< vector<int> >& adj,int gpar,int par,int gchi[])
{
    int ans=0;
    for(int i=0;i<adj[par].size();i++)
    {
        if(adj[par][i]!=gpar)
        {
            ans++;
            ans+=gra_chi(adj,par,adj[par][i],gchi);
        }
    }
    gchi[par]=ans;
    return ans;
}

void solve()
{
    int n,x,y,m;
    cin>>n;

    vector< vector<int> > adj(n+1);
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int gchi[n+1]={0},w[n+1];
    int xx=gra_chi(adj,-1,1,gchi);


    for(int i=1;i<=n;i++) gchi[i]++;
    for(int i=1;i<=n;i++) w[i]=gchi[i]*(n-gchi[i]);
    sort(w+1,w+n+1);

    cin>>m;
    int prime[m+1];
    for(int i=1;i<=m;i++) cin>>prime[i];
    sort(prime+1,prime+m+1);

    int arr_prime[n+1];
    arr_prime[1]=1;
    if(m<n)
    {
        for(int i=2;i<=n-m;i++) arr_prime[i]=1;
        for(int i=n-m+1;i<=n;i++) arr_prime[i]=prime[i-n+m];
    }
    else
    {
        for(int i=2;i<=n-1;i++) arr_prime[i]=prime[i-1];
        int temp=1;
        for(int i=n-1;i<=m;i++) { temp*=prime[i]; temp%=mod; }
        arr_prime[n]=temp;
    }

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=(((w[i]%mod)*arr_prime[i])%mod);
        ans%=mod;
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}