#include <stdio.h>

int p[5];
char x[4][200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=3;i++) scanf("%s",x[i]+1);
		p[1] = p[2] = p[3] = 1;
		while(1)
		{
			int C = 0;
			for(int i=1;i<=3;i++) if(p[i]==2*a+1) C++;
			if(C>=1) break;
			
			int count0 = 0, count1 = 0;
			for(int i=1;i<=3;i++)
			{
				if(x[i][p[i]]=='0') count0++;
				else count1++;
			}
			
			if(count1>=count0)
			{
				printf("1");
				for(int i=1;i<=3;i++) if(x[i][p[i]]=='1') p[i]++;
			}
			else
			{
				printf("0");
				for(int i=1;i<=3;i++) if(x[i][p[i]]=='0') p[i]++;
			}
			
		}
		
		if(p[1]==2*a+1)
		{
			if(p[2]>p[3]) for(int i=p[2];i<=2*a;i++) printf("%c",x[2][i]);
			else for(int i=p[3];i<=2*a;i++) printf("%c",x[3][i]);
		}
		else if(p[2]==2*a+1)
		{
			if(p[1]>p[3]) for(int i=p[1];i<=2*a;i++) printf("%c",x[1][i]);
			else for(int i=p[3];i<=2*a;i++) printf("%c",x[3][i]);
		}
		else
		{
			if(p[1]>p[2]) for(int i=p[1];i<=2*a;i++) printf("%c",x[1][i]);
			else for(int i=p[2];i<=2*a;i++) printf("%c",x[2][i]);
		}
		printf("\n");
	}
}