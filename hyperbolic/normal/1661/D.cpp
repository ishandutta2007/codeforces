#include <stdio.h>

struct segTree{
	long long int lazy[1200010];
	void addValue(int L, int R, long long int val, int l=1 ,int r=300000, int v=1)
	{
		if(L<=l&&r<=R) lazy[v] += val;
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				lazy[2*v] += lazy[v];
				lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			addValue(L,R,val,l,h,2*v);
			addValue(L,R,val,h+1,r,2*v+1);
		}
	}
	long long int getValue(int ind, int l=1, int r=300000 ,int v=1)
	{
		if(l==r) return lazy[v];
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				lazy[2*v] += lazy[v];
				lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			if(ind<=h) return getValue(ind,l,h,2*v);
			else return getValue(ind,h+1,r,2*v+1);
		}
	}
}T1,T2;

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		long long int c;
		scanf("%lld",&c);
		T1.addValue(i,i,c);
	}
	
	long long int ans = 0;
	long long int S = 0;
	for(int i=a;i>=b+1;i--)
	{
		S += T2.getValue(i);
		if(T1.getValue(i) + S<=0) continue;
		
		long long int t = (T1.getValue(i) + S-1)/b +1;
		ans += t;
		T1.addValue(i-b+1,i-1,-(t*b));
		T2.addValue(i-b+1,i-1,t);
		T2.addValue(i-b,i-b,-(b-1)*t);
	}
	
	long long int ans2 = 0;
	for(int i=b;i>=1;i--)
	{
		S += T2.getValue(i);
		long long int t = T1.getValue(i) + S;
		ans2 = ans2>(t-1)/i+1?ans2:(t-1)/i+1;
	}
	printf("%lld",ans+ans2);
}