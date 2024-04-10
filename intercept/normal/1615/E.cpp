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
const int M=2e5+9;
int n,k,m;
int a[M],l[M];
vector<int>g[M];
void dfs(int u,int fa){
    int p=0;
    for(auto v:g[u]){
        if(v!=fa){
            dfs(v,u);
            if(l[p]<l[v])p=v;
        }
    }
    l[u]=l[p]+1;
    for(auto v:g[u]){
        if(v!=fa&&v!=p)a[++m]=l[v];
    }
    if(!fa)a[++m]=l[u];
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].eb(v);
        g[v].eb(u);
    }
    dfs(1,0);
    sort(a+1,a+m+1,[&](const int&l,const int&r){return l>r;});
    ll ans=-(1ll<<60);
    for(int i=0,s=n;i<=k;++i){
        int r=i,b=s;
        b=min(b,n/2);
        r+=min(max(n/2-i,0),k-i);
        int w=n-r-b;
        ans=max(ans,1ll*w*(r-b));
        s-=a[i+1];
    }
    printf("%lld\n",ans);
    return 0;
}
/*
4 4
1 2
1 3
1 4


*/