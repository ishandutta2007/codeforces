#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Mod=998244353;
int n,m,A,b[210000];
ll qpow(ll x,int a){
	ll res=1;
	while (a){
		if (a&1) res=res*x%Mod;
		x=x*x%Mod; a>>=1;
	}
	return res;
}
int main(){
	scanf("%d%d%d",&n,&m,&A);
	for (int i=1;i<=m;i++) scanf("%d",&b[i]);
	sort(b+1,b+m+1);
	ll ans=qpow(A,n-(b[m]<<1));
	for (int i=1;i<=m;i++){
		ll tot=qpow(A,b[i]-b[i-1]);
		ans=ans*(tot*(tot+1)/2%Mod)%Mod;
	}
	printf("%lld\n",ans);
	return 0;
}