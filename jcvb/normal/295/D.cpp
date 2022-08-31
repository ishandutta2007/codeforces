#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
#define mo 1000000007
int f[2005][2005]={0};
int g[2005][2005]={0};
int h[2005][2005]={0};
int k[2005][2005]={0};
int n,m;
int main()
{
	int ans=0;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int l=2;l<=m;l++){
			k[i][l]=f[i][l]=(1ll*(l+1)*f[i-1][l]-g[i-1][l]+1)%mo;
			h[i][l]=(1ll*(l+1)*f[i-1][l-1]-g[i-1][l-1]+1)%mo;
		}
		for (int l=2;l<=m;l++){
			g[i][l]=(g[i][l-1]+1ll*l*f[i][l])%mo;
			f[i][l]=(f[i][l-1]+f[i][l])%mo;
		}
	}
	for (int i=1;i<=n;i++)
		for (int l=2;l<=m;l++){
			ans=(ans+1ll*(m-l+1)*(1ll*k[i][l]*h[n-i+1][l]%mo))%mo;
		}
	printf("%d\n",(ans+mo)%mo);
	return 0;
}