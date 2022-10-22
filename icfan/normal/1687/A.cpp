#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=200000;
int n,k;
int a[Maxn+5];
ll sum[Maxn+5];
void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	ll ans=0;
	for(int i=0;i<=n;i++){
		int r=std::min(i+k,n);
		int len=r-i;
		ans=std::max(ans,sum[r]-sum[i]+1ll*len*k-1ll*len*(len+1)/2);
	}
	printf("%lld\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}