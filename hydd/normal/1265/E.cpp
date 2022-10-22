#include<cstdio>
using namespace std;
const int Mod=998244353;
int n,p[210000],dp[210000],inv[110];
int main(){
	inv[1]=1;
	for (int i=2;i<=100;i++) inv[i]=1ll*(Mod-Mod/i)*inv[Mod%i]%Mod;
	scanf("%d",&n); dp[0]=0;
	for (int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		dp[i]=100ll*inv[p[i]]%Mod*(dp[i-1]+1)%Mod;
	}
	printf("%d\n",dp[n]);
	return 0;
}