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
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			V.push_back(b);
		}
		std::sort(V.begin(),V.end());
		V.erase(std::unique(V.begin(),V.end()),V.end());
		if(V.size()==1) printf("1\n");
		else if(V.size()==2) printf("%d\n",a/2 + 1);
		else printf("%d\n",a);
	}
}