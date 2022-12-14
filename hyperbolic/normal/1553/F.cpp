#include <stdio.h>
#define SIZE 1000

struct segTree{
	long long int value[1200010],lazy[1200010];
	void addValue(int L, int R, long long int val, int l=1, int r=300000, int v=1)
	{
		if(L<=l&&r<=R) value[v] += (r-l+1)*val, lazy[v] += val;
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] += (h-l+1)*lazy[v], value[2*v+1] += (r-h)*lazy[v];
				lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			addValue(L,R,val,l,h,2*v);
			addValue(L,R,val,h+1,r,2*v+1);
			value[v] = value[2*v] + value[2*v+1];
		}
	}
	long long int getSum(int L, int R, int l=1, int  r=300000, int v=1)
	{
		if(L>R) return 0;
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] += (h-l+1)*lazy[v], value[2*v+1] += (r-h)*lazy[v];
				lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			
			long long int s1 = getSum(L,R,l,h,2*v);
			long long int s2 = getSum(L,R,h+1,r,2*v+1);
			return s1+s2;
		}
	}
}T1,T2,T3;
int x[200010];
long long int ans[200010];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int MAX = x[1];
	for(int i=2;i<=a;i++) MAX = MAX>x[i]?MAX:x[i];
	
	for(int i=1;i<=a;i++)
	{
		for(int j=x[i];j<=MAX;j+=x[i])
		{
			int t = j+x[i]-1<MAX?j+x[i]-1:MAX;
			long long int s1 = T1.getSum(j,t);
			if(s1==0) continue;
			long long int s2 = T2.getSum(j,t);
			ans[i] += s1*x[i];
			ans[i] += (s2 - s1*j);
		}
		
		long long int s1 = T1.getSum(1,x[i]-1);
		if(s1!=0)
		{
			long long int s2 = T2.getSum(1,x[i]-1);
			ans[i] += s2;
			ans[i] += s1*x[i];
		}
		T1.addValue(x[i],x[i],1);
		T2.addValue(x[i],x[i],x[i]);
	}
	
	for(int i=a;i>=1;i--)
	{
		for(int j=x[i];j<=MAX;j+=x[i])
		{
			int t = j+x[i]-1<MAX?j+x[i]-1:MAX;
			T3.addValue(j,t,-j);
		}
		long long int t = T3.getSum(x[i],x[i]);
		T3.addValue(x[i],x[i],ans[i]-t);
	}
	
	for(int i=1;i<=a;i++) ans[i] = T3.getSum(x[i],x[i]);
	for(int i=1;i<=a;i++) ans[i] += ans[i-1];
	for(int i=1;i<=a;i++) printf("%lld ",ans[i]);
}