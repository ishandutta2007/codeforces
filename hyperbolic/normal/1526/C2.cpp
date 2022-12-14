#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX (long long int)1e16

struct str{
	long long int value[800010];
	long long int lazy[800010];
	void addValue(int L, int R, int val, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) value[v] += val, lazy[v] += val;
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] += lazy[v], value[2*v+1] += lazy[v];
				lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			addValue(L,R,val,l,h,2*v);
			addValue(L,R,val,h+1,r,2*v+1);
			value[v] = value[2*v]<value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	long long int getMin(int L, int R, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return MAX;
		else if(R<l) return MAX;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] += lazy[v], value[2*v+1] += lazy[v];
				lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			long long int s1 = getMin(L,R,l,h,2*v);
			long long int s2 = getMin(L,R,h+1,r,2*v+1);
			return s1<s2?s1:s2;
		}
	}
}T;

int x[200010];
std::vector< std::pair<int,int> > V;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int ans = 0;
	for(int i=1;i<=a;i++)
	{
		if(x[i]<0) V.push_back({-x[i],i});
		else
		{
			ans++;
			T.addValue(i,a,x[i]);
		}
	}
	
	std::sort(V.begin(),V.end());
	for(int i=0;i<V.size();i++)
	{
		int val = V[i].first;
		int ind = V[i].second;
		T.addValue(ind,a,-val);
		if(T.getMin(1,a)<0) T.addValue(ind,a,val);
		else ans++;
	}
	
	printf("%d",ans);
}