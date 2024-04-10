#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p1,p2,t1,t2,s;
ll dp[5009];
bool ch(ll x,ll y)
{
    ll u=(x/t1);
    if(u>=y)return true;
    ll res=u*(p1-s);
    u=(x/t2);
    if(u>=y)return true;
    res+=u*(p2-s);
    return (res>=y);
}
ll go(ll u)
{
    if(u<=0)return 0;
    if(dp[u]!=-1)return dp[u];
    ll l=0,r=100000000000000000;
    while(l<r)
    {
        ll mid=(l+r)/2;
        if(ch(mid,u))r=mid;
        else l=mid+1;

    }
    dp[u]=l;
    for(int i=1;i<=5000;i++)
    {
     ll gg=i*t1;
     if(gg<t2)continue;
     ll z=u-(i-1)*(p1-s);
     ll d=(gg-t2)/t2;
     if(d>u){dp[u]=min(dp[u],gg);break;}
     z-=d*(p2-s);
     z-=(p1+p2-s);
     if(z<0){dp[u]=min(dp[u],gg);break;}
     dp[u]=min(dp[u],gg+go(z));
    }

    for(int i=1;i<=5000;i++)
    {
     ll gg=i*t2;
     if(gg<t1)continue;
     ll z=u-(i-1)*(p2-s);
     ll d=(gg-t1)/t1;
     if(d>u){dp[u]=min(dp[u],gg);break;}
     z-=d*(p1-s);
     z-=(p1+p2-s);
     if(z<0){dp[u]=min(dp[u],gg);break;}
     dp[u]=min(dp[u],gg+go(z));
    }
    return dp[u];
}
ll h;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>p1>>t1>>p2>>t2>>h>>s;
    memset(dp,-1,sizeof dp);
    cout<<go(h);

    return 0;
}