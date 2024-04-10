#include <stdio.h>

struct segTree{
	int value[4000010];
	int lazy[4000010];
	void addValue(int L, int R, int val, int l=1, int r=1000000, int v=1)
	{
		if(L<=l&&r<=R) value[v] += val, lazy[v] += val;
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
			value[v] = value[2*v]>value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	int getQuery(int l=1, int r=1000000, int v=1)
	{
		if(value[v]<=0) return -1;
		
		if(l==r) return l;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] += lazy[v], value[2*v+1] += lazy[v];
				lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			int s = getQuery(h+1,r,2*v+1);
			if(s>0) return s;
			s = getQuery(l,h,2*v);
			if(s>0) return s;
		}
	}
}T;

int x[300010],y[300010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=b;i++) scanf("%d",&y[i]);
	
	for(int i=1;i<=a;i++) T.addValue(1,x[i],1);
	for(int i=1;i<=b;i++) T.addValue(1,y[i],-1);
	int c;
	scanf("%d",&c);
	for(int i=1;i<=c;i++)
	{
		int d,e,f;
		scanf("%d%d%d",&d,&e,&f);
		if(d==1)
		{
			T.addValue(1,x[e],-1);
			x[e] = f;
			T.addValue(1,x[e],1);
		}
		else
		{
			T.addValue(1,y[e],1);
			y[e] = f;
			T.addValue(1,y[e],-1);
		}
		printf("%d\n",T.getQuery());
	}
}