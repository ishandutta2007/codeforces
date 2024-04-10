#include <stdio.h>

struct segTree{
	int value[2000010];
	long long int sum[2000010];
	int lazy[2000010];
	void addValue(int L, int R, int val, int l=1, int r=500000, int v=1)
	{
		if(L<=l&&r<=R) sum[v] += (long long int)(r-l+1)*val, value[v]+=val, lazy[v]+=val;
		else if(r<L) return;
		else if(R<l) return;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]>0)
			{
				value[2*v] += lazy[v];
				value[2*v+1] += lazy[v];
				sum[2*v] += (long long int)(h-l+1) * lazy[v];
				sum[2*v+1] += (long long int)(r-h) * lazy[v];
				lazy[2*v] += lazy[v];
				lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			addValue(L,R,val,l,h,2*v);
			addValue(L,R,val,h+1,r,2*v+1);
			value[v] = value[2*v]>value[2*v+1]?value[2*v]:value[2*v+1];
			sum[v] = sum[2*v] + sum[2*v+1];
		}
	}
	long long int getSum(int L, int R, int l=1,int r=500000, int v=1)
	{
		if(L<=l&&r<=R) return sum[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]>0)
			{
				value[2*v] += lazy[v];
				value[2*v+1] += lazy[v];
				sum[2*v] += (long long int)(h-l+1) * lazy[v];
				sum[2*v+1] += (long long int)(r-h) * lazy[v];
				lazy[2*v] += lazy[v];
				lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			long long int s1 = getSum(L,R,l,h,2*v);
			long long int s2 = getSum(L,R,h+1,r,2*v+1);
			return s1+s2;
		}
	}
	int getPos(int val, int l=1, int r=500000, int v=1)
	{
		if(value[v]<val) return 0;
		if(l==r) return l;
		
		int h = (l+r)/2;
		if(lazy[v]>0)
		{
			value[2*v] += lazy[v];
			value[2*v+1] += lazy[v];
			sum[2*v] += (long long int)(h-l+1) * lazy[v];
			sum[2*v+1] += (long long int)(r-h) * lazy[v];
			lazy[2*v] += lazy[v];
			lazy[2*v+1] += lazy[v];
			lazy[v] = 0;
		}
		int s1 = getPos(val,h+1,r,2*v+1);
		if(s1==0) return getPos(val,l,h,2*v);
		else return s1;
	}
}T;

char x[500010];
int prev[500010];
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	int p = 1;
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='1') prev[i] = p;
		else p = i+1;
	}
	
	long long int ans = 0;
	long long int S = 0;
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='0') ans += S;
		else
		{
			int len = i-prev[i]+1;
			int p = T.getPos(len);
			// find max[p]>=length
			S = 0;
			S += T.getSum(1,p);
			S += (long long int)(prev[i]-p-1)*len;
			S += (long long int)len*(len+1)/2;
			ans += S;
			T.addValue(p+1,i,1);
		}
	}
	printf("%lld",ans);
}