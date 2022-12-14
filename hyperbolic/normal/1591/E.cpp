#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
#include <set>

std::set<int> S[1000010];
std::vector<int> V[1000010];

struct str{
	int x0;
	int y0;
	int index;
	int ans;
};
std::vector<str> query[1000010];


struct segTree{
	int value[4000010];
	void addValue(int ind ,int val, int l=0, int r=1000000, int v=1)
	{
		if(l==r) value[v] += val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) addValue(ind,val,l,h,2*v);
			else addValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v]+value[2*v+1];
		}
	}
	int getSum(int L, int R, int l=0, int r=1000000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			int s1 = getSum(L,R,l,h,2*v);
			int s2 = getSum(L,R,h+1,r,2*v+1);
			return s1+s2;
		}
	}
	
	int lower(int val, int l=0, int r=1000000, int v=1)
	{
		if(value[v]<val) return -1;
		else if(l==r) return r;
		else
		{
			int h = (l+r)/2;
			int t = value[2*v];
			if(t>=val) return lower(val,l,h,2*v);
			else return lower(val-t,h+1,r,2*v+1);
		}
	}
}T;

int a;
int x[1000010];
int count[1000010];
void func(int k, int prev)
{
	T.addValue(count[x[k]],-1);
	S[count[x[k]]].erase(x[k]);
	count[x[k]]++;
	S[count[x[k]]].insert(x[k]);
	T.addValue(count[x[k]],1);
	
	for(int i=0;i<query[k].size();i++)
	{
		/*
		int min = query[k][i].x0;
		int max = a;
		int ans = a+1;
		while(min<=max)
		{
			int h = (min+max)/2;
			if(T.getSum(query[k][i].x0,h)>=query[k][i].y0)
			{
				ans = h;
				max = h-1;
			}
			else min = h+1;
		}
		*/
		
		int ans = T.lower(query[k][i].y0 + T.getSum(0,query[k][i].x0-1));
		if(ans==-1) query[k][i].ans = -1;
		else query[k][i].ans = (*S[ans].begin());
	}
	
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		func(V[k][i],k);
	}
	
	T.addValue(count[x[k]],-1);
	S[count[x[k]]].erase(x[k]);
	count[x[k]]--;
	S[count[x[k]]].insert(x[k]);
	T.addValue(count[x[k]],1);
}

int check[1000010];
std::vector<int> index;

int main()
{
	int Case;
	scanf("%d",&Case);
	while(Case--)
	{
		int b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) index.push_back(x[i]);
		std::sort(index.begin(),index.end());
		index.erase(std::unique(index.begin(),index.end()),index.end());
		for(int i=0;i<index.size();i++) S[0].insert(index[i]);
		T.addValue(0,a);
		
		for(int i=1;i<a;i++)
		{
			int c;
			scanf("%d",&c);
			V[c].push_back(i+1);
		}
		
		for(int i=1;i<=b;i++)
		{
			int c,d,e;
			scanf("%d%d%d",&c,&d,&e);
			query[c].push_back({d,e,i});
		}
		
		func(1,0);
		
		for(int i=1;i<=a;i++) for(int j=0;j<query[i].size();j++) check[query[i][j].index] = query[i][j].ans;
		
		for(int i=1;i<=b;i++) printf("%d ",check[i]);
		printf("\n");
		
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=1;i<=a;i++) query[i].clear();
		for(int i=0;i<=a;i++) S[i].clear();
		for(int i=0;i<=a;i++) count[i] = 0;
		index.clear();
		T.addValue(0,-a);
	}
}