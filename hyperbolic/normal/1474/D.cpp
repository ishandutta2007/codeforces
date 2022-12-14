#include <stdio.h>

long long int MIN = -1, MAX = 1;
struct segTree{
	long long int max[800010];
	long long int min[800010];
	long long int lazy[800010];
	
	void addValue(int L, int R, long long int val, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R)
		{
			max[v] += val;
			min[v] += val;
			lazy[v] += val;
		}
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
				max[2*v] += lazy[v], max[2*v+1] += lazy[v];
				min[2*v] += lazy[v], min[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			addValue(L,R,val,l,h,2*v);
			addValue(L,R,val,h+1,r,2*v+1);
			max[v] = max[2*v]>max[2*v+1]?max[2*v]:max[2*v+1];
			min[v] = min[2*v]<min[2*v+1]?min[2*v]:min[2*v+1];
		}
	}
	
	long long int getMax(int L, int R, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) return max[v];
		else if(r<L) return MIN;
		else if(R<l) return MIN;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
				max[2*v] += lazy[v], max[2*v+1] += lazy[v];
				min[2*v] += lazy[v], min[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			long long int s1 = getMax(L,R,l,h,2*v);
			long long int s2 = getMax(L,R,h+1,r,2*v+1);
			return s1>s2?s1:s2;
		}
	}
	
	long long int getMin(int L, int R, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) return min[v];
		else if(r<L) return MAX;
		else if(R<l) return MAX;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
				max[2*v] += lazy[v], max[2*v+1] += lazy[v];
				min[2*v] += lazy[v], min[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			long long int s1 = getMin(L,R,l,h,2*v);
			long long int s2 = getMin(L,R,h+1,r,2*v+1);
			return s1<s2?s1:s2;
		}
	}
}T1,T2;

void reset(int k)
{
	for(int i=1;i<=k;i+=2) T1.addValue((i+1)/2,(i+1)/2,-T1.getMax((i+1)/2,(i+1)/2));
	for(int i=2;i<=k;i+=2) T2.addValue((i)/2,(i)/2,-T2.getMax((i)/2,(i)/2));
}

long long int x[200010];
long long int y[200010];

int main()
{
	for(int i=1;i<=16;i++) MIN*=10;
	for(int i=1;i<=16;i++) MAX*=10;
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		reset(a);
		
		for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
		for(int i=2;i<=a;i+=2) x[i] *= (-1);
		for(int i=1;i<=a;i++) y[i] = y[i-1] + x[i];
		
		long long int sum = y[a];
		
		for(int i=1;i<=a;i+=2) T1.addValue((i+1)/2,(i+1)/2,y[i]);
		for(int i=2;i<=a;i+=2) T2.addValue((i)/2,(i)/2,y[i]);

		if(T1.getMin(1,(a+1)/2)>=0&&T2.getMax(1,(a)/2)<=0 && sum==0) printf("YES\n");
		else
		{
			for(int i=1;i<a;i++)
			{
				if(i%2==1)
				{
					T1.addValue((i+1)/2,(a+1)/2,-(x[i+1]+x[i]));
					T1.addValue((i+3)/2,(a+1)/2,-(x[i+1]+x[i]));
					T2.addValue((i+1)/2,a/2,-2*(x[i]+x[i+1]));
					sum = (sum-2*x[i+1]-2*x[i]);
					
					if(T1.getMin(1,(a+1)/2)>=0&&T2.getMax(1,(a)/2)<=0 && sum==0)
					{
						printf("YES\n");
						goto u;
					}
					
					T1.addValue((i+1)/2,(a+1)/2,x[i+1]+x[i]);
					T1.addValue((i+3)/2,(a+1)/2,x[i+1]+x[i]);
					T2.addValue((i+1)/2,a/2,2*(x[i]+x[i+1]));
					sum = (sum+2*x[i+1]+2*x[i]);
				}
				else
				{
					T1.addValue((i+2)/2,(a+1)/2,-2*(x[i+1]+x[i]));
					T2.addValue((i)/2,a/2,-(x[i]+x[i+1]));
					T2.addValue((i+2)/2,a/2,-(x[i]+x[i+1]));
					sum = (sum-2*x[i+1]-2*x[i]);
					
					if(T1.getMin(1,(a+1)/2)>=0&&T2.getMax(1,(a)/2)<=0 && sum==0)
					{
						printf("YES\n");
						goto u;
					}
					
					T1.addValue((i+2)/2,(a+1)/2,2*(x[i+1]+x[i]));
					T2.addValue((i)/2,a/2,x[i]+x[i+1]);
					T2.addValue((i+2)/2,a/2,x[i]+x[i+1]);
					sum = (sum+2*x[i+1]+2*x[i]);
				}
			}
			printf("NO\n");
			u:;
		}
	}
}