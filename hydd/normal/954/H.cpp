#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Mod=1e9+7;
const int inv2=(Mod+1)/2;
int n,m,a[5100];
ll f[2][11000],g[2][11000],Ans[11000];
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++) scanf("%d",&a[i]);
	f[1][0]=1; m=n+n-2;
	g[1][0]=1; for (int j=1;j<n;j++) g[1][j]=1ll*g[1][j-1]*a[j]%Mod;
	for (int j=1;j<=m;j++){
		Ans[j]=(Ans[j]+g[1][j])%Mod;
		Ans[j]=(Ans[j]+f[1][j])%Mod;
	}
	int now=1; ll mul=1;
	for (int i=2;i<=n;i++){
		now^=1; mul=mul*a[i-1]%Mod;
		for (int j=1;j<=m;j++){
			g[now][j]=0;
			f[now][j]=0;
		}
		g[now][0]=1;
		for (int j=1;i+j<=n;j++) g[now][j]=g[now][j-1]*a[i+j-1]%Mod;
		f[now][0]=1; f[now][1]=1;
		for (int j=2;j<=m;j++)
			f[now][j]=(f[now][j]+f[now^1][j-1]+g[now^1][j-1]-g[now][j-2]+Mod)%Mod;
		for (int j=1;j<=m;j++){
			Ans[j]=(Ans[j]+g[now][j]*mul)%Mod;
			Ans[j]=(Ans[j]+f[now][j]*mul)%Mod;
		}
	}
	for (int i=1;i<=m;i++) printf("%lld ",Ans[i]*inv2%Mod);
	return 0;
}