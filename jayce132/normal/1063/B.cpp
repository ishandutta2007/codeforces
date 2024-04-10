#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=2e3+20;

const int d[4][2]={ {1,0},{-1,0},{0,1},{0,-1}};

char str[maxn];

int n,m,num[maxn][maxn],tot;
int sx,sy,Liml,Limr;
int vis[maxn][maxn];

inline void init()
{
	n=read();m=read();
	REP(i,1,n)REP(j,1,m)num[i][j]=++tot;
	sx=read();sy=read();
	Liml=read(); Limr=read();
	REP(i,1,n)
	{
		scanf("%s",str+1);
		REP(j,1,m)vis[i][j]=str[j]!='*';
	}
}

#define pii pair<int,int>
#define mkr(a,b) make_pair(a,b)
#define fi first
#define se second

deque<pii >q;
int dist[maxn][maxn];

inline void doing()
{
	q.push_back(mkr(sx,sy));
	memset(dist,63,sizeof(dist));
	dist[sx][sy]=0;
	
	while(!q.empty())
	{
		int x=q.front().fi,y=q.front().se; q.pop_front();
		REP(i,0,3)
		{
			int xx=x+d[i][0],yy=y+d[i][1];
			if(vis[xx][yy])
			{
				if(dist[xx][yy]>dist[x][y]+(i==3))
				{
					dist[xx][yy]=dist[x][y]+(i==3);
					if(dist[xx][yy]<=Liml && dist[xx][yy]-(sy-yy)<=Limr)
					{
						if(i==3)q.push_back(mkr(xx,yy));
						else q.push_front(mkr(xx,yy));
					}
				}
			}
		}
	}
	int ans=0;
	REP(xx,1,n)REP(yy,1,m)if(dist[xx][yy]<=Liml && dist[xx][yy]-(sy-yy)<=Limr)ans++;
	printf("%d\n",ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}