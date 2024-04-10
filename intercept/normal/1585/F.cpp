#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=998244353;
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
const int M=1000009;
int n,sz;
struct Segment_tree{
    int vis[M*20],sum[M*20],mul[M*20];
    int ls[M*20],rs[M*20];
    void get(int&x){
        if(x)return;
        x=++sz;
        mul[x]=1;
    }
    void pu(int now,int l,int r){
        get(ls[now]);
        get(rs[now]);
        int &v=vis[now];
        int &m=mul[now];
        if(m!=1){
            mul[ls[now]]*=m;
            vis[ls[now]]*=m;
            sum[ls[now]]*=m;
            mul[rs[now]]*=m;
            vis[rs[now]]*=m;
            sum[rs[now]]*=m;
            m=1;
        }
        if(v){
            int mid=l+r>>1;
            vis[ls[now]]=(vis[ls[now]]+v)%mod;
            sum[ls[now]]=(sum[ls[now]]+1ll*v*(mid-l+1)%mod)%mod;
            vis[rs[now]]=(vis[rs[now]]+v)%mod;
            sum[rs[now]]=(sum[rs[now]]+1ll*v*(r-mid)%mod)%mod;
            v=0;
        }
    }
    void pd(int now){
        sum[now]=(sum[ls[now]]+sum[rs[now]])%mod;
    }
    void update(int&now,int l,int r,int x,int y,int v){
        if(x>y)return;
        get(now);
        if(x<=l&&r<=y){
            vis[now]=(vis[now]+v)%mod;
            sum[now]=(sum[now]+1ll*(r-l+1)*v%mod)%mod;
            return;
        }
        pu(now,l,r);
        int mid=l+r>>1;
        if(x<=mid)update(ls[now],l,mid,x,y,v);
        if(y>mid)update(rs[now],mid+1,r,x,y,v);
        pd(now);
    }
    void change(int&now,int l,int r,int x,int y,int v){
        if(x>y)return;
        get(now);
        if(x<=l&&r<=y){
            mul[now]*=v;
            vis[now]*=v;
            sum[now]*=v;
            return;
        }
        pu(now,l,r);
        int mid=l+r>>1;
        if(x<=mid)change(ls[now],l,mid,x,y,v);
        if(y>mid)change(rs[now],mid+1,r,x,y,v);
        pd(now);
    }
    int query(int&now,int l,int r,int x,int y){
        if(x>y)return 0;
        get(now);
        if(x<=l&&r<=y){
            return sum[now];
        }
        pu(now,l,r);
        int mid=l+r>>1;
        int rex=0;
        if(x<=mid)rex=(rex+query(ls[now],l,mid,x,y))%mod;
        if(y>mid)rex=(rex+query(rs[now],mid+1,r,x,y))%mod;
        return rex;
    }
}s;
int a[M];
int main(){
    scanf("%d",&n);
    scanf("%d",&a[1]);
    int rt=0;
    s.update(rt,1,1e9,1,a[1],1);
    for(int i=2;i<=n;++i){
        scanf("%d",&a[i]);
        int sum=s.query(rt,1,1e9,1,a[i-1]);
        int x=min(a[i-1],a[i]);
        s.change(rt,1,1e9,1,x,-1);
        s.change(rt,1,1e9,x+1,1e9,0);
        s.update(rt,1,1e9,1,a[i],sum);
    }
    int ans=s.query(rt,1,1e9,1,a[n]);
    ans=(ans%mod+mod)%mod;
    printf("%d\n",ans);
    return 0;
}
/*
4
7 9 8 3

*/