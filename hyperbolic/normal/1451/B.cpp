#include <stdio.h>
#include <string.h>

int check1[110],check2[110];
char x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) check1[i] = check2[i] = 0;
		scanf("%s",x+1);
		check1[1] = 1;
		for(int i=2;i<=a;i++)
		{
			if(x[i]!=x[i-1]) break;
			check1[i] = 1;
		}
		check2[a] = 1;
		for(int i=a-1;i>=1;i--)
		{
			if(x[i]!=x[i+1]) break;
			check2[i] = 1;
		}
		
		for(int i=1;i<=b;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			if(c==1 || (x[c]!=x[c-1]&&check1[c-1]==1))
			{
				if(d==a || (x[d]!=x[d+1]&&check2[d+1]==1)) printf("NO\n");
				else printf("YES\n");
			}
			else printf("YES\n");
		}
	}
}