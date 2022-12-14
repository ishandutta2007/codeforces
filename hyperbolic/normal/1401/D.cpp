#include <stdio.h>
#include <vector>
#include <algorithm>
#define MOD 1000000007

int a;
int size[100010];
std::vector<int> V[100010];
std::vector<long long int> save;

int getSize(int k, int prev)
{
	if(size[k]) return size[k];
	int ans = 1;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		ans += getSize(V[k][i],k);
	}
	return size[k] = ans;
}
void func(int k, int prev)
{
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		long long int t = getSize(V[k][i],k);
		save.push_back(t*(long long int)(a-t));
		func(V[k][i],k);
	}
}

int x[100010];
long long int y[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&a);
		for(int i=1;i<=a;i++) size[i] = 0;
		for(int i=1;i<=a;i++) V[i].clear();
		save.clear();
		
		for(int i=1;i<a;i++)
		{
			int b,c;
			scanf("%d%d",&b,&c);
			V[b].push_back(c);
			V[c].push_back(b);
		}
		func(1,0);
		std::sort(save.begin(),save.end());
		
		int b;
		scanf("%d",&b);
		for(int i=1;i<=b;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+b+1);
		
		if(b<=a-1)
		{
			for(int i=1;i<=(a-1-b);i++) y[i] = 1;
			for(int i=(a-b);i<=a-1;i++) y[i] = x[i-(a-b)+1];
		}
		else
		{
			y[a-1] = 1;
			for(int i=1;i<=a-2;i++) y[i] = x[i];
			for(int i=a-1;i<=b;i++)
			{
				y[a-1] *= x[i];
				y[a-1] %= MOD;
			}
		}
		
		
		long long int ans = 0;
		for(int i=0;i<save.size();i++) save[i]%=MOD;
		for(int i=1;i<=a-1;i++)
		{
			long long int S = save[i-1]*y[i];
			ans += (S%MOD);
			ans %= MOD;
		}
		printf("%lld\n",ans);
	}
}