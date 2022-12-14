#include <stdio.h>
#define MIN -12345678
struct str{
	int time;
	int first;
	int second;
}x[100010];

int abs(int k)
{
	return k>0?k:-k;
}

int ans[100010];
int max[100010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		x[i]={c,d,e};
	}
	x[0]={0,1,1};
	ans[0] = 0;
	for(int i=1;i<=b;i++)
	{
		int S = MIN;
		int p = 0>i-1000?0:i-1000;
		for(int j=p;j<i;j++) if(abs(x[i].first-x[j].first)+abs(x[i].second-x[j].second)<=x[i].time-x[j].time) S = S>ans[j]?S:ans[j];
		ans[i] = S;
		if(i-1000>=1) ans[i] = ans[i]>max[i-1001]?ans[i]:max[i-1001];
		ans[i]++;
		max[i] = max[i-1]>ans[i]?max[i-1]:ans[i];
	}
	
	int t = ans[0];
	for(int i=1;i<=b;i++) t = t>ans[i]?t:ans[i];
	printf("%d",t);
}