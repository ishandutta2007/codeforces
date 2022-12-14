#include <stdio.h>

char x[200010],y[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s%s",x+1,y+1);
		
		int pos1 = 1, pos2 = 1;
		for(int i=1;i<=a;i++)
		{
			int t1 = pos1, t2 = pos2;
			if(x[i]=='B'&&y[i]=='B') pos1 = t2, pos2 = t1;
			else if(x[i]=='B') pos2 = 0;
			else if(y[i]=='B') pos1 = 0;
		}
		if(pos1==0&&pos2==0) printf("NO\n");
		else printf("YES\n");
	}
}