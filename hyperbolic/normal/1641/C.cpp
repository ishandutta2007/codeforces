#include <stdio.h>

struct segTree1{
	int value[800010];
	int lazy[800010];
	void setValue(int L, int R, int val, int l=1, int r=200002, int v=1)
	{
		if(L<=l&&r<=R) value[v] = (r-l+1)*val, lazy[v] = val;
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=-1)
			{
				lazy[2*v] = lazy[2*v+1] = lazy[v];
				value[2*v] = (h-l+1)*lazy[v], value[2*v+1] = (r-h)*lazy[v];
				lazy[v] = -1;
			}
			setValue(L,R,val,l,h,2*v);
			setValue(L,R,val,h+1,r,2*v+1);
			value[v] = value[2*v] + value[2*v+1];
		}
	}
	int getSum(int L, int R, int l=1, int r=200002, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=-1)
			{
				lazy[2*v] = lazy[2*v+1] = lazy[v];
				value[2*v] = (h-l+1)*lazy[v], value[2*v+1] = (r-h)*lazy[v];
				lazy[v] = -1;
			}
			int s1 = getSum(L,R,l,h,2*v);
			int s2 = getSum(L,R,h+1,r,2*v+1);
			return s1+s2;
		}
	}
}T1;

struct segTree2{
	int value[800010];
	void setValue(int ind, int val, int l=1, int r=200002, int v=1)
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
	int getMin(int L, int R, int l=1, int r=200002, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 12345678;
		else if(R<l) return 12345678;
		else
		{
			int h = (l+r)/2;
			int s1 = getMin(L,R,l,h,2*v);
			int s2 = getMin(L,R,h+1,r,2*v+1);
			return s1<s2?s1:s2;
		}
	}
}T2;


int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	
	T1.setValue(1,a+2,1);
	for(int i=1;i<=a;i++) T2.setValue(i,a+2);
	
	while(b--)
	{
		int c;
		scanf("%d",&c);
		if(c==0)
		{
			int d,e,f;
			scanf("%d%d%d",&d,&e,&f);
			if(f==0) T1.setValue(d,e,0);
			else
			{
				int t = T2.getMin(d,d);
				if(e<t) T2.setValue(d,e);
			}
		}
		else
		{
			int d;
			scanf("%d",&d);
			if(T1.getSum(d,d)==0)
			{
				printf("NO\n");
				continue;
			}
			
			int min = 1, max = d-1;
			int p = 0;
			while(min<=max)
			{
				int h = (min+max)/2;
				if(T1.getSum(h,d-1)>0)
				{
					p = h;
					min = h+1;
				}
				else max = h-1;
			}
			int R = T2.getMin(p+1,d);
			
			if(T1.getSum(p+1,R)==1) printf("YES\n");
			else printf("N/A\n");
		}
	}
}