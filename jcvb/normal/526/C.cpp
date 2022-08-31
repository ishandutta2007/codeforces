#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;
#define mo 1000000007
typedef long long ll;
int qp(int a,int b){
    int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);
    return ans;
}

ll m,a,b,c,d;
typedef long long ll;

ll exgcd(ll a,ll b,ll &lx,ll &ly){
    ll x=0,y=1,q,t;lx=1,ly=0;
    while(b){
        q=a/b;
        t=b;b=a%b;a=t;
        t=x;x=lx-q*x;lx=t;
        t=y;y=ly-q*y;ly=t;
    }
    return a;
}
ll r,p,q;
ll calc(ll m){
    ll ma=0;
    if(m%r!=0)return 0; 
    ll bei=m/r;
    ll p=::p*bei,q=::q*bei;
    ll d1=d/r,d2=c/r;
    ll k=(p-(p%d1+d1)%d1)/d1;
    ll qq=q+k*d2;
    if(qq>=0){
        ma=max(ma,(p-k*d1)*a+(q+k*d2)*b);
    }
    k=(q-(q%d2+d2)%d2)/d2;
    ll pp=p+k*d1;
    if(pp>=0){
        ma=max(ma,(p+k*d1)*a+(q-k*d2)*b);
    }
    return ma;
}
int main()
{
    cin>>m>>a>>b>>c>>d;
    //if(a*d>=b*c)swap(a,b),swap(c,d);
    if(d>=50000){
        ll ma=0;
        for (ll y=0;y*d<=m;y++)ma=max(ma,y*b+(m-y*d)/c*a);
        cout<<ma<<endl;
    }else{
        r=exgcd(c,d,p,q);
        ll ma=0;
        for (ll x=m;x>=0 && x>=m-d;x--)ma=max(ma,calc(x));
        cout<<ma<<endl;
    }
    return 0;
}