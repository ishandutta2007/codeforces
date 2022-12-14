#include <stdio.h>
#include <vector>
#include <algorithm>
#define MOD 1000000007

struct segTree{
	long long int value[2000010];
	long long int lazy[2000010];
	void addValue(int L, int R, int val, int l=0, int r=500000 ,int v=1)
	{
		if(L<=l&&r<=R) value[v] += (long long int)(r-l+1)*val, lazy[v] += val;
		else if(r<L) return;
		else if(R<l) return;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] += (long long int)(h-l+1)*lazy[v], lazy[2*v] += lazy[v];
				value[2*v+1] += (long long int)(r-h)*lazy[v], lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			addValue(L,R,val,l,h,2*v);
			addValue(L,R,val,h+1,r,2*v+1);
			value[v] = value[2*v] + value[2*v+1];
		}
	}
	long long int getSum(int L, int R, int l=0, int r=500000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] += (long long int)(h-l+1)*lazy[v], lazy[2*v] += lazy[v];
				value[2*v+1] += (long long int)(r-h)*lazy[v], lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			return getSum(L,R,l,h,2*v) + getSum(L,R,h+1,r,2*v+1);
		}
	}
}T;

std::vector< std::pair<int,int> > V;
int x[500010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) V.push_back(std::make_pair(x[i],i));
	std::sort(V.begin(),V.end());
	
	
	long long int ans = 0;
	for(int i=0;i<V.size();i++)
	{
		int val = V[i].first;
		int ind = V[i].second;
		T.addValue(ind,a,1);
		
		long long int sum1 = T.getSum(0,ind-1);
		long long int sum2 = T.getSum(ind,a);
		ans += ((sum2*ind - sum1*(a-ind+1))%MOD)*val;
		ans %= MOD;
	}
	printf("%lld",ans);
}