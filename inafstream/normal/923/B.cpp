#include<bits/stdc++.h>

using namespace std;

long long sum[100005],add[100005],t[100005],sum2[100005];

int main()
{
	long long n;
	int i;
	
	scanf("%I64d",&n);
	
	for (i=1;i<=n;i++) scanf("%I64d",&add[i]);
	for (i=1;i<=n;i++) scanf("%I64d",&t[i]);
	
	for (i=1;i<=n;i++) t[i]+=t[i-1];
	
	for (i=1;i<=n;i++)
	{
		long long j=upper_bound(t+1,t+n+1,add[i]+t[i-1]-1)-t;
		//fprintf(stderr,"%I64d\n",j);
		
		sum[i]++;
		sum[j]--;
		sum2[j]+=add[i]-(t[j-1]-t[i-1]);
	}
	
	for (i=1;i<=n;i++)
	{
		sum[i]+=sum[i-1];
		printf("%I64d ",sum2[i]+sum[i]*(t[i]-t[i-1]));
	}
	
	return 0;
}