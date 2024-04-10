#include <stdio.h>
#include <algorithm>
#define MAX 1234567890

struct segTree{
	int value[4000010];
	int lazy[4000010];
	void addValue(int L, int R, int val, int l=1, int r=1000000, int v=1)
	{
		if(L<=l&&r<=R) value[v] += val, lazy[v] += val;
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			value[2*v] += lazy[v], value[2*v+1] += lazy[v];
			lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
			lazy[v] = 0;
			addValue(L,R,val,l,h,2*v);
			addValue(L,R,val,h+1,r,2*v+1);
			value[v] = value[2*v]<value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	int getMin(int L, int R, int l=1, int r=1000000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return MAX;
		else if(R<l) return MAX;
		else
		{
			int h = (l+r)/2;
			value[2*v] += lazy[v], value[2*v+1] += lazy[v];
			lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
			lazy[v] = 0;
			int s1 = getMin(L,R,l,h,2*v);
			int s2 = getMin(L,R,h+1,r,2*v+1);
			return s1<s2?s1:s2;
		}
	}
}T;

struct str{
	int first;
	int second;
	int value;
}query[300010];
bool cmp(str a, str b)
{
	return a.value<b.value;
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		query[i] = {c,d-1,e};
	}
	std::sort(query+1,query+a+1,cmp);
	
	int p = 1;
	long long int ans = MAX;
	for(int i=1;i<=a;i++)
	{
		while(p<=a && T.getMin(1,b-1)==0)
		{
			T.addValue(query[p].first,query[p].second,1);
			p++;
		}
		
		if(T.getMin(1,b-1)>0)
		{
			long long int t = query[p-1].value - query[i].value;
			//printf("%d %lld??\n",query[i].value,t);
			ans = ans<t?ans:t;
		}
		T.addValue(query[i].first,query[i].second,-1);
	}
	printf("%lld",ans);
}