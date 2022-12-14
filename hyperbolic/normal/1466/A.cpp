#include <stdio.h>
#include <set>

int x[110];
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
		for(int i=1;i<=a;i++) for(int j=i+1;j<=a;j++) S.insert(x[j]-x[i]);
		printf("%d\n",S.size());
	}
}