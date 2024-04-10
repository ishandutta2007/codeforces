#include <stdio.h>
#include <vector>

int a;
std::pair<int,long long int> check[100010];
int x[100010];
std::pair<int,long long int> func(int k)
{
	if(k>=a) return std::make_pair(0,0);
	else if(check[k].first!=0) return check[k];
	else
	{
		long long int limit = x[k-1]>x[k+1]?x[k-1]:x[k+1];
		limit++;
		
		long long int ans = 0;
		if(limit>x[k]) ans = limit-x[k];
		int count = 1;
		
		std::pair<int, long long int> P1 = func(k+2);
		std::pair<int, long long int> P2 = func(k+3);
		if(P1.first<P2.first) count += P2.first, ans += P2.second;
		else if(P1.first>P2.first) count += P1.first, ans += P1.second;
		else
		{
			if(P1.second<P2.second) count += P1.first, ans += P1.second;
			else count += P2.first, ans += P2.second;
		}
		return check[k] = std::make_pair(count,ans);
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&a);
		for(int i=0;i<=a+1;i++) x[i] = 0;
		for(int i=0;i<=a+1;i++) check[i] = std::make_pair(0,0);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		std::pair<int, long long int> P1 = func(2);
		std::pair<int, long long int> P2 = func(3);
		if(P1.first<P2.first) printf("%lld\n",P2.second);
		else if(P1.first>P2.first) printf("%lld\n",P1.second);
		else printf("%lld\n",P1.second<P2.second?P1.second:P2.second);
	}
}