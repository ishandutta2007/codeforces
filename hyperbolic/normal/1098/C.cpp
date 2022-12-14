#include <stdio.h>
#include <vector>

int limit;
int p[100010],count[100010],prev[100010];
std::vector<int> V[100010];
int main()
{
	long long int a;
	long long int b;
	scanf("%lld%lld",&a,&b);
	if((long long int)a*(a+1)/2 < b)
	{
		printf("No");
		return 0;
	}
	
	for(limit=1;limit<=a;limit++)
	{
		long long int s = 1;
		long long int sum1 = 0, sum2 = 0;
		for(int i=1;i<=a;i++)
		{
			if(a-sum2<=s)
			{
				sum1 += (a-sum2)*i;
				sum2 = a;
				break;
			}
			else
			{
				sum1 += s*i;
				sum2 += s;
				s*=limit;
			}
		}
		if(sum1<=b) goto v;
	}
	printf("No");
	return 0;
	v:;
	
	for(int i=1;i<=a;i++) p[i] = i;
	for(int i=1;i<=a;i++) count[i] = 1;
	
	long long int sum = (long long int)a*(a+1)/2;
	int L = 2;
	for(int i=a;i>=2;i--)
	{
		if(sum==b) goto u;
		if(L>p[i])
		{
			printf("No");
			return 0;
		}
		
		if((sum-b)<=(p[i]-L))
		{
			p[i] = p[i] - (sum-b);
			goto u;
		}
		sum -= (p[i]-L);
		count[p[i]]--;
		p[i] = L;
		count[p[i]]++;
		if(count[L]==limit*count[L-1]) L++;
	}
	printf("No");
	return 0;
	u:;
	
	for(int i=1;i<=a;i++) V[p[i]].push_back(i);
	for(int i=2;i<=a;i++)
	{
		for(int j=0;j<V[i].size();j++)
		{
			prev[V[i][j]] = V[i-1][j%V[i-1].size()];
		}
	}
	
	printf("Yes\n");
	for(int i=2;i<=a;i++) printf("%d ",prev[i]);
}