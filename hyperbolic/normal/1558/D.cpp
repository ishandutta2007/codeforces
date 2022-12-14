#include <stdio.h>
#include <vector>
#include <algorithm>
#define MOD 998244353

struct segTree{
	int value[800010];
	int lazy[800010];
	void setValue(int L, int R, int val, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) value[v] = (r-l+1)*val, lazy[v] = val;
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=-1)
			{
				value[2*v] = (h-l+1)*lazy[v], value[2*v+1] = (r-h) * lazy[v];
				lazy[2*v] = lazy[v], lazy[2*v+1] = lazy[v];
				lazy[v] = -1;
			}
			setValue(L,R,val,l,h,2*v);
			setValue(L,R,val,h+1,r,2*v+1);
			value[v] = value[2*v] + value[2*v+1];
		}
	}
	int getSum(int L, int R, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=-1)
			{
				value[2*v] = (h-l+1)*lazy[v], value[2*v+1] = (r-h) * lazy[v];
				lazy[2*v] = lazy[v], lazy[2*v+1] = lazy[v];
				lazy[v] = -1;
			}
			int s1 = getSum(L,R,l,h,2*v);
			int s2 = getSum(L,R,h+1,r,2*v+1);
			return s1+s2;
		}
	}
}T;

long long int fact[400010];
long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		b/=2;
		k*=k, k%=MOD;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}
long long int comb(int a, int b)
{
	long long int ans = fact[a];
	ans *= inv(fact[b]), ans %= MOD;
	ans *= inv(fact[a-b]), ans %= MOD;
	return ans;
}

int value[200010];
std::pair<int,int> x[200010];
std::vector<int> V;
int main()
{
	fact[0] = 1;
	for(int i=1;i<=400000;i++) fact[i] = (i*fact[i-1])%MOD;
	
	int Case;
	scanf("%d",&Case);
	while(Case--)
	{
		V.clear();
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=b;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			x[i] = std::make_pair(c,d);
		}
		T.setValue(1,a,1);
		
		for(int i=b;i>=1;i--)
		{
			int min = 1, max = a;
			int p = 0;
			while(min<=max)
			{
				int h = (min+max)/2;
				if(T.getSum(1,h)>=x[i].second)
				{
					p = h;
					max = h-1;
				}
				else min = h+1;
			}
			value[i] = p;
			T.setValue(p,p,0);
		}
		
		T.setValue(1,a,1);
		for(int i=1;i<=b;i++) T.setValue(value[i],value[i],0);
		for(int i=1;i<=b;i++)
		{
			int min = value[i]+1, max = a;
			int p = 0;
			while(min<=max)
			{
				int h = (min+max)/2;
				if(T.getSum(value[i]+1,h)>=1)
				{
					p = h;
					max = h-1;
				}
				else min = h+1;
			}
			V.push_back(p);
			T.setValue(value[i],value[i],1);
		}
		
		std::sort(V.begin(),V.end());
		V.erase(std::unique(V.begin(),V.end()),V.end());
		
		printf("%lld\n",comb(a+(a-1-V.size()),a));
	}
}