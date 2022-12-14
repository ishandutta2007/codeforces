#include <stdio.h>
#include <algorithm>
#include <vector>

std::vector<int> V;
int x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+a+1);
		
		int p = 0;
		for(int i=1;i<=a;i++)
		{
			if(x[i]==p)
			{
				printf("%d ",x[i]);
				p++;
			}
			else V.push_back(x[i]);
		}
		for(int i=0;i<V.size();i++) printf("%d ",V[i]);
		printf("\n");
	}
}