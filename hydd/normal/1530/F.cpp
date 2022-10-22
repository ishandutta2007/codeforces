#include<bits/stdc++.h>
using namespace std;
const int Mod=31607;
const int Inv=3973;//(10000)^(-1)
int n,p[22][22],f[2100000],g[22][2100000],op[2100000];
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++){
			scanf("%d",&p[i][j]);
			p[i][j]=1ll*p[i][j]*Inv%Mod;
		}
	int upperlim=(1<<n)-1;
	for (int i=0;i<n;i++){
		g[i][0]=1;
		for (int j=0;j<n;j++) g[i][1<<j]=p[i][j];
		for (int s=1;s<=upperlim;s++)
			g[i][s]=1ll*g[i][s^(s&-s)]*g[i][s&-s]%Mod;
	}
	op[0]=1;
	for (int s=1;s<=upperlim;s++)
		if (s&1) op[s]=Mod-op[s>>1];
		else op[s]=op[s>>1];
	//01
	int res=0;
	for (int t=0;t<4;t++){//
		for (int s=0;s<=upperlim;s++) f[s]=op[s];
		for (int i=0;i<n;i++)
			for (int s=0;s<=upperlim;s++){
				int sta=s|((t&1)<<i)|(((t>>1)&1)<<(n-i-1));
				f[s]=1ll*f[s]*(g[i][sta]-g[i][upperlim]+Mod)%Mod;
			}
		int sum=0;
		for (int s=0;s<=upperlim;s++) sum=(sum+f[s])%Mod;
		res=(res+1ll*op[t]*sum)%Mod;
	}
	printf("%d\n",(Mod+1-res)%Mod);
	return 0;
}