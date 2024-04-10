#include <cstdio>
#include <algorithm>
#define int long long
int n,h,a[1010],tem[1010];
signed main(){
	scanf("%I64d%I64d",&n,&h);
	for(int i=1;i<=n;i++)scanf("%I64d",a+i);
	int ans=-1;
	for(int mid=1;mid<=n;mid++){
		for(int j=1;j<=mid;j++)tem[j]=a[j];
		std::sort(tem+1,tem+mid+1);
		int used=h;
		for(int j=mid;j>1;j-=2){
			used-=tem[j];
		}
		if(mid&1)used-=tem[1];
		if(used>=0)ans=mid;
	}
	printf("%I64d\n",ans);
}