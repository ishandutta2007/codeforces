#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,u) for(int i=start[u];i;i=e[i].next)
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
#define SZ(A) ((int)A.size())
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
inline int read()
{
    int s=0,f=1; char ch=getchar();
    while(!isdigit(ch) && ch!='-')ch=getchar();
    if(ch=='-')ch=getchar(),f=-1;
    while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
    return ~f?s:-s;
}

const int maxn=1e3+20;

int a[maxn][maxn];
int dis[maxn][maxn];

int n,m,q;

const int d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

inline void bfs()
{
#define pii pair<int,int>
    queue<pii>q;
    REP(i,1,n)REP(j,1,m)if(dis[i][j]==0)q.push(mkr(i,j));
    while(!q.empty())
    {
	int x=q.front().fi,y=q.front().se; q.pop();
	REP(l,0,3)
	{
	    int xx=x+d[l][0],yy=y+d[l][1];
	    if(xx>0 && xx<=n && yy>0 && yy<=m && dis[xx][yy]==-1)
	    {
		dis[xx][yy]=dis[x][y]+1;
		q.push(mkr(xx,yy));
	    }
	}
    }
}

inline void init()
{
    n=read();m=read();q=read();
    REP(i,1,n)
    {
	char str[maxn];
	scanf("%s",str+1);
	REP(j,1,m)a[i][j]=str[j]-'0';
    }
    memset(dis,-1,sizeof(dis));
    REP(i,1,n)REP(j,1,m)
    {
	if(j<m && a[i][j]==a[i][j+1])
	    dis[i][j]=dis[i][j+1]=0;
	if(i<n && a[i][j]==a[i+1][j])
	    dis[i][j]=dis[i+1][j]=0;
    }
    bfs();
}

inline void doing()
{
    REP(i,1,q)
    {
	int x=read(),y=read();ll p; cin>>p;
	if(p<=dis[x][y] || dis[x][y]==-1)printf("%d\n",a[x][y]);
	else {
	    printf("%lld\n",a[x][y]^(p-dis[x][y]&1));
	}
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
#endif
    init();
    doing();
    return 0;
}