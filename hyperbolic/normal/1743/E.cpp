#include <stdio.h>
#define MAX (long long int)1e16

long long int check[100010],check2[100010];
int main()
{
	long long int a,b,c,d,e,f;
	scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e,&f);
	
	long long int power = a+c-f;
	long long int gap = b>d?b:d;
	
	for(int i=0;i<=10000;i++) check[i] = MAX;
	for(int i=0;i<=10000;i++) check2[i] = MAX;
	for(long long int i=0;i<=e;i++)
	{
		for(long long int j=0;j<=e;j++)
		{
			long long int D = i*(a-f) + j*(c-f) + (a+c-f);
			long long int T1 = (i+1)*b;
			long long int T2 = (j+1)*d;
			long long int T = T1>T2?T1:T2;
			if(D<=10000) check[D] = check[D]<T?check[D]:T;
		}
	}
	check2[0] = 0;
	for(int i=0;i<=10000;i++)
	{
		for(int j=0;j+i<=10000;j++)
		{
			if(check2[j+i]>check2[j]+check[i]) check2[j+i] = check2[j]+check[i];
		}
		for(int j=10000-1;j>=0;j--) check2[j] = check2[j]<check2[j+1]?check2[j]:check2[j+1];
	}
	
	long long int ans = MAX;
	for(long long int i=0;i<=e;i++)
	{
		long long int val = i;
		long long int p = 0;
		long long int min = 0, max = MAX;
		while(min<=max)
		{
			long long int h = (min+max)/2;
			if(h/b >= 10000)
			{
				p = h;
				max = h-1;
				continue;
			}
			if(h/d >= 10000)
			{
				p = h;
				max = h-1;
				continue;
			}
			
			long long int val1 = (a-f)*(h/b);
			long long int val2 = (c-f)*(h/d);
			if(val1+val2>=val)
			{
				p = h;
				max = h-1;
			}
			else min = h+1;
		}
		ans = ans<p+check2[e-i]?ans:p+check2[e-i];
	}
	
	printf("%lld",ans);
}