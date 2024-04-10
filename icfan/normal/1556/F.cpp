#include <cstdio>
#include <algorithm>
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
const int Maxn=14;
const int Maxv=2000000;
const int Mod=1000000007;
int find_inv(int x){
	return quick_power(x,Mod-2,Mod);
}
int inv[Maxv+5];
int sz[1<<Maxn|5];
void init(){
	inv[1]=1;
	for(int i=2;i<=Maxv;i++){
		inv[i]=1ll*(Mod-Mod/i)*inv[Mod%i]%Mod;
	}
	for(int i=1;i<(1<<Maxn);i++){
		sz[i]=sz[i-(i&(-i))]+1;
	}
}
int n;
int a[Maxn+5];
int p[Maxn+5][Maxn+5];
int id[1<<Maxn|5];
int f[1<<Maxn|5],g[Maxn+5][1<<Maxn|5],h[1<<Maxn|5];
int lis[1<<Maxn|5],lis_len;
int main(){
	init();
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		id[1<<i]=i;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			p[i][j]=1ll*a[i]*inv[a[i]+a[j]]%Mod;
		}
	}
	for(int i=1;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if((i>>j)&1){
				g[j][i]=1;
				for(int k=0;k<n;k++){
					if((i>>k)&1){
						continue;
					}
					g[j][i]=1ll*g[j][i]*p[j][k]%Mod;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		f[1<<i]=g[i][1<<i];
	}
	for(int i=1;i<(1<<n);i++){
		if(sz[i]==1){
			continue;
		}
		lis_len=0;
		for(int j=i;j;j=(j-1)&i){
			lis[++lis_len]=j;
		}
		std::reverse(lis+1,lis+1+lis_len);
		h[0]=1;
		for(int j=1;j<=lis_len;j++){
			int low_bit=lis[j]&(-lis[j]);
			h[lis[j]]=1ll*h[lis[j]^low_bit]*g[id[low_bit]][i]%Mod;
		}
		f[i]=1;
		for(int j=0;j<n;j++){
			if((i>>j)&1){
				f[i]=1ll*f[i]*g[j][i]%Mod;
			}
		}
		for(int j=((i-1)&i);j;j=(j-1)&i){
			f[i]=(f[i]-1ll*f[j]*h[i^j]%Mod+Mod)%Mod;
		}
	}
	int ans=0;
	for(int i=1;i<(1<<n);i++){
		ans=(ans+1ll*sz[i]*f[i])%Mod;
	}
	printf("%d\n",ans);
	return 0;
}