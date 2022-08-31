#include <cstdio>
#include <algorithm>

int t,n,d[100001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		int mx=0;
		for(int i=1;i<=n;++i)scanf("%d",d+i);
		std::sort(d+1,d+n+1);
		long long ans=d[n];
		for(int i=n;i;--i){
			ans+=1ll*d[i]*(n-i);
			ans-=1ll*d[i]*(i-1);
		}
		printf("%lld\n",ans);
	}
}