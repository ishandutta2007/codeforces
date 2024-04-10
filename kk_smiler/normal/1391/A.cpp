#include <bits/stdc++.h>
#define Rint register int
#define C(n,m) (n<m?0:1ll*fac[n]*invfac[n-m]%mod*invfac[m]%mod)
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
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) printf("%d ",i);
		puts("");
	}
}