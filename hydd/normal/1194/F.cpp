#include<cstdio>
using namespace std;
typedef long long ll;
const int Mod=1e9+7;
const int inv2=(Mod+1)/2;
int n; ll T;
ll fac[210000],inv[210000];
ll C(int n,int m){
    if (n<m) return 0;
    return 1ll*fac[n]*inv[m]%Mod*inv[n-m]%Mod;
}
int main(){
	scanf("%d%lld",&n,&T);
	fac[0]=1; for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%Mod;
	inv[1]=1; for (int i=2;i<=n;i++) inv[i]=(Mod-Mod/i)*inv[Mod%i]%Mod;
	inv[0]=1; for (int i=1;i<=n;i++) inv[i]=inv[i-1]*inv[i]%Mod;
	int x=n,t,ans=0;
	int sum=1,mul=1;
	//sum=C(i,0)+C(i,1)+C(i,2)+...+C(i,x)
	for (int i=1;i<=n;i++){
		scanf("%d",&t); T-=t;
		if (T<0) break;
		
		sum=(((sum<<1)-C(i-1,x))%Mod+Mod)%Mod;
		while (x>T){
			sum=(sum-C(i,x)+Mod)%Mod;
			x--;
		}
		mul=1ll*mul*inv2%Mod;
		ans=(ans+1ll*sum*mul)%Mod;
	}
	printf("%d\n",ans);
	return 0;
}