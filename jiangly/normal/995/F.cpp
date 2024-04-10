#include<bits/stdc++.h>
using namespace std;
const int N=3005,P=1e9+7;
int n,d;
int dp[N][N],fac[N],facinv[N],pre[N],suf[N];
vector<int>e[N];
int Pow(int a,int b){
    int ans=1;
    for(;b;a=1ll*a*a%P,b>>=1)
        if(b&1)
            ans=1ll*ans*a%P;
    return ans;
}
void dfs(int u){
    for(int i=1;i<=n;++i)
        dp[u][i]=1;
    for(int v:e[u]){
        dfs(v);
        for(int i=1;i<=n;++i)
            dp[u][i]=1ll*dp[u][i]*dp[v][i]%P;
    }
    for(int i=1;i<=n;++i)
        dp[u][i]=(dp[u][i]+dp[u][i-1])%P;
}
int main(){
    scanf("%d%d",&n,&d);
    fac[0]=1;
    for(int i=1;i<=n;++i)
        fac[i]=1ll*fac[i-1]*i%P;
    facinv[n]=Pow(fac[n],P-2);
    for(int i=n-1;i>=0;--i)
        facinv[i]=1ll*facinv[i+1]*(i+1)%P;
    for(int i=2;i<=n;++i){
        int f;
        scanf("%d",&f);
        e[f].push_back(i);
    }
    dfs(1);
    if(d<=n)
        printf("%d\n",dp[1][d]);
    else{
        pre[0]=1;
        for(int i=1;i<=n;++i)
            pre[i]=1ll*pre[i-1]*(d-i+1)%P;
        suf[n]=1;
        for(int i=n-1;i>=0;--i)
            suf[i]=1ll*suf[i+1]*(d-i-1)%P;
        int ans=0;
        for(int i=0;i<=n;++i)
            ans=(ans+((n-i&1)?-1ll:1ll)*dp[1][i]*pre[i]%P*suf[i]%P*facinv[i]%P*facinv[n-i])%P;
        ans=(ans+P)%P;
        printf("%d\n",ans);
    }
    return 0;
}