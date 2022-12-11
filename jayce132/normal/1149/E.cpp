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

const int maxn=3e5+20;
vector<int>ed[maxn];

int h[maxn];
int n,m,sg[maxn],rd[maxn];

int rk[maxn],tp;

inline void get_topx()
{
    queue<int>q;
    REP(i,1,n)if(!rd[i])q.push(i);
    while(!q.empty())
    {
	int u=q.front();q.pop();
	rk[++tp]=u;
	for(int v:ed[u])
	    if(!(--rd[v]))q.push(v);
    }
}

inline void init()
{
    n=read();m=read();
    REP(i,1,n)h[i]=read();
    REP(i,1,m)
    {
	int u=read(),v=read();
	ed[u].push_back(v); rd[v]++;
    }
    get_topx();
}

int vis[maxn];
int sum[maxn];

inline void doing()
{
    DREP(i,n,1)
    {
	int x=rk[i];
	for(int y:ed[x])
	    vis[sg[y]]++;
	while(vis[sg[x]])++sg[x];
	for(int y:ed[x])
	    vis[sg[y]]--;
    }
    REP(i,1,n)sum[sg[i]]^=h[i];
    DREP(i,n,0)if(sum[i])
    {
	puts("WIN");
	REP(j,1,n)if(sg[j]==i && (h[j]^sum[i])<h[j])
	{
	    h[j]=h[j]^sum[i];
	    for(int k:ed[j])
		if(sum[sg[k]])
		    h[k]^=sum[sg[k]],sum[sg[k]]=0;
	    break;
	}
	REP(j,1,n)printf("%d ",h[j]);
	return;
    }
    puts("LOSE");
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("cf1149e.in","r",stdin);
    freopen("cf1149e.out","w",stdout);
#endif
    init();
    doing();
    return 0;
}