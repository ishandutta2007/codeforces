#include <stdio.h>
struct str{
	int x0;
	int height;
}x[100010];
int abs(int k)
{
	return k>0?k:-k;
}
int main()
{
	int a,b,c,d,i,max=0,h1,h2;
	scanf("%d%d",&a,&b);
	for(i=1;i<=b;i++)
	{
		scanf("%d%d",&c,&d);
		x[i]={c,d};
	}
	for(i=1;i<b;i++)
	{
		d = x[i+1].x0-x[i].x0;
		h1 = x[i].height;
		h2 = x[i+1].height;
		if(abs(h1-h2)>d)
		{
			printf("IMPOSSIBLE");
			return 0;
		}
		else
		{
			if((d+h1+h2)%2==1) c = (d+h1+h2-1)/2;
			else c = (d+h1+h2)/2;
			max=max>c?max:c;
		}
	}
	max=max>(x[1].x0-1)+x[1].height?max:(x[1].x0-1)+x[1].height;
	max=max>(a-x[b].x0)+x[b].height?max:(a-x[b].x0)+x[b].height;
	printf("%d",max);
}