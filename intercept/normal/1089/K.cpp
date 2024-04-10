#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define ls now<<1,l,mid
#define rs now<<1|1,mid+1,r
#define pii pair<int,int>
using namespace std;
const int mod=1e9+7;
int kpow(int x,int y,int rex=1){
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
const int N=1e6;
int q;
pii op[M];
ll ma[M<<2],va[M<<2],vis[M<<2];
void build(int now,int l,int r){
    if(l==r){
        ma[now]=l;
        return;
    }
    int mid=l+r>>1;
    build(ls);
    build(rs);
    ma[now]=max(ma[now<<1],ma[now<<1|1]);
}
void pu(int now){
    ll &v=vis[now];
    if(v){
        ma[now<<1]+=v;
        vis[now<<1]+=v;
        ma[now<<1|1]+=v;
        vis[now<<1|1]+=v;
        v=0;
    }
}
void update(int now,int l,int r,int x,int d){
    va[now]+=d;
    if(l==r)return;
    pu(now);
    int mid=l+r>>1;
    x<=mid?update(ls,x,d):update(rs,x,d);
    ma[now]=max(ma[now<<1],ma[now<<1|1]);
}
void change(int now,int l,int r,int x,int y,int d){
    if(x<=l&&r<=y){
        ma[now]+=d;
        vis[now]+=d;
        return;
    }
    pu(now);
    int mid=l+r>>1;
    if(x<=mid)change(ls,x,y,d);
    if(y>mid)change(rs,x,y,d);
    ma[now]=max(ma[now<<1],ma[now<<1|1]);
}
ll query(int now,int l,int r,int x,int y){
    if(x<=l&&r<=y){
        return ma[now];
    }
    pu(now);
    int mid=l+r>>1;
    ll mx=0;
    if(x<=mid)mx=max(mx,query(ls,x,y));
    if(y>mid)mx=max(mx,query(rs,x,y));
    return mx;
}
ll find(int now,int l,int r,int x,int y){
    if(x<=l&&r<=y){
        return va[now];
    }
    int mid=l+r>>1;
    ll s=0;
    if(x<=mid)s+=find(ls,x,y);
    if(y>mid)s+=find(rs,x,y);
    return s;
}
int main(){
    scanf("%d",&q);
    build(1,1,N);
    for(int i=1;i<=q;++i){
        char c[4];
        int t,o,d;
        scanf("%s",c);
        if(c[0]=='+'){
            scanf("%d%d",&t,&d);
            op[i]=make_pair(t,d);
            update(1,1,N,t,d);
            change(1,1,N,t+1,N,-d);
        }
        if(c[0]=='-'){
            scanf("%d",&o);
            t=op[o].fi;
            d=op[o].se;
            update(1,1,N,t,-d);
            change(1,1,N,t+1,N,d);
        }
        if(c[0]=='?'){
            scanf("%d",&t);
            ll ma=query(1,1,N,1,t)+find(1,1,N,1,t);
            printf("%lld\n",max(ma-t,0ll));
        }
    }
    return 0;
}
/*
4
+ 2 2
+ 5 2
+ 1 2 
? 2
*/