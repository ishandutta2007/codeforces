#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=998244353;
int kpow(int x,int y,int rex=0){
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
int a[M],b[M<<2],c[M],dp[M];
ll s[M],t[M];
void update(int now,int l,int r,int x,int v){
    b[now]=max(b[now],v);
    if(l==r){
        return;
    }
    int mid=l+r>>1;
    if(x<=mid)update(now<<1,l,mid,x,v);
    else update(now<<1|1,mid+1,r,x,v);
}
int query(int now,int l,int r,int x,int y){
    if(x>y)return -1e9;
    if(x<=l&&r<=y){
        return b[now];
    }
    int mid=l+r>>1,ans=-1e9;
    if(x<=mid)ans=max(ans,query(now<<1,l,mid,x,y));
    if(y>mid)ans=max(ans,query(now<<1|1,mid+1,r,x,y));
    return ans;
}
void build(int now,int l,int r){
    b[now]=-1e9;
    if(l==r){
        return;
    }
    int mid=l+r>>1;
    build(now<<1,l,mid);
    build(now<<1|1,mid+1,r);
}
void work(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    s[1]=0;
    for(int i=1;i<=n;++i){
        s[i+1]=s[i]+a[i];
    }
    sort(s+1,s+n+2);
    int m=unique(s+1,s+n+2)-s-1;
    int x=lower_bound(s+1,s+m+1,t[0])-s;
    build(1,1,m);
    update(1,1,m,x,0);
    for(int i=1;i<=m;++i)c[i]=-1e9;
    c[x]=0;
    for(int i=1;i<=n;++i){
        t[i]=t[i-1]+a[i];
        x=lower_bound(s+1,s+m+1,t[i])-s;
        dp[i]=max({query(1,1,m,1,x-1)+i,dp[i-1]-1,c[x]});
        c[x]=max(c[x],dp[i]);
        update(1,1,m,x,dp[i]-i);
        
    }
    printf("%d\n",dp[n]);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
    return 0;
}
/*
3
1
1
1
-1
1
0


*/