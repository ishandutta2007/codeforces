#include <stdio.h>

long long int b;
long long int gcd(long long int a, long long int b)
{
	return a?gcd(b%a,a):b;
}

struct segTree{
	long long int value[400010];
	void setValue(int ind, long long int val, int l=1, int r=100000, int v=1)
	{
		if(l==r) value[v] = gcd(val,b);
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			value[v] = gcd(value[2*v]*value[2*v+1],b);
		}
	}
	long long int getValue(int L, int R, int l=1, int r=100000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 1;
		else if(R<l) return 1;
		else
		{
			int h = (l+r)/2;
			long long int s1 = getValue(L,R,l,h,2*v);
			long long int s2 = getValue(L,R,h+1,r,2*v+1);
			return gcd(s1*s2,b);
		}
	}
}T;

int x[100010];
int main()
{
	int a;
	scanf("%d%lld",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) T.setValue(i,x[i]);
	
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		int min = i, max = a;
		int val = 0;
		while(min<=max)
		{
			int h = (min+max)/2;
			if(T.getValue(i,h)==b)
			{
				val = (a-h+1);
				max = h-1;
			}
			else min = h+1;
		}
		ans += val;
	}
	printf("%lld",ans);
}