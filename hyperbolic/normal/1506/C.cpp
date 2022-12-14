#include <stdio.h>
#include <string.h>

char x[110],y[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s%s",x+1,y+1);
		int a = strlen(x+1);
		int b = strlen(y+1);
		int ans = a+b;
		for(int l1=1;l1<=a;l1++)
		{
			for(int r1=l1;r1<=a;r1++)
			{
				for(int l2=1;l2<=b;l2++)
				{
					for(int r2=l2;r2<=b;r2++)
					{
						if((r1-l1+1)!=(r2-l2+1)) continue;
						for(int k=l1;k<=r1;k++) if(x[k]!=y[k+(l2-l1)]) goto u;
						ans = ans<(l1-1)+(a-r1)+(l2-1)+(b-r2)?ans:(l1-1)+(a-r1)+(l2-1)+(b-r2);
						u:;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
}