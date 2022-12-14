#include <stdio.h>
int x[1000010],y[1000010];
int main()
{
	int a,b,c,d;
	int xMove = 0, yMove = 0, switched = 0;
	scanf("%d%d",&a,&b);
	a/=2;
	for(int i=1;i<=b;i++)
	{
		scanf("%d",&c);
		if(c==1)
		{
			scanf("%d",&d);
			if(d<0) d+=(2*a);
			if(d%2==0)
			{
				xMove+=d/2;
				yMove+=d/2;
			}
			else
			{
				xMove+=d/2;
				yMove+=d/2;
				if(switched==0) yMove++,switched=1;
				else xMove++,switched = 0;
			}
		}
		else if(c==2) switched = 1-switched;
		xMove%=a,yMove%=a;
	}
	for(int i=xMove;i>=1;i--) x[i] = (2*a-1)-(xMove-i)*2;
	for(int i=xMove+1;i<=a;i++) x[i] = 1 + (i-xMove-1)*2;
	
	for(int i=yMove;i>=1;i--) y[i] = (2*a)-(yMove-i)*2;
	for(int i=yMove+1;i<=a;i++) y[i] = 2 + (i-yMove-1)*2;
	
	if(switched==0)
	{
		for(int i=1;i<=a;i++)
		{
			printf("%d ",x[i]);
			printf("%d ",y[i]);
		}
	}
	else
	{
		for(int i=1;i<=a;i++)
		{
			printf("%d ",y[i]);
			printf("%d ",x[i]);
		}
	}
}