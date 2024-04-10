#include <cstdio>
#include <algorithm>
#define int long long

long long a[200001],b[200001];
int n,d,m;
signed main(){
	scanf("%lld%lld%lld",&n,&d,&m);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	std::sort(a+1,a+n+1);
	int cnt=0;
	for(int i=1;i<=n;i++)cnt+=(a[i]>m);
	long long ans=0;
	std::reverse(a+1,a+n+1);
	for(int i=1;i<=n;i++)a[i]+=a[i-1];
	for(int i=0;i<=cnt;i++){
			int Cnt=n-std::max(1ll*d*(i-1),0ll)-i;
			if(Cnt>=0)ans=std::max(ans,a[i]+a[std::min(cnt+Cnt,n)]-a[cnt]);
		}
	printf("%lld\n",ans);
}