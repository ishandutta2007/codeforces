#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int mo=1e9+7,a[160][160][160],b[160][160][160],f[160][160],w[160][160],n,m,c[160][160],g[160][160],d[160][160][160];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			int now=0;
			for (int k=j;k;k--){
				now=(now+a[i-1][k][j])%mo; a[i][k][j]=((a[i][k][j]+now)%mo+a[i][k][j-1])%mo;
			}
		}
		for (int j=1;j<=m;j++)
			for (int k=j;k<=m;k++)
				a[i][j][k]=(a[i][j][k]+1)%mo;
		for (int j=1;j<=m;j++){
			int now=0;
			for (int k=1;k<=j;k++){
				now=(now+d[i-1][k][j])%mo; d[i][k][j]=(d[i][k][j]+now)%mo;
			}
		}
		for (int j=1;j<=m;j++){
			int now=0;
			for (int k=2;k<=j;k++){
				now=(now+a[i-1][k-1][j])%mo; d[i][k][j]=(d[i][k][j]+now)%mo;
			}
		}
		for (int j=1;j<=m;j++){
			int now=0;
			for (int k=2;k<j;k++){
				now=(now+a[i-1][k-1][j-1])%mo; b[i][k][j]=((b[i][k][j]+now)%mo+b[i][k][j-1])%mo;
			}
		}
		memset(c,0x00,sizeof c);
		for (int j=1;j<=m;j++){
			int now=0;
			for (int k=1;k<=j;k++){
				now=(now+b[i-1][k][j])%mo; c[k][j]=(now+c[k][j-1])%mo; 
				b[i][k][j]=((b[i][k][j]+now)%mo+c[k][j-1])%mo;
			}
		}
		memset(c,0x00,sizeof c);
		for (int j=1;j<=m;j++){
			int now=0;
			for (int k=1;k<j;k++){
				now=(now+d[i-1][k][j-1])%mo; c[k][j]=(now+c[k][j-1])%mo;
				b[i][k][j]=(b[i][k][j]+c[k][j])%mo;
			}
		}
	}
	for (int i=1;i<=m;i++) f[1][i]=1;
	for (int i=2;i<=n;i++)
		for (int j=1;j<=m;j++) 
			for (int k=1;k<=j;k++) f[i][j]=(f[i][j]+1ll*f[i-1][k]*(j-k+1))%mo;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			for (int k=1;k<j;k++) w[i][j]=(w[i][j]+1ll*f[i][k]*(j-k+1))%mo;
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) w[i][j]=(w[i][j]+w[i-1][j])%mo;
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) f[i][j]=(f[i][j]+f[i-1][j])%mo;
	memset(g,0x00,sizeof g);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			for (int k=1;k<j;k++) g[i][j]=(g[i][j]+1ll*f[i][k]*(j-k))%mo;
	int ans=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			for (int k=j;k<=m;k++)
				if (i==n) ans=(ans+1ll*b[i][j][k]*(w[n-i][k-j+1]+1))%mo; else ans=(ans+1ll*b[i][j][k]*(g[n-i][k-j+1]+1))%mo;
	ans=ans*2%mo;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			ans=(ans+1ll*f[i][j]*(w[n-i][j]+1)%mo*(m-j+1))%mo;
	cout<<ans<<endl;
}