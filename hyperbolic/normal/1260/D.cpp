#include <stdio.h>
#include <algorithm>

struct segTree{
	int value[800010];
	int lazy[800010];
	void setValue(int L, int R, int val, int l=1, int r=200000 ,int v=1)
	{
		if(L<=l&&r<=R) value[v] = (r-l+1)*val, lazy[v] = val;
		else if(R<l) return;
		else if(r<L) return;
		else
		{
			int h =(l+r)/2;
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
	int getValue(int L, int R, int l=1, int r=200000, int v=1)
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
			return getValue(L,R,l,h,2*v) + getValue(L,R,h+1,r,2*v+1);
		}
	}
}T;

int left[200010],right[200010],danger[200010];
int x[200010];
int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	
	for(int i=1;i<=c;i++)
	{
		int e,f,g;
		scanf("%d%d%d",&e,&f,&g);
		left[i] = e;
		right[i] = f;
		danger[i] = g;
	}
	
	int min = 1, max = a;
	int ans = 0;
	
	while(min<=max)
	{
		int h = (min+max)/2;
		
		T.setValue(1,b,0);
		for(int i=1;i<=c;i++) if(danger[i]>x[a-h+1]) T.setValue(left[i],right[i],1);
		int S = b+1 + 2*T.getValue(1,b);
		
		if(S<=d)
		{
			ans = h;
			min = h+1;
		}
		else max = h-1;
	}
	printf("%d",ans);
}