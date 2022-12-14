#include <stdio.h>
#include <vector>
#include <algorithm>

int x[110],y[110];
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
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) scanf("%d",&y[i]);
		
		for(int i=1;i<=a;i++) if(y[i]==0) V.push_back(x[i]);
		std::sort(V.begin(),V.end());
		
		int p = V.size()-1;
		for(int i=1;i<=a;i++) if(y[i]==0) x[i] = V[p--];
		
		for(int i=1;i<=a;i++) printf("%d ",x[i]);
		printf("\n");
	}
}