#include <stdio.h>

int ans[510][510];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		
		if(b==1)
		{
			printf("YES\n");
			
			for(int i=1;i<=a;i++) printf("%d\n",i);
		}
		else if(a%2==0)
		{
			printf("YES\n");
			
			int s = 0;
			for(int i=1;i<=a;i+=2)
			{
				for(int j=1;j<=b;j++) ans[i][j] = s+(2*j-1);
				for(int j=1;j<=b;j++) ans[i+1][j] = s+(2*j);
				s += 2*b;
			}
			
			for(int i=1;i<=a;i++)
			{
				for(int j=1;j<=b;j++) printf("%d ",ans[i][j]);
				printf("\n");
			}
		}
		else printf("NO\n");
	}
}