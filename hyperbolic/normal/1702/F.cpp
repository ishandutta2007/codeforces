#include <stdio.h>
#include <set>

int x[200010],y[200010];
std::multiset<int> S1,S2;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		S1.clear();
		S2.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) scanf("%d",&y[i]);
		for(int i=1;i<=a;i++) while(x[i]%2==0) x[i]/=2;
		for(int i=1;i<=a;i++) while(y[i]%2==0) y[i]/=2;
		for(int i=1;i<=a;i++) S1.insert(x[i]);
		for(int i=1;i<=a;i++) S2.insert(y[i]);
		
		while(!S2.empty())
		{
			std::multiset<int> ::iterator it = S2.end();
			it--;
			int val = (*it);
			if(S1.find(val)!=S1.end())
			{
				std::multiset<int> ::iterator it2 = S1.find(val);
				S1.erase(it2);
				S2.erase(it);
			}
			else if(val==1)
			{
				printf("NO\n");
				goto u;
			}
			else
			{
				S2.erase(it);
				S2.insert(val/2);
			}
		}
		printf("YES\n");
		u:;
	}
}