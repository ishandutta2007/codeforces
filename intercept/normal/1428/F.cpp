#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
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
const int M=5e5+9;
int n;
char s[M];
struct Segment_tree{
    ll vis[M<<2],sum[M<<2];
    void pu(int now,int l,int r){
        ll &v=vis[now];
        if(v){
            int ls=now<<1,rs=now<<1|1,mid=l+r>>1;
            vis[ls]+=v;
            vis[rs]+=v;
            sum[ls]+=1ll*(mid-l+1)*v;
            sum[rs]+=1ll*(r-mid)*v;
            v=0;
        }
    }
    void pd(int now){
        sum[now]=sum[now<<1]+sum[now<<1|1];
    }
    void update(int now,int l,int r,int x,int y,int v){
        if(x>y)return;
        if(x<=l&&r<=y){
            vis[now]+=v;
            sum[now]+=1ll*(r-l+1)*v;
            return;
        }
        pu(now,l,r);
        int mid=l+r>>1;
        if(x<=mid)update(now<<1,l,mid,x,y,v);
        if(y>mid)update(now<<1|1,mid+1,r,x,y,v);
        pd(now);
    }
    ll query(int now,int l,int r,int x,int y){
        if(x>y)return 0;
        if(x<=l&&r<=y){
            return sum[now];
        }
        pu(now,l,r);
        int mid=l+r>>1;
        ll rex=0;
        if(x<=mid)rex+=query(now<<1,l,mid,x,y);
        if(y>mid)rex+=query(now<<1|1,mid+1,r,x,y);
        return rex;
    }
}t;
int main(){
    scanf("%d%s",&n,s+1);
    ll ans=0;
    for(int i=1,c=0;i<=n;++i){
        if(s[i]=='1'){
            c++;
            ll x=t.query(1,1,n,c,c);
            t.update(1,1,n,c,c,i-c+1-x);
            t.update(1,1,n,1,c-1,1);
        }
        else c=0;
        ans+=t.query(1,1,n,1,n);
    }
    printf("%lld\n",ans);
    return 0;
}