#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

struct segTree{
	int value[1600010];
	int lazy[1600010];
	void setValue(int L, int R, int val, int l=0, int r=400000, int v=1)
	{
		if(L<=l&&r<=R) value[v] = (r-l+1)*val, lazy[v] = val;
		else if(r<L) return;
		else if(R<l) return;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=-1)
			{
				value[2*v] = (h-l+1)*lazy[v], lazy[2*v] = lazy[v];
				value[2*v+1] = (r-h)*lazy[v], lazy[2*v+1] = lazy[v];
				lazy[v] = -1;
			}
			setValue(L,R,val,l,h,2*v);
			setValue(L,R,val,h+1,r,2*v+1);
			value[v] = value[2*v] + value[2*v+1];
		}
	}
	int getSum(int L, int R, int l=0, int r=400000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(R<l) return 0;
		else if(r<L) return 0;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=-1)
			{
				value[2*v] = (h-l+1)*lazy[v], lazy[2*v] = lazy[v];
				value[2*v+1] = (r-h)*lazy[v], lazy[2*v+1] = lazy[v];
				lazy[v] = -1;
			}
			return getSum(L,R,l,h,2*v) + getSum(L,R,h+1,r,2*v+1);
		}
	}
}T;

struct str{
	int x1;
	int y1;
	int x2;
	int y2;
}x[100010];
bool cmp1(str a, str b)
{
	return a.y1<b.y1;
}
bool cmp2(str a, str b)
{
	return a.y2<b.y2;
}
std::vector<int> index;
std::map<int,int> hash;
std::vector<int> V[100010];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c,d,e;
		scanf("%d%d%d%d",&b,&c,&d,&e);
		x[i]={b,c,d,e};
		index.push_back(b);
		index.push_back(c);
		index.push_back(d);
		index.push_back(e);
	}
	std::sort(index.begin(),index.end());
	index.erase(std::unique(index.begin(),index.end()),index.end());
	for(int i=0;i<index.size();i++) hash[index[i]] = i;
	for(int i=1;i<=a;i++)
	{
		x[i].x1 = hash[x[i].x1];
		x[i].y1 = hash[x[i].y1];
		x[i].x2 = hash[x[i].x2];
		x[i].y2 = hash[x[i].y2];
	}
	
	std::sort(x+1,x+a+1,cmp1);
	for(int i=1;i<=a;i++)
	{
		int min = 1, max = i-1;
		int p = 0;
		while(min<=max)
		{
			int h = (min+max)/2;
			if(x[h].y1<x[i].x1)
			{
				p = h;
				min = h+1;
			}
			else max = h-1;
		}
		V[p].push_back(i);
	}
	
	for(int i=1;i<=a;i++)
	{
		T.setValue(x[i].x2,x[i].y2,1);
		for(int j=0;j<V[i].size();j++)
		{
			if(T.getSum(x[V[i][j]].x2,x[V[i][j]].y2)>0)
			{
				printf("NO");
				return 0;
			}
		}
	}
	
	for(int i=0;i<=a;i++) V[i].clear();
	T.setValue(1,4*a,0);
	
	std::sort(x+1,x+a+1,cmp2);
	for(int i=1;i<=a;i++)
	{
		int min = 1, max = i-1;
		int p = 0;
		while(min<=max)
		{
			int h = (min+max)/2;
			if(x[h].y2<x[i].x2)
			{
				p = h;
				min = h+1;
			}
			else max = h-1;
		}
		V[p].push_back(i);
	}
	
	for(int i=1;i<=a;i++)
	{
		T.setValue(x[i].x1,x[i].y1,1);
		for(int j=0;j<V[i].size();j++)
		{
			if(T.getSum(x[V[i][j]].x1,x[V[i][j]].y1)>0)
			{
				printf("NO");
				return 0;
			}
		}
	}
	printf("YES");
}