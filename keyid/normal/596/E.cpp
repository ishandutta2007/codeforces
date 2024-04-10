#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAXN=205,MAXL=1000005;

struct Pos
{
	int x,y;
}to[MAXN][MAXN],qu[MAXN*MAXN];

int n,m,cnt,d[10][2],dg[MAXN][MAXN],cir[MAXN][MAXN],f[MAXL],p[MAXN][MAXN];
bool vis[MAXN][MAXN];
char a[MAXN][MAXN],s[MAXL];

inline Pos trans(int x,int y)
{
	int c=a[x][y]-'0';
	return (Pos){x+d[c][0],y+d[c][1]};
}

void preprocess()
{
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
		{
			to[i][j]=trans(i,j);
			Pos &t=to[i][j];
			if (t.x<0||t.x>=n||t.y<0||t.y>=m)
				t={i,j};
			dg[t.x][t.y]++;
		}
	int head=0;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			if (dg[i][j]==0)
				qu[cnt++]={i,j};
	while (head<cnt)
	{
		const Pos &u=qu[head++];
		vis[u.x][u.y]=true;
		Pos t=to[u.x][u.y];
		if (--dg[t.x][t.y]==0)
			qu[cnt++]={t.x,t.y};
	}
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			if (!vis[i][j])
			{
				int ret=1<<a[i][j]-'0';
				for (Pos p=to[i][j];p.x!=i||p.y!=j;p=to[p.x][p.y]) ret|=1<<a[p.x][p.y]-'0';
				cir[i][j]=ret;
				vis[i][j]=true;
				for (Pos p=to[i][j];p.x!=i||p.y!=j;p=to[p.x][p.y])
				{
					cir[p.x][p.y]=ret;
					vis[p.x][p.y]=true;
				}
			}
}

bool solve()
{
	scanf("%s",s);
	int l=strlen(s);
	f[l]=0;
	for (int i=l-1;i>=0;i--) f[i]=f[i+1]|(1<<s[i]-'0');
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			p[i][j]=0;
	for (int i=0;i<cnt;i++)
	{
		const Pos &u=qu[i];
		if (a[u.x][u.y]==s[p[u.x][u.y]])
			if (++p[u.x][u.y]==l)
				return true;
		const Pos &t=to[u.x][u.y];
		p[t.x][t.y]=max(p[t.x][t.y],p[u.x][u.y]);
	}
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			if (cir[i][j])
			{
				int x=f[p[i][j]];
				if ((cir[i][j]&x)==x)
					return true;
			}
	return false;
}

int main()
{
	int q;
	scanf("%d%d%d",&n,&m,&q);
	for (int i=0;i<n;i++)
		scanf("%s",a[i]);
	for (int i=0;i<10;i++) scanf("%d%d",&d[i][0],&d[i][1]);
	preprocess();
	while (q--) puts(solve()?"YES":"NO");
	return 0;
}