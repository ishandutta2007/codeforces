#include <stdio.h>
#include <vector>
#include <algorithm>

struct str{
	int value[800010];
	void setValue(int ind, int val, int l=1, int r=200000, int v=1)
	{
		if(l==r) value[v] = value[v]>val?value[v]:val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v]>value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	int getMax(int L, int R, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(R<l) return 0;
		else if(r<L) return 0;
		else
		{
			int h = (l+r)/2;
			int s1 = getMax(L,R,l,h,2*v);
			int s2 = getMax(L,R,h+1,r,2*v+1);
			return s1>s2?s1:s2;
		}
	}
	void clear(int ind, int l=1, int r=200000, int v=1)
	{
		value[v] = 0;
		if(l==r) return;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) clear(ind,l,h,2*v);
			else clear(ind,h+1,r,2*v+1);
		}
	}
}T1,T2;

int x[200010],DP[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++)
		{
			T1.clear(i);
			T2.clear(i);
		}
		
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		int b;
		scanf("%d",&b);
		for(int i=1;i<=b;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			T1.setValue(d,c);
		}
		
		for(int i=1;i<=a;i++) T2.setValue(i,x[i]);
		
		DP[0] = 0;
		for(int i=1;i<=a;i++)
		{
			int min = 0, max = i-1;
			int ans = i;
			while(min<=max)
			{
				int h = (min+max)/2;
				//from h
				if(T2.getMax(h+1,i)<=T1.getMax(i-h,a))
				{
					ans = h;
					max = h-1;
				}
				else min = h+1;
			}
			if(ans==i)
			{
				printf("-1\n");
				goto u;
			}
			DP[i] = DP[ans]+1;
		}
		printf("%d\n",DP[a]);
		u:;
	}
}