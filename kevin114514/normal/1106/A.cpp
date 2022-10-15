#include<bits/stdc++.h>
using namespace std;
//the row and column numbers start with 1!
#define MAXN 501
char grid[MAXN][MAXN];
const int dx[]={1,-1,1,-1},dy[]={-1,-1,1,1};
bool isca(int x,int y)
{
	for(int i=0;i<4;i++)
		if(grid[x][y]!=grid[x+dx[i]][y+dy[i]])
			return false;
	return grid[x][y]=='X';
}
int main()
{
	int n,cnt=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n+1;j++)
			scanf("%c",&grid[i][j]);
	for(int i=2;i<n;i++)
		for(int j=2;j<=n;j++)
			cnt+=isca(i,j);
	printf("%d\n",cnt);
	return 0;
}