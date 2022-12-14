#include <stdio.h>

int x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		int control = 0;
		long long int sum = 0;
		int R = -1;
		for(int i=1;i<=a;i++) if(x[i]!=0) control = 1;
		if(control==0)
		{
			printf("Yes\n");
			goto u;
		}
		
		if(x[1]<=0)
		{
			printf("No\n");
			goto u;
		}
		for(int i=a;i>=1;i--)
		{
			if(x[i]!=0)
			{
				R = i;
				break;
			}
		}
		if(x[R]>=0)
		{
			printf("No\n");
			goto u;
		}
		x[1]--, x[R]++;
		
		for(int i=1;i<=a;i++)
		{
			if(x[i]<0)
			{
				if(sum+x[i]<0)
				{
					printf("No\n");
					goto u;
				}
			}
			sum += x[i];
		}
		if(sum==0) printf("Yes\n");
		else printf("No\n");
		u:;
	}
}