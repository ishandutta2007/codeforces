#include <stdio.h>

int x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		if(a==1)
		{
			printf("0\n");
			continue;
		}
		
		int val;
		val = x[2];
		for(int i=2;i<=a;i++) val = val>x[i]?val:x[i];
		int ans = -12345678;
		ans = ans>val-x[1]?ans:val-x[1];
		
		val = x[1];
		for(int i=1;i<a;i++) val = val<x[i]?val:x[i];
		ans = ans>x[a]-val?ans:x[a]-val;
		
		for(int i=1;i<a;i++)
		{
			val = x[i] - x[i+1];
			ans = ans>val?ans:val;
		}
		printf("%d\n",ans);
	}
}