#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>

std::vector<int> V;
std::map<int,int> count;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		count.clear();
		V.clear();
		
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			count[b]++;
		}
		for(std::map<int,int> ::iterator it = count.begin(); it!=count.end();it++) V.push_back(it->second);
		std::sort(V.begin(),V.end());
		
		int ans = 0;
		for(int i=0;i<V.size();i++) ans = ans>V[i]*(V.size()-i)?ans:V[i]*(V.size()-i);
		printf("%d\n",a-ans);
	}
}