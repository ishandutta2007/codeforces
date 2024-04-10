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
int n,num;
ll t;
int x[M],b[M],c[M],l[M];
vector<int>g[M];
ll dp[M];
struct Bit{
    ll bit[M];
    void add(int x,ll v){
        for(;x<=num;x+=x&-x)bit[x]+=v;
    }
    ll ask(int x,ll rex=0){
        for(;x;x-=x&-x)rex+=bit[x];
        return rex;
    }
    int kth(ll k,int y=0){//find k_th element
        for(int i=1<<20;i;i>>=1)
            if(y+i<=num&&bit[y+i]<=k)k-=bit[y+=i];
        return y;
    }
}va,na;
void dfs(int u,ll s){
    va.add(b[u],1ll*x[u]*c[b[u]]);
    na.add(b[u],x[u]);
    int y=va.kth(t-s);
    dp[u]=na.ask(y);
    if(y<num)dp[u]+=min(na.ask(y+1)-na.ask(y),max((t-s-va.ask(y)),0ll)/c[y+1]);
    ll fi=0,se=0;
    for(auto v:g[u]){
        dfs(v,s+2ll*l[v]);
        if(dp[v]>fi)se=fi,fi=dp[v];
        else if(dp[v]>se)se=dp[v];
    }
    if(u>1)dp[u]=max(dp[u],se);
    else dp[u]=max(dp[u],fi);
    na.add(b[u],-x[u]);
    va.add(b[u],-1ll*x[u]*c[b[u]]);
}
int main(){
    scanf("%d%lld",&n,&t);
    for(int i=1;i<=n;++i)scanf("%d",&x[i]);
    for(int i=1;i<=n;++i)scanf("%d",&b[i]),c[i]=b[i];
    sort(c+1,c+n+1);
    num=unique(c+1,c+n+1)-c-1;
    for(int i=1;i<=n;++i)b[i]=lower_bound(c+1,c+num+1,b[i])-c;
    for(int i=2;i<=n;++i){
        int pa;
        scanf("%d%d",&pa,&l[i]);
        g[pa].eb(i);
    }
    dfs(1,0);
    printf("%lld\n",dp[1]);
    return 0;
}
/*
5 25
1 5 1 7 7
1 3 2 2 2
1 1
1 1
2 0
2 0

*/