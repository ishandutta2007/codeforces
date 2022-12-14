#include <stdio.h>
#include <vector>
#define MAX (long long int)1e16

struct segTree{
	long long int value[800010];
	void setValue(int ind, long long int val, int l=1, int r=200000, int v=1)
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
	long long int getMin(int L, int R, int l=1, int r=200000, int v=1)
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
}T;

long long int x[200010];
int main()
{
	int Case;
	scanf("%d",&Case);
	while(Case--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
		for(int i=1;i<=a;i++) x[i] += x[i-1];
		for(int i=1;i<=a;i++) T.setValue(i,x[i]);
		
		int ans1 = 0;
		std::pair<int,int> ans2 = std::make_pair(-1,-1);
		
		for(int i=1;i<=a;i++)
		{
			int min = i, max = a;
			int p = i-1;
			while(min<=max)
			{
				int h = (min+max)/2;
				if(T.getMin(i,h)-x[i-1]+b>=0)
				{
					p = h;
					min = h+1;
				}
				else max = h-1;
			}
			
			if(p-i+1>ans1)
			{
				ans1 = p-i+1;
				ans2 = std::make_pair(i,p);
			}
		}
		
		if(ans1==0) printf("-1\n");
		else printf("%d %d\n",ans2.first,ans2.second);
	}
}