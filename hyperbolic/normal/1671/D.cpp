#include <stdio.h>

struct segTree{
	int lazy[800010];
	void setValue(int L, int R ,int val, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) lazy[v] = val;
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=-1)
			{
				lazy[2*v] = lazy[v], lazy[2*v+1] = lazy[v];
				lazy[v] = -1;
			}
			setValue(L,R,val,l,h,2*v);
			setValue(L,R,val,h+1,r,2*v+1);
		}
	}
	int getValue(int ind, int l=1, int r=200000, int v=1)
	{
		if(l==r) return lazy[v];
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=-1)
			{
				lazy[2*v] = lazy[v], lazy[2*v+1] = lazy[v];
				lazy[v] = -1;
			}
			if(ind<=h) return getValue(ind,l,h,2*v);
			else return getValue(ind,h+1,r,2*v+1);
		}
	}
}T;

int x[200010];
int main()
{
	int Case;
	scanf("%d",&Case);
	while(Case--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		int min = x[1], max = x[1];
		for(int i=1;i<=a;i++)
		{
			min = min<x[i]?min:x[i];
			max = max>x[i]?max:x[i];
		}
		long long int ans = 0;
		for(int i=1;i<a;i++)
		{
			int s = x[i], t = x[i+1];
			if(s>t)
			{
				int temp = s;
				s = t;
				t = temp;
			}
			ans += (t-s);
		}
		
		if(1<min)
		{
			int val1, val2, val3;
			val1 = x[1]-1;
			val2 = x[a]-1;
			val3 = 2*(min-1);
			ans += val1<val2?val3<val1?val3:val1:val3<val2?val3:val2;
		}
		if(max<b)
		{
			int val1, val2, val3;
			val1 = b-x[1];
			val2 = b-x[a];
			val3 = 2*(b-max);
			ans += val1<val2?val3<val1?val3:val1:val3<val2?val3:val2;
		}
		printf("%lld\n",ans);
	}
}