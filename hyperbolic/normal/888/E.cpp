#include <stdio.h>
#include <set>

int b;
int x[110];
std::set<long long int> S[3];
void func(int s, int t, long long int sum, int type)
{
	if(s>t)
	{
		S[type].insert(sum);
		return;
	}
	
	func(s+1,t,sum,type);
	func(s+1,t,(sum+x[s])%b,type);
}

int main()
{
	int a;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int c = (a/2);
	func(1,c,0,1);
	func(c+1,a,0,2);
	
	long long int ans = 0;
	for(std::set<long long int> ::iterator it = S[1].begin();it != S[1].end();it++)
	{
		long long int val = (*it);
		std::set<long long int> ::iterator it2 = S[2].lower_bound(b-val);
		if(it2!=S[2].begin())
		{
			it2--;
			ans = ans>val+(*it2)?ans:val+(*it2);
		}
		it2 = S[2].end();
		if(it2!=S[2].begin())
		{
			it2--;
			ans = ans>val+(*it2)-b?ans:val+(*it2)-b;
		}
	}
	printf("%lld",ans);
}