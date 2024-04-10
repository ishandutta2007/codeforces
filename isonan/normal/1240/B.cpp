#include <cstdio>
#include <cstring>
#include <algorithm>

int mn[300001],mx[300001],n,q,a[300001],cnt[300001];
bool exi[300001];
int main(){
	scanf("%d",&q);
	for(int fd=1;fd<=q;fd++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)mn[i]=mx[i]=exi[i]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",a+i);
			if(!mn[a[i]])mn[a[i]]=i;
			mx[a[i]]=i;
			exi[a[i]]=1;
		}
		for(int i=1;i<=n;i++)cnt[i]=cnt[i-1]+exi[i];
		for(int i=1;i<=n;i++)mx[i]=exi[i]?mx[i]:mx[i-1];
		int r=1,ans=n+1,tem=0;
		for(int i=1;i<=n;i++){
			if(r<i)r=i;
			while(r<n&&(mx[r]<mn[r+1]||!exi[r+1]))++r;
			ans=std::min(ans,cnt[i-1]+cnt[n]-cnt[r]);
		}
		printf("%d\n",ans);
	}
}