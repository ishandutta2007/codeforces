#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>

struct segTree{
	int value[4000010];
	void setValue(int ind, int val, int l=1, int r=1000001, int v=1)
	{
		if(l==r) value[v] = value[v]>val?value[v]:val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v]>value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	int getMax(int L, int R, int l=1, int r=1000001, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			int s1 = getMax(L,R,l,h,2*v);
			int s2 = getMax(L,R,h+1,r,2*v+1);
			return s1>s2?s1:s2;
		}
	}
}T;

std::pair<int,int> x[2010];
std::vector<int> V2;
std::multiset<int> S;
std::vector< std::pair<int,int> > query[1000010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d%d",&x[i].first,&x[i].second);
	for(int i=1;i<=a;i++)
	{
		x[i].first++;
		x[i].second++;
	}
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		T.setValue(c+1,d+1);
		V2.push_back(c+2);
	}
	std::sort(V2.begin(),V2.end());
	V2.erase(std::unique(V2.begin(),V2.end()),V2.end());
	
	for(int i=1;i<=a;i++)
	{
		int t = T.getMax(x[i].first,1000001);
		if(t<x[i].second) continue;
		
		int p = t - x[i].second + 1;
		query[0].push_back(std::make_pair(1,p));
		for(int j=0;j<V2.size();j++)
		{
			if(V2[j]>x[i].first)
			{
				query[V2[j]-x[i].first].push_back(std::make_pair(0,p));
				t = T.getMax(V2[j],1000001);
				if(t<x[i].second) break;
				
				p = t - x[i].second + 1;
				query[V2[j]-x[i].first].push_back(std::make_pair(1,p));
			}
		}
	}
	
	
	std::multiset<int> ::iterator it;
	for(int i=0;i<query[0].size();i++) if(query[0][i].first==1) S.insert(query[0][i].second);
	int ans;
	if(!S.empty())
	{
		it = S.end();
		it--;
		ans = (*it);
	}
	else ans = 0;
	for(int i=1;i<=1000001;i++)
	{
		for(int j=0;j<query[i].size();j++)
		{
			if(query[i][j].first==1) S.insert(query[i][j].second);
			else
			{
				it = S.find(query[i][j].second);
				S.erase(it);
			}
		}
		if(!S.empty())
		{
			it = S.end();
			it--;
			ans = ans<(*it)+i?ans:(*it)+i;
		}
		else ans = ans<i?ans:i;
	}
	printf("%d",ans);
}