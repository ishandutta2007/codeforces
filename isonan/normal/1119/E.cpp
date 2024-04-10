#include <cstdio>
#include <algorithm>
using std::min;

long long a[300001],n;
long long ans=0;
int main(){
	scanf("%I64d",&n);
	for(int i=1;i<=n;i++)scanf("%I64d",a+i);
	long long left=0;
	for(int i=1;i<=n;i++){
		long long tem=min(a[i]>>1,left);
		a[i]-=tem<<1;
		ans+=tem+(a[i]/3);
		left+=(a[i]%3)-tem;
	}
	printf("%I64d",ans);
}