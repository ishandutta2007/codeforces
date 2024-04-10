#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<int> V;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		int a,b;
		scanf("%d%d",&a,&b);
		if(a>b)
		{
			int temp = a;
			a = b;
			b = temp;
		}
		int s1 = (a+b)/2;
		int s2 = (a+b) - s1;
		for(int i=0;i<=a&&i<=s1;i++) V.push_back(s1-i + a-i);
		for(int i=0;i<=a&&i<=s2;i++) V.push_back(s2-i + a-i);
		
		std::sort(V.begin(),V.end());
		V.erase(std::unique(V.begin(),V.end()),V.end());
		
		printf("%d\n",V.size());
		for(int i=0;i<V.size();i++) printf("%d ",V[i]);
		printf("\n");
	}
}