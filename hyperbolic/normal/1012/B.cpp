#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
struct str{
	int x0;
	int y0;
	int index;
}x[200010];
bool cmp1(str a, str b)
{
	return a.x0<b.x0;
}
bool cmp2(str a, str b)
{
	return a.y0<b.y0;
}
bool cmp3(str a, str b)
{
	return a.index<b.index;
}

std::vector<int> V[200010];
int check[200010];
void func(int k)
{
	check[k] = 1;
	for(int i=0;i<V[k].size();i++) if(check[V[k][i]]==0) func(V[k][i]);
}

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=c;i++)
	{
		scanf("%d%d",&x[i].x0,&x[i].y0);
		x[i].index = i;
	}
	if(c==0)
	{
		printf("%d",a+b-1);
		return 0;
	}
	
	int s = 1, t = 1;
	std::sort(x+1,x+c+1,cmp1);
	for(int i=2;i<=c;i++)
	{
		if(x[i].x0==x[i-1].x0)
		{
			V[x[i].index].push_back(x[i-1].index);
			V[x[i-1].index].push_back(x[i].index);
		}
		else s++;
	}
	std::sort(x+1,x+c+1,cmp2);
	for(int i=2;i<=c;i++)
	{
		if(x[i].y0==x[i-1].y0)
		{
			V[x[i].index].push_back(x[i-1].index);
			V[x[i-1].index].push_back(x[i].index);
		}
		else t++;
	}
	
	int count = 0;
	for(int i=1;i<=c;i++)
	{
		if(check[i]==0)
		{
			count++;
			func(i);
		}
	}
	if(a-s==0&&b-t==0) printf("%d",count-1);
	else printf("%d",(a-s)+(b-t)-1+count);
}