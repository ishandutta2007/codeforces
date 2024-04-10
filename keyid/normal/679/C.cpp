#include <bits/stdc++.h>
using namespace std;

const int MAXN=505,dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

struct Point
{
	int x,y;
};

char a[MAXN][MAXN];
int n,k,b[MAXN][MAXN],sze[MAXN*MAXN],cnt[MAXN*MAXN],now;
queue <Point> q;

void bfs(int sx,int sy)
{
	int v=sx*n+sy;
	b[sx][sy]=v;
	q.push((Point){sx,sy});
	while (!q.empty())
	{
		Point u=q.front();q.pop();
		sze[v]++;
		for (int i=0;i<4;i++)
		{
			int x=u.x+dx[i],y=u.y+dy[i];
			if (x>=0&&x<n&&y>=0&&y<n&&a[x][y]=='.'&&b[x][y]==-1)
			{
				b[x][y]=v;
				q.push((Point){x,y});
			}
		}
	}
}

inline void addr(int r,int x)
{
	if (r<0||r>=n) return;
	for (int i=0;i<k;i++)
		if (a[r][i+x]=='.'&&++cnt[b[r][i+x]]==1)
			now+=sze[b[r][i+x]];
}

inline void delr(int r,int x)
{
	if (r<0||r>=n) return;
	for (int i=0;i<k;i++)
		if (a[r][i+x]=='.'&&--cnt[b[r][i+x]]==0)
			now-=sze[b[r][i+x]];
}

inline void addc(int c,int x)
{
	if (c<0||c>=n) return;
	for (int i=0;i<k;i++)
		if (a[i+x][c]=='.'&&++cnt[b[i+x][c]]==1)
			now+=sze[b[i+x][c]];
}

inline void delc(int c,int x)
{
	if (c<0||c>=n) return;
	for (int i=0;i<k;i++)
		if (a[i+x][c]=='.'&&--cnt[b[i+x][c]]==0)
			now-=sze[b[i+x][c]];
}

inline void addc2(int c,int x)
{
	if (c<0||c>=n) return;
	for (int i=0;i<k;i++)
		if (a[i+x][c]=='X')
			now++;
}

inline void delc2(int c,int x)
{
	if (c<0||c>=n) return;
	for (int i=0;i<k;i++)
		if (a[i+x][c]=='X')
			now--;
}

int main()
{
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++)
		scanf("%s",a[i]);
	memset(b,-1,sizeof(b));
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			if (a[i][j]=='.'&&b[i][j]==-1)
				bfs(i,j);
	int ans=0;
	for (int i=0;i+k<=n;i++)
	{
		now=0;
		memset(cnt,0,sizeof(cnt));
		addr(i-1,0);
		addr(i+k,0);
		addc(k,i);
		for (int j=0;j<k;j++)
			for (int l=0;l<k;l++)
				if (a[i+j][l]=='X')
					now++;
				else if (++cnt[b[i+j][l]]==1)
					now+=sze[b[i+j][l]];
		ans=max(ans,now);
		for (int j=1;j+k<=n;j++)
		{
			delr(i-1,j-1);
			delr(i+k,j-1);
			addc2(j-1+k,i);
			delc(j-2,i);
			addr(i-1,j);
			addr(i+k,j);
			addc(j+k,i);
			delc2(j-1,i);
			ans=max(ans,now);
		}
	}
	printf("%d",ans);
	return 0;
}