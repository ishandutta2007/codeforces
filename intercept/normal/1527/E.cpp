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
const int M=1e5+9;
struct Segment_tree{
    ll vis[M<<2],sum[M<<2];
    void pu(int now,int l,int r){
        ll &v=vis[now];
        if(v){
            int ls=now<<1,rs=now<<1|1,mid=l+r>>1;
            vis[ls]+=v;
            vis[rs]+=v;
            sum[ls]+=v;
            sum[rs]+=v;
            v=0;
        }
    }
    void pd(int now){
        sum[now]=min(sum[now<<1],sum[now<<1|1]);
    }
    void update(int now,int l,int r,int x,int y,int v){
        if(x>y)return;
        if(x<=l&&r<=y){
            vis[now]+=v;
            sum[now]+=v;
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
        ll rex=2e9;
        if(x<=mid)rex=min(rex,query(now<<1,l,mid,x,y));
        if(y>mid)rex=min(rex,query(now<<1|1,mid+1,r,x,y));
        return rex;
    }
}t;
int n,k;
int a[M],b[M],p[M],dp[M];
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        p[i]=b[a[i]];
        b[a[i]]=i;
    }
    for(int i=1;i<=n;++i)t.update(1,0,n,i,i,1e9);
    for(int j=1;j<=k;++j){
        for(int i=1;i<=n;++i){
            if(p[i])t.update(1,0,n,0,p[i]-1,i-p[i]);
            dp[i]=t.query(1,0,n,0,i-1);
        }
        for(int i=0;i<=n;++i){
            t.update(1,0,n,i,i,dp[i]-t.query(1,0,n,i,i));
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}