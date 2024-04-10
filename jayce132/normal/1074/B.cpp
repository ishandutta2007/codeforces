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

const int maxn=1e3+20;

struct node {
	int v,next;
};
node e[maxn<<1];
int cnt,start[maxn];

inline void addedge(int u,int v){ e[++cnt]=(node){v,start[u]};start[u]=cnt;}

int n,vis[maxn],visx[maxn],visy[maxn];
int rkx[maxn],rky[maxn],k1,k2;

inline void init()
{
	n=read(); memset(start,0,sizeof(int)*(n+1)); cnt=0;
	REP(i,1,n-1)
	{
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
	memset(visx,0,sizeof(visx)); memset(visy,0,sizeof(visy));
	k1=read(); REP(i,1,k1)rkx[i]=read(),visx[rkx[i]]=1;
	k2=read(); REP(i,1,k2)rky[i]=read(),visy[rky[i]]=1;
}

int tot,id[maxn],Rk[maxn];

void dfs(int u,int fa)
{
	id[u]=tot;
	EREP(i,u)
	{
		int v=e[i].v;
		if(v==fa || visx[v])continue;
		dfs(v,u);
	}
}

inline void doing()
{
	tot=0; memset(id,0,sizeof(id));
	REP(u,1,n)if(visx[u])
	{
		EREP(i,u)
		{
			int v=e[i].v;
			if(!visx[v])++tot,Rk[tot]=u,dfs(v,u);
		}
	}

	//fflush(stdout);
	printf("B %d\n",rky[1]);fflush(stdout);
	int ID=read();
	if(visx[ID])printf("C %d\n",ID),fflush(stdout);
	else {
		int a=id[ID];
		printf("A %d\n",Rk[a]);fflush(stdout);
		int b=read();
		if(!visy[b])puts("C -1"),fflush(stdout);
		else printf("C %d\n",Rk[a]),fflush(stdout);
	}
	
}

int main()
{
	fflush(stdout);
	int t=read();
	while(t--)
	{
		init();
		doing();
	}
	return 0;
}