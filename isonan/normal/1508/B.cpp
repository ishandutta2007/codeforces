#include <cstdio>
#include <algorithm>

int t,n,ans[100001];
long long k;
bool vis[100001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d%lld",&n,&k);
		int o=n;
		n=std::min(n,63);
		if((1ll<<(n-1))<k){
			puts("-1");
			continue;
		}
		for(int i=1;i<=n;++i)vis[i]=0;
		for(int i=1,mn=1;i<=n;++i){
			int p,tem;
			p=mn;
			tem=p;
			int m=n-p-1;
			while((1ll<<std::max(m,0))<k)k-=1ll<<m,++p,--m;
			mn=p+1;
			ans[i]=p;
			while(p>tem)ans[++i]=--p;
		}
		for(int i=1;i<=o-n;++i)printf("%d ",i);
		for(int i=1;i<=n;++i)printf("%d ",ans[i]+o-n);putchar('\n');
	}
}