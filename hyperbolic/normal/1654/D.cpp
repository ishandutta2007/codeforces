#include <stdio.h>
#include <vector>
#include <algorithm>
#define MOD 998244353

struct segTree{
	long long int value[800010],lazy[800010];
	void mulValue(int L, int R, long long int val, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R)
		{
			value[v] = (value[v]*val)%MOD;
			lazy[v] = (lazy[v]*val)%MOD;
		}
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=1)
			{
				value[2*v] = (value[2*v]*lazy[v])%MOD, value[2*v+1] = (value[2*v+1]*lazy[v])%MOD;
				lazy[2*v] = (lazy[2*v]*lazy[v])%MOD, lazy[2*v+1] = (lazy[2*v+1]*lazy[v])%MOD;
				lazy[v] = 1;
			}
			mulValue(L,R,val,l,h,2*v);
			mulValue(L,R,val,h+1,r,2*v+1);
			value[v] = (value[2*v]+value[2*v+1])%MOD;
		}
	}
	long long int getSum(int L, int R, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=1)
			{
				value[2*v] = (value[2*v]*lazy[v])%MOD, value[2*v+1] = (value[2*v+1]*lazy[v])%MOD;
				lazy[2*v] = (lazy[2*v]*lazy[v])%MOD, lazy[2*v+1] = (lazy[2*v+1]*lazy[v])%MOD;
				lazy[v] = 1;
			}
			long long int s1 = getSum(L,R,l,h,2*v);
			long long int s2 = getSum(L,R,h+1,r,2*v+1);
			return (s1+s2)%MOD;
		}
	}
	void clear(int L, int R, int l=1, int r=200000, int v=1)
	{
		if(l==r)
		{
			lazy[v] = 1;
			value[v] = 1;
			return;
		}
		if(r<L) return;
		if(R<l) return;
		
		int h = (l+r)/2;
		clear(L,R,l,h,2*v);
		clear(L,R,h+1,r,2*v+1);
		lazy[v] = 1;
		value[v] = (value[2*v]+value[2*v+1])%MOD;
	}
}T2;

struct segTree2{
	int value[800010],lazy[800010];
	void addValue(int L, int R, int val, int l=1, int r=200000, int v=1)
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
			value[v] = value[2*v]<value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	int getMin(int L, int R, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 12345678;
		else if(R<l) return 12345678;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] += lazy[v], value[2*v+1] += lazy[v];
				lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			int s1 = getMin(L,R,l,h,2*v);
			int s2 = getMin(L,R,h+1,r,2*v+1);
			return s1<s2?s1:s2;
		}
	}
	void clear(int L, int R, int l=1, int r=200000, int v=1)
	{
		if(l==r)
		{
			lazy[v] = 0;
			value[v] = 0;
			return;
		}
		if(r<L) return;
		if(R<l) return;
		
		int h = (l+r)/2;
		clear(L,R,l,h,2*v);
		clear(L,R,h+1,r,2*v+1);
		lazy[v] = 0;
		value[v] = value[2*v]<value[2*v+1]?value[2*v]:value[2*v+1];
	}
}T1;

struct str{
	int first;
	long long int value1;
	long long int value2;
};
std::vector<str> query[200010];
std::vector<str> V[200010];
int left[200010],right[200010],height[200010];
int init(int k, int prev, int h ,int& C)
{
	left[k] = C++;
	right[k] = left[k];
	height[k] = h+1;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i].first==prev) continue;
		if(height[V[k][i].first]!=0) continue;
		right[k] = init(V[k][i].first,k,h+1,C);
	}
	return right[k];
}

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		k*=k, k%=MOD;
		b/=2;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}

long long int gcd(long long int a, long long int b)
{
	return a?gcd(b%a,a):b;
}

std::vector< std::pair<int,int> > event;
std::vector<int> prime[200010];
int main()
{
	for(int i=2;i<=200000;i++)
	{
		if(prime[i].size()==0)
		{
			for(int j=i;j<=200000;j+=i) prime[j].push_back(i);
		}
	}
	int Case;
	scanf("%d",&Case);
	while(Case--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) query[i].clear();
		
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=1;i<=a;i++) left[i] = right[i] = height[i] = 0;
		
		for(int i=1;i<a;i++)
		{
			int c,d,e,f,g;
			scanf("%d%d%d%d",&c,&d,&e,&f);
			g = gcd(e,f);
			e/=g, f/=g;
			V[c].push_back({d,e,f});
			V[d].push_back({c,f,e});
		}
		
		int C = 1;
		init(1,0,1,C);
		
		for(int i=1;i<=a;i++)
		{
			for(int j=0;j<V[i].size();j++)
			{
				if(height[V[i][j].first]>height[i])
				{
					int L = left[V[i][j].first], R = right[V[i][j].first];
					int val, val2;
					val = V[i][j].value1, val2 = V[i][j].value1;
					for(int k=0;k<prime[val].size();k++)
					{
						int C = 0;
						while(val2%prime[val][k]==0) C++, val2/=prime[val][k];
						query[prime[val][k]].push_back({C,1,L-1});
						query[prime[val][k]].push_back({C,R+1,a});
					}
					val = V[i][j].value2, val2 = V[i][j].value2;
					for(int k=0;k<prime[val].size();k++)
					{
						int C = 0;
						while(val2%prime[val][k]==0) C++, val2/=prime[val][k];
						query[prime[val][k]].push_back({C,L,R});
					}
				}
			}
		}
		
		T2.clear(1,a);
		for(int i=2;i<=a;i++)
		{
			if(prime[i].size()==1)
			{
				event.clear();
				for(int j=0;j<query[i].size();j++)
				{
					event.push_back(std::make_pair(query[i][j].value1,query[i][j].first));
					event.push_back(std::make_pair(query[i][j].value2+1,-query[i][j].first));
					T2.mulValue(query[i][j].value1, query[i][j].value2,power(i,query[i][j].first));
				}
				std::sort(event.begin(),event.end());
				
				if(event.size()==0) continue;
				if(event[0].first>1) continue;
				int min = 12345678;
				int sum = event[0].second;
				for(int i=1;i<event.size();i++)
				{
					if(event[i].first==a+1) break;
					if(event[i].first!=event[i-1].first) min = min<sum?min:sum;
					sum += event[i].second;
				}
				min = min<sum?min:sum;
				T2.mulValue(1,a,inv(power(i,min)));
			}
		}
		
		printf("%lld\n",T2.getSum(1,a));
	}
}