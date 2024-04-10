#include <cstdio>
#include <algorithm>

int t,n,a[200001],b[200001],f[200001],top;
bool judge(int x){
	for(int i=1,now=0;i<=n;++i)
		if(a[i]>=x-now-1&&b[i]>=now){
			++now;
			// printf("%d %d\n",x,i);
			if(now==x)return 1;
		}
	return 0;
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d%d",a+i,b+i);
		int l=1,r=n,mid,ans;
		while(l<=r){
			mid=(l+r)>>1;
			if(judge(mid))ans=mid,l=mid+1;
			else r=mid-1;
		}
		printf("%d\n",ans);
	}
}