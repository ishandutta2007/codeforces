#include <stdio.h>
#include <algorithm>
int x[10];
int main()
{
	int s = 0;
	scanf("%d%d%d%d%d",&x[1],&x[2],&x[3],&x[4],&x[5]);
	s = x[1]+x[2]+x[3]+x[4]+x[5];
	std::sort(x+1,x+5+1);
	if(x[5]==x[4])
	{
		if(x[4]==x[3]) printf("%d",s-3*x[4]);
		else if(x[1]==x[2]&&x[2]==x[3])
		{
			if(3*x[1]>2*x[4]) printf("%d",s-3*x[1]);
			else printf("%d",s-2*x[4]);
		}
		else printf("%d",s-2*x[4]);
	}
	else
	{
		if(x[4]==x[3])
		{
			if(x[3]==x[2]) printf("%d",s-3*x[3]);
			else printf("%d",s-2*x[3]);
		}
		else if(x[3]==x[2])
		{
			if(x[2]==x[1]) printf("%d",s-3*x[2]);
			else printf("%d",s-2*x[2]);
		}
		else if(x[2]==x[1]) printf("%d",s-2*x[1]);
		else printf("%d",s);
	}
}