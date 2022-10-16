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
vector<ll> val[2][22][22];
ll grid[22][22];
int n,m;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void dfs(int x,int y,ll sum,int type)
{
//	cout<<x<<" "<<y<<endl;
	if(x+y==(n+m)/2+1)
	{
//		cout<<x<<" "<<y<<" "<<sum<<endl;
		val[type][x][y].pb(sum);
		return ;
	}
	for(int i=type*2;i<type*2+2;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
//		cout<<nx<<" "<<ny<<endl;
		if(!nx||nx>n||!ny||ny>m)
			continue;
		dfs(nx,ny,sum^grid[nx][ny],type);
	}
}
int main()
{
//	int n,m;
	ll k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>grid[i][j];
	dfs(1,1,grid[1][1],0);
	dfs(n,m,grid[n][m],1);
	ll ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(i+j==(n+m)/2+1)
			{
//				printf("(%d,%d):\n",i,j);
//				printf("\t");
//				for(int l=0;l<sz(val[0][i][j]);l++)
//					cout<<val[0][i][j][l]<<" ";
//				puts("");
//				printf("\t");
//				for(int l=0;l<sz(val[1][i][j]);l++)
//					cout<<val[1][i][j][l]<" ";
//				puts("");
				srt(val[0][i][j]);
//				srt(val[1][i][j]);
				for(int l=0;l<sz(val[1][i][j]);l++)
				{
					ll x=val[1][i][j][l];
					x^=k;
					x^=grid[i][j];
					ans+=upper_bound(ALL(val[0][i][j]),x)-lower_bound(ALL(val[0][i][j]),x);
				}
			}
	cout<<ans<<endl;
	return 0;
}