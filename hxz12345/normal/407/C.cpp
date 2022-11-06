#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
  long long x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
long long pow(long long x,long long y,long long p)
{
    long long ans=1;
    for (;y;y>>=1,x=x*x % p)
        if (y&1) ans=ans*x % p;
    return ans;
}
int L,R,K,e[1010100],inv[200],f[110][101010],n,Q,MOD,i,j;
long long x;
/*long long C(long long n,long long m)
{
    if (m>n) return 0;
    if ((n<0)||(m<0)) return 0;
    return fac[n]*ifac[m] % MOD*ifac[n-m] % MOD;
}*/
int main()
{
    n=read();Q=read();MOD=1e9+7;
    inv[1]=1;
    for (i=1;i<=n;i++) e[i]=read(); 
    for (i=2;i<=100;i++) inv[i]=(MOD-MOD/i)*(long long)inv[MOD % i] % MOD;
    for (;Q;Q--)
        {
            L=read();R=read();K=read();
            f[K][L]++;f[K][R+1]--;x=R-L+1;
            //(K-i+1)^(K-i+R-L)
            for (i=K-1;i>=0;i--)
                 {
                    f[i][R+1]=(f[i][R+1]+MOD-x);
                    if (f[i][R+1]>=MOD) f[i][R+1]=f[i][R+1]-MOD;
                    x=x*(long long)inv[K-i+1] % MOD*(R-L+K-i+1) % MOD;
                 }
        }
    for (i=100;i>=0;i--)
        {
        for (j=1;j<=n;j++)
                {
                f[i][j]=f[i][j]+f[i][j-1];
                if (f[i][j]>=MOD) f[i][j]-=MOD;
                f[i][j]=f[i][j]+f[i+1][j];
                if (f[i][j]>=MOD) f[i][j]-=MOD;
               }
    /*  for (j=1;j<=n;j++)
             {
                f[i][j]=((f[i][j]+e[j])) % MOD;
                e[j]=(e[j-1]+f[i][j]) % MOD;
             }*/
        }
    for (i=1;i<=n;i++) printf("%d ",(f[0][i]+e[i]) % MOD);
    return 0;
}