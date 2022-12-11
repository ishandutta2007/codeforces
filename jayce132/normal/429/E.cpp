#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=2e5+20;
const int maxp=2e5;

struct node {
	int v,next;
};
node e[maxn<<1];
int cnt=1,start[maxn];
inline void addedge(int u,int v){ e[++cnt]=(node){v,start[u]};start[u]=cnt;}

int n,sx[maxn<<1],l[maxn],r[maxn],tx,rd[maxn];

inline void init()
{
	n=read();
	REP(i,1,n)
	{
		l[i]=read(); r[i]=read()+1;
		sx[++tx]=l[i]; sx[++tx]=r[i];
	}
	sort(sx+1,sx+tx+1);
	tx=unique(sx+1,sx+tx+1)-(sx+1);
	REP(i,1,n)l[i]=lower_bound(sx+1,sx+tx+1,l[i])-sx,r[i]=lower_bound(sx+1,sx+tx+1,r[i])-sx;
	REP(i,1,n)addedge(l[i],r[i]),addedge(r[i],l[i]),rd[l[i]]++,rd[r[i]]++;
	int lst=0;
	REP(i,1,maxp)
	{
		if(rd[i]&1)
		{
			if(!lst)lst=i;
			else addedge(lst,i),addedge(i,lst),lst=0;
		}
	}
}

int st[maxn],top;
int vis[maxn],visit[maxn];

void dfs(int u,int fai)
{
	visit[u]=1;
	for(int &i=start[u];i;i=e[i].next)
		if(i!=(fai^1) && !vis[i>>1])
		{
			int v=e[i].v,tmp=i;
			vis[i>>1]=1;
			dfs(v,i);
			st[++top]=tmp;
		}
}

int ans[maxn];

inline void doing()
{
	REP(i,1,maxp)if(rd[i] && !visit[i])
	{
		dfs(i,0);
	}
	DREP(i,top,1)ans[st[i]>>1]=st[i]&1;
	REP(i,1,n)printf("%d ",ans[i]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("points.in","r",stdin);
	freopen("points.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}