#include <stdio.h>

struct segTree{
	long long int value[4000010];
	long long int lazy[4000010];
	void addValue(int L, int R, int val, int l=1, int r=1000000, int v=1)
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
	long long int getSum(int L, int R, int l=1, int r=1000000, int v=1)
	{
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
}T;

int x[1000010];
int next[1000010];
int check[1000010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=a;i>=1;i--)
	{
		if(check[x[i]]==0) next[i] = a+1;
		else next[i] = check[x[i]];
		check[x[i]] = i;
	}
	
	long long int ans = 0;
	for(int i=a;i>=1;i--)
	{
		T.addValue(i,next[i]-1,1);
		ans += 2*T.getSum(i+1,a);
		ans += T.getSum(i,i);
	}
	
	long long int t = (long long int)a*a;
	printf("%.12lf",(double)ans/t);
}