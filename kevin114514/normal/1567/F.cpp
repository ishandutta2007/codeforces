#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > d={{0,1},{1,0},{-1,0},{0,-1}};
int res[505][505];
char grid[505][505];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",grid[i]+1);
	int xo=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int cnt=0;
			for(auto p:d)
			{
				int x=p.first,y=p.second;
				cnt+=(grid[i+x][j+y]=='.');
			}
			if(grid[i][j]=='X')
			{
				xo^=(grid[i-1][j]=='X');
//				res[i][j]=5;
				if(cnt%2)
				{
					puts("NO");
					return 0;
				}
			}
			else if((j+xo)%2)
				res[i][j]=1;
			else	res[i][j]=4;
		}
	puts("YES");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(grid[i][j]=='X')
				for(auto p:d)
				{
					int x=p.first,y=p.second;
					if(grid[x+i][y+j]=='.')
						res[i][j]+=res[x+i][y+j];
				}
			cout<<res[i][j]<<" ";
			
		}
		puts("");
	}
	return 0;
}