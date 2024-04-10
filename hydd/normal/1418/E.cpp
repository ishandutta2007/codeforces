#include<cstdio>
#include<algorithm>
using namespace std;
const int Mod=998244353;
int n,m,d[210000],sum[210000],inv[210000];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&d[i]);
	sort(d+1,d+n+1);
	sum[1]=d[1]; inv[1]=1;
	for (int i=2;i<=n;i++){
		sum[i]=(sum[i-1]+d[i])%Mod;
		inv[i]=1ll*(Mod-Mod/i)*inv[Mod%i]%Mod;
	}
	int a,b;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		int pos=lower_bound(d+1,d+n+1,b)-d;
		int x=n-pos+1;
		if (a>x){ puts("0"); continue;}
		printf("%lld\n",(1ll*(x-a)*inv[x]%Mod*(sum[n]-sum[pos-1]+Mod)
						+1ll*(x-a+1)*inv[x+1]%Mod*sum[pos-1])%Mod);
	}
	return 0;
}