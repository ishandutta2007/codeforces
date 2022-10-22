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
int n,k;
vector<int>g[M];
int inv[M],fac[M];
int c(int x,int y){
    if(x<y||y<0)return 0;
    return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
void pre(){
    fac[0]=fac[1]=inv[0]=inv[1]=1;
    for(int i=2;i<M;++i){
        fac[i]=1ll*fac[i-1]*i%mod;
        inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    }
    for(int i=2;i<M;++i)inv[i]=1ll*inv[i]*inv[i-1]%mod;
}
int siz[M],dp[M],f[M],ans;
void pfs(int u,int fa){
    siz[u]=1;
    for(auto v:g[u]){
        if(v!=fa){
            pfs(v,u);
            siz[u]+=siz[v];
            dp[u]=(dp[u]+dp[v])%mod;
        }
    }
    for(auto v:g[u]){
        if(v!=fa)
            dp[u]=(dp[u]+1ll*c(siz[v],k)*(siz[u]-siz[v])%mod)%mod;
    }
}
void pfs2(int u,int fa){
    int sum=(f[u]+1ll*c(n-siz[u],k)*siz[u]%mod)%mod;
    int rex=c(n-siz[u],k);
    for(auto v:g[u]){
        if(v!=fa){
            sum=(sum+dp[v])%mod;
            sum=(sum+1ll*c(siz[v],k)*(n-siz[v])%mod)%mod;
            rex=(rex+c(siz[v],k))%mod;
        }
    }
    for(auto v:g[u]){
        if(v!=fa){
            f[v]=((sum+mod-dp[v])%mod+mod-(1ll*c(siz[v],k)*(n-siz[v])%mod+1ll*(rex+mod-c(siz[v],k))%mod*siz[v]%mod)%mod)%mod;
            pfs2(v,u);
        }
    }
}
void dfs(int u,int fa){
    for(auto v:g[u]){
        if(v!=fa)dfs(v,u);
    }
    int sum=1ll*c(n,k)*n%mod;
    for(auto v:g[u]){
        if(v!=fa){
            sum=(sum+mod-1ll*c(siz[v],k)*(n-siz[v])%mod)%mod;
            sum=(sum+mod-dp[v])%mod;
        }
        else {
            sum=(sum+mod-1ll*c(n-siz[u],k)*siz[u]%mod)%mod;
            sum=(sum+mod-f[u])%mod;
        }
    }
    ans=(ans+sum)%mod;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].eb(v);
        g[v].eb(u);
    }
    pre();
    pfs(1,0);
    pfs2(1,0);
    dfs(1,0);
    printf("%d\n",ans);
    return 0;
}
/*
5 2
1 2
1 3
1 4
4 5

*/