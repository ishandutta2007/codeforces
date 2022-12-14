#include <stdio.h>
#include <vector>
std::vector<int> V;
int check[110],x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) check[i] = 0;
		for(int i=1;i<=a;i++) check[x[i]] = 1;
		
		V.clear();
		for(int i=1;i<=a;i++) if(check[i]==1) V.push_back(i);
		if(V.size()>b)
		{
			printf("-1\n");
			continue;
		}
		else
		{
			printf("%d\n",b*a);
			for(int i=1;i<=a;i++)
			{
				for(int j=0;j<V.size();j++) printf("%d ",V[j]);
				for(int j=V.size();j<b;j++) printf("%d ",1);
			}
			printf("\n");
		}
	}
}