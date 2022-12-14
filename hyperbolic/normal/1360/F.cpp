#include <stdio.h>

char x[110][110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
		
		for(int j=1;j<=b;j++)
		{
			char p = 0;
			for(int i=2;i<=a;i++)
			{
				int count = 0;
				for(int k=1;k<=b;k++)
				{
					if(k==j) continue;
					if(x[i][k]!=x[1][k]) count++;
				}
				if(count>=2) goto u1;
				else if(count==1)
				{
					if(p!=0 && p!=x[i][j]) goto u1;
					else p = x[i][j];
				}
			}
			
			if(p==0)
			{
				for(int k=1;k<=b;k++) printf("%c",x[1][k]);
				printf("\n");
			}
			else
			{
				for(int k=1;k<=b;k++)
				{
					if(j==k) printf("%c",p);
					else printf("%c",x[1][k]);
				}
				printf("\n");
			}
			goto u2;
			u1:;
		}
		
		printf("-1\n");
		u2:;
	}
}