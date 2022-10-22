#include<cstdio>
using namespace std;
const int Mod=998244353;
typedef long long ll;
int n,m,k,l,s;
ll pow2[4100],C[4100][4100],inv[8100],f[4100];
int main(){
	for (int i=0;i<=4000;i++){
		C[i][0]=1;
		for (int j=1;j<=i;j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
	}
	inv[1]=1; for (int i=2;i<=8000;i++) inv[i]=1ll*(Mod-Mod/i)*inv[Mod%i]%Mod;
	pow2[0]=1; for (int i=1;i<=4000;i++) pow2[i]=(pow2[i-1]<<1)%Mod;
	for (int i=1;i<=4000;i++)
		for (int j=0;j<=i;j++)
			if (j&1) f[i]=(f[i]-1ll*C[i][j]*inv[i+j+1]%Mod+Mod)%Mod;
			else f[i]=(f[i]+1ll*C[i][j]*inv[i+j+1])%Mod;
			
			
	scanf("%d%d%d",&n,&k,&l);
	int ans=0;
	for (int i=k;i<=n;i++){
		int s=0;
		for (int j=0;j<=n-i;j++)
			if (j&1) s=(s-1ll*pow2[i+j]*C[n-i][j]%Mod*f[i+j]%Mod+Mod)%Mod;
			else s=(s+1ll*pow2[i+j]*C[n-i][j]%Mod*f[i+j])%Mod;
		ans=(ans+1ll*C[n][i]*s)%Mod;
	}
	printf("%lld\n",1ll*ans*l%Mod);
	return 0;
}