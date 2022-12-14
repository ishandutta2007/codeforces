#include <stdio.h>

int x[110][110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) scanf("%d",&x[i][j]);
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				if((i+j)%2==0)
				{
					if(x[i][j]%2==0) printf("%d ",x[i][j]);
					else printf("%d ",x[i][j]+1);
				}
				else
				{
					if(x[i][j]%2==1) printf("%d ",x[i][j]);
					else printf("%d ",x[i][j]+1);
				}
			}
			printf("\n");
		}
	}
}