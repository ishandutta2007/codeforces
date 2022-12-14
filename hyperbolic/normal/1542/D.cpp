#include <stdio.h>
#include <vector>
#define MOD 998244353

int a;
long long int check[510][510];
std::vector< std::pair<int,int> > query;

long long int func(int s, int t, int target)
{
	if(s>=a) return 1;
	if(check[s][t]!=-1) return check[s][t];
	if(s==target) return check[s][t] = func(s+1,t,target);
	else
	{
		if(query[s].first==1)
		{
			if(query[s].second>query[target].second)
			{
				long long int s1 = func(s+1,t,target);
				long long int s2 = func(s+1,t,target);
				return check[s][t] = (s1+s2)%MOD;
			}
			else if(query[s].second==query[target].second)
			{
				if(s<target)
				{
					long long int s1 = func(s+1,t,target);
					long long int s2 = func(s+1,t+1,target);
					return check[s][t] = (s1+s2)%MOD;
				}
				else
				{
					long long int s1 = func(s+1,t,target);
					long long int s2 = func(s+1,t,target);
					return check[s][t] = (s1+s2)%MOD;
				}
			}
			else
			{
				long long int s1 = func(s+1,t,target);
				long long int s2 = func(s+1,t+1,target);
				return check[s][t] = (s1+s2)%MOD;
			}
		}
		else
		{
			if(t>0)
			{
				long long int s1 = func(s+1,t,target);
				long long int s2 = func(s+1,t-1,target);
				return check[s][t] = (s1+s2)%MOD;
			}
			else
			{
				if(s<target)
				{
					long long int s1 = func(s+1,t,target);
					long long int s2 = func(s+1,t,target);
					return check[s][t] = (s1+s2)%MOD;
				}
				else return check[s][t] = func(s+1,t,target);
			}
		}
	}
}

char x[10];
int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%s",x+1);
		if(x[1]=='-') query.push_back(std::make_pair(-1,0));
		else
		{
			int b;
			scanf("%d",&b);
			query.push_back(std::make_pair(1,b));
		}
	}
	
	long long int ans = 0;
	for(int i=0;i<a;i++)
	{
		if(query[i].first==1)
		{
			for(int j=0;j<a;j++) for(int k=0;k<a;k++) check[j][k] = -1;
			long long int t = func(0,0,i);
			t *= query[i].second, t %= MOD;
			ans += t, ans %= MOD;
		}
	}
	printf("%lld",ans);
	
}