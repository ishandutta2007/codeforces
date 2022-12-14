#include <stdio.h>
#include <vector>
#include <algorithm>

int check[100010],check2[100010];
int value[100010];
int prev[100010];
int height[100010];
std::vector< std::pair<int,int> > V[100010];
std::vector<int> cycle;
void func(int k, int p, int h, int val)
{
	check[k] = 1;
	value[k] = val;
	prev[k] = p;
	height[k] = h;
	for(int i=0;i<V[k].size();i++)
	{
		if(check[V[k][i].first]==1) cycle.push_back((V[k][i].second^value[k]^value[V[k][i].first]));
		else func(V[k][i].first,k,h+1,val^V[k][i].second);
	}
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		V[c].push_back({d,e});
		V[d].push_back({c,e});
	}
	
	func(1,0,1,0);
	
	for(int i=30;i>=0;i--)
	{
		for(int j=0;j<cycle.size();j++)
		{
			if(check2[j]) continue;
			if((cycle[j]&(1<<i))!=0)
			{
				check2[j] = 1;
				for(int k=0;k<cycle.size();k++)
				{
					if(j==k) continue;
					if((cycle[k]&(1<<i))!=0) cycle[k] ^= cycle[j];
				}
				break;
			}
		}
	}
	std::sort(cycle.begin(),cycle.end());
	
	int ans = value[a];
	for(int i=cycle.size()-1;i>=0;i--)
	{
		int val = (ans^cycle[i]);
		if(ans>val) ans = val;
	}
	printf("%d",ans);
}