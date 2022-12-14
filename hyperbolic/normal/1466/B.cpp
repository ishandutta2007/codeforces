#include <stdio.h>
#include <set>

int x[100010];
std::set<int> S;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		S.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=2;i<=a;i++) if(x[i]<=x[i-1]) x[i]++;
		for(int i=1;i<=a;i++) S.insert(x[i]);
		printf("%d\n",S.size());
	}
}