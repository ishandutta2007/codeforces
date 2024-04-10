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
		long long int ans = 0;
		for(int i=a;i>=1;i-=2)
		{
			if(i==1) V.push_back(1);
			else
			{
				V.push_back(i-1);
				V.push_back(i);
			}
		}
		std::reverse(V.begin(),V.end());
		
		for(int i=0;i<V.size();i++) printf("%d ",V[i]);
		printf("\n");
	}
}