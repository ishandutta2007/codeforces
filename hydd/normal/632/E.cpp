#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,k,a[1100],b[1100],dp[1100000];
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) b[i]=a[i]-a[1];
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for (int i=1;i<=n;i++)
		for (int j=b[i];j<=1000010;j++)
			dp[j]=min(dp[j],dp[j-b[i]]+1);
	for (int j=0;j<=1000010;j++)
		if (dp[j]<=k) printf("%d ",k*a[1]+j);
	return 0;
}