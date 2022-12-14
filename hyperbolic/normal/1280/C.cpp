#include <stdio.h>
#include <vector>
std::vector< std::pair<int,long long int> > V[200010];
int size[200010];
int getSize(int k, int prev)
{
	if(size[k]) return size[k];
	int ans = 1;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i].first==prev) continue;
		ans += getSize(V[k][i].first,k);
	}
	return size[k] = ans;
}

long long int func1(int k, int prev)
{
	long long int ans = 0;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i].first==prev) continue;
		int s = getSize(V[k][i].first,k);
		if(s%2==1) ans += V[k][i].second;
		ans += func1(V[k][i].first,k);
	}
	return ans;
}

long long int func2(int k, int prev, int C)
{
	int maxSize = 0;
	long long int ans = 0;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i].first==prev) continue;
		maxSize = maxSize > getSize(V[k][i].first,k)?maxSize:getSize(V[k][i].first,k);
	}
	if(getSize(k,prev) - maxSize<C)
	{
		for(int i=0;i<V[k].size();i++)
		{
			if(V[k][i].first==prev) continue;
			if(getSize(V[k][i].first,k)==maxSize)
			{
				int C2 = C + maxSize - getSize(k,prev);
				ans += (getSize(V[k][i].first,k)-2*C2)*V[k][i].second;
				ans += func2(V[k][i].first,k,C2);
			}
			else
			{
				ans += getSize(V[k][i].first,k)*V[k][i].second;
				ans += func2(V[k][i].first,k,0);
			}
		}
	}
	else
	{
		for(int i=0;i<V[k].size();i++)
		{
			if(V[k][i].first==prev) continue;
			ans += getSize(V[k][i].first,k)*V[k][i].second;
			ans += func2(V[k][i].first,k,0);
		}
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
		for(int i=1;i<=2*a;i++) size[i] = 0;
		for(int i=1;i<=2*a;i++) V[i].clear();
		
		for(int i=1;i<2*a;i++)
		{
			int b,c,d;
			scanf("%d%d%d",&b,&c,&d);
			V[b].push_back(std::make_pair(c,d));
			V[c].push_back(std::make_pair(b,d));
		}
		printf("%lld %lld\n",func1(1,0),func2(1,0,a));
	}
}