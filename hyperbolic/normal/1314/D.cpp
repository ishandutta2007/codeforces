#include <stdio.h>
#include <vector>
#include <set>

long long int MAX = 1;
std::vector<int> V;

struct str{
	int x0;
	int y0;
};
bool operator<(str a, str b)
{
	if(a.x0==b.x0) return a.y0<b.y0;
	return a.x0<b.x0;
}
std::set<str> x[110][110];

long long int cost[110][110];
int check[110],a;
long long int func()
{
	for(int i=0;i<V.size();i++) check[V[i]] = 1;
	long long int ans = 0;
	for(int i=0;i<V.size()-1;i++)
	{
		int s = V[i];
		int t = V[i+1];
		
		int S = MAX;
		for(std::set<str> ::iterator it = x[s][t].begin();it!=x[s][t].end();it++)
		{
			int x0 = it->x0;
			int y0 = it->y0;
			if(check[y0]) continue;
			else
			{
				S = x0;
				break;
			}
		}
		ans += S;
	}
	for(int i=0;i<V.size();i++) check[V[i]] = 0;
	return ans;
}

long long int y[10];
int main()
{
	for(int i=1;i<=16;i++) MAX*=10;
	int b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) scanf("%d",&cost[i][j]);
	for(int i=1;i<=a;i++) cost[i][i] = MAX;
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++)
		{
			for(int k=1;k<=a;k++)
			{
				x[i][j].insert({cost[i][k]+cost[k][j],k});
			}
		}
	}
	int i1,i2,i3,i4;
	
	for(int i=1;i<=5;i++) y[i] = MAX;
	V.push_back(1);
	for(int i1=1;i1<=a+1;i1++)
	{
		if(i1<=a) V.push_back(i1);
		for(int i2=1;i2<=a+1;i2++)
		{
			if(i2<=a) V.push_back(i2);
			for(int i3=1;i3<=a+1;i3++)
			{
				if(i3<=a) V.push_back(i3);
				for(int i4=1;i4<=a+1;i4++)
				{
					if(i4<=a) V.push_back(i4);
					V.push_back(1);
					
					long long int C = func();
					y[V.size()-1] = y[V.size()-1]<C?y[V.size()-1]:C;
					
					V.pop_back();
					if(i4<=a) V.pop_back();
				}
				if(i3<=a) V.pop_back();
			}
			if(i2<=a) V.pop_back();
		}
		if(i1<=a) V.pop_back();
	}
	
	printf("%lld",y[b/2]);
}