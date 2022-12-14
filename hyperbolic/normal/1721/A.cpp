#include <stdio.h>
#include <vector>
#include <algorithm>

char x[110][110];
std::vector<char> V;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=1;i<=2;i++) scanf("%s",x[i]+1);
		V.clear();
		for(int i=1;i<=2;i++) for(int j=1;j<=2;j++) V.push_back(x[i][j]);
		std::sort(V.begin(),V.end());
		V.erase(std::unique(V.begin(),V.end()),V.end());
		printf("%d\n",V.size()-1);
	}
}