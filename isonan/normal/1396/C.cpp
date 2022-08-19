#include <cstdio>
#include <algorithm>
#define int long long

int n,r1,r2,r3,d,a[1000001];
long long cost[2][1000001],f[100001];
signed main(){
	scanf("%lld%lld%lld%lld%lld",&n,&r1,&r2,&r3,&d);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	f[0]=-d;
	for(int i=1;i<=n;i++){
		cost[1][i]=std::min(r1*(a[i]+1),r2)+r1;
		cost[0][i]=r1*a[i]+r3;
		f[i]=f[i-1]+d+cost[0][i];
		if(i>=2)f[i]=std::min(f[i],f[i-2]+d*4+cost[1][i]+cost[1][i-1]);
		f[i]=std::min(f[i],f[i-1]+d*3+cost[1][i]);
//		printf("%lld %lld\n",cost[0][i],cost[1][i]);
//		printf("%lld\n",f[i]);
	}
	printf("%lld\n",std::min(f[n],f[n-2]+d*3+cost[0][n]+cost[1][n-1]));
}