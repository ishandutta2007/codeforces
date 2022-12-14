#include <stdio.h>
#include <vector>

struct segTree{
	long long int value[1600010];
	int lazy[1600010];
	void addValue(int ind, long long int val, int l=0, int r=400000, int v=1)
	{
		if(l==r) value[v] += val;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]==1)
			{
				lazy[2*v] = lazy[2*v+1] = 1;
				value[2*v] = value[2*v+1] = 0;
				lazy[v] = 0;
			}
			
			if(ind<=h) addValue(ind,val,l,h,2*v);
			else addValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v] + value[2*v+1];
		}
	}
	long long int getSum(int L, int R, int l=0, int r=400000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]==1)
			{
				lazy[2*v] = lazy[2*v+1] = 1;
				value[2*v] = value[2*v+1] = 0;
				lazy[v] = 0;
			}
			long long int s1 = getSum(L,R,l,h,2*v);
			long long int s2 = getSum(L,R,h+1,r,2*v+1);
			return s1+s2;
		}
	}
	void clear(int L, int R, int l=0, int r=400000, int v=1)
	{
		if(L<=l&&r<=R)
		{
			value[v] = 0;
			lazy[v] = 1;
		}
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			if(lazy[v]==1)
			{
				lazy[2*v] = lazy[2*v+1] = 1;
				value[2*v] = value[2*v+1] = 0;
				lazy[v] = 0;
			}
			clear(L,R,l,h,2*v);
			clear(L,R,h+1,r,2*v+1);
			value[v] = value[2*v] + value[2*v+1];
		}
	}
}T,count;

char x[200010];
int y[200010];
int main()
{
	int Case;
	scanf("%d",&Case);
	while(Case--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		for(int i=1;i<=a;i++)
		{
			if(x[i]=='(') y[i] = 1;
			else y[i] = -1;
		}
		
		long long int ans = 0;
		int S = 0;
		T.clear(0,400000);
		count.clear(0,400000);
		for(int i=a;i>=1;i--)
		{
			S -= y[i];
			if(y[i]<0)
			{
				T.addValue(S+y[i]+200000,S+y[i]);
				count.addValue(S+y[i]+200000,1);
			}
			else
			{
				T.addValue(S+200000,S);
				count.addValue(S+200000,1);
			}
			
			long long int val1 = T.getSum(0,S+200000);
			long long int val2 = count.getSum(0,S+200000);
			long long int val = val1 - S*val2;
			ans -= val;
			
			long long int val4 = count.getSum(S+1+200000, 400000);
			T.addValue(S+200000,val4*S);
			count.addValue(S+200000,val4);
			T.clear(S+1+200000,400000);
			count.clear(S+1+200000,400000);
		}
		
		S = 0;
		T.clear(0,400000);
		count.clear(0,400000);
		for(int i=1;i<=a;i++)
		{
			S -= y[i];
			T.addValue(S+y[i]+200000,S+y[i]);
			count.addValue(S+y[i]+200000,1);
			
			long long int val1 = T.getSum(S+200000,400000);
			long long int val2 = count.getSum(S+200000,400000);
			long long int val = val1 - S*val2;
			ans += val;
		}
		
		printf("%lld\n",ans);
	}
}