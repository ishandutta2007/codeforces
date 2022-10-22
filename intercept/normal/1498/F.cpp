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
const int M=1e5+9;
int n,k;
int dp[M][23][2],p[M][23][2],ans[M],a[M];
vector<int>g[M];
void merge(int a[23][2],int b[23][2]){
    for(int o=0;o<2;++o){
        for(int i=0;i<k-1;++i){
            a[i+1][o]^=b[i][o];
        }
        a[0][o^1]^=b[k-1][o];
    }
}
void pfs(int u,int fa){
    if(fa){
        merge(p[fa],dp[u]);
        merge(p[u],p[fa]);
        merge(p[fa],dp[u]);
    }
    p[u][0][0]^=a[u];
    for(auto v:g[u]){
        if(v!=fa){
            merge(p[u],dp[v]);
        }
    }
    for(int i=0;i<k;++i)ans[u]^=p[u][i][1];
    for(auto v:g[u]){
        if(v!=fa){
            pfs(v,u);
        }
    }
}
void dfs(int u,int fa){
    dp[u][0][0]=a[u];
    for(auto v:g[u]){
        if(v!=fa){
            dfs(v,u);
            merge(dp[u],dp[v]);
        }
    }
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].eb(v);
        g[v].eb(u);
    }
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    dfs(1,0);
    pfs(1,0);
    for(int i=1;i<=n;++i){
        printf("%d%c",ans[i]>0," \n"[i==n]);
    }
    return 0;
}
/*
3 1
1 2
2 3
0 1 0


*/