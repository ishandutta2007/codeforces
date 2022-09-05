#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)

const int N=2000+5,inf=1e9;
char s[N][N];
int g[N][N];
deque<int>q; 
int n,m,r,c;

void bfs()
{
	rep(i,1,n)
	rep(j,1,m)g[i][j]=inf;
	g[r][c]=0;
	q.push_back(r*N+c);
	while(!q.empty())
	{
		int x=q.front();q.pop_front();
		int y=x%N;x/=N;
		if(s[x-1][y]=='.'&&g[x-1][y]>g[x][y])
		{
			g[x-1][y]=g[x][y];
			q.push_front((x-1)*N+y);
		}
		if(s[x+1][y]=='.'&&g[x+1][y]>g[x][y])
		{
			g[x+1][y]=g[x][y];
			q.push_front((x+1)*N+y);
		}
		if(s[x][y-1]=='.'&&g[x][y-1]>g[x][y]+1)
		{
			g[x][y-1]=g[x][y]+1;
			q.push_back(x*N+y-1);
		}
		if(s[x][y+1]=='.'&&g[x][y+1]>g[x][y]+1)
		{
			g[x][y+1]=g[x][y]+1;
			q.push_back(x*N+y+1);
		}
	}
}

int main()
{
	//freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	cin>>n>>m>>r>>c;
	int x,y;
	cin>>x>>y;
	rep(i,1,n)scanf("%s",s[i]+1);
	bfs();
	int ans=0;
	rep(i,1,n)
	rep(j,1,m)
	if(g[i][j]!=inf)
	{
		int a=j-c;
		int b=g[i][j];
		ans+=(b-a)/2<=x&&(b+a)/2<=y;
	}
	cout<<ans;
}