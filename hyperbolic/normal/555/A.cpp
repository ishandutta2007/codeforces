#include <stdio.h>
#include <vector>
std::vector<int> V[100010];
int main()
{
	int a,b,c,d,i,j;
	scanf("%d%d",&a,&b);
	for(i=1;i<=b;i++)
	{
		scanf("%d",&c);
		for(j=1;j<=c;j++)
		{
			scanf("%d",&d);
			V[i].push_back(d);
		}
	}
	int count=0;
	for(i=1;i<=b;i++)
	{
		if(V[i][0]==1)
		{
			for(j=1;j<V[i].size();j++)
			{
				if(V[i][j]-V[i][j-1]==1) count++;
				else break;
			}
			printf("%d",(a-b-count)+(a-count)-1);
		}
	}
}