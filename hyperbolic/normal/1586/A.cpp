#include <stdio.h>

int x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		int sum = 0;
		for(int i=1;i<=a;i++) sum += x[i];
		
		for(int i=2;i*i<=sum;i++)
		{
			if(sum%i==0)
			{
				printf("%d\n",a);
				for(int j=1;j<=a;j++) printf("%d ",j);
				printf("\n");
				goto u;
			}
		}
		
		for(int i=1;i<=a;i++)
		{
			if((sum-x[i])%2==0)
			{
				printf("%d\n",a-1);
				for(int j=1;j<i;j++) printf("%d ",j);
				for(int j=i+1;j<=a;j++) printf("%d ",j);
				printf("\n");
				goto u;
			}
		}
		u:;
	}
}