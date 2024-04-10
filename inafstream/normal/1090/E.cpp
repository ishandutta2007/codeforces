#include <bits/stdc++.h>
using namespace std;
int n,m,mp[15][15],prex[15][15],prey[15][15],q[1000005],b,e;
int dx[8]={-2,-2,-1,-1,1,1,2,2},dy[8]={-1,1,-2,2,-2,2,-1,1};
char s[15];
vector<int> s1,s2,s3,s4;
void inans(int x,int y,int sx,int sy)
{
	if (x==sx&&y==sy) return;
	if (mp[prex[x][y]][prey[x][y]]) inans(prex[x][y],prey[x][y],sx,sy);
	s3.push_back(prex[x][y]);s4.push_back(prey[x][y]);
	s1.push_back(x);s2.push_back(y);
	if (!mp[prex[x][y]][prey[x][y]]) inans(prex[x][y],prey[x][y],sx,sy);
}
void bfs(int x,int y)
{
	if (mp[x][y]==1) {mp[x][y]=2;return;}
	memset(prex,0,sizeof(prex));prex[x][y]=-1;
	memset(prey,0,sizeof(prey));
	int i,tx,ty,sx=111,sy;
	q[b=1]=x;
	q[e=2]=y;
	while (b<=e)
	{
		tx=q[b++];ty=q[b++];
		for (i=0;i<8;i++)
		{
			int fx=tx+dx[i],fy=ty+dy[i];
			if (fx<1||fx>8||fy<1||fy>8) continue;
			if (prex[fx][fy]) continue;
			prex[fx][fy]=tx;
			prey[fx][fy]=ty;
			if (mp[fx][fy]==1)
			{
				if (fx<sx||(fx==sx&&fy<sy))
				{
					sx=fx;
					sy=fy;
				}
			}
			q[++e]=fx;q[++e]=fy;
		}
	}
	tx=sx;ty=sy;
	if (1!=mp[tx][ty]) exit(x*8+y);
	//cerr<<tx<<' '<<ty<<' '<<x<<' '<<y<<endl;
	inans(tx,ty,x,y);
	mp[tx][ty]=0;mp[x][y]=2;
}
int main()
{
	scanf("%d",&n);
	int i;
	for (i=1;i<=n;i++)
	{
		scanf(" %s",s);
		mp[s[1]-'0'][s[0]-'a'+1]=1;
	}
	int x=1,y=1;
	while (n--)
	{
		bfs(x,y);
		y++;
		if (y>8){y=1;x++;}
	}
	cout<<s1.size()<<endl;
	for (i=0;i<s1.size();i++)
	{
		cout<<((char)(s2[i]+'a'-1))<<s1[i];
		cout<<'-'; 
		cout<<((char)(s4[i]+'a'-1))<<s3[i];
		cout<<endl;
	}
	return 0;
}