#include <stdio.h>
#include <vector>

std::vector<int> V;
int x[10010];
int check[10010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) check[i] = 0;
		
		for(int i=1;i<=2*a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=2*a;i++)
		{
			if(check[x[i]]==1) continue;
			else
			{
				V.push_back(x[i]);
				check[x[i]] = 1;
			}
		}
		for(int i=0;i<V.size();i++) printf("%d " ,V[i]);
		printf("\n");
	}
}