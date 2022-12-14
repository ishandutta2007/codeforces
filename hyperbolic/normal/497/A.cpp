#include <stdio.h>
#include <vector>
int a,b;
char x[110][110];
int check[110];
struct str{
	int x0;
	int y0;
};
std::vector<str> V[110];
int main()
{
	int i,j,k,count=0;
	scanf("%d%d",&a,&b);
	for(i=1;i<=a;i++) scanf("%s",x[i]+1);
	V[1].push_back({1,a});
	for(i=1;i<=b;i++)
	{
		for(j=0;j<V[i].size();j++)
		{
			for(k=V[i][j].x0+1;k<=V[i][j].y0;k++)
			{
				if(x[k-1][i]>x[k][i])
				{
					check[i]=1;
					for(j=0;j<V[i].size();j++)
					{
						V[i+1].push_back(V[i][j]);
					}
					goto u;
				}
			}
		}
		for(j=0;j<V[i].size();j++)
		{
			int s=V[i][j].x0;
			for(k=V[i][j].x0+1;k<=V[i][j].y0;k++)
			{
				if(x[k-1][i]!=x[k][i])
				{
					V[i+1].push_back({s,k-1});
					s=k;
				}
			}
			V[i+1].push_back({s,V[i][j].y0});
		}
		u:;
	}
	for(i=1;i<=b;i++) if(check[i]) count++;
	printf("%d",count);
}