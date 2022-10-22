#include <cstdio>
const int Maxn=1000000;
const int Mod=998244353;
int n;
int f[Maxn+5];
int sum[Maxn+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j+=i){
			f[j]++;
		}
	}
	sum[1]=f[1];
	for(int i=2;i<=n;i++){
		f[i]=(f[i]+sum[i-1])%Mod;
		sum[i]=(sum[i-1]+f[i])%Mod;
	}
	printf("%d\n",f[n]);
	return 0;
}