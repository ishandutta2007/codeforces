// Hydro submission #62c7c796c3a9fda5622c4817@1657259926335
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=200001,P=1e9+7;
int n,k,dp[N],f[N],g[N],siz[N],fac[N],inv[N];
vector<int> G[N];
int ans;
void Inc(int&x,int y){
    if((x+=y)>=P) x-=P;
}
void Dec(int&x,int y){
    if((x-=y)<0) x+=P;
}
int bp(int x,int y){
    int r=1;
    for(;y;y=y>>1,x=1ll*x*x%P) if(y&1) r=1ll*r*x%P;
    return r;
}
int C(int x,int y){
    if(x<y) return 0;
    return 1ll*fac[x]*inv[y]%P*inv[x-y]%P;
}
void dfs1(int u,int fa){
    siz[u]=1;
    for(auto v:G[u]) if(v^fa){
        dfs1(v,u);
        siz[u]+=siz[v];
        Inc(g[u],g[v]),Dec(f[u],C(siz[v],k));
    }
    if(siz[u]>=k) Inc(f[u],C(siz[u],k));
    Inc(g[u],1ll*f[u]*siz[u]%P);
}
void dfs2(int u,int fa){
    int cnt=C(n,k);
    for(auto v:G[u]) if(v^fa) Inc(ans,g[v]),Dec(cnt,C(siz[v],k));
    Inc(ans,dp[u]),Dec(cnt,C(n-siz[u],k));
    Inc(ans,1ll*n*cnt%P);
    int sum=0;
    for(auto v:G[u]) if(v^fa) Inc(sum,C(siz[v],k));
    Inc(sum,C(n-siz[u],k));
    for(auto v:G[u]) if(v^fa){
        Inc(dp[v],g[u]),Dec(dp[v],g[v]),Dec(dp[v],1ll*f[u]*siz[u]%P);
        Inc(dp[v],dp[u]);
        Dec(sum,C(siz[v],k));
        int tmp=(P-sum)%P;
        Inc(tmp,C(n-siz[v],k));
        Inc(dp[v],1ll*tmp*(n-siz[v])%P);
        Inc(sum,C(siz[v],k));
        dfs2(v,u);
    }
}
int main(){
    scanf("%d%d",&n,&k),fac[0]=inv[0]=1;
    rep(i,1,n) fac[i]=1ll*fac[i-1]*i%P,inv[i]=bp(fac[i],P-2);
    rep(i,2,n){
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].push_back(y),G[y].push_back(x);
    }
    dfs1(1,0);
    dfs2(1,0);
    printf("%d",ans);
}