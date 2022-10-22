#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int M=2e5+9;
int n;
int f[M],s[M],p[M],ans[M],fac[M],inv[M];
int c(int x,int y){
    if(x<y||y<0)return 0;
    return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int main() {
    fac[0]=fac[1]=inv[0]=inv[1]=1;
    for(int i=2;i<M;++i){
        fac[i]=1ll*fac[i-1]*i%mod;
        inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    }
    for(int i=2;i<M;++i)inv[i]=1ll*inv[i]*inv[i-1]%mod;
    cin>>n;
    for(int i=2;i<=n/2+1;++i){
        ans[i]=1ll*c(n/2,i-1)*fac[i-1]%mod*fac[n-i]%mod;
    }
    int s=0;
    for(int i=n/2+1;i>=2;--i){
        ans[i]=(ans[i]+mod-1ll*s*inv[i]%mod*fac[i-1]%mod)%mod;
        s=(s+ans[i])%mod;
    }
    ans[1]=ans[2];
    for(int i=1;i<=n;++i)printf("%d%c",ans[i]," \n"[i==n]);
    return 0;
}