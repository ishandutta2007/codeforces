#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=998244353;
ll n,m,k,q;
ll x[200009],y[200009];
bool vis[200009][2];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k>>q;
        for(int i=0;i<q;i++)cin>>x[i]>>y[i];
        ll ans=1;
        for(int i=q-1;i>=0;i--)
        {
            if(vis[x[i]][0] && vis[y[i]][1])continue;
            ans=(ans*k)%mod;
            if(!vis[x[i]][0]){n--;vis[x[i]][0]=1;}
            if(!vis[y[i]][1]){m--;vis[y[i]][1]=1;}
            if(n==0|| m==0)break;
        }
        cout<<ans<<endl;

        for(int i=0;i<q;i++)vis[x[i]][0]=vis[y[i]][1]=0;
    }
    return 0;
}