#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
void die(string S){puts(S.c_str());exit(0);}
string grid[2];
int n;
bool vis[2][110];
void dfs(int x,int y)
{
	vis[x][y]=1;
	for(int i=-1;i<=1;i++)
		for(int j=-1;j<=1;j++)
		{
			int nx=x+i;
			int ny=y+j;
			if(nx<0||nx>1||ny<0||ny>=n)
				continue;
			if(!vis[nx][ny]&&grid[nx][ny]=='0')
				dfs(nx,ny);
		}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		cin>>n;
		cin>>grid[0]>>grid[1];
		dfs(0,0);
		if(vis[1][n-1])
			puts("YES");
		else	puts("NO");
	}
	return 0;
}