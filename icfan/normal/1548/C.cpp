#include <cstdio>
int quick_power(int a,int b,int Mod){
	int ans=1;
	while(b){
		if(b&1){
			ans=1ll*ans*a%Mod;
		}
		b>>=1;
		a=1ll*a*a%Mod;
	}
	return ans;
}
const int Maxn=1000000;
const int Maxq=200000;
const int Mod=1000000007;
int find_inv(int x){
	return quick_power(x,Mod-2,Mod);
}
int n,q;
int f[Maxn*4+5],g[Maxn*4+5];
int fac[Maxn*4+5],inv_f[Maxn*4+5];
void init(){
	fac[0]=1;
	for(int i=1;i<=Maxn*4;i++){
		fac[i]=1ll*fac[i-1]*i%Mod;
	}
	inv_f[Maxn*4]=find_inv(fac[Maxn*4]);
	for(int i=Maxn*4-1;i>=0;i--){
		inv_f[i]=1ll*inv_f[i+1]*(i+1)%Mod;
	}
}
int C(int n,int m){
	return 1ll*fac[n]*inv_f[m]%Mod*inv_f[n-m]%Mod;
}
int main(){
	init();
	scanf("%d%d",&n,&q);
	for(int i=0;i<=3*n+3;i++){
		f[i]=C(3*n+3,i);
	}
	f[0]=(f[0]-1+Mod)%Mod;
	for(int i=3*n+3;i>=3;i--){
		int val=f[i];
		g[i-3]=val;
		f[i]=(f[i]-val+Mod)%Mod;
		f[i-1]=(f[i-1]-3ll*val%Mod+Mod)%Mod;
		f[i-2]=(f[i-2]-3ll*val%Mod+Mod)%Mod;
	}
	for(int i=1;i<=q;i++){
		int x;
		scanf("%d",&x);
		printf("%d\n",g[x]);
	}
	return 0;
}