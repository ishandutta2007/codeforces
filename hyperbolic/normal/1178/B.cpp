#include <stdio.h>
#include <string.h>
char x[1000010];
long long int sum1[1000010],sum2[1000010];
int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='v'&&x[i-1]=='v') sum1[i] = sum1[i-1]+1;
		else sum1[i] = sum1[i-1];
	}
	for(int i=a;i>=1;i--)
	{
		if(x[i]=='v'&&x[i+1]=='v') sum2[i] = sum2[i+1]+1;
		else sum2[i] = sum2[i+1];
	}
	
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='o')
		{
			ans += sum1[i-1]*sum2[i+1];
		}
	}
	printf("%lld",ans);
}