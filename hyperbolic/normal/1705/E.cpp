#include <stdio.h>

struct segTree{
	int value[900010];
	int lazy[900010];
	void setValue(int L, int R, int val, int l=1, int r=210000, int v=1)
	{
		if(L<=l&&r<=R) lazy[v] = val, value[v] = (r-l+1)*val;
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=-1)
			{
				value[2*v] = (h-l+1)*lazy[v];
				value[2*v+1] = (r-h)*lazy[v];
				lazy[2*v]=lazy[v], lazy[2*v+1] = lazy[v];
				lazy[v] = -1;
			}
			setValue(L,R,val,l,h,2*v);
			setValue(L,R,val,h+1,r,2*v+1);
			value[v] = value[2*v]+value[2*v+1];
		}
	}
	int getSum(int L, int R, int l=1, int r=210000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=-1)
			{
				value[2*v] = (h-l+1)*lazy[v];
				value[2*v+1] = (r-h)*lazy[v];
				lazy[2*v]=lazy[v], lazy[2*v+1] = lazy[v];
				lazy[v] = -1;
			}
			int s1 = getSum(L,R,l,h,2*v);
			int s2 = getSum(L,R,h+1,r,2*v+1);
			return s1+s2;
		}
	}
}digit;

int x[210010],check[210010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) check[x[i]]++;
	for(int i=1;i<=210000;i++)
	{
		check[i+1] += check[i]/2;
		check[i] %= 2;
	}
	for(int i=1;i<=210000;i++) digit.setValue(i,i,check[i]);
	
	while(b--)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		if(digit.getSum(x[c],x[c])==1) digit.setValue(x[c],x[c],0);
		else
		{
			int p = 210001;
			int min = x[c]+1, max = 210000;
			while(min<=max)
			{
				int h = (min+max)/2;
				if(digit.getSum(x[c],h)>0)
				{
					p = h;
					max = h-1;
				}
				else min = h+1;
			}
			digit.setValue(x[c],p-1,1);
			digit.setValue(p,p,0);
		}
		x[c] = d;
		if(digit.getSum(x[c],x[c])==0) digit.setValue(x[c],x[c],1);
		else
		{
			int p = 210001;
			int min = x[c]+1, max = 210000;
			while(min<=max)
			{
				int h = (min+max)/2;
				if(digit.getSum(x[c],h)<(h-x[c]+1))
				{
					p = h;
					max = h-1;
				}
				else min = h+1;
			}
			digit.setValue(x[c],p-1,0);
			digit.setValue(p,p,1);
		}
		
		int ans = 0;
		int min = 1, max = 210000;
		while(min<=max)
		{
			int h = (min+max)/2;
			if(digit.getSum(h,210000)>0)
			{
				ans = h;
				min = h+1;
			}
			else max = h-1;
		}
		printf("%d\n",ans);
	}
}