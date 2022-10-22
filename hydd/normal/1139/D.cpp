#include<cstdio>
#include<vector>
using namespace std;
const int Mod=1e9+7;
int m,inv[110000],mu[110000];
int main(){
	scanf("%d",&m); mu[1]=1;
	for (int i=1;i<=m;i++)
		for (int j=i+i;j<=m;j+=i)
			mu[j]-=mu[i];
	inv[1]=1;
	for (int i=2;i<=m;i++) inv[i]=1ll*(Mod-Mod/i)*inv[Mod%i]%Mod;
	int ans=1;
	for (int i=2;i<=m;i++) ans=(ans-1ll*mu[i]*(m/i)%Mod*inv[m-(m/i)])%Mod;
	printf("%d\n",(ans+Mod)%Mod);
	return 0;
}