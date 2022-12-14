#include <stdio.h>
#include <algorithm>
struct str{
	int time;
	int limit;
	int price;
	int index;
}x[110];
bool cmp(str a, str b)
{
	if(a.limit==b.limit)
	{
		if(a.time==b.time) return a.price>b.price;
		return a.time<b.time;
	}
	return a.limit<b.limit;
}
int next[110][2010],a;
int save[110];
int check[110][2010];
int func(int s, int t)
{
	int ans = 0;
	if(s>a) return 0;
	if(check[s][t]!=-1) return check[s][t];
	for(int i=s;i<=a;i++)
	{
		if(x[i].time+t<x[i].limit)
		{
			int S = func(i+1,t+x[i].time)+x[i].price;
			if(S>ans)
			{
				ans = S;
				next[s][t] = i;
			}
		}
	}
	return check[s][t] = ans;
}
int main()
{
	scanf("%d",&a);
	for(int i=0;i<=a;i++) for(int j=0;j<=20*a;j++) check[i][j] = -1;
	for(int i=1;i<=a;i++) scanf("%d%d%d",&x[i].time,&x[i].limit,&x[i].price);
	for(int i=1;i<=a;i++) x[i].index = i;
	std::sort(x+1,x+a+1,cmp);
	printf("%d\n",func(1,0));
	
	int s = 1, t = 0;
	int count = 0;
	while(next[s][t]!=0)
	{
		count++;
		save[count] = x[next[s][t]].index;
		int s1 = next[s][t]+1;
		int t1 = t+x[next[s][t]].time;
		s = s1, t = t1;
	}
	printf("%d\n",count);
	for(int i=1;i<=count;i++) printf("%d ",save[i]);
}