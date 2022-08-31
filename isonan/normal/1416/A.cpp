#include <cstdio>
#include <cstring>
#include <algorithm>

int t,n,a[300010],last[300010],val[300010],cnt[300010];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&n);
		memset(last,0,(n+1)<<2);
		for(int i=1;i<=n;i++)scanf("%d",a+i),val[i]=0,cnt[i]=0x7f7f7f7f;
		for(int i=1;i<=n;i++){
			int u=i-last[a[i]]-1;
			if(val[a[i]]<u)val[a[i]]=u;
			last[a[i]]=i;
		}
		for(int i=1;i<=n;i++){
			int u=n-last[i];
			if(val[i]<u)val[i]=u;
			cnt[val[i]+1]=std::min(cnt[val[i]+1],i);
//			printf("%d %d\n",i,val[i]);
		}
		for(int i=2;i<=n;i++)cnt[i]=std::min(cnt[i],cnt[i-1]);
		for(int i=1;i<=n;i++){
			if(cnt[i]==0x7f7f7f7f)printf("-1 ");
			else printf("%d ",cnt[i]);
		}
		putchar('\n');
	}
}