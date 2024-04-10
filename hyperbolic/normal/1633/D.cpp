#include <stdio.h>
#include <algorithm>
#define MIN -1234567890
int dist[1010];

int x[1010],y[1010];
int a,b;
int check[1010][12010];
int func(int s, int t)
{
	if(t>b) return MIN;
	if(s>a) return 0;
	if(check[s][t]!=-1) return check[s][t];
	
	int s1 = func(s+1,t);
	int s2 = func(s+1,t+dist[x[s]]) + y[s];
	return check[s][t] = s1>s2?s1:s2;
}
 
int main()
{
	for(int i=1;i<=1000;i++) dist[i] = 1234567;
	dist[1] = 0;
	for(int i=1;i<=1000;i++)
	{
		for(int j=1;j<=i;j++)
		{
			int t = i+(i/j);
			if(t<=1000)
			{
				dist[t] = dist[t]<dist[i]+1?dist[t]:dist[i]+1;
			}
		}
	}
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) scanf("%d",&y[i]);
		
		if(b>=12*a)
		{
			int sum = 0;
			for(int i=1;i<=a;i++) sum += y[i];
			printf("%d\n",sum);
		}
		else
		{
			for(int i=1;i<=a;i++) for(int j=0;j<=b;j++) check[i][j] = -1;
			printf("%d\n",func(1,0));
		}
		
 	}
}