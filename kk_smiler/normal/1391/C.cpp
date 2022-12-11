#include <bits/stdc++.h>
const int mod=1e9+7;
#define Rint register int
#define C(n,m) (n<m?0:1ll*fac[n]*invfac[(n)-(m)]%mod*invfac[m]%mod)
using namespace std;
int T,n,m,p,k;
inline int read(){
	register int tmp=0,fl=0;
	static char ch;
	while(ch=getchar(),ch<'0'||ch>'9') fl|=(ch=='-');
	tmp=ch^48;
	while(ch=getchar(),ch>='0'&&ch<='9') tmp=tmp*10+(ch^48);
	return fl?-tmp:tmp;
}
int ksm(int a,int k,int mod){
	int ans=1;
	for(;k;k>>=1,a=1ll*a*a%mod) if(k&1) ans=1ll*ans*a%mod;
	return ans;
}
int fac[1000010],invfac[1000010],ans=0;
int main(){
	scanf("%d",&n);
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod; 
	invfac[n]=ksm(fac[n],mod-2,mod);
	for(int i=n-1;i>=0;i--) invfac[i]=1ll*invfac[i+1]*(i+1)%mod;
	for(int i=1;i<=n;i++) ans=(ans+C(n-1,i-1))%mod;
	printf("%d\n",(fac[n]-ans+mod)%mod);
}