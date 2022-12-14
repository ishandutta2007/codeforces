#include <stdio.h>
#include <vector>
#define MAX (long long int)1e18

std::vector<long long int> save[110];
long long int root(long long int a, int b)
{
	if(b>=3)
	{
		int min = 1, max = save[b].size()-1;
		int ans = 1;
		while(min<=max)
		{
			int h = (min+max)/2;
			if(save[b][h]<=a)
			{
				ans = h;
				min = h+1;
			}
			else max = h-1;
		}
		return ans;
	}
	
	long long int min = 1, max = a;
	long long int ans = a;
	while(min<=max)
	{
		long long int h = (min+max)/2;
		long long int C = a;
		for(int i=1;i<=b;i++)
		{
			C/=h;
			if(C==0)
			{
				max = h-1;
				goto u;
			}
		}
		ans = h;
		min = h+1;
		u:;
	}
	return ans;
}

long long int x[110];
int main()
{
	for(int i=3;i<=60;i++)
	{
		save[i].push_back(0);
		save[i].push_back(1);
		for(int j=2;;j++)
		{
			long long int s = 1;
			for(int k=1;k<=i;k++)
			{
				if(MAX/j+1<s) goto u;
				s*=j;
				if(s>MAX) goto u;
			}
			save[i].push_back(s);
		}
		u:;
	}
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a;
		scanf("%lld",&a);
		
		x[0] = a-1;
		for(int i=1;i<=60;i++) x[i] = root(a,i)-1;
		for(int i=60;i>=1;i--) for(int j=2*i;j<=60;j+=i) x[i] -= x[j];
		printf("%lld\n",x[1]);
	}
}