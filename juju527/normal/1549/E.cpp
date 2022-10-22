#include<bits/stdc++.h>
using namespace std;
const int maxn=3e6+5,mod=1e9+7,iv3=333333336;
int fc[maxn],iv[maxn];
int f[maxn][3];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline int add(int x){return x>=mod?x-mod:x;}
inline int sub(int x){return x<0?x+mod:x;}
inline int power(int x,int b){
    int res=1;
    while(b){
        if(b&1)res=1ll*res*x%mod;
        x=1ll*x*x%mod;
        b>>=1;
    }
    return res;
}
int binom(int n,int m){return 1ll*fc[n]*iv[m]%mod*iv[n-m]%mod;}
int main(){
    int n,q;
    n=read();q=read();
    fc[0]=1;for(int i=1;i<=3*n;i++)fc[i]=1ll*fc[i-1]*i%mod;
    iv[3*n]=power(fc[3*n],mod-2);for(int i=3*n-1;i>=0;i--)iv[i]=1ll*iv[i+1]*(i+1)%mod;
    f[0][0]=f[0][1]=f[0][2]=n;
    for(int i=1;i<=3*n;i++){
        f[i][0]=1ll*iv3*sub(binom(3*n,i+1)-add(2ll*f[i-1][0]%mod+f[i-1][1]))%mod;
        f[i][1]=add(f[i][0]+f[i-1][0]);
        f[i][2]=add(f[i][1]+f[i-1][1]);
    }
    while(q--){
        int x;
        x=read();
        printf("%d\n",add(f[x][0]+binom(3*n,x)));
    }
    return 0;
}