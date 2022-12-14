#include <stdio.h>
#include <set>

std::multiset<int> S;
std::pair<int,int> P[200010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		long long int b;
		scanf("%d%lld",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d%d",&P[i].first,&P[i].second);
		
		long long int min = 1, max = 1000000000;
		long long int ans = 0;
		while(min<=max)
		{
			long long int h = (min+max)/2;
			
			int count = 0;
			long long int sum = 0;
			S.clear();
			
			for(int i=1;i<=a;i++)
			{
				if(P[i].second>=h)
				{
					count++;
					if(h>P[i].first)
					{
						sum += h;
						S.insert(P[i].first-h);
					}
					else sum += P[i].first;
				}
				else sum += P[i].first;
			}
			if(count<(a+1)/2) max = h-1;
			else
			{
				int C = count - (a+1)/2;
				while(C--)
				{
					if(S.empty()) break;
					std::multiset<int> ::iterator it = S.begin();
					sum += (*it);
					S.erase(it);
				}
				if(sum > b) max = h-1;
				else
				{
					ans = h;
					min = h+1;
				}
			}
		}
		
		printf("%lld\n",ans);
	}
}