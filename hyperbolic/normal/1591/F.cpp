#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
#define MOD 998244353

int x[200010];
std::pair<int,int> y[200010];
std::set<int> S;
int prev[200010];
long long int value[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	for(int i=1;i<=a;i++) y[i] = std::make_pair(x[i],i);
	std::sort(y+1,y+a+1);
	
	S.insert(0);
	for(int i=1;i<=a;i++)
	{
		std::set<int> ::iterator it = S.upper_bound(y[i].second);
		it--;
		prev[y[i].second] = (*it);
		S.insert(y[i].second);
	}
	
	value[0] = 1;
	//value[1] = x[1];
	for(int i=1;i<=a;i++)
	{
		if((i+prev[i])%2==0)
		{
			long long int t;
			if(prev[i]>0) t = value[i-1]-value[prev[i]-1]+MOD;
			else t = value[i-1];
			t%=MOD;
			t *= x[i], t %= MOD;
			if(prev[i]>0) t += (value[prev[i]]+value[prev[i]-1]), t %= MOD;
			value[i] = (t-value[i-1]+MOD)%MOD;
		}
		else
		{
			long long int t;
			if(prev[i]>0) t = value[i-1]+value[prev[i]-1];
			else t = value[i-1];
			t%=MOD;
			t *= x[i], t %= MOD;
			if(prev[i]>0) t += (2*MOD-value[prev[i]]-value[prev[i]-1]), t %= MOD;
			value[i] = (t-value[i-1]+MOD)%MOD;
		}
	}
	
	printf("%lld",(value[a]+value[a-1]+MOD)%MOD);
}