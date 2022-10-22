#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=998244353;
int kpow(int x,ll y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
int exgcd(int a,int b,int &x,int &y){
    int t=b?exgcd(b,a%b,y,x):a;
    if(!b)x=1,y=0;
    else y-=a/b*x;
    return t;
}
const int M=259;
int n,k;
int dp[M][M],s[M][M];
int fac[M],inv[M];
int c(int x,int y){
    if(x<y||y<0)return 0;
    return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int main(){
    scanf("%d%d",&n,&k);
    fac[0]=fac[1]=inv[0]=inv[1]=1;
    for(int i=2;i<=n;++i){
        fac[i]=1ll*fac[i-1]*i%mod;
        inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    }
    for(int i=2;i<=n;++i)inv[i]=1ll*inv[i]*inv[i-1]%mod;
    dp[0][0]=1;
    n--;
    for(int i=1;i<=k;++i){
        for(int j=0;j<=n;++j){
            for(int l=0;l<=j;++l){
                dp[i][j]=(dp[i][j]+1ll*c(n-l,j-l)*dp[i-1][l]%mod*kpow(k-i+1,(1ll*(j-l)*(j-l-1)/2+1ll*(j-l)*l))%mod)%mod;
            }
        }
    }
    printf("%d\n",dp[k][n]);
    return 0;
}