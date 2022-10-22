#include<cstdio>
using namespace std;
typedef long long ll;
int n,m;
ll ans,fac[1100000];
int main(){
	scanf("%d%d",&n,&m);
	fac[0]=1;
	for (int i=1;i<=n;i++) fac[i]=(ll)fac[i-1]*i%m;
	for (int i=1;i<=n;i++)
		ans=(ans+(ll)(n-i+1)*fac[n-i+1]%m*fac[i]%m)%m;
	printf("%lld\n",ans);		
	return 0;
}