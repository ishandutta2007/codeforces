#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int mo=1e9+7,f[2001][2001],n,m,w[2001][2001];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) f[1][i]=1;
	for (int i=1;i<=m;i++) f[0][i]=0;
	for (int i=2;i<=n;i++){
		int k1=0,k2=0;
		for (int j=1;j<=m;j++){
			k1=(k1+f[i-1][j])%mo;
			k2=(1ll*f[i-1][j]*(j-1)+k2)%mo;
			f[i][j]=((1ll*j*k1-k2)%mo+mo)%mo;
		}
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) f[i][j]=(f[i][j]+f[i-1][j])%mo;
	for (int i=1;i<=n;i++){
		int k1=0,k2=0;
		for (int j=2;j<=m;j++){
			k1=(k1+f[i][j-1])%mo;
			k2=(1ll*f[i][j-1]*(j-2)+k2)%mo;
			w[i][j]=((1ll*j*k1-k2)%mo+mo)%mo;
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<m;j++){
			//cout<<i<<" "<<j<<" "<<1ll*f[i][j]*(w[n-i][j]+1)%mo*(m-j)%mo<<endl;
			ans=(ans+1ll*f[i][j]*(w[n-i][j]+1)%mo*(m-j)%mo)%mo;
		}
	cout<<ans<<endl;
	return 0;
}