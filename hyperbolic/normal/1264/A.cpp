#include <stdio.h>
#include <algorithm>
#define MIN -123456789

int x[400010];
int a;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int b,s,g;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+a+1);
		
		int last;
		for(int i=a;i>=2;i--)
		{
			if(x[i]!=x[i-1])
			{
				g = (a-i+1);
				last = i-1;
				goto u1;
			}
		}
		printf("0 0 0\n");
		continue;
		
		u1:;
		for(int i=last;i>=2;i--)
		{
			if(x[i]!=x[i-1])
			{
				if((last-i+1)>g)
				{
					s = (last-i+1);
					last = i-1;
					goto u2;
				}
			}
		}
		printf("0 0 0\n");
		continue;
		u2:;
		
		for(int i=(a+1)/2+1;i<=last;i++)
		{
			if(x[i]!=x[i-1])
			{
				b = (last-i+1);
				goto u3;
			}
		}
		printf("0 0 0\n");
		continue;
		u3:;
		
		if(g<b) printf("%d %d %d\n",g,s,b);
		else printf("0 0 0\n");
	}
}