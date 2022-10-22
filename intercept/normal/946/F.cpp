#include<bits/stdc++.h>
#define pii pair<int,int>
#define eb emplace_back
#define fi first
#define se second
using namespace std;
const int mod=1e9+7;
int kpow(int x,int y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
const int M=1e5+9;
int n,m;
char s[109];
int dp[3][109][109][109],f[109];
void add(int &x,int y){
    x+=y;
    if(x>=mod)x-=mod;
}
int main(){
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    f[1]=f[0]=1;
    for(int i=1;i<=n;++i){
        dp[s[i]&1][i][i][0]=dp[s[i]&1][i][i][1]=dp[s[i]&1][i][i][2]=dp[s[i]&1][i][i][3]=1;
    }
    for(int i=2;i<=m;++i){
        f[i]=(f[i-1]+f[i-2])%(mod-1);
        memset(dp[i%3],0,sizeof(dp[i%3]));
        int i1=(i-1)%3,i2=(i-2)%3;
        for(int l=1;l<=n;++l){
            for(int r=l;r<=n;++r){
                add(dp[i%3][l][r][0],dp[i1][l][r][0]);
                add(dp[i%3][l][r][0],dp[i2][l][r][0]);
                add(dp[i%3][l][r][1],dp[i1][l][r][1]);
                add(dp[i%3][l][r][1],1ll*dp[i2][l][r][1]*kpow(2,f[i-1])%mod);
                add(dp[i%3][l][r][2],1ll*dp[i1][l][r][2]*kpow(2,f[i-2])%mod);
                add(dp[i%3][l][r][2],dp[i2][l][r][2]);
                add(dp[i%3][l][r][3],1ll*dp[i1][l][r][3]*kpow(2,f[i-2])%mod);
                add(dp[i%3][l][r][3],1ll*dp[i2][l][r][3]*kpow(2,f[i-1])%mod);
                for(int k=l;k<r;++k){
                    add(dp[i%3][l][r][0],1ll*dp[i1][l][k][0]*dp[i2][k+1][r][0]%mod);
                    add(dp[i%3][l][r][1],1ll*dp[i1][l][k][1]*dp[i2][k+1][r][0]%mod);
                    add(dp[i%3][l][r][2],1ll*dp[i1][l][k][0]*dp[i2][k+1][r][2]%mod);
                    add(dp[i%3][l][r][3],1ll*dp[i1][l][k][1]*dp[i2][k+1][r][2]%mod);
                }
            }
        }
    }
    printf("%d\n",dp[m%3][1][n][3]);
    return 0;
}
/*
2 2
11

*/