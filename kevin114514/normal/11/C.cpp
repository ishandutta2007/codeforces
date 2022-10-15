#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
void die(string S){puts(S.c_str());exit(0);}
const int dx[]={-1,-1,-1,0,1,1,1,0};
const int dy[]={-1,0,1,1,1,0,-1,-1};
vector<int> seq;
char G[255][255];
bool vis[255][255];
int type[255][255];
void dfs(int x,int y)
{
	vis[x][y]=true;
	seq.pb(type[x][y]);
	for(int d=1;d<8;d+=2)
	{
		int nx=x+dx[d];
		int ny=y+dy[d];
		if(G[nx][ny]=='1'&&!vis[nx][ny])
			dfs(nx,ny);
	}
	for(int d=0;d<8;d+=2)
	{
		int nx=x+dx[d];
		int ny=y+dy[d];
		if(G[nx][ny]=='1'&&!vis[nx][ny])
			dfs(nx,ny);
	}
}
bool ok(vector<int> seq)
{
	vector<int> TWO;
	int sz=seq.size();
	if(sz==4&&seq[0]==6&&seq[1]==6&&seq[2]==6&&seq[3]==6)
		return true;
	if(sz==8&&seq[0]==2&&seq[1]==7&&seq[2]==2&&seq[3]==7&&seq[4]==2&&seq[5]==7&&seq[6]==2&&seq[7]==7)
		return true;
//	for(int i=0;i<sz;i++)
//		cout<<seq[i]<<" ";
//	puts("");
	for(int i=0;i<sz;i++)
		if(seq[i]!=2&&seq[i]!=4&&seq[i]!=6)
			return false;
		else if(seq[i]==2)
			TWO.pb(i);
	int sz1=TWO.size();
	if(sz1!=4)
		return false;
	int d1=TWO[1]-TWO[0],d2=TWO[2]-TWO[1],d3=TWO[3]-TWO[2],d4=sz-d1-d2-d3;
	if(d1==d2&&d2==d3&&d3==d4)
		return true;
	for(int i=0;i<sz;i++)
		if(seq[i]!=2&&seq[i]!=4&&seq[i]!=6)
			return false;
		else if(seq[i]==2)
		{
			if(seq[(i+sz-1)%sz]!=6||seq[(i+1)%sz]!=6)
				return false;
			TWO.pb(i);
		}
		else if(seq[i]==6)
		{
			if(seq[(i+sz-1)%sz]!=2&&seq[(i+1)%sz]!=2)
				return false;
		}
	if(d1==d2&&d2==d3&&d3==d4)
		return true;
	return false;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int ans=0;
		int h,w;
		cin>>h>>w;
		for(int i=1;i<=h;i++)
			for(int j=1;j<=w;j++)
			{
				G[i][j]=getchar();
				while(!isdigit(G[i][j]))
					G[i][j]=getchar();
			}
		for(int i=1;i<=h;i++)
			for(int j=1;j<=w;j++)
			if(G[i][j]=='1')
			{
				vector<int> adj;
				for(int d=0;d<8;d++)
					if(G[i+dx[d]][j+dy[d]]=='1')
						adj.push_back(d);
				if((int)(adj.size())==2)
					type[i][j]=min(adj[1]-adj[0],adj[0]+8-adj[1]);
				else	if((int)(adj.size())==3)
					type[i][j]=6;
				else	if((int)(adj.size())==4)
					type[i][j]=7;
				else	type[i][j]=5;
//				cout<<i<<" "<<j<<" "<<type[i][j]<<endl;
			}
		for(int i=1;i<=h;i++)
			for(int j=1;j<=w;j++)
				if(G[i][j]=='1'&&!vis[i][j])
				{
					seq.clear();
					dfs(i,j);
					if(ok(seq))
						ans++;
				}
		cout<<ans<<endl;
		for(int i=1;i<=h;i++)
			for(int j=1;j<=w;j++)
				vis[i][j]=false,
				G[i][j]='0';
	}
}
/*
2
8 8
00010001
00101000
01000100
10000010
01000100
00101000
11010011
11000011
10 10
1111111000
1000001000
1011001000
1011001010
1000001101
1001001010
1010101000
1001001000
1000001000
1111111000

1
12 11
11111111111
10000000001
10111111101
10100000101
10101100101
10101100101
10100000101
10100000101
10111111101
10000000001
11111111111
00000000000
*/