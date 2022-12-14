#include <stdio.h>
#include <vector>

std::vector<int> St;
std::vector<int> V[200010],V2[200010];
int check[200010],color[200010];

void findCycle(int k, int prev)
{
	if(check[k]==1)
	{
		for(int i=St.size()-1;i>=0;i--)
		{
			color[St[i]] = 0;
			if(St[i]==k) break;
		}
		return;
	}
	if(check[k]==2) return;
	
	St.push_back(k);
	check[k] = 1;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		findCycle(V[k][i],k);
	}
	check[k] = 2;
	St.pop_back();
}

int func(int k, int prev)
{
	int ans = 1;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev||color[V[k][i]]==0) continue;
		ans += func(V[k][i],k);
	}
	return ans;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		St.clear();
		for(int i=1;i<=a;i++) color[i] = i;
		for(int i=1;i<=a;i++) check[i] = 0;
		for(int i=0;i<=a;i++) V[i].clear();
		for(int i=0;i<=a;i++) V2[i].clear();
		
		for(int i=1;i<=a;i++)
		{
			int b,c;
			scanf("%d%d",&b,&c);
			V[b].push_back(c);
			V[c].push_back(b);
		}
		findCycle(1,0);
		
		long long int ans = 0;
		long long int S0 = 0;
		long long int S1 = 0;
		long long int S2 = 0;
		for(int i=1;i<=a;i++) if(color[i]==0) S0++;
		
		for(int i=1;i<=a;i++)
		{
			if(color[i]==0)
			{
				long long int k = func(i,0)-1;
				ans += k*(k-1)/2;
				ans += (2*S0-1)*k;
				S1 += k;
				S2 += (k*k);
			}
		}
		printf("%lld\n",ans+(S1*S1-S2)+S0*(S0-1));
	}
}