#include <stdio.h>

long long int gcd(long long int a, long long int b)
{
	return a?gcd(b%a,a):b;
}
long long int abs(long long int k)
{
	return k>0?k:-k;
}

struct segTree{
	long long int value[800010];
	void setValue(int ind, long long int val, int l=1, int r=200000, int v=1)
	{
		if(l==r) value[v] = val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			value[v] = gcd(value[2*v],value[2*v+1]);
		}
	}
	long long int getGCD(int L, int R, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			long long int s1 = getGCD(L,R,l,h,2*v);
			long long int s2 = getGCD(L,R,h+1,r,2*v+1);
			return gcd(s1,s2);
		}
	}
}T;

long long int x[200010];
int main()
{
	int Case;
	scanf("%d",&Case);
	while(Case--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) T.setValue(i,0);
		
		for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
		if(a==1)
		{
			printf("1\n");
			continue;
		}
		
		for(int i=2;i<=a;i++) T.setValue(i,abs(x[i]-x[i-1]));
		
		int ans = 1;
		for(int i=1;i<=a;i++)
		{
			int min = i+1, max = a;
			while(min<=max)
			{
				int h = (min+max)/2;
				long long int s1 = T.getGCD(i+1,h);
				if(s1>=2)
				{
					ans = ans>(h-i+1)?ans:(h-i+1);
					min = h+1;
				}
				else max = h-1;
			}
		}
		printf("%d\n",ans);
	}
}