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
int cost[10][10],f[1000010][10],t[10];
bool can[10][10];
char ma[4][1000010];
int main(){
	scanf("%d %d",&n,&m);
	if(n>=4&&m>=4) return puts("-1"),0;
	if(n==1||m==1) return puts("0"),0;
	if(n<=m) for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
		ma[i][j]=getchar();
		while(ma[i][j]<'0'||ma[i][j]>'1') ma[i][j]=getchar();
	}
	else{
		swap(n,m);
		for(int j=1;j<=m;j++) for(int i=1;i<=n;i++){
			ma[i][j]=getchar();
			while(ma[i][j]<'0'||ma[i][j]>'1') ma[i][j]=getchar();
		}
	}
	for(int S=0;S<(1<<n);S++) for(int T=S;T<(1<<n);T++){
		for(int i=0;i<n;i++) if(((S>>i)&1)!=((T>>i)&1)) cost[S][T]++;
		cost[T][S]=cost[S][T];
		can[S][T]=true;
		for(int i=0;i<n;i++) t[i]=((S>>i)&1)+((T>>i)&1);
		for(int i=1;i<n;i++) if(((t[i]+t[i-1])&1)==0) can[S][T]=false;
		can[T][S]=can[S][T];
	}
	int tmp=0;
	for(int i=1;i<=n;i++) tmp|=(ma[i][1]-'0')<<(i-1);
	for(int S=0;S<(1<<n);S++) f[1][S]=cost[tmp][S];
	for(int j=2;j<=m;j++){
		int tmp=0;
		for(int i=1;i<=n;i++) tmp|=(ma[i][j]-'0')<<(i-1);
		for(int S=0;S<(1<<n);S++){
			f[j][S]=INT_MAX;
			for(int T=0;T<(1<<n);T++) if(can[S][T]) f[j][S]=min(f[j][S],f[j-1][T]+cost[S][tmp]);
//			printf("%d")
		}
	}
	int ans=INT_MAX;
	for(int S=0;S<(1<<n);S++) ans=min(ans,f[m][S]);
	printf("%d\n",ans);
}