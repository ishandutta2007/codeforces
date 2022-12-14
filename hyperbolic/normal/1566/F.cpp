#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#define MAX (long long int)1e12
#define SIZE 1000000

struct str{
	long long int value[4*SIZE+10];
	void setValue(int ind, long long int val, int l=0, int r=SIZE, int v=1)
	{
		if(l==r)
		{
			if(val==MAX) value[v] = MAX;
			else value[v] = value[v]<val?value[v]:val;
		}
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v]<value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	long long int getMin(int L, int R, int l=0, int r=SIZE, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return MAX;
		else if(R<l) return MAX;
		else
		{
			int h = (l+r)/2;
			long long int s1 = getMin(L,R,l,h,2*v);
			long long int s2 = getMin(L,R,h+1,r,2*v+1);
			return s1<s2?s1:s2;
		}
	}
}T;

std::vector<long long int> index;
std::map<long long int,int> hash;
std::set<long long int> S,S2;
std::vector< std::pair<int,int> > edge;

long long int check[SIZE+10][3];
long long int func(int k, int C) // k : event 
{
	if(k==index.size()) return 0;
	if(check[k][C]!=-1) return check[k][C];
	
	long long int s1, s2;
	s1 = func(k+1,C) + C*(index[k]-index[k-1]);
	
	std::set<long long int> ::iterator it = S.lower_bound(index[k]);
	if(it==S.end()) return 0;
	
	long long int start = (*it);
	long long int end = T.getMin(k,index.size());
	
	std::set<long long int> ::iterator it2 = S2.upper_bound(start);
	if(it2!=S2.begin())
	{
		it2--;
		long long int val = (*it2);
		
		if(val>index[k-1])
		{
			s2 = func(hash[start+1],1) + (start-val);
			s1 = s1<s2?s1:s2;
		}
	}
	it2 = S2.lower_bound(end+1);
	if(it2!=S2.end())
	{
		long long int val = (*it2);
		s2 = func(hash[val+1],1) + 2*(val-end);
		s1 = s1<s2?s1:s2;
		s2 = func(hash[val+1],2) + (val-end);
		s1 = s1<s2?s1:s2;
	}
	return check[k][C] = s1;
}

int x[200010];
int main()
{
	int Case;
	scanf("%d",&Case);
	while(Case--)
	{
		S.clear();
		S2.clear();
		edge.clear();
		index.clear();
		hash.clear();
		
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) S2.insert(x[i]);
		for(int i=1;i<=b;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			std::set<long long int> ::iterator it = S2.lower_bound(c);
			if(it!=S2.end())
			{
				if((*it)<=d) continue;
			}
			edge.push_back(std::make_pair(c,d));
		}
		
		for(int i=0;i<edge.size();i++) S.insert(edge[i].first);
		for(int i=1;i<=a;i++)
		{
			index.push_back(x[i]);
			index.push_back(x[i]+1);
		}
		for(int i=0;i<edge.size();i++)
		{
			index.push_back(edge[i].first);
			index.push_back(edge[i].first+1);
			index.push_back(edge[i].second+1);
			
		}
		index.push_back(-MAX);
		std::sort(index.begin(),index.end());
		index.erase(std::unique(index.begin(),index.end()),index.end());
		
		for(int i=0;i<index.size();i++) hash[index[i]] = i;
		
		for(int i=0;i<=index.size();i++) T.setValue(i,MAX);
		for(int i=0;i<edge.size();i++) T.setValue(hash[edge[i].first],edge[i].second);
		
		for(int i=0;i<=index.size();i++) for(int j=0;j<=2;j++) check[i][j] = -1;
		
		printf("%lld\n",func(1,1));
	}
}