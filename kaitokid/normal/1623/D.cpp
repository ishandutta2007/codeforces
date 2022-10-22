#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1e9+7;
ll pw(ll x,ll y)
{
    if(y==0)return 1;
    ll p=pw(x,y/2);
    p=(p*p)%mod;
    if(y%2)p=(p*x)%mod;
    return p;
}
ll inv(ll x)
{
    return pw(x,mod-2);
}
ll n,m,x,y,a,b,gr,gc,p,q;
ll go(ll u,ll v,ll tu,ll tv,ll f,ll z)
{
    if(u==n)tu=-1;
    if(u==1)tu=1;
    if(v==m)tv=-1;
    if(v==1)tv=1;
   // cout<<u<<" "<<v<<" "<<tu<<" "<<tv<<" "<<f<<" "<<z<<endl;
    if(u==x && v==y && tu==gr && tv==gc)
    {
    //    cout<<f<<" "<<z<<endl;
        ll ans=(1-z+mod)%mod;
      //  if(ans==0)ans=mod;
        ans=inv(ans);
        ans=(ans*f)%mod;
        return ans;
    }
if(u!=a && v!=b)
{
    return go(u+tu,v+tv,tu,tv,(f+z)%mod,z);
}
z=(q*z)%mod;
return go(u+tu,v+tv,tu,tv,(f+z)%mod,z);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>x>>y>>a>>b>>p;
        gr=1,gc=1;
        if(x==n)gr=-1;
        if(y==m)gc=-1;
        q=(inv(100)*(100-p))%mod;
 //       cout<<q<<endl;
        if(x!=a && y!=b)cout<<go(x+gr,y+gc,gr,gc,1,1)<<endl;
        else cout<<go(x+gr,y+gc,gr,gc,q,q)<<endl;
    }
    return 0;
}