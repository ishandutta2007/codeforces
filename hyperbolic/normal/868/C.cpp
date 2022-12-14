#include <stdio.h>
#include <set>
#include <vector>
std::set<int> S;

std::vector<int> func(int k,int t)
{
	std::vector<int> V;
	for(int i=0;i<(1<<t);i++) if((k&i)==0) V.push_back(i);
	return V;
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		int sum = 0,c;
		for(int j=1;j<=b;j++)
		{
			scanf("%d",&c);
			sum*=2;
			sum+=c;
		}
		S.insert(sum);
	}
	for(int i=0;i<(1<<b);i++)
	{
		if(S.find(i)!=S.end())
		{
			std::vector<int> V = func(i,b);
			for(int j=0;j<V.size();j++)
			{
				if(S.find(V[j])!=S.end())
				{
					printf("YES");
					return 0;
				}
			}
		}
	}
	printf("NO");
}