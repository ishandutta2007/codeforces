#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		
		int s = 3*(c%2);
		if(b>0)
		{
			if(b%2==1)
			{
				if(s==3) s = 1;
				else s = 2;
			}
			else
			{
				if(s==3) s = 1;
				else s = 0;
			}
		}
		
		if(s<=a) printf("%d\n",(a-s)%2);
		else printf("%d\n",s-a);
	}
}