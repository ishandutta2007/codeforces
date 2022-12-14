#include <stdio.h>

int x[400010];
int main()
{
	int a;
	long long int b;
	scanf("%d%lld",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) x[a+i] = x[i];
	
	long long int ans = 0;
	int p = 2*a;
	long long int sum = 0;
	long long int value = 0;
	
	while(1)
	{
		if(x[p]+sum>b) break;
		else
		{
			sum += x[p];
			value += (long long int)x[p]*(x[p]+1)/2;
			p--;
		}
	}
	long long int temp = value + (long long int)(b-sum)*(2*x[p]-(b-sum)+1)/2;
	ans = ans>temp?ans:temp;
	
	for(int i=2*a-1;i>a;i--)
	{
		if(p<i+1)
		{
			sum -= x[i+1];
			value -= (long long int)x[i+1]*(x[i+1]+1)/2;
		}
		else p = i;
		
		while(1)
		{
			if(x[p]+sum>b) break;
			else
			{
				sum += x[p];
				value += (long long int)x[p]*(x[p]+1)/2;
				p--;
			}
		}
		temp = value + (long long int)(b-sum)*(2*x[p]-(b-sum)+1)/2;
		ans = ans>temp?ans:temp;
	}
	printf("%lld",ans);
}