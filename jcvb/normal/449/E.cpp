#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
const int N=1000000;
int phi[N+100],s[N+100],ps[N+100],pis[N+100],pi2s[N+100];
int t;
ll ans,n,m;
int main() {
	for (int i=1;i<=N;i++) phi[i]=i;
	for (int i=1;i<=N;i++) for (int j=i+i;j<=N;j+=i) phi[j]-=phi[i];
	for (int i=1;i<=N;i++) for (int j=i;j<=N;j+=i) {
		s[j]=(s[j]+1ll*(i-1)*phi[j/i])%mod;
	}
	for (int i=1;i<=N;i++) {
		ps[i]=(ps[i-1]+s[i])%mod;
		pis[i]=(pis[i-1]+1ll*s[i]*i)%mod;
		pi2s[i]=(pi2s[i-1]+1ll*s[i]*i%mod*i)%mod;
	}
	for (scanf("%d",&t);t;t--) {
		scanf("%I64d%I64d",&n,&m);
		if (n>m) swap(n,m);
		ans=((n+1)*(m+1)%mod*ps[n]-(n+m+2)*pis[n]+pi2s[n])%mod*2%mod;
		ans+=-((-1+n)*n%mod*(1+n)%mod*(2+n)%mod*((3+m*(27-6*n)+n*(-17+4*n))%mod))%mod*powmod(180,mod-2)%mod;
		ans+=(-n*(n+1)%mod*(n+2)%mod)*((3*n*n+n-4-5*m*(1+n))%mod)%mod*powmod(60,mod-2)%mod;
		ans%=mod;
		if (ans<0) ans+=mod;
		printf("%I64d\n",ans);
	}
}