#include <stdio.h>
#include <set>
#include <algorithm>
#include <vector>
#define MAX 1234567890
#include <map>

struct str{
	int first;
	int second;
	int color;
	int index;
}x[400010];

std::vector<int> event[400010];
int ans[400010],check[400010];
std::set< std::pair<int,int> > S;

std::vector<int> index;
std::map<int,int> hash;

int sum[400010];
std::vector<int> V[400010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		index.clear();
		hash.clear();
		
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++)
		{
			int b,c,d;
			scanf("%d%d%d",&b,&c,&d);
			x[i] = {b,c,d,i};
			index.push_back(b);
			index.push_back(c);
		}
		for(int i=1;i<=a;i++) ans[i] = MAX;
		std::sort(index.begin(),index.end());
		index.erase(std::unique(index.begin(),index.end()),index.end());
		for(int i=0;i<index.size();i++) hash[index[i]] = i+1;
		
		
		S.clear();
		for(int i=1;i<=a;i++) check[i] = -1;
		for(int i=1;i<=2*a;i++) event[i].clear();
		for(int i=1;i<=a;i++) event[hash[x[i].second]].push_back(i);
		
		for(int k=2*a;k>=1;k--)
		{
			for(int j=0;j<event[k].size();j++)
			{
				int t = event[k][j];
				if(check[x[t].color]==-1)
				{
					check[x[t].color] = x[t].first;
					S.insert(std::make_pair(check[x[t].color],x[t].color));
				}
				else if(check[x[t].color]>x[t].first)
				{
					S.erase(std::make_pair(check[x[t].color],x[t].color));
					check[x[t].color] = x[t].first;
					S.insert(std::make_pair(check[x[t].color],x[t].color));
				}			
			}
			
			for(int j=0;j<event[k].size();j++)
			{
				int i = event[k][j];
				std::set< std::pair<int,int> > :: iterator it,it2;
				
				if(!S.empty())
				{
					it = S.begin();
					if((it->second)==x[i].color)
					{
						it++;
						if(it==S.end()) goto u;
					}
					
					if(it->first <= x[i].second) ans[x[i].index] = 0;
					else ans[x[i].index] = ans[x[i].index] < (it->first)-x[i].second? ans[x[i].index] : (it->first)-x[i].second;
				}
				u:;
			}
		}
		
		S.clear();
		for(int i=1;i<=a;i++) check[i] = -1;
		for(int i=1;i<=2*a;i++) event[i].clear();
		for(int i=1;i<=a;i++) event[hash[x[i].first]].push_back(i);
		
		for(int k=1;k<=2*a;k++)
		{
			for(int j=0;j<event[k].size();j++)
			{
				int i = event[k][j];
				
				if(check[x[i].color]==-1)
				{
					check[x[i].color] = x[i].second;
					S.insert(std::make_pair(check[x[i].color],x[i].color));
				}
				else if(check[x[i].color]<x[i].second)
				{
					S.erase(std::make_pair(check[x[i].color],x[i].color));
					check[x[i].color] = x[i].second;
					S.insert(std::make_pair(check[x[i].color],x[i].color));
				}
			}
			
			for(int j=0;j<event[k].size();j++)
			{
				int i = event[k][j];
				std::set< std::pair<int,int> > :: iterator it,it2;
				
				if(!S.empty())
				{
					it = S.end();
					it--;
					if((it->second)==x[i].color)
					{
						if(it==S.begin()) goto u2;
						else it--;
					}
					
					if(it->first >= x[i].first) ans[x[i].index] = 0;
					else ans[x[i].index] = ans[x[i].index] < x[i].first-(it->first)? ans[x[i].index] : x[i].first-(it->first);
				}
				u2:;
			}
		}
		
		for(int i=0;i<=2*a;i++) sum[i] = 0;
		for(int i=1;i<=a;i++) V[i].clear();
		
		for(int i=1;i<=a;i++)
		{
			int s = hash[x[i].first];
			int t = hash[x[i].second];
			sum[s]++;
			sum[t]++;
			V[x[i].color].push_back(s);
			V[x[i].color].push_back(t);
		}
		for(int i=1;i<=2*a;i++) sum[i] += sum[i-1];
		for(int i=1;i<=a;i++) std::sort(V[i].begin(),V[i].end());
		
		for(int i=1;i<=a;i++)
		{
			int L = hash[x[i].first], R = hash[x[i].second];
			int min,max;
			int l,r;
			
			min = 0, max = V[x[i].color].size()-1;
			while(min<=max)
			{
				int h = (min+max)/2;
				if(V[x[i].color][h]>=L)
				{
					l = h;
					max = h-1;
				}
				else min = h+1;
			}
			min = 0, max = V[x[i].color].size()-1;
			while(min<=max)
			{
				int h = (min+max)/2;
				if(V[x[i].color][h]<=R)
				{
					r = h;
					min = h+1;
				}
				else max = h-1;
			}
			
			if(sum[R]-sum[L-1]!=(r-l+1)) ans[i] = 0;
 		}
		
		
		for(int i=1;i<=a;i++) printf("%d ",ans[i]);
		printf("\n");
	}
}