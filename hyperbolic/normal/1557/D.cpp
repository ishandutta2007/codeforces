#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#define MAX 12345678

struct segTree{
	int value1[2400010],value2[2400010];
	int lazy1[2400010],lazy2[2400010];
	void setValue2(int L, int R, int val, int l=1, int r=600000, int v=1)
	{
		if(L<=l&&r<=R) value1[v] = val, lazy1[v] = val;
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			if(lazy1[v]!=-1)
			{
				value1[2*v] = lazy1[v], value1[2*v+1] = lazy1[v];
				lazy1[2*v] = lazy1[v], lazy1[2*v+1] = lazy1[v];
				lazy1[v] = -1;
			}
			if(lazy2[v]!=-1)
			{
				value2[2*v] = lazy2[v], value2[2*v+1] = lazy2[v];
				lazy2[2*v] = lazy2[v], lazy2[2*v+1] = lazy2[v];
				lazy2[v] = -1;
			}
			setValue2(L,R,val,l,h,2*v);
			setValue2(L,R,val,h+1,r,2*v+1);
			if(value1[2*v]>value1[2*v+1])
			{
				value1[v] = value1[2*v];
				value2[v] = value2[2*v];
			}
			else
			{
				value1[v] = value1[2*v+1];
				value2[v] = value2[2*v+1];
			}
		}
	}
	void setValue(int L, int R, int val, int l=1, int r=600000, int v=1)
	{
		if(L<=l&&r<=R) value2[v] = val, lazy2[v] = val;
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			if(lazy1[v]!=-1)
			{
				value1[2*v] = lazy1[v], value1[2*v+1] = lazy1[v];
				lazy1[2*v] = lazy1[v], lazy1[2*v+1] = lazy1[v];
				lazy1[v] = -1;
			}
			if(lazy2[v]!=-1)
			{
				value2[2*v] = lazy2[v], value2[2*v+1] = lazy2[v];
				lazy2[2*v] = lazy2[v], lazy2[2*v+1] = lazy2[v];
				lazy2[v] = -1;
			}
			setValue(L,R,val,l,h,2*v);
			setValue(L,R,val,h+1,r,2*v+1);
			if(value1[2*v]>value1[2*v+1])
			{
				value1[v] = value1[2*v];
				value2[v] = value2[2*v];
			}
			else
			{
				value1[v] = value1[2*v+1];
				value2[v] = value2[2*v+1];
			}
		}
	}
	std::pair<int,int> getMax(int L, int R, int l=1, int r=600000, int v=1)
	{
		if(L<=l&&r<=R) return std::make_pair(value1[v],value2[v]);
		else if(r<L) return std::make_pair(-1,0);
		else if(R<l) return std::make_pair(-1,0);
		else
		{
			int h = (l+r)/2;
			if(lazy1[v]!=-1)
			{
				value1[2*v] = lazy1[v], value1[2*v+1] = lazy1[v];
				lazy1[2*v] = lazy1[v], lazy1[2*v+1] = lazy1[v];
				lazy1[v] = -1;
			}
			if(lazy2[v]!=-1)
			{
				value2[2*v] = lazy2[v], value2[2*v+1] = lazy2[v];
				lazy2[2*v] = lazy2[v], lazy2[2*v+1] = lazy2[v];
				lazy2[v] = -1;
			}
			std::pair<int,int> P1 = getMax(L,R,l,h,2*v);
			std::pair<int,int> P2 = getMax(L,R,h+1,r,2*v+1);
			return P1>P2?P1:P2;
		}
	}
}T;

std::vector<int> V;
std::vector<int> index;
std::map<int,int> hash;
std::vector< std::pair<int,int> > query[300010];
int check[300010],prev[300010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		index.push_back(d);
		index.push_back(e);
		query[c].push_back(std::make_pair(d,e));
	}
	std::sort(index.begin(),index.end());
	index.erase(std::unique(index.begin(),index.end()),index.end());
	for(int i=0;i<index.size();i++) hash[index[i]] = i+1;
	
	int n = index.size();
	for(int i=1;i<=a;i++)
	{
		std::pair<int,int> ans = std::make_pair(-1,0);
		for(int j=0;j<query[i].size();j++)
		{
			int l = hash[query[i][j].first];
			int r = hash[query[i][j].second];
			std::pair<int,int> P = T.getMax(l,r);
			if(ans<P) ans = P;
		}
		prev[i] = ans.second;
		for(int j=0;j<query[i].size();j++)
		{
			int l = hash[query[i][j].first];
			int r = hash[query[i][j].second];
			T.setValue2(l,r,ans.first+1);
			T.setValue(l,r,i);
		}
	}
	
	std::pair<int,int> P = T.getMax(1,n);
	int p = P.second;
	while(p>0)
	{
		check[p] = 1;
		p = prev[p];
	}
	
	for(int i=1;i<=a;i++) if(check[i]==0) V.push_back(i);
	printf("%d\n",V.size());
	for(int i=0;i<V.size();i++) printf("%d ",V[i]);
}