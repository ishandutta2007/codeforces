#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstdio>
#define mo 1000000007
using namespace std;
int n,k;
void upd(int &x,int v){
	x+=v;if(x>=mo)x-=mo;
}
int f[1005][1005][2][2];
int fact[1005];
int c[1005][1005];
int g[1005];
int h[1005];
int main()
{
	scanf("%d%d",&n,&k);
	f[0][0][1][0]=1;
	fact[0]=1;for (int i=1;i<=n;i++)fact[i]=1ll*fact[i-1]*i%mo;
	c[0][0]=1;
	for (int i=1;i<=n;i++){
		c[i][0]=1;
		for (int j=1;j<=n;j++){
			c[i][j]=c[i-1][j]+c[i-1][j-1];
			if(c[i][j]>=mo)c[i][j]-=mo;
		}
	}
	int v;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			for (int p=0;p<2;p++)
				for (int q=0;q<2;q++)if(v=f[i][j][p][q]){
					upd(f[i+1][j][q][0],v);
					if(!p)upd(f[i+1][j+1][q][0],v);
					if(i+1!=n)upd(f[i+1][j+1][q][1],v);
				}
	for (int i=0;i<=n;i++){
		g[i]=(0ll+f[n][i][0][0]+f[n][i][0][1]+f[n][i][1][0]+f[n][i][1][1])%mo;
		g[i]=1ll*g[i]*fact[n-i]%mo;
	}
	h[n]=g[n];
	for (int i=n-1;i>=k;i--){
		h[i]=g[i];
		for (int t=i+1;t<=n;t++){
			upd(h[i],mo-1ll*h[t]*c[t][i]%mo);
		}
	}
	printf("%d\n",h[k]%mo);
	return 0;
}