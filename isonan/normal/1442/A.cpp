#include <cstdio>
#include <algorithm>
#define int long long

int n,t,a[30001],b[30001];
signed main(){
	scanf("%lld",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)scanf("%lld",a+i);
		for(int i=1;i<=n;i++)b[i]=a[i]-a[i-1];
		int sum=0;
		for(int i=2;i<=n;i++)sum+=std::max(0ll,-b[i]);
		if(sum<=b[1])puts("YES");
		else puts("NO");
	}
}