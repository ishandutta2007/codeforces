#include <stdio.h>
#define SIZE 10

int getQuery(int a, int b)
{
	printf("? %d %d\n",a,b);
	fflush(stdout);
	
	int c;
	scanf("%d",&c);
	return c;
}

int count[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int c;
	scanf("%d",&c);
	
	int L = 1, R = a;
	int ans = a;
	while(L<=R)
	{
		int h = (L+R)/2;
		int t = h - getQuery(1,h);
		if(t>=c)
		{
			ans = h;
			R = h-1;
		}
		else L = h+1;
	}
	printf("! %d\n",ans);
	fflush(stdout);
}