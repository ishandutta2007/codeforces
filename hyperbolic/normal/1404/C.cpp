#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX 123456789

struct segTree1{
	int value[1200010];
	int lazy[1200010];
	int index[1200010];
	void addValue(int L, int R, int val, int l=1, int r=300000, int v=1)
	{
		if(L<=l&&r<=R)
		{
			value[v] += val;
			lazy[v] += val;
			if(l==r) index[v] = l;
		}
		else if(r<L) return;
		else if(R<l) return;
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
			if(value[2*v]<value[2*v+1])
			{
				value[v] = value[2*v];
				index[v] = index[2*v];
			}
			else
			{
				value[v] = value[2*v+1];
				index[v] = index[2*v+1];
			}
		}
	}
	std::pair<int,int> getMin(int L, int R, int l=1, int r=300000, int v=1)
	{
		if(L<=l&&r<=R) return std::make_pair(value[v],index[v]);
		else if(r<L) return std::make_pair(MAX,-1);
		else if(R<l) return std::make_pair(MAX,-1);
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] += lazy[v], value[2*v+1] += lazy[v];
				lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			std::pair<int,int> P1 = getMin(L,R,l,h,2*v);
			std::pair<int,int> P2 = getMin(L,R,h+1,r,2*v+1);
			if(P1.first<P2.first) return P1;
			else return P2;
		}
	}
}T;

struct segTree2{
	int value[1200010];
	void addValue(int ind, int val, int l=1, int r=300000, int v=1)
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
	int getSum(int L, int R, int l=1, int r=300000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			return getSum(L,R,l,h,2*v) + getSum(L,R,h+1,r,2*v+1);
		}
	}
}T2;

struct str{
	int x0;
	int y0;
	int index;
	int ans;
}query[300010];
bool cmp(str a, str b)
{
	if(a.x0==b.x0) return a.y0<b.y0;
	return a.x0<b.x0;
}
bool cmp2(str a, str b)
{
	return a.index<b.index;
}

int x[300010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		query[i]={c,d,i,0};
	}
	std::sort(query+1,query+b+1,cmp);
	
	for(int i=1;i<=a;i++)
	{
		if(x[i]>i) T.addValue(i,i,MAX);
		else T.addValue(i,i,x[i]-i);
	}
	
	for(int i=1;i<=a;i++)
	{
		if(T.getMin(i,i).first<MAX) // min over 0
		{
			int k = T.getMin(i,i).first;
			if(k>=0)
			{
				T2.addValue(i,1);
				T.addValue(i+1,a,1);
			}
			else T.addValue(i,i,MAX-k);
		}
	}
	
	int p = 1;
	while(p<=b && query[p].x0==0) query[p].ans = T2.getSum(1,a-query[p].y0),p++;
	
	for(int i=1;i<=a;i++)
	{
		if(T2.getSum(i,i)==1)
		{
			T2.addValue(i,-1);
			T.addValue(i+1,a,-1);
			T.addValue(i,i,MAX);
			while(T.getMin(i+1,a).first<0)
			{
				int k = T.getMin(i+1,a).second;
				T2.addValue(k,-1);
				T.addValue(k+1,a,-1);
				T.addValue(k,k,MAX);
			}
		}
		
		while(p<=b && query[p].x0==i) query[p].ans = T2.getSum(1,a-query[p].y0),p++;
	}
	std::sort(query+1,query+b+1,cmp2);
	for(int i=1;i<=b;i++) printf("%d\n",query[i].ans);
}