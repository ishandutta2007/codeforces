#include<cstdio>
using namespace std;
const int Mod=1e9+7;
typedef long long ll;
int n,m;
ll ans,powm[1100000],powx[1100000];
int main(){
	scanf("%d%d",&n,&m);
	powm[0]=1; for (int i=1;i<=n;i++) powm[i]=powm[i-1]*m%Mod;
	int x=2*m-1;
	powx[0]=1; for (int i=1;i<=n;i++) powx[i]=powx[i-1]*x%Mod;
	ans=powm[n];
	for (int i=0;i<n;i++) (ans+=powm[n-i]*powx[i]%Mod)%=Mod;
	printf("%lld\n",ans);
	return 0;
}