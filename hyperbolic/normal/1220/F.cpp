#include <stdio.h>
#define MAX 123456789

struct segTree1{
	int value[1600010];
	void setValue(int ind, int val, int l=1, int r=400000, int v=1)
	{
		if(l==r) value[v] = val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v]<value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	int getMin(int L, int R, int l=1, int r=400000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return MAX;
		else if(R<l) return MAX;
		else
		{
			int h = (l+r)/2;
			int s1 = getMin(L,R,l,h,2*v);
			int s2 = getMin(L,R,h+1,r,2*v+1);
			return s1<s2?s1:s2;
		}
	}
}T;

struct segTree2{
	int value[1600010];
	int lazy[1600010];
	void addValue(int L, int R, int val, int l=1, int r=400000, int v=1)
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
			value[v] = value[2*v]>value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	int getMax(int L, int R, int l=1, int r=400000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] += lazy[v], value[2*v+1] += lazy[v];
				lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			int s1 = getMax(L,R,l,h,2*v);
			int s2 = getMax(L,R,h+1,r,2*v+1);
			return s1>s2?s1:s2;
		}
	}
}T2;

int height[400010];
int x[400010],next[400010],prev[400010];
int hash[400010];

void func(int s, int t, int h)
{
	if(s>t) return;
	
	int m = hash[T.getMin(s,t)];
	height[m] = h;
	func(s,m-1,h+1);
	func(m+1,t,h+1);
}

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) hash[x[i]] = i;
	for(int i=a+1;i<=2*a;i++) x[i] = x[i-a];
	for(int i=1;i<=2*a;i++) T.setValue(i,x[i]);
	
	for(int i=a;i>=1;i--)
	{
		next[i] = i+a;
		int min = i+1, max = i+a-1;
		while(min<=max)
		{
			int h = (min+max)/2;
			if(T.getMin(i+1,h)<=x[i])
			{
				next[i] = h;
				max = h-1;
			}
			else min = h+1;
		}
	}
	
	for(int i=a+1;i<=2*a;i++)
	{
		prev[i] = i-a;
		int min = i-a+1, max = i-1;
		while(min<=max)
		{
			int h = (min+max)/2;
			if(T.getMin(h,i-1)<=x[i])
			{
				prev[i] = h;
				min = h+1;
			}
			else max = h-1;
		}
	}
	func(1,a,1);
	
	for(int i=1;i<=a;i++) T2.addValue(i,i,height[i]);
	
	int ans1 = 0, ans2 = T2.getMax(1,a);
	for(int i=1;i<=a;i++)
	{
		T2.addValue(i,next[i]-1,-1);
		T2.addValue(prev[i+a]+1,i+a-1,1);
		T2.addValue(i+a,i+a,T2.getMax(prev[i+a],prev[i+a])+1);
		int t = T2.getMax(i+1,i+a);
		if(t<ans2)
		{
			ans1 = i;
			ans2 = t;
		}
	}
	printf("%d %d",ans2,ans1);
}