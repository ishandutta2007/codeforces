#include <stdio.h>
#include <algorithm>
#include <vector>

struct str{
	long long int x0;
	long long int y0;
	int index;
}x[300010];
bool cmp1(str a, str b)
{
	return (a.x0-a.y0)<(b.x0-b.y0);
}

bool cmp2(str a, str b)
{
	return a.index<b.index;
}

std::vector<int> V[300010];
long long int sum[300010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%lld%lld",&x[i].x0,&x[i].y0);
	for(int i=1;i<=a;i++) x[i].index = i;
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
		V[d].push_back(c);
	}
	
	std::sort(x+1,x+a+1,cmp1);
	long long int S = 0;
	for(int i=1;i<=a;i++)
	{
		sum[x[i].index] += S;
		S += x[i].x0;
	}
	S = 0;
	for(int i=a;i>=1;i--)
	{
		sum[x[i].index] += S;
		S += x[i].y0;
	}
	for(int i=1;i<=a;i++)
	{
		sum[x[i].index] += (i-1)*x[i].y0;
		sum[x[i].index] += (a-i)*x[i].x0;
	}
	
	std::sort(x+1,x+a+1,cmp2);
	for(int i=1;i<=a;i++)
	{
		for(int j=0;j<V[i].size();j++)
		{
			if(x[i].x0+x[V[i][j]].y0<x[i].y0+x[V[i][j]].x0) sum[i] -= x[i].x0+x[V[i][j]].y0;
			else sum[i] -= x[i].y0+x[V[i][j]].x0;
		}
	}
	for(int i=1;i<=a;i++) printf("%lld ",sum[i]);
}