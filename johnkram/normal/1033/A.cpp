#include<bits/stdc++.h>
using namespace std;
const int dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1};
bool b[1005][1005];
int n,sx,sy,tx,ty,ax,ay;
bool check(int x,int y)
{
	if(x==ax||y==ay||x+y==ax+ay||x-y==ax-ay)return 0;
	return 1;
}
void dfs(int x,int y)
{
	b[x][y]=1;
	for(int i=0;i<8;i++)if(x+dx[i]&&y+dy[i]&&x+dx[i]<=n&&y+dy[i]<=n&&!b[x+dx[i]][y+dy[i]]&&check(x+dx[i],y+dy[i]))dfs(x+dx[i],y+dy[i]);
}
int main()
{
	cin>>n>>ax>>ay>>sx>>sy>>tx>>ty;
	dfs(sx,sy);
	if(b[tx][ty])puts("YES");
	else puts("NO");
	return 0;
}