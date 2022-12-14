#include <stdio.h>

int getQuery(int x1, int y1, int x2, int y2)
{
	printf("? %d %d %d %d\n",x1,y1,x2,y2);
	fflush(stdout);
	
	int a;
	scanf("%d",&a);
	return a;
}

struct str{
	int x1;
	int y1;
	int x2;
	int y2;
}ans[10];

void func(int k, int x1, int y1, int x2, int y2)
{
	int min, max;
	
	//printf("%d %d %d %d\n",x1,y1,x2,y2);
	min = x1+1, max = x2;
	while(min<=max)
	{
		int h = (min+max)/2;
		if(getQuery(h,y1,x2,y2)==1)
		{
			x1 = h;
			min = h+1;
		}
		else max = h-1;
	}
	//printf("%d %d %d %d\n",x1,y1,x2,y2);
	min = x1, max = x2-1;
	while(min<=max)
	{
		int h = (min+max)/2;
		if(getQuery(x1,y1,h,y2)==1)
		{
			x2 = h;
			max = h-1;
		}
		else min = h+1;
	}
	//printf("%d %d %d %d\n",x1,y1,x2,y2);
	min = y1+1, max = y2;
	while(min<=max)
	{
		int h = (min+max)/2;
		if(getQuery(x1,h,x2,y2)==1)
		{
			y1 = h;
			min = h+1;
		}
		else max = h-1;
	}
	//printf("%d %d %d %d\n",x1,y1,x2,y2);
	min = y1, max = y2-1;
	while(min<=max)
	{
		int h = (min+max)/2;
		if(getQuery(x1,y1,x2,h)==1)
		{
			y2 = h;
			max = h-1;
		}
		else min = h+1;
	}
	
	ans[k] = {x1,y1,x2,y2};
}

int main()
{
	int a;
	scanf("%d",&a);
	
	//case1
	int min = 1, max = a-1;
	while(min<=max)
	{
		int h = (min+max)/2;
		int s1 = getQuery(1,1,h,a);
		int s2 = getQuery(h+1,1,a,a);
		if(s1==0&&s2==0) goto u;
		else if(s1==1&&s2==1)
		{
			func(1,1,1,h,a);
			func(2,h+1,1,a,a);
			goto u2;
		}
		else
		{
			if(s1==0) min = h+1;
			else max = h-1;
		}
	}
	u:;
	
	//case 2
	
	min = 1, max = a-1;
	while(min<=max)
	{
		int h = (min+max)/2;
		int s1 = getQuery(1,1,a,h);
		int s2 = getQuery(1,h+1,a,a);
		if(s1==0&&s2==0) goto u2;
		else if(s1==1&&s2==1)
		{
			func(1,1,1,a,h);
			func(2,1,h+1,a,a);
			goto u2;
		}
		else
		{
			if(s1==0) min = h+1;
			else max = h-1;
		}
	}
	u2:;
	
	printf("! ");
	for(int i=1;i<=2;i++) printf("%d %d %d %d ",ans[i].x1,ans[i].y1,ans[i].x2,ans[i].y2);
	fflush(stdout);
}