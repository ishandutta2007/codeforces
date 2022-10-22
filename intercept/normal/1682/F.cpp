#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=1e9+7;
int kpow(int x,ll y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
int exgcd(int a,int b,int &x,int &y){
    int t=b?exgcd(b,a%b,y,x):a;
    if(!b)x=1,y=0;
    else y-=a/b*x;
    return t;
}

const int M=1e6+9;
int n,m,num;
int a[M],b[M];
struct Bit{
    int bit[M];
    void add(int x,int v){
        for(;x<M;x+=x&-x)bit[x]=(bit[x]+v)%mod;
    }
    ll ask(int x,int rex=0){
        for(;x;x-=x&-x)rex=(rex+bit[x])%mod;
        return rex;
    }
}p0,p1,s0,s1;
int ans[M];
struct P{
    int o;
    ll fi;
    int id;
};
vector<P>g[M];
ll c[M],p[M];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    for(int i=1;i<=n;++i)scanf("%d",&b[i]);
    for(int i=1;i<=n;++i){
        p[i]=p[i-1]+b[i];
    }
    for(int i=0;i<=n;++i)c[++num]=p[i];
    sort(c+1,c+num+1);
    num=unique(c+1,c+num+1)-c-1;
    for(int i=0;i<=n;++i)p[i]=lower_bound(c+1,c+num+1,p[i])-c;
    for(int i=1;i<=num;++i)c[i]=c[i]%mod;
    for(int i=1;i<=m;++i){
        int l,r;
        scanf("%d%d",&l,&r);
        if(p[r]!=p[l-1]){
            ans[i]=0;
            continue;
        }
        g[l-1].eb(P{-1,p[l-1],i});
        g[r].eb(P{1,p[l-1],i});
    }
    for(int i=1;i<=n;++i){
        p0.add(p[i-1],1ll*a[i]*c[p[i-1]]%mod);
        p1.add(p[i],1ll*a[i]*c[p[i]]%mod);
        s0.add(p[i-1],a[i]);
        s1.add(p[i],a[i]);
        for(auto o:g[i]){
            ll pp1=1ll*p1.ask(o.fi)-(p1.ask(num)-p1.ask(o.fi));
            ll ss1=(-1ll*s1.ask(o.fi)+s1.ask(num)-s1.ask(o.fi))*(c[o.fi]%mod)%mod;
            ll pp0=(1ll*p0.ask(num)-p0.ask(o.fi))-p0.ask(o.fi);
            ll ss0=(1ll*s0.ask(o.fi)-(s0.ask(num)-s0.ask(o.fi)))*(c[o.fi]%mod)%mod;
            int rex=((1ll*pp1+ss1+pp0+ss0)%mod+mod)%mod;
            ans[o.id]=(ans[o.id]+1ll*o.o*rex%mod)%mod;
        }
    }
    for(int i=1;i<=m;++i){
        printf("%d\n",(ans[i]+mod)%mod);
    }
    return 0;
}
/*
2 1
2 4 
-1 1
1 2 
*/