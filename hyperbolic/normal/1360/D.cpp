#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		
		int ans = 1;
		for(int i=1;i*i<=a;i++)
		{
			if(a%i==0)
			{
				if(i<=b) ans = ans>i?ans:i;
				if(a/i<=b) ans = ans>a/i?ans:a/i;
			}
		}
		printf("%d\n",a/ans);
	}
}