#include <stdio.h>
#include <vector>

std::vector< std::pair<int,int> > V;

int x[110][110],y[110][110];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) scanf("%d",&x[i][j]);
	for(int i=1;i<a;i++)
	{
		for(int j=1;j<b;j++)
		{
			if(x[i][j]==1&&x[i+1][j]==1&&x[i][j+1]==1&&x[i+1][j+1]==1)
			{
				V.push_back(std::make_pair(i,j));
				y[i][j] = y[i+1][j] = y[i][j+1] = y[i+1][j+1] = 1;
			}
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]!=y[i][j])
			{
				printf("-1");
				return 0;
			}
		}
	}
	printf("%d\n",V.size());
	for(int i=0;i<V.size();i++) printf("%d %d\n",V[i].first,V[i].second);
}