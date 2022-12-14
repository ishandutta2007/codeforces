#include <stdio.h>

struct segTree{
	long long int value[1200010];
	int swap[30];
	int level[1200010];
	segTree()
	{
		level[0] = 19;
		for(int i=1;i<=1200000;i++) level[i] = level[i/2]-1;
	}
	
	void replace(int ind, int val, int l=1, int r = (1<<18), int v=1)
	{
		if(l==r) value[v] = val;
		else
		{
			int h = (l+r)/2;
			if(swap[level[v]-1]==1)
			{
				if(ind<=h) replace(ind,val,l,h,2*v+1);
				else replace(ind,val,h+1,r,2*v);
			}
			else
			{
				if(ind<=h) replace(ind,val,l,h,2*v);
				else replace(ind,val,h+1,r,2*v+1);
			}
			value[v] = value[2*v] + value[2*v+1];
		}
	}
	void toSwap(int k)
	{
		swap[k] = (swap[k]+1)%2;
	}
	long long int getSum(int L, int R, int l=1, int r=(1<<18), int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(R<l) return 0;
		else if(r<L) return 0;
		else
		{
			int h = (l+r)/2;
			if(swap[level[v]-1]==1)
			{
				long long int s1 = getSum(L,R,l,h,2*v+1);
				long long int s2 = getSum(L,R,h+1,r,2*v);
				return s1+s2;
			}
			else
			{
				long long int s1 = getSum(L,R,l,h,2*v);
				long long int s2 = getSum(L,R,h+1,r,2*v+1);
				return s1+s2;
			}
		}
	}
		
}T;


int main()
{
	int c,b;
	scanf("%d%d",&c,&b);
	int a = (1<<c);
	for(int i=1;i<=a;i++)
	{
		int d;
		scanf("%d",&d);
		T.replace(i,d);
	}
	for(int i=1;i<=b;i++)
	{
		int d;
		scanf("%d",&d);
		if(d==1)
		{
			int e,f;
			scanf("%d%d",&e,&f);
			T.replace(e,f);
		}
		if(d==2)
		{
			int e;
			scanf("%d",&e);
			for(int j=e-1;j>=0;j--) T.toSwap(j);
		}
		if(d==3)
		{
			int e;
			scanf("%d",&e);
			T.toSwap(e);
		}
		if(d==4)
		{
			int e,f;
			scanf("%d%d",&e,&f);
			printf("%lld\n",T.getSum(e,f));
		}
	}
}