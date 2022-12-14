#include <stdio.h>
#include <vector>
int x[1000010],g[1000010],h[1000010],check[1000010];
std::vector<int> V;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) if(i==x[i]) V.push_back(x[i]);
	for(int i=0;i<V.size();i++) check[V[i]] = 1;
	for(int i=1;i<=a;i++)
	{
		if(check[x[i]]==0)
		{
			printf("-1");
			return 0;
		}
	}
	
	if(V.size()==0) printf("-1");
	else
	{
		int b = V.size();
		for(int i=0;i<b;i++)
		{
			h[i+1] = V[i];
			g[V[i]] = i+1;
		}
		for(int i=1;i<=a;i++)
		{
			if(g[i]==0)
			{
				g[i] = g[x[i]];
			}
			
		}
		
		printf("%d\n",b);
		for(int i=1;i<=a;i++) printf("%d ",g[i]);
		printf("\n");
		for(int i=1;i<=b;i++) printf("%d ",h[i]);
	}
}