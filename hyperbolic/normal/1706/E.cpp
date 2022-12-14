#include <stdio.h>
#include <vector>
#include <algorithm>

struct segTree{
	int value[800010];
	void setValue(int ind, int val, int l=1, int r=200000, int v=1)
	{
		if(l==r) value[v] = val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v]>value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	int getMax(int L, int R, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(R<l) return 0;
		else if(r<L) return 0;
		else
		{
			int h = (l+r)/2;
			int s1 = getMax(L,R,l,h,2*v);
			int s2 = getMax(L,R,h+1,r,2*v+1);
			return s1>s2?s1:s2;
		}
	}
}T;

int next[200010],size[200010];
int ans[200010];
std::pair<int,int> edge[200010];
void func(int L, int R, std::vector<int> &index)
{
	if(L>R) return;
	int h = (L+R)/2;
	std::vector< std::pair<int,int> > save;
	for(int i=L;i<=h;i++)
	{
		int s = edge[i].first, t = edge[i].second;
		while(next[s]!=s) s = next[s];
		while(next[t]!=t) t = next[t];
		if(s==t) continue;
		if(size[s]<size[t])
		{
			next[s] = t;
			size[t] += size[s];
			save.push_back(std::make_pair(s,t));
		}
		else
		{
			next[t] = s;
			size[s] += size[t];
			save.push_back(std::make_pair(t,s));
		}
	}
	
	std::vector<int> index1, index2;
	for(int i=0;i<index.size();i++)
	{
		int s = index[i];
		int t = s+1;
		while(next[s]!=s) s = next[s];
		while(next[t]!=t) t = next[t];
		if(s==t)
		{
			ans[index[i]] = h;
			index1.push_back(index[i]);
		}
		else index2.push_back(index[i]);
	}
	index.clear();
	
	func(h+1,R,index2);
	
	while(!save.empty())
	{
		int s = save.back().first;
		int t = save.back().second;
		save.pop_back();
		size[t] -= size[s];
		next[s] = s;
	}
	
	func(L,h-1,index1);
}

std::vector<int> index;
int main()
{
	int Case;
	scanf("%d",&Case);
	while(Case--)
	{
		index.clear();
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		for(int i=1;i<=a;i++) next[i] = i;
		for(int i=1;i<=a;i++) size[i] = 1;
		
		for(int i=1;i<=b;i++)
		{
			int d,e;
			scanf("%d%d",&d,&e);
			edge[i] = std::make_pair(d,e);
		}
		for(int i=1;i<a;i++) index.push_back(i);
		func(1,b,index);
		for(int i=1;i<a;i++) T.setValue(i,ans[i]);
		
		for(int i=1;i<=c;i++)
		{
			int d,e;
			scanf("%d%d",&d,&e);
			if(d==e) printf("0\n");
			else printf("%d\n",T.getMax(d,e-1));
		}
	}
}