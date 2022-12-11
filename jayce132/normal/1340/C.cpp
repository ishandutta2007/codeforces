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

const int maxn=1e4+20;
const int inf=0x3f3f3f3f;
int n,m,d[maxn],g,r;

bool in[maxn][1020];

inline void init()
{
    n=read();m=read();
    REP(i,1,m)d[i]=read();
    sort(d+1,d+m+1);
    g=read();r=read();
    REP(i,1,m)in[i][0]=1;
    REP(j,1,g)
    {
	REP(i,1,m)
	{
	    if(i>1 && j>=d[i]-d[i-1])
		in[i][j]|=in[i-1][j-(d[i]-d[i-1])];
	    if(i<m && j>=d[i+1]-d[i])
		in[i][j]|=in[i+1][j-(d[i+1]-d[i])];
	}
    }
}


int dist[maxn][1020],vis[maxn];
#define pii pair<int,int>

inline void doing()
{
    queue<pii>q;
    memset(dist,inf,sizeof(dist));
    q.push(mkr(1,0)); dist[1][0]=0;
    while(1)
    {
	vector<int>num;
	while(!q.empty())
	{
	    int u=q.front().fi,tim=q.front().se;q.pop();
	    if(tim==g)
	    {
		if(dist[u][0]==inf)dist[u][0]=dist[u][tim]+1,num.push_back(u);
	    }
	    if(u>1)
	    {
		int ntm=tim+d[u]-d[u-1];
		if(ntm<=g && dist[u-1][ntm]==inf)
		    dist[u-1][ntm]=dist[u][tim],q.push(mkr(u-1,ntm));
	    }
	    if(u<m)
	    {
		int ntm=tim+d[u+1]-d[u];
		if(ntm<=g && dist[u+1][ntm]==inf)
		    dist[u+1][ntm]=dist[u][tim],q.push(mkr(u+1,ntm));
	    }
	}
	if(SZ(num)==0)break;
	for(int x:num)q.push(mkr(x,0));
    }
    int ans=inf;
    REP(i,1,m)if(dist[i][0]!=inf && g+d[i]>=d[m])chkmin(ans,dist[i][0]*(g+r)+(d[m]-d[i]));
    if(ans<(int)1e9)printf("%d\n",ans);
    else puts("-1");
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