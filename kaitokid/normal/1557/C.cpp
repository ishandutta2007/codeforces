#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1e9 +7;
ll p[200009];
ll pw(ll x,ll y)
{
    if(y==0)return 1;
    if(y%2)return ((x*1LL*pw(x,y-1))%mod);
    ll p=pw(x,y/2);
    return ((p*1LL*p)%mod);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
p[0]=1;
for(int i=1;i<=200009;i++)p[i]=(p[i-1]*1LL*2)%mod;
int t;
cin>>t;
while(t--)
{
    ll n,k;
    cin>>n>>k;
    if(n%2)
    {
        ll u= (p[n-1]+1)%mod;
        cout<<pw(u,k)<<endl;
        continue;
    }
    ll rr=(pw(2,n-1)+mod-1)%mod;
    ll ans=pw(rr,k);
    for(ll i=0;i<k;i++)
    {
        ll u=p[n];
        u=pw(u,i);
        ll g=rr;
        g=pw(g,k-i-1);
        ans+=(u*1LL*g)%mod;
        ans%=mod;
    }
cout<<ans<<endl;
}
  return 0;
}