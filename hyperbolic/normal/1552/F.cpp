#include <stdio.h>
#include <vector>
#define MOD 998244353

struct segTree{
	long long int value[800010];
	void setValue(int ind ,long long int val, int l=1, int r=200000, int v=1)
	{
		if(l==r) value[v] = val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			value[v] = (value[2*v] + value[2*v+1])%MOD;
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
			long long int s1 = getSum(L,R,l,h,2*v);
			long long int s2 = getSum(L,R,h+1,r,2*v+1);
			return (s1+s2)%MOD;
		}
	}
}T;

struct str{
	int first;
	int second;
	int type;
}x[200010];
std::vector<int> V;
long long int sum[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c,d;
		scanf("%d%d%d",&b,&c,&d);
		x[i]={b,c,d};
	}
	x[a+1] = {x[a].first+1,0,0};
	
	V.push_back(0);
	for(int i=1;i<=a;i++)
	{
		V.push_back(x[i].first);
		int p = 0;
		int min = 1, max = i;
		while(min<=max)
		{
			int h = (min+max)/2;
			if(V[h]>=x[i].second)
			{
				p = h;
				max = h-1;
			}
			else min = h+1;
		}
		sum[i] = (x[p].first-x[i].second) + T.getSum(p,i-1) + (x[i+1].first-x[i].first);
		sum[i] %= MOD;
		T.setValue(i,sum[i]);
	}
	
	long long int ans = x[1].first;
	for(int i=1;i<=a;i++)
	{
		if(x[i].type==0) ans += (x[i+1].first-x[i].first);
		else ans += sum[i];
		ans %= MOD;
	}
	printf("%lld",ans);
}