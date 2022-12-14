#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

std::vector<int> index;
std::map<int,int> hash;

std::vector< std::pair<int,int> > V1[400010],V2[400010];
std::vector<int> V3;

std::pair<int,int> x[200010];
int next[200010],value[200010];
int find(int k)
{
	if(k==next[k]) return k;
	else return next[k] = find(next[k]);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		index.clear();
		hash.clear();
		
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=0;i<=2*a;i++) V1[i].clear();
		for(int i=0;i<=2*a;i++) V2[i].clear();
		V3.clear();
		
		for(int i=1;i<=a;i++) next[i] = i;
		for(int i=1;i<=a;i++)
		{
			int c,d,e;
			scanf("%d%d%d",&c,&d,&e);
			value[i] = e;
			x[i] = std::make_pair(c,d);
			index.push_back(c);
			index.push_back(d);
		}
		std::sort(index.begin(),index.end());
		index.erase(std::unique(index.begin(),index.end()),index.end());
		for(int i=0;i<index.size();i++) hash[index[i]] = i;
		
		for(int i=1;i<=a;i++)
		{
			V1[hash[x[i].first]].push_back(std::make_pair(x[i].second,i));
			V2[hash[x[i].second]].push_back(std::make_pair(x[i].first,i));
		}
		
		for(int i=0;i<=2*a;i++) std::sort(V1[i].begin(),V1[i].end());
		for(int i=0;i<=2*a;i++) std::sort(V2[i].begin(),V2[i].end());
		
		for(int i=0;i<=2*a;i++)
		{
			for(int j=0;j+1<V1[i].size();j++)
			{
				if(V1[i][j+1].first - V1[i][j].first <= b)
				{
					int s = find(V1[i][j+1].second);
					int t = find(V1[i][j].second);
					if(value[s]<value[t]) next[t] = s;
					else next[s] = t;
				}
			}
		}
		for(int i=0;i<=2*a;i++)
		{
			for(int j=0;j+1<V2[i].size();j++)
			{
				if(V2[i][j+1].first - V2[i][j].first <= b)
				{
					int s = find(V2[i][j+1].second);
					int t = find(V2[i][j].second);
					if(value[s]<value[t]) next[t] = s;
					else next[s] = t;
				}
			}
		}
		
		for(int i=1;i<=a;i++) if(i==find(i)) V3.push_back(value[i]);
		std::sort(V3.begin(),V3.end());
		
		if(V3.size()<=1)
		{
			printf("0\n");
			continue;
		}
		
		int ans = V3.size()-1;
		for(int i=0;i<V3.size();i++)
		{
			int s1 = ((int)V3.size()-i-2);
			s1 = s1>V3[i]?s1:V3[i];
			ans = ans<s1?ans:s1;
		}
		printf("%d\n",ans);
	}
}