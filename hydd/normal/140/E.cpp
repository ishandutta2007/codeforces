#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,Mod,l[1100000];
ll A[1100000],fac[1100000],f[5100][5100],g[5100];
int main(){
	scanf("%d%d%d",&n,&m,&Mod);
	for (int i=1;i<=n;i++) scanf("%d",&l[i]);
	A[0]=1; for (int i=1;i<=m;i++) A[i]=A[i-1]*(m-i+1)%Mod;
	fac[0]=1; for (int i=1;i<=m;i++) fac[i]=fac[i-1]*i%Mod;
	f[0][0]=1;
	for (int i=1;i<=5000;i++)
		for (int j=1;j<=i;j++)
			f[i][j]=(f[i-1][j-1]+f[i-1][j]*(j-1))%Mod;
	ll sum=1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=min(l[i],m);j++)
			g[j]=(sum*A[j]%Mod-g[j]*fac[j]%Mod+Mod)*f[l[i]][j]%Mod;
		sum=0;
		for (int j=1;j<=min(l[i],m);j++){
			sum=(sum+g[j])%Mod;
			if (j>l[i+1]) g[j]=0;
		}
	}
	printf("%lld\n",sum);
	return 0;
}