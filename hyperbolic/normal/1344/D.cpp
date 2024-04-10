#include <stdio.h>
#include <queue>

int x[100010];
long long int check[100010];
std::priority_queue< std::pair<long long int,int> > Q;
long long int func(int k, long long int limit)
{
	long long int ans = 0;
	long long int min = 1, max = x[k];
	while(min<=max)
	{
		long long int h = (min+max)/2;
		long long int s = x[k]-3*h*h+3*h-1;
		if(s<limit) max = h-1;
		else
		{
			ans = h;
			min = h+1;
		}
	}
	return ans;
}
int main()
{
	int a;
	long long int b;
	scanf("%d%lld",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	long long int min = -3, max = 1;
	for(int i=1;i<=10;i++) max*=10;
	for(int i=1;i<=18;i++) min*=10;
	long long int ans = max;
	
	while(min<=max)
	{
		long long int h = (min+max)/2;
		long long int count = 0;
		for(int i=1;i<=a;i++) count += func(i,h);
		if(count>=b) min = h+1;
		else
		{
			ans = h;
			max = h-1;
		}
	}
	
	long long int sum = 0;
	for(int i=1;i<=a;i++)
	{
		check[i] = func(i,ans);
		sum += check[i];
	}
	for(int i=1;i<=a;i++)
	{
		if(check[i]==x[i]) continue;
		long long int C = check[i]+1;
		Q.push(std::make_pair(x[i]-3*C*C+3*C-1,i));
	}
	while(b-sum>0)
	{
		std::pair<long long int,int> P = Q.top();
		Q.pop();
		check[P.second]++;
		sum++;
	}
	for(int i=1;i<=a;i++) printf("%lld ",check[i]);
}