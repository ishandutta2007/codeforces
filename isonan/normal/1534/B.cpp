#include <cstdio>
#include <algorithm>

int t,n,a[400010];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		long long ans=0;
		for(int i=1;i<=n;++i){
			scanf("%d",a+i);
		}
		a[n+1]=0;
		for(int i=1;i<=n+1;++i){
			long long v=a[i]-a[i-1];
			if(v<0)v=-v;
			ans+=v;
		}
		for(int i=1;i<=n;++i){
			ans-=std::max(0,std::min(a[i]-a[i-1],a[i]-a[i+1]));
		} 
		printf("%lld\n",ans);
	}
}