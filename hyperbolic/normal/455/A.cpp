#include <stdio.h>

int count[100010];
long long int check[100010];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		count[b]++;
	}
	
	for(int i=1;i<=100000;i++)
	{
		/*long long int s1 = 0;
		if(count[i]>0) s1 = (long long int)count[i]*i+check[i-1];*/
		long long int s1 = (long long int)count[i]*i+check[i-1];
		long long int s2 = check[i];
		//printf("%d %lld %lld??\n",i,s1,s2);
		check[i+1] = s1>s2?s1:s2;
	}
	
	printf("%lld",check[100001]);
}