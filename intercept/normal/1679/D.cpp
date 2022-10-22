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
const int M=2e5+9;
int n,m;
ll k;
vector<int>g[M];
int a[M],d[M],in[M];
bool dfs(int u,int x){
    in[u]=1;
    d[u]=1;
    for(auto v:g[u]){
        if(a[v]<=x){
            if(in[v])return 1;
            if(!d[v]){
                if(dfs(v,x))return 1;
            }
            d[u]=max(d[u],d[v]+1);
        }
    }
    in[u]=0;
    return d[u]>=k;
}
bool check(int x){
    for(int i=1;i<=n;++i)d[i]=in[i]=0;
    for(int i=1;i<=n;++i){
        if(d[i]==0&&a[i]<=x){
            if(dfs(i,x))return 1;
        }
    }
    return 0;
}
int main(){
    scanf("%d%d%lld",&n,&m,&k);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    for(int i=1;i<=m;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].eb(v);
    }
    int l=1,r=1e9+1;
    while(l<r){
        int mid=l+r>>1;
        if(!check(mid))l=mid+1;
        else r=mid;
    }
    if(l>1e9)puts("-1");
    else printf("%d\n",l);
    return 0;
}
/*
5 : 3
*/