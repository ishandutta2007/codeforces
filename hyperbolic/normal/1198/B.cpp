#include <stdio.h>

struct segTree{
	int value[800010];
	void update(int v, int val)
	{
		if(value[v]==-1) value[v] = val;
		else value[v] = value[v]>val?value[v]:val;
	}
	void setValue(int L,int R, int val, int l=1, int r=200000,int v=1)
	{
		if(L<=l&&r<=R) update(v,val);
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			if(value[v]!=-1)
			{
				update(2*v,value[v]);
				update(2*v+1,value[v]);
				value[v] = -1;
			}
			setValue(L,R,val,l,h,2*v);
			setValue(L,R,val,h+1,r,2*v+1);
		}
	}
	void setValue2(int ind, int l=1, int r=200000, int v=1)
	{
		if(l==r) value[v] = -1;
		else
		{
			int h = (l+r)/2;
			if(value[v]!=-1)
			{
				update(2*v,value[v]);
				update(2*v+1,value[v]);
				value[v] = -1;
			}
			if(ind<=h) setValue2(ind,l,h,2*v);
			else setValue2(ind,h+1,r,2*v+1);
		}
	}
	int getValue(int ind, int l=1, int r=200000, int v=1)
	{
		if(l==r) return value[v];
		else
		{
			int h = (l+r)/2;
			if(value[v]!=-1)
			{
				update(2*v,value[v]);
				update(2*v+1,value[v]);
				value[v] = -1;
			}
			if(ind<=h) return getValue(ind,l,h,2*v);
			else return getValue(ind,h+1,r,2*v+1);
		}
	}
}T;

int x[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	int b;
	scanf("%d",&b);
	for(int i=1;i<=b;i++)
	{
		int c;
		scanf("%d",&c);
		if(c==1)
		{
			int d,e;
			scanf("%d%d",&d,&e);
			x[d] = e;
			T.setValue2(d);
		}
		else
		{
			int d;
			scanf("%d",&d);
			T.setValue(1,a,d);
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		int t = T.getValue(i);
		printf("%d ",t>x[i]?t:x[i]);
	}
}