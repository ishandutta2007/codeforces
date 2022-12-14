#include <stdio.h>

struct segTree{
	long long int value[2000010];
	long long int lazy[2000010];
	void update(int v)
	{
		value[v] = value[2*v] + value[2*v+1];
		lazy[v] = -1;
	}
	void setValue(int L, int R, long long int val, int l=1, int r=500000, int v=1)
	{
		if(L<=l&&r<=R) value[v] = val*(r-l+1), lazy[v] = val;
		else if(R<l) return;
		else if(r<L) return;
		else
		{
			int h = (l+r)/2;
			
			if(lazy[v]!=-1)
			{
				value[2*v] = lazy[v]*(h-l+1), value[2*v+1] = lazy[v]*(r-h);
				lazy[2*v] = lazy[v], lazy[2*v+1] = lazy[v];
				lazy[v] = -1;
			}
			
			setValue(L,R,val,l,h,2*v);
			setValue(L,R,val,h+1,r,2*v+1);
			update(v);
		}
	}
	long long int getSum(int L, int R, int l=1, int r=500000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=-1)
			{
				value[2*v] = lazy[v]*(h-l+1), value[2*v+1] = lazy[v]*(r-h);
				lazy[2*v] = lazy[v], lazy[2*v+1] = lazy[v];
				lazy[v] = -1;
			}
			
			long long int s1 = getSum(L,R,l,h,2*v);
			long long int s2 = getSum(L,R,h+1,r,2*v+1);
			return s1+s2;
		}
	}
}T;

int x[500010],y[500010];
long long int check[500010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=a;i>=1;i--)
	{
		int min = i+1, max = a, ans = i;
		while(min<=max)
		{
			int h = (min+max)/2;
			if(T.getSum(h,h)>x[i])
			{
				ans = h;
				min = h+1;
			}
			else max = h-1;
		}
		T.setValue(i,ans,x[i]);
		check[i] += T.getSum(i,a);
	}
	for(int i=1;i<=a;i++)
	{
		int min = 1, max = i-1, ans = i;
		while(min<=max)
		{
			int h = (min+max)/2;
			if(T.getSum(h,h)>x[i])
			{
				ans = h;
				max = h-1;
			}
			else min = h+1;
		}
		T.setValue(ans,i,x[i]);
		check[i] += T.getSum(1,i);
	}
	for(int i=1;i<=a;i++) check[i] -= x[i];
	
	long long int M = check[1];
	for(int i=2;i<=a;i++) M = M>check[i]?M:check[i];
	for(int i=1;i<=a;i++)
	{
		if(check[i]==M)
		{
			int C = x[i];
			for(int j=i-1;j>=1;j--) C = C<x[j]? C:x[j], y[j] = C;
			C = x[i];
			for(int j=i+1;j<=a;j++) C = C<x[j]? C:x[j], y[j] = C;
			y[i] = x[i];
			goto u;
		}
	}
	u:;
	for(int i=1;i<=a;i++) printf("%d ",y[i]);
}