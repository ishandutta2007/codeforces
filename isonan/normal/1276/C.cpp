#include <cstdio>
#include <vector>
#include <algorithm>

int n,a[400010],orig[400010],cnt[400010],top;
int fin,x,y;
int sum[400010];
std::vector<int>answer[400010];
std::pair<int,int>tem[400010];
bool judge(int x,int y){
	int pos=std::upper_bound(cnt+1,cnt+top+1,x)-cnt-1;
	return sum[pos]+x*(top-pos)>=x*y;
}
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),orig[i]=a[i];
	std::sort(a+1,a+n+1);
	top=std::unique(a+1,a+n+1)-a-1;
	for(int i=1;i<=n;i++)
		++cnt[std::lower_bound(a+1,a+top+1,orig[i])-a];
	std::sort(cnt+1,cnt+top+1);
	for(int i=1;i<=top;i++)sum[i]=sum[i-1]+cnt[i];
	for(int i=1;i<=n;i++){
		int l=i,r=n/i,mid,ans=-1;
		while(l<=r){
			mid=(l+r)>>1;
			if(judge(i,mid))ans=mid,l=mid+1;
			else r=mid-1;
		}
		if(i*ans>fin)fin=i*ans,x=i,y=ans;
	}
	printf("%d\n%d %d\n",fin,x,y);
	int X=0,Y=0;
	for(int i=top;i;i--)cnt[i]=0;
	for(int i=1;i<=n;i++)
		++cnt[std::lower_bound(a+1,a+top+1,orig[i])-a];
	for(int i=1;i<=top;i++)tem[i]=std::make_pair(cnt[i],a[i]);
	std::sort(tem+1,tem+top+1);
	for(int i=0;i<x;i++)answer[i].resize(y);
	for(int i=top;i;i--){
		for(int j=0;j<tem[i].first&&j<x;j++){
			answer[X][Y]=tem[i].second;
			(++X)%=x;
			(++Y)%=y;
			if(answer[X][Y])(++Y)%=y;
		}
	}
	for(int i=0;i<x;i++,putchar('\n'))
		for(int j=0;j<y;j++)
			printf("%d ",answer[i][j]);
}