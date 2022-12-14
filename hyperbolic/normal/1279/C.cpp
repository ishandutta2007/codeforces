#include <stdio.h>

struct segTree{
	int value[400010];
	void addValue(int ind ,int val, int l=1, int r=100000, int v=1)
	{
		if(l==r) value[v] += val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) addValue(ind,val,l,h,2*v);
			else addValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v] + value[2*v+1];
		}
	}
	int getSum(int L, int R, int l=1, int r=100000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			int s1 = getSum(L,R,l,h,2*v);
			int s2 = getSum(L,R,h+1,r,2*v+1);
			return s1+s2;
		}
	}
}T;

int index[100010];
int main()
{
	int Case;
	scanf("%d",&Case);
	while(Case--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) T.addValue(i,-T.getSum(i,i));
		
		for(int i=1;i<=a;i++)
		{
			int c;
			scanf("%d",&c);
			index[c] = i;
		}
		
		long long int ans = 0;
		int limit = 0;
		for(int i=1;i<=b;i++)
		{
			int c;
			scanf("%d",&c);
			int d = index[c];
			if(limit>=d) ans++;
			else
			{
				ans += (2*(d-1-T.getSum(1,d-1))+1);
				limit = d;
			}
			T.addValue(d,1);
		}
		printf("%lld\n",ans);
	}
}