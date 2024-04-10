#include <stdio.h>

int x[10010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		for(int i=1;i<a;i++)
		{
			if(x[i]==0&&x[i+1]==1)
			{
				for(int j=1;j<=i;j++) printf("%d ",j);
				printf("%d ",a+1);
				for(int j=i+1;j<=a;j++) printf("%d ",j);
				printf("\n");
				goto u;
			}
		}
		
		if(x[1]==1)
		{
			printf("%d ",a+1);
			for(int i=1;i<=a;i++) printf("%d ",i);
			printf("\n");
		}
		else
		{
			for(int i=1;i<=a;i++) printf("%d ",i);
			printf("%d\n",a+1);
		}
		
		u:;
	}
}