#include <stdio.h>
#include <vector>
#include <map>

std::vector<int> V;
std::pair<int,int> getQuery()
{
	printf("? ");
	for(int i=0;i<V.size();i++) printf("%d ",V[i]);
	printf("\n");
	fflush(stdout);
	
	std::pair<int,int> P;
	scanf("%d%d",&P.first,&P.second);
	return P;
}

std::map<int,int> count;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b+1;i++)
	{
		V.clear();
		for(int j=1;j<=b+1;j++)
		{
			if(j==i) continue;
			V.push_back(j);
		}
		std::pair<int,int> P = getQuery();
		count[P.second]++;
	}
	std::map<int,int> ::iterator it = count.end();
	it--;
	printf("! %d",it->second);
	fflush(stdout);
}