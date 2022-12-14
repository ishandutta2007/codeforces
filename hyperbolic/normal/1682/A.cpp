#include <stdio.h>

char x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		int b = (a+1)/2;
		int count = 0;
		for(int i=b;i>=1;i--)
		{
			if(x[i]==x[b]) count++;
			else break;
		}
		for(int i=b+1;i<=a;i++)
		{
			if(x[i]==x[b]) count++;
			else break;
		}
		printf("%d\n",count);
	}
}