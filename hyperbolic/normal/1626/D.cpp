#include <stdio.h>
#include <set>
#include <algorithm>
int func(int k)
{
	if(k==0) return 1;
	k--;
	int count = 0;
	while(k) k/=2, count++;
	return (1<<count);
}

std::set<int> S;
int x[200010],sum[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		S.clear();
		int a;
		scanf("%d",&a);
		for(int i=0;i<=a;i++) sum[i] = 0;
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		for(int i=1;i<=a;i++) sum[x[i]]++;
		for(int i=1;i<=a;i++) sum[i] += sum[i-1];
		
		int ans = 1234567890;
		for(int i=a;i>=0;i--)
		{
			S.insert(a-sum[i]);
			for(int j=0;j<=20;j++)
			{
				std::set<int> ::iterator it = S.lower_bound((1<<j)+1);
				if(it==S.begin()) continue;
				it--;
				int val = (*it);
				int t = func(sum[i]) + func(val) + func(a-sum[i]-val);
				ans = ans<t-a?ans:t-a;
			}
			
			for(int j=0;j<=20;j++)
			{
				std::set<int> ::iterator it = S.lower_bound((a-sum[i])-(1<<j));
				if(it==S.end()) continue;
				int val = (*it);
				int t = func(sum[i]) + func(val) + func(a-sum[i]-val);
				ans = ans<t-a?ans:t-a;
			}
		}
		printf("%d\n",ans);
	}
}