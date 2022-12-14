#include <stdio.h>

char x[110],y[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		int C = 0;
		scanf("%d%d",&a,&b);
		scanf("%s",x+1);
		scanf("%s",y+1);
		for(int i=a-b+2;i<=a;i++)
		{
			if(x[i]!=y[i-(a-b)])
			{
				printf("NO\n");
				goto u;
			}
		}
		
		for(int i=1;i<=a-b;i++) if(x[i]!=x[i+1]) C = 1;
		if(C==1) printf("YES\n");
		else if(x[1]==y[1]) printf("YES\n");
		else printf("NO\n");
		u:;
	}
}