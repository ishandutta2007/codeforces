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
		
		int p = 0;
		if(x[1]==a) p = 1;
		if(x[a]==a) p = a;
		if(p==0) printf("-1\n");
		else
		{
			if(p==1)
			{
				printf("%d ",a);
				for(int i=a;i>=2;i--) printf("%d ",x[i]);
				printf("\n");
			}
			else
			{
				for(int i=a-1;i>=1;i--) printf("%d ",x[i]);
				printf("%d\n",a);
			}
		}
	}
}