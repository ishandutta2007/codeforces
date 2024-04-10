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
		for(int i=9;i>=1;i--)
		{
			if(a>=i)
			{
				V.push_back(i);
				a -= i;
			}
		}
		std::reverse(V.begin(),V.end());
		for(int i=0;i<V.size();i++) printf("%d",V[i]);
		printf("\n");
	}
}