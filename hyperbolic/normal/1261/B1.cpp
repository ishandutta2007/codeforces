#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

struct segTree{
	int value[800010];
	void addValue(int ind, int val, int l=1, int r=200000, int v=1)
	{
		if(l==r) value[v] += val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) addValue(ind,val,l,h,2*v);
			else addValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v] + value[2*v+1];
		}
	}
	int find(int ind, int l=1, int r=200000, int v=1)
	{
		if(l==r) return l;
		else
		{
			int h = (l+r)/2;
			if(value[2*v]>=ind) return find(ind,l,h,2*v);
			else return find(ind-value[2*v],h+1,r,2*v+1);
		}
	}
}T;

struct str{
	int first;
	int second;
	int index;
	int ans;
}query[200010];
bool cmp(str a, str b)
{
	return a.first<b.first;
}
bool cmp2(str a, str b)
{
	return a.index<b.index;
}

std::priority_queue< std::pair<int,int> > Q;
int x[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) Q.push(std::make_pair(x[i],200000-i));
	int b;
	scanf("%d",&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		query[i] = {c,d,i,-1};
	}
	std::sort(query+1,query+b+1,cmp);
	int p = 1;
	for(int i=1;i<=a;i++)
	{
		std::pair<int,int> P = Q.top();
		Q.pop();
		
		T.addValue(200000-P.second,1);
		while(p<=b&&query[p].first==i)
		{
			query[p].ans = T.find(query[p].second);
			p++;
		}
	}
	std::sort(query+1,query+b+1,cmp2);
	for(int i=1;i<=b;i++) printf("%d\n",x[query[i].ans]);
}