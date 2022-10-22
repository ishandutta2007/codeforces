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
const int M=5009;
int n,k;
int siz[M];
int dp[M][M],p[M];
vector<int>g[M];
void dfs(int u,int fa){
    dp[u][0]=1;
    siz[u]=1;
    for(auto v:g[u]){
        if(v!=fa){
            dfs(v,u);
            for(int i=0;i<=siz[u]+siz[v];++i)p[i]=0;
            for(int i=0;i<=siz[u];++i){
                for(int j=0;j<=siz[v];++j){
                    
                    if(i+j+1<=k)
                        p[max(i,j+1)]=(p[max(i,j+1)]+1ll*dp[u][i]*dp[v][j]%mod)%mod;
                    p[i]=(p[i]+1ll*dp[u][i]*dp[v][j]%mod)%mod;
                }
            }
            
            siz[u]+=siz[v];
            
            for(int i=0;i<=siz[u];++i)dp[u][i]=p[i];
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
    dfs(1,0);
    int ans=0;
    for(int i=0;i<=k;++i)ans=(ans+dp[1][i])%mod;
    printf("%d\n",ans);
    return 0;
}
/*
5
7 4 1 6 2
*/