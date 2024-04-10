#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1e9+7;
ll dp[200009],n,p,a[200009];
map<int,bool> vis;
bool go(int x)
{
    while(x>0)
    {
        if(vis[x])return true;
        if(x%2){x/=2;continue;}
        if(x%4==0){x/=4;continue;}
        break;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>p;
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=p;i++)dp[i]=(dp[i-1]+dp[i-2])%mod;
    for(int i=1;i<=p;i++)dp[i]=(dp[i]+dp[i-1])%mod;
    for(int i=0;i<n;i++)cin>>a[i];
    ll ans=0;
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        if(go(a[i]))continue;
        vis[a[i]]=true;
        int u=0;
        while(a[i]>0){u++;a[i]/=2;}
        if(u>p)continue;
        ans=(ans+dp[p-u])%mod;
    }
    cout<<ans;
    return 0;
}