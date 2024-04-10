#include <cstdio>
#include <algorithm>

int t,n,a[100001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		int cnt=0;
		for(int i=1;i<=n;++i)scanf("%d",a+i),a[i]&=1;
		for(int i=1;i<=n;++i)cnt+=a[i];
		long long ans=1e18;
		for(int j=0;j<2;++j){
			if(((n-j+1)>>1)==cnt){
				long long now=0;
				for(int i=1,k=j+1;i<=n;++i){
					if(a[i]){
						now+=std::max(i-k,k-i);
						k+=2;
					}
				}
				if(ans>now)ans=now;
			}
		}
		if(ans==1e18)puts("-1");
		else printf("%lld\n",ans);
	}
}