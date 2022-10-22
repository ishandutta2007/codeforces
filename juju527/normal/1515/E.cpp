#include<bits/stdc++.h>
using namespace std;
const int maxn=405;
int n,mod;
int f[maxn][maxn];
int pw2[maxn],fc[maxn],iv[maxn];
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
inline int power(int x,int b){
    int res=1;
    while(b){
        if(b&1)res=1ll*res*x%mod;
        x=1ll*x*x%mod;
        b>>=1;
    }
    return res;
}
int C(int n,int m){
    return 1ll*fc[n]*iv[m]%mod*iv[n-m]%mod;
}
int main(){
    n=read();mod=read();
    fc[0]=1;
    for(int i=1;i<=n;i++)fc[i]=1ll*fc[i-1]*i%mod;
    iv[n]=power(fc[n],mod-2);
    for(int i=n-1;i>=0;i--)iv[i]=1ll*iv[i+1]*(i+1)%mod;
    pw2[0]=1;
    for(int i=1;i<=n;i++)pw2[i]=add(pw2[i-1]+pw2[i-1]);
    f[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if(!f[i][j])continue;
            for(int k=1;k<=n-i;k++)
                f[i+k+1][j+k]=add(f[i+k+1][j+k]+1ll*f[i][j]*C(j+k,j)%mod*pw2[k-1]%mod);
        }
    }
    int res=0;
    for(int i=1;i<=n;i++)res=add(res+f[n+1][i]);
    printf("%d\n",res);
    return 0;
}