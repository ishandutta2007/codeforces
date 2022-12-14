#include <stdio.h>
#include <vector>
#define MAX (long long int)1e16

struct segTree{
	long long int value[140010];
	long long int lazy[140010];
	void addValue(int L, int R, long long int val, int l=1, int r=35000, int v=1)
	{
		if(L>R) return;
		if(L<=l&&r<=R) value[v] += val, lazy[v] += val;
		else if(r<L) return;
		else if(R<l) return;
		else
		{
			if(lazy[v]!=0)
			{
				value[2*v] += lazy[v], value[2*v+1] += lazy[v];
				lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			int h = (l+r)/2;
			addValue(L,R,val,l,h,2*v);
			addValue(L,R,val,h+1,r,2*v+1);
			value[v] = value[2*v]<value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	long long int getMin(int L, int R, int l=1, int r=35000, int v=1)
	{
		if(L>R) return MAX;
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return MAX;
		else if(R<l) return MAX;
		else
		{
			if(lazy[v]!=0)
			{
				value[2*v] += lazy[v], value[2*v+1] += lazy[v];
				lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			int h = (l+r)/2;
			long long int s1 = getMin(L,R,l,h,2*v);
			long long int s2 = getMin(L,R,h+1,r,2*v+1);
			return s1<s2?s1:s2;
		}
	}
}T[101];

int x[35010];
int check[35010],left[35010];
long long int DP[110];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++)
	{
		left[i] = check[x[i]];
		check[x[i]] = i;
	}
	
	for(int i=1;i<=a;i++)
	{
		if(left[i]>0) for(int j=1;j<=b;j++) T[j].addValue(1,left[i]-1,i-left[i]);
		for(int j=2;j<=b;j++) DP[j] = T[j-1].getMin(1,i-1);
		DP[1] += (left[i]==0?0:i-left[i]);
		for(int j=1;j<=b;j++) T[j].addValue(i,i,DP[j]);
	}
	printf("%lld",DP[b]);
}