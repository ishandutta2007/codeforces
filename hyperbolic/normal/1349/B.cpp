#include <stdio.h>

int x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		if(a==1)
		{
			if(x[1]==b) printf("yes\n");
			else printf("no\n");
			continue;
		}
		
		int control = 0;
		for(int i=1;i<=a;i++) if(x[i]==b) control = 1;
		if(control==0)
		{
			printf("no\n");
			goto u;
		}
		
		for(int i=1;i<=a;i++)
		{
			if(x[i]>=b)
			{
				if(i-1>=1 && x[i-1]>=b)
				{
					printf("yes\n");
					goto u;
				}
				else if(i+1<=a && x[i+1]>=b)
				{
					printf("yes\n");
					goto u;
				}
				else if(i-2>=1 && x[i-2]>=b)
				{
					printf("yes\n");
					goto u;
				}
				else if(i+2<=a && x[i+2]>=b)
				{
					printf("yes\n");
					goto u;
				}
			}
		}
		printf("no\n");
		u:;
	}
}