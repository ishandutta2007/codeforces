#include <stdio.h>

struct segTree{
	short value[800010][101];
	
	void init(int l=1, int r=200000, int v=1)
	{
		for(int i=1;i<=100;i++) value[v][i] = i;
		if(l==r) return;
		
		int h = (l+r)/2;
		init(l,h,2*v);
		init(h+1,r,2*v+1);
	}
	
	void doQuery(int L, int R, int x, int y, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R)
		{
			for(int i=1;i<=100;i++) if(value[v][i]==x) value[v][i] = y;
		}
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			for(int i=1;i<=100;i++) value[2*v][i] = value[v][value[2*v][i]];
			for(int i=1;i<=100;i++) value[2*v+1][i] = value[v][value[2*v+1][i]];
			for(int i=1;i<=100;i++) value[v][i] = i;
			doQuery(L,R,x,y,l,h,2*v);
			doQuery(L,R,x,y,h+1,r,2*v+1);
		}
	}
	
	int getValue(int ind, short val, int l=1, int r=200000, int v=1)
	{
		if(l==r) return value[v][val];
		else
		{
			int h = (l+r)/2;
			for(int i=1;i<=100;i++) value[2*v][i] = value[v][value[2*v][i]];
			for(int i=1;i<=100;i++) value[2*v+1][i] = value[v][value[2*v+1][i]];
			for(int i=1;i<=100;i++) value[v][i] = i;
			if(ind<=h) return getValue(ind,val,l,h,2*v);
			else return getValue(ind,val,h+1,r,2*v+1);
		}
	}
}T;

int x[200010];
int main()
{
	T.init();
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int b;
	scanf("%d",&b);
	for(int i=1;i<=b;i++)
	{
		int c,d,e,f;
		scanf("%d%d%d%d",&c,&d,&e,&f);
		T.doQuery(c,d,e,f);
	}
	
	for(int i=1;i<=a;i++) printf("%d ",T.getValue(i,x[i]));
}