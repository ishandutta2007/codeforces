#include <stdio.h>
#include <algorithm>
#include <map>
int x[200010];
long long int sum[200010];

std::map<long long int,int> check;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) sum[i] = sum[i-1] + x[i];
	
	int p = 0;
	long long int ans = 0;
	for(int i=0;i<a;i++)
	{
		if(i>=1) check[sum[i-1]]--;
		for(int j=p;j<=a+1;j++)
		{
			if(j==a+1)
			{
				p = a+1;
				break;
			}
			if(check[sum[j]]>=1)
			{
				p = j;
				break;
			}
			else check[sum[j]]++;
		}
		ans += (p-1-i);
	}
	printf("%lld",ans);
}