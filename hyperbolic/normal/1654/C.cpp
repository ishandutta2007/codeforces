#include <stdio.h>
#include <set>
#include <algorithm>

long long int x[200010];
std::multiset<long long int> S;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		S.clear();
		int a;
		scanf("%d",&a);
		long long int sum = 0;
		for(int i=1;i<=a;i++)
		{
			long long int b;
			scanf("%lld",&b);
			sum += b;
			x[i] = b;
		}
		std::sort(x+1,x+a+1);
		
		int p = a, C = 1;
		S.insert(sum);
		while(C<=a && S.size()>0)
		{
			std::multiset<long long int> ::iterator it = S.end();
			it--;
			if((*it)<x[p])
			{
				printf("NO\n");
				goto u;
			}
			else if((*it)>x[p])
			{
				long long int val = (*it);
				S.erase(it);
				S.insert(val/2);
				S.insert((val+1)/2);
				C++;
			}
			else
			{
				p--;
				S.erase(it);
			}
		}
		if(p==0) printf("YES\n");
		else printf("NO\n");
		u:;
	}
}