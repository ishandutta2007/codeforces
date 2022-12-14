#include <stdio.h>
#include <vector>

std::vector<int> V[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b].push_back(c);
		V[c].push_back(b);
	}
	for(int i=1;i<=a;i++)
	{
		if(V[i].size()==2)
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
}