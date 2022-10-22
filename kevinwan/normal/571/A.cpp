#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sn(ll x){
    if(x<=0)return 0;
    return x*(x+1)/2;
}
ll solve(ll b,ll c,ll l,ll a){
    ll x1=(l+1)*(l+2)/2-sn(min(l+1,a-b-c+1));
    ll d1=min(l+1,b+l-a+1);
    ll d2=min(l+1,c+l-a+1);
    ll x2=sn(d1)+sn(d2)-sn(d1+d2-(l+1));
    return x1-x2;
}
int main()
{
    ll a,b,c,l,ans=0,i;
    scanf("%lld%lld%lld%lld",&a,&b,&c,&l);
    for(i=0;i<=l;i++){
        ans+=solve(b,c,l-i,a+i);
    }
    for(i=0;i<=l;i++){
        ans+=solve(a,c,l-i,b+i);
    }
    for(i=0;i<=l;i++){
        ans+=solve(b,a,l-i,c+i);
    }
    for(i=max(a,b);i<=min(a,b)+l;i++){
        ll u=i-a+i-b;
        u=l-u;
        if(u<0)continue;
        if(i<c)continue;
        ans+=min(i-c,u+1);
    }
    swap(a,c);
    for(i=max(a,b);i<=min(a,b)+l;i++){
        ll u=i-a+i-b;
        u=l-u;
        if(u<0)continue;
        if(i<c)continue;
        ans+=min(i-c,u+1);
    }
    swap(c,b);
    for(i=max(a,b);i<=min(a,b)+l;i++){
        ll u=i-a+i-b;
        u=l-u;
        if(u<0)continue;
        if(i<c)continue;
        ans+=min(i-c,u+1);
    }
    if(a<b)swap(a,b);
    if(b<c)swap(b,c);
    if(a<b)swap(a,b);
    ll u=2*a-b-c;
    u=l-u;
    if(u>=0){
        ans+=(u/3)+1;
    }
    printf("%lld",ans);
}