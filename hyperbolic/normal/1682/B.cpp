#include <stdio.h>
#include <vector>
int x[200010];
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
		for(int i=1;i<=a;i++) if(x[i]!=i-1) V.push_back(x[i]);
		if(V.size()==0) printf("0\n");
		else
		{
			int ans = V[0];
			for(int i=1;i<V.size();i++) ans &= V[i];
			printf("%d\n",ans);
		}
	}
}