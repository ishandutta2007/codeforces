#include <stdio.h>

int x[1010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		int sum = 0;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		for(int i=1;i<=a;i++) if(x[i]!=b) goto u;
		printf("0\n");
		continue;
		u:;
		
		for(int i=1;i<=a;i++)
		{
			if(x[i]==b)
			{
				printf("1\n");
				goto v;
			}
		}
		
		for(int i=1;i<=a;i++) sum += x[i];
		
		if(sum==b*a) printf("1\n");
		else printf("2\n");
		
		v:;
	}
}