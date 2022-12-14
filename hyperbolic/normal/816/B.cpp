#include <stdio.h>
int x[200010],y[200010];
int z[200010],p=1;
int upper(int k)
{
	int min = 1, max = p;
	int ans = 0;
	while(min<=max)
	{
		int h = (min+max)/2;
		if(z[h]>k) max = h-1;
		else ans = h, min = h+1;
	}
	return ans;
}
int lower(int k)
{
	int min = 1, max = p;
	int ans = p+1;
	while(min<=max)
	{
		int h = (min+max)/2;
		if(z[h]<k) min = h+1;
		else ans = h, max = h-1;
	}
	return ans;
}
int main()
{
	int a,b,c,d,e;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++)
	{
		scanf("%d%d",&d,&e);
		y[d]++, y[e+1]--;
	}
	for(int i=1;i<=200000;i++) x[i] = x[i-1]+y[i];
	for(int i=1;i<=200000;i++) if(x[i]>=b) z[p++] = i;
	p--;
	for(int i=1;i<=c;i++)
	{
		scanf("%d%d",&d,&e);
		printf("%d\n",upper(e)-lower(d)+1);
	}
}