// Hydro submission #61e9409e60e0722665d4b7b4@1642676383285
#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5,mod=998244353,L=720720;
int n,a[N],x,y,k,M,f[20][L+5],ans;
int main(){
    scanf("%d%d%d%d%d%d",&n,&a[0],&x,&y,&k,&M);
    for(int i=1;i<n;i++)a[i]=(1ll*a[i-1]*x+y)%M;
    int now=1;
    for(int i=1;i<k;i++)now=1ll*now*n%mod;
    for(int i=0;i<n;i++){
        ans=(ans+1ll*a[i]/L*L*k%mod*now%mod)%mod;
        f[0][a[i]%L]++;
    }
    for(int i=1;i<k;i++){
        for(int j=0;j<L;j++){
            f[i][j]=(f[i][j]+1ll*(n-1)*f[i-1][j]%mod)%mod;
            f[i][j-j%i]=(f[i][j-j%i]+f[i-1][j])%mod;
        }
    }
    int P=1;
    for(int i=k-1;i>=0;i--,P=1ll*P*n%mod)
        for(int j=0;j<L;j++)
            ans=(ans+1ll*j*f[i][j]%mod*P%mod)%mod;
    printf("%d",ans);
}