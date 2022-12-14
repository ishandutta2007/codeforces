#include <stdio.h>

char x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		int b = a/2;
		for(int i=1;i<=b;i++)
		{
			if(x[i]=='0')
			{
				printf("%d %d %d %d\n",i,a,i+1,a);
				goto u;
			}
		}
		for(int i=b+1;i<=a;i++)
		{
			if(x[i]=='0')
			{
				printf("%d %d %d %d\n",1,i,1,i-1);
				goto u;
			}
		}
		printf("%d %d %d %d\n",1,2*b,1,b);
		u:;
	}
}