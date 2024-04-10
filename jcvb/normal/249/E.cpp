#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
ll mo;
ll mul(ll x,ll y){
    x%=mo;y%=mo;
    if(x<0)x+=mo;if(y<0)y+=mo;
    return ((x*y-(ll)((long double)x*y/mo)*mo)%mo+mo)%mo;
}
ll mul2(ll x,ll y){
    x%=mo;y%=mo;
    if(x<0)x+=mo;if(y<0)y+=mo;
    ll ans=0;
    do{
        if(y&1){ans+=x;if(ans>=mo)ans-=mo;}
        x<<=1;if(x>=mo)x-=mo;
    }while(y>>=1);
    return ans;
}
ll sum(ll x){
    if(x&1)return mul((x+1)>>1,x);
    else return mul(x>>1,x+1);
}
ll sqsum(ll n){
    ll p=n,q=n+1,r=2*n+1;
    if(p%3==0)p/=3;
    else if(q%3==0)q/=3;
    else r/=3;
    if(p&1)q>>=1;
    else p>>=1;
    return mul(mul(p,q),r);
}
ll work(ll x,ll y){
    if(x==y)return sum(x*x);
    ll ans=0;
    if(x<y){
        ans+=sum(x*x);
        ll tmp=sqsum(y-1)-sqsum(x-1)+y-x;
        tmp=(mul(tmp,x)+mul(y-x,sum(x-1)))%mo;
        ans=(ans+tmp)%mo;
        if(ans<0)ans+=mo;
        return ans;
    }else{
        ans+=sum(y*y);
        ll tmp=sqsum(x)-sqsum(y);
        tmp=(mul(tmp,y)-mul(x-y,sum(y-1)))%mo;
        ans=(ans+tmp)%mo;
        if(ans<0)ans+=mo;
        return ans;
    }
}
int main()
{
    int tes;scanf("%d",&tes);
    while(tes--){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        ll ans1,ans2;
        mo=10000000000ll;
        ans1=(work(x2,y2)-work(x1-1,y2)-work(x2,y1-1)+work(x1-1,y1-1))%mo;
        if(ans1<0)ans1+=mo;
        mo=11037271757ll;
        ans2=(work(x2,y2)-work(x1-1,y2)-work(x2,y1-1)+work(x1-1,y1-1))%mo;
        if(ans2<0)ans2+=mo;
        if(ans2!=ans1)printf("...%010I64d\n",ans1);
        else printf("%lld\n",ans1);
    }
    return 0;
}