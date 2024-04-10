#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,G=3,Gi=332748118;
const int maxn=262144+5;
int fc[maxn],iv[maxn];
int rev[4*maxn];
int f[4*maxn];
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
inline int sub(int x){
    if(x<0)x+=mod;
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
int pw[2][20][4*maxn];
void pre(int lim){
    int c=0;
    for(int i=1;i<lim;i<<=1,c++){
        pw[0][c][0]=pw[1][c][0]=1;
        pw[0][c][1]=power(G,(mod-1)/(i<<1));
        pw[1][c][1]=power(Gi,(mod-1)/(i<<1));
        for(int j=2;j<i;j++){
            pw[0][c][j]=1ll*pw[0][c][j-1]*pw[0][c][1]%mod;
            pw[1][c][j]=1ll*pw[1][c][j-1]*pw[1][c][1]%mod;
        }
    }
    return ;
}
void NTT(int *f,int lim,int opt){
    for(int i=0;i<lim;i++)if(i<rev[i])swap(f[i],f[rev[i]]);
    int op=(opt==-1),c=0;
    for(int mid=1;mid<lim;mid<<=1,c++){
        for(int j=0;j<lim;j+=(mid<<1)){
            for(int k=0;k<mid;k++){
                int u=f[j+k],v=1ll*pw[op][c][k]*f[j+k+mid]%mod;
                f[j+k]=add(u+v);
                f[j+k+mid]=sub(u-v);
            }
        }
    }
    if(opt==1)return ;
    int inv=power(lim,mod-2);
    for(int i=0;i<lim;i++)f[i]=1ll*f[i]*inv%mod;
    return ;
}
int A[4*maxn],B[4*maxn];
void get_s(int *f,int n){
    if(n==0){f[0]=1;return ;}
    if(n==1){f[1]=1;return ;}
    get_s(f,n/2);
    int m=n/2,pw=power(m,m+1),ivm=power(m,mod-2);
    for(int i=0;i<=m;i++)B[i]=f[i];
    for(int i=0;i<=m+1;i++){A[i]=1ll*pw*iv[m+1-i]%mod;pw=1ll*pw*ivm%mod;}
    for(int i=0;i<=m;i++)f[i]=1ll*f[i]*fc[i]%mod;
    int lim=1,k=0;
    while(lim<=2*m+1)lim<<=1,k++;
    for(int i=0;i<lim;i++)rev[i]=rev[i>>1]>>1|((i&1)<<(k-1));
    NTT(f,lim,1);NTT(A,lim,1);
    for(int i=0;i<lim;i++)f[i]=1ll*f[i]*A[i]%mod;
    NTT(f,lim,-1);
    for(int i=0;i<=m;i++)f[i]=1ll*iv[i]*f[i+m+1]%mod;
    for(int i=m+1;i<lim;i++)f[i]=0;
    for(int i=0;i<lim;i++)A[i]=0;
    NTT(f,lim,1);NTT(B,lim,1);
    for(int i=0;i<lim;i++)f[i]=1ll*f[i]*B[i]%mod;
    NTT(f,lim,-1);
    for(int i=n+1;i<lim;i++)f[i]=0;
    for(int i=0;i<lim;i++)B[i]=0;
    if(n&1){
        for(int i=n;i>=1;i--)f[i]=add(1ll*f[i-1]+1ll*(n-1)*f[i]%mod);
        f[0]=1ll*(n-1)*f[0]%mod;
    }
    return ;
}
int main(){
    int n,a,b;
    n=read();a=read();b=read();
    fc[0]=1;
    for(int i=1;i<=n;i++)fc[i]=1ll*fc[i-1]*i%mod;
    iv[n]=power(fc[n],mod-2);
    for(int i=n-1;i>=0;i--)iv[i]=1ll*iv[i+1]*(i+1)%mod;
    pre(4*n);
    get_s(f,n-1);
    printf("%d\n",1ll*f[a+b-2]*fc[a+b-2]%mod*iv[a-1]%mod*iv[b-1]%mod);
    return 0;
}