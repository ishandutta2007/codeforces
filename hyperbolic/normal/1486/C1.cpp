#include <stdio.h>

int getQuery(int s, int t)
{
	printf("? %d %d\n",s,t);
	fflush(stdout);
	
	int a;
	scanf("%d",&a);
	return a;
}

int main()
{
	int a;
	scanf("%d",&a);
	
	int s = getQuery(1,a);
	int t1 = -1,t2 = -1;
	if(s>1) t1 = getQuery(1,s);
	if(s<a) t2 = getQuery(s,a);
	if(s==t1)
	{
		int ans = 1;
		int l = 1, r = s-1;
		while(l<=r)
		{
			int h = (l+r)/2;
			int t = getQuery(h,s);
			if(s==t)
			{
				ans = h;
				l = h+1;
			}
			else r = h-1;
		}
		printf("! %d\n",ans);
		fflush(stdout);
	}
	else
	{
		int ans = a;
		int l = s+1, r = a;
		while(l<=r)
		{
			int h = (l+r)/2;
			int t = getQuery(s,h);
			if(s==t)
			{
				ans = h;
				r = h-1;
			}
			else l = h+1;
		}
		printf("! %d\n",ans);
		fflush(stdout);
	}
}