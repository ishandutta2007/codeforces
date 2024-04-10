#include<bits/stdc++.h>
using namespace std;
const int maxn=1005,mod=1e9+7;
int f[maxn][maxn][2][2];
int fac[maxn],inv[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline int add(int x){
    if(x>=mod)x-=mod;
    return x;
}
int power(int x,int b){
    int ans=1;
    while(b){
        if(b&1)ans=1ll*ans*x%mod;
        x=1ll*x*x%mod;
        b>>=1;
    }
    return ans;
}
int C(int n,int m){
    return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main(){
    int n,m;
    n=read();m=read();
    f[0][0][0][0]=1;
    f[1][0][0][0]=1;
    for(int i=2;i<=n;i++){
        f[i][0][0][0]=1;
        for(int j=1;j<=i;j++){
            f[i][j][0][0]=add(add(f[i-1][j][0][0]+f[i-1][j][0][1])+add(f[i-1][j][1][0]+f[i-1][j][1][1]));
            f[i][j][0][1]=add(f[i-1][j-1][0][0]+f[i-1][j-1][0][1]);
            f[i][j][1][0]=add(f[i-1][j-1][0][0]+f[i-1][j-1][1][0]);
            if(j>1)f[i][j][1][1]=f[i-1][j-2][0][0];
        }
    }
    fac[0]=1;
    for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
    inv[n]=power(fac[n],mod-2);
    for(int i=n-1;i>=0;i--)inv[i]=1ll*inv[i+1]*(i+1)%mod;
    int op=1,res=0;
    for(int i=m;i<=n;i++){
        int val=add(add(f[n][i][0][0]+f[n][i][0][1])+add(f[n][i][1][0]+f[n][i][1][1]));
        res=add(res+1ll*op*C(i,m)%mod*val%mod*fac[n-i]%mod);
        op=mod-op;
    }
    printf("%d\n",res);
    return 0;
}