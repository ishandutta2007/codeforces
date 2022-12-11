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
char a[110];
int main(){
	scanf("%d",&T);
	while(T--){
		int ans=0;
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%s",a+1);
			if(a[m]!='D'&&a[m]!='C') ans++;
			if(i==n) for(int j=1;j<=m;j++) if(a[j]!='R'&&a[j]!='C') ans++;
		}
		printf("%d\n",ans);
		ans=0;
	}
}