#include <stdio.h>
#include <map>
#include <set>

std::multiset<long long int> S;
std::map< std::pair<int,int> , long long int> M;
long long int value[300010];
int main()
{
	int a;
	scanf("%d",&a);
	long long int sum = 0;
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		sum += b;
		S.insert(c-b);
	}
	value[0] = sum;
	for(int i=1;i<=a;i++)
	{
		std::multiset<long long int> ::iterator it = S.end();
		it--;
		value[i] = value[i-1] + (*it);
		S.erase(it);
	}
	
	int b;
	scanf("%d",&b);
	while(b--)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		if(M.find(std::make_pair(c,d))!=M.end()) printf("%lld\n",M[std::make_pair(c,d)]);
		else
		{
			long long int ans = -1;
			if(c<d)
			{
				for(int i=0;i<=a;i+=d) if((a-i)%c==0) ans = ans>value[i]?ans:value[i];
			}
			else
			{
				for(int i=0;i<=a;i+=c) if((a-i)%d==0) ans = ans>value[a-i]?ans:value[a-i];
			}
			M[std::make_pair(c,d)] = ans;
			printf("%lld\n",ans);
		}
	}
}