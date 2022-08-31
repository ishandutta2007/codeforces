#include <cstdio>
#include <algorithm>
#define int long long

long long f[300010],g[300010],n,p[300010],mrk[300010],ans[300010],top;
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",p+i);
	f[1]=p[1],g[1]=1;
	f[2]=p[2],g[2]=1;
	for(int i=3;i<=n+1;i++){
		f[i]=f[i-2]+p[i],g[i]=1;
		if(i>2&&f[i]>f[i-3]+std::max(p[i-1],p[i])){
			f[i]=f[i-3]+std::max(p[i-1],p[i]),g[i]=2;
		}
	}
	int tem=n+1;
	while(tem>0)mrk[tem]=1,mrk[tem-1]=(g[tem]==2),tem-=g[tem]+1;
//	for(int i=1;i<=n;i++)printf("%d ",mrk[i]);putchar('\n');
//	for(int i=1;i<=n+1;i++)printf("%d ",f[i]);putchar('\n');
//	for(int i=1;i<=n+1;i++)printf("%d ",g[i]);putchar('\n');
	for(int i=1;i<n;i++)
		if(mrk[i]&&mrk[i+1]){
//			printf("%d\n",i);
			if(p[i]&&p[i+1]){
				int x=std::min(p[i],p[i+1]);
				p[i]-=x,p[i+1]-=x;
				ans[++top]=i;
			}
		}
	for(int i=1;i<n;i++)
		if(p[i]&&p[i+1]){
			int x=std::min(p[i],p[i+1]);
			p[i]-=x,p[i+1]-=x;
			ans[++top]=i;
		}
	printf("%lld\n",top);
	for(int i=1;i<=top;i++)printf("%lld\n",ans[i]);
}