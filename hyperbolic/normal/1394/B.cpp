#include <stdio.h>
#include <map>
#include <algorithm>
#include <vector>

std::vector< std::pair<int,int> > V[200010];

int check[200010][10][10];
int check2[10][10],check3[10][10];
int next[10][10][10][10];
int a,b,c;
long long int ans = 0;
int y[10];

void func(int k)
{
	if(k>c)
	{
		ans++;
		return;
	}
	
	int temp[10][10]={};
	for(int i=1;i<=c;i++) for(int j=1;j<=c;j++) temp[i][j] = check3[i][j];
	
	for(int i=1;i<=k;i++)
	{
		if(check3[k][i]==1) continue;
		if(check2[k][i]==1) continue;
		
		y[k] = i;
		for(int j1=1;j1<=c;j1++) for(int j2=1;j2<=c;j2++) if(next[k][i][j1][j2]==1) check3[j1][j2] = 1;
		func(k+1);
		for(int j1=1;j1<=c;j1++) for(int j2=1;j2<=c;j2++) check3[j1][j2] = temp[j1][j2];
	}
	y[k] = 0;
}
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=b;i++)
	{
		int d,e,f;
		scanf("%d%d%d",&d,&e,&f);
		V[d].push_back(std::make_pair(f,e));
	}
	for(int i=1;i<=a;i++) std::sort(V[i].begin(),V[i].end());
	
	for(int i=1;i<=a;i++)
	{
		for(int j=0;j<V[i].size();j++)
		{
			if(check[V[i][j].second][V[i].size()][j+1]==1) check2[V[i].size()][j+1] = 1;
			check[V[i][j].second][V[i].size()][j+1] = 1;
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		std::vector< std::pair<int,int> > temp;
		for(int j=1;j<=c;j++) for(int k=1;k<=c;k++) if(check[i][j][k]==1) temp.push_back(std::make_pair(j,k));
		for(int j=0;j<temp.size();j++)
		{
			for(int k=0;k<temp.size();k++)
			{
				next[temp[j].first][temp[j].second][temp[k].first][temp[k].second] = 1;
			}
		}
	}
	func(1);
	printf("%lld",ans);
}