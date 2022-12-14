#include <stdio.h>

int getQuery(int k)
{
	printf("? %d\n",k);
	fflush(stdout);
	
	int s;
	scanf("%d",&s);
	return s;
}

int main()
{
	int a;
	scanf("%d",&a);
	
	int L = 5000000;
	int min = 1, max = 5000000;
	while(min<=max)
	{
		int h = (min+max)/2;
		int s = getQuery(h);
		if(s==0) min = h+1;
		else if(s>1) min = h+1;
		else
		{
			L = h;
			max = h-1;
		}
	}
	
	int ans = L;
	for(int i=1;i<=a;i++)
	{
		int w = L/i;
		int s = getQuery(w);
		if(s==i)
		{
			ans = ans<s*w?ans:s*w;
		}
	}
	printf("! %d\n",ans);
	fflush(stdout);
}