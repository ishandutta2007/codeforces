#include <stdio.h>
#include <vector>
#define MAX 1234

std::vector<int> ans;
int dist[110][110];
char x[110];
int y[1000010];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%s",x+1);
		for(int j=1;j<=a;j++)
		{
			if(x[j]=='0') dist[i][j] = MAX;
			else dist[i][j] = 1;
		}
		dist[i][i] = 0;
	}
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++)
		{
			for(int k=1;k<=a;k++)
			{
				for(int l=1;l<=a;l++)
				{
					int t = dist[j][l]+dist[l][k];
					if(dist[j][k]>t) dist[j][k] = t;
				}
			}
		}
	}
	
	int b;
	scanf("%d",&b);
	for(int i=1;i<=b;i++) scanf("%d",&y[i]);
	ans.push_back(y[1]);
	int prev = 1;
	for(int i=2;i<=b;i++)
	{
		if(dist[y[prev]][y[i]]!=i-prev)
		{
			ans.push_back(y[i-1]);
			prev = i-1;
		}
	}
	ans.push_back(y[b]);
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
}