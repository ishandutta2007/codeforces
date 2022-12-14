#include <stdio.h>
#include <set>

std::multiset<long long int> S;
int x[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) S.insert(x[i]);
	long long int ans = 0;
	if(S.size()%2==0)
	{
		std::multiset<long long int> ::iterator it;
		long long int sum = 0;
		it = S.begin();
		sum += (*it);
		S.erase(it);
		it = S.begin();
		sum += (*it);
		S.erase(it);
		ans += sum;
		S.insert(sum);
	}
	while(S.size()>1)
	{
		std::multiset<long long int> ::iterator it;
		long long int sum = 0;
		it = S.begin();
		sum += (*it);
		S.erase(it);
		it = S.begin();
		sum += (*it);
		S.erase(it);
		it = S.begin();
		sum += (*it);
		S.erase(it);
		
		ans += sum;
		S.insert(sum);
	}
	printf("%lld",ans);
}