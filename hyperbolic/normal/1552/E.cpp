#include <stdio.h>
#include <vector>

struct segTree{
	int value[40010],lazy[40010];
	void addValue(int L, int R, int val, int l=1, int r=10000, int v=1)
	{
		if(L<=l&&r<=R) value[v] += val, lazy[v] += val;
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] += lazy[v], value[2*v+1] += lazy[v];
				lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			addValue(L,R,val,l,h,2*v);
			addValue(L,R,val,h+1,r,2*v+1);
			value[v] = value[2*v]>value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	int getMax(int L, int R, int l=1, int r=10000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] += lazy[v], value[2*v+1] += lazy[v];
				lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			int s1 = getMax(L,R,l,h,2*v);
			int s2 = getMax(L,R,h+1,r,2*v+1);
			return s1>s2?s1:s2;
		}
	}
}T;
int x[10010];
int last[110],check[110];
std::pair<int,int> ans[110];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int limit;
	if(a%(b-1)==0) limit = a/(b-1);
	else limit = a/(b-1)+1;
	
	for(int i=1;i<=a*b;i++) scanf("%d",&x[i]);
	for(int i=a*b;i>=1;i--)
	{
		if(check[x[i]]) continue;
		if(last[x[i]]==0) last[x[i]] = i;
		else
		{
			int t = T.getMax(i,last[x[i]]);
			if(t<limit)
			{
				check[x[i]] = 1;
				ans[x[i]] = std::make_pair(i,last[x[i]]);
				T.addValue(i,last[x[i]],1);
			}
			last[x[i]] = i;
		}
	}
	
	for(int i=1;i<=a;i++) printf("%d %d\n",ans[i].first,ans[i].second);
}