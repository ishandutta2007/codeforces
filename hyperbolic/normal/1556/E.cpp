#include <stdio.h>
#define MAX (long long int)1e18
#define MIN -(long long int)1e18

struct segTree{
	long long int value[400010];
	void setValue(int ind, long long int val, int l=1, int r=100000, int v=1)
	{
		if(l==r) value[v] = val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v]<value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	long long int getMin(int L, int R, int l=1, int r=100000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return MAX;
		else if(R<l) return MAX;
		else
		{
			int h = (l+r)/2;
			long long int s1 = getMin(L,R,l,h,2*v);
			long long int s2 = getMin(L,R,h+1,r,2*v+1);
			return s1<s2?s1:s2;
		}
	}
}T1;

struct segTree2{
	long long int value[400010];
	void setValue(int ind, long long int val, int l=1, int r=100000, int v=1)
	{
		if(l==r) value[v] = val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v]>value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	long long int getMax(int L, int R, int l=1, int r=100000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return MIN;
		else if(R<l) return MIN;
		else
		{
			int h = (l+r)/2;
			long long int s1 = getMax(L,R,l,h,2*v);
			long long int s2 = getMax(L,R,h+1,r,2*v+1);
			return s1>s2?s1:s2;
		}
	}
}T2;

int x[100010],y[100010];
long long int value[100010],sum[100010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) scanf("%d",&y[i]);
	
	for(int i=1;i<=a;i++) value[i] = y[i]-x[i];
	for(int i=1;i<=a;i++) sum[i] = sum[i-1] + value[i];
	
	for(int i=1;i<=a;i++) T1.setValue(i,sum[i]);
	for(int i=1;i<=a;i++) T2.setValue(i,sum[i]);
	
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		if(T1.getMin(c,d)<sum[c-1]) printf("-1\n");
		else if(T1.getMin(d,d)>sum[c-1]) printf("-1\n");
		else printf("%lld\n",T2.getMax(c,d)-sum[c-1]);
	}
}