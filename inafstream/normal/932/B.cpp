#include<bits\stdc++.h>
using namespace std;
long long dp[1000002],ans[1000002][12];
int main()
{
	long long i;
	
	for (i=1;i<10;i++) dp[i]=i;
	
	for (i=1;i<=1000000;i++)
	{
		long long mul=1,x=i;
		
		while (x)
		{
			if (x%10) mul*=x%10;
			x/=10;
		}
		
		dp[i]=dp[mul];
	}
	
	for (i=1;i<=1000000;i++)
	{
		memcpy(ans[i],ans[i-1],sizeof(ans[i]));
		
		ans[i][dp[i]]++;
	}
	
	long long n;
	scanf("%I64d",&n);
	
	while (n--)
	{
		long long l,r,k;
		
		scanf("%I64d%I64d%I64d",&l,&r,&k);
		
		printf("%I64d\n",ans[r][k]-ans[l-1][k]);
	}
	
	return 0;
}