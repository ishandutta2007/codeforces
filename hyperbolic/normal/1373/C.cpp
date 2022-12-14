#include <stdio.h>
#include <string.h>

char x[1000010];
int y[1000010],check[2000010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		int a = strlen(x+1);
		
		for(int i=0;i<=2*a;i++) check[i] = 0;
		
		int count = 0;
		for(int i=1;i<=a;i++)
		{
			if(x[i]=='+') count++;
			else count--;
			y[i] = count;
		}
		for(int i=a;i>=1;i--) check[y[i]+a] = i;
		
		long long int C = 0;
		for(int i=0;i<=a;i++)
		{
			if(check[a-i-1]==0)
			{
				printf("%lld\n",C+a);
				goto u;
			}
			else C += check[a-i-1];
		}
		u:;
	}
}