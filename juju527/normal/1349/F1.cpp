#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5005,mod=998244353;
int fac[maxn],inv[maxn];
int o[maxn][maxn];
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
int power(int x,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		b>>=1;
	}
	return ans;
}
int C(int n,int m){
	return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main(){
	int n;
	n=read();
	for(int i=1;i<=n;i++){
		o[i][0]=1;o[i][i-1]=1;
		for(int k=1;k<i-1;k++)
			o[i][k]=(1ll*(k+1)*o[i-1][k]%mod+1ll*(i-k)*o[i-1][k-1]%mod)%mod;
	}
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=power(fac[n],mod-2);
	for(int i=n-1;i>=0;i--)inv[i]=1ll*inv[i+1]*(i+1)%mod;
	for(int k=1;k<=n;k++){
		int ans=0;
		for(int i=k;i<=n;i++)
			ans=(ans+1ll*C(n,i)*o[i][k-1]%mod*fac[n-i]%mod)%mod;
		printf("%d ",ans);
	}
	return 0;
}