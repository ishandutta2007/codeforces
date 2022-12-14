#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int x,y,x1,y1,x2,y2;
		scanf("%d%d%d%d%d%d",&x,&y,&x1,&y1,&x2,&y2);
		if(a==b)
		{
			if(a>0)
			{
				if(x1<=x-1&&x-1<=x2);
				else if(x1<=x+1&&x+1<=x2);
				else
				{
					printf("NO\n");
					continue;
				}
			}
		}
		if(c==d)
		{
			if(c>0)
			{
				if(y1<=y-1&&y-1<=y2);
				else if(y1<=y+1&&y+1<=y2);
				else
				{
					printf("NO\n");
					continue;
				}
			}
		}
		
		if(x1<=x+b-a&&x+b-a<=x2&&y1<=y+d-c&&y+d-c<=y2) printf("YES\n");
		else printf("NO\n");
	}
}