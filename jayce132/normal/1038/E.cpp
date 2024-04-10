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

const int maxn=200;

struct node {
	int v,next,w;
};
node e[maxn<<2];
int cnt=1,start[maxn],rd[maxn];
inline void addedge(int u,int v){ e[++cnt]=(node){v,start[u]};start[u]=cnt;}

int n,m;
int del;

int fa[maxn],s[maxn];

int fin(int x){ return x==fa[x]?x:fa[x]=fin(fa[x]);}
inline void merge(int x,int y)
{
	x=fin(x);y=fin(y);
	if(x==y)return;
	fa[y]=x;
}

int x[maxn],y[maxn],val[maxn];

inline void init()
{
	n=4;
	m=read();
	REP(i,1,n)fa[i]=i;
	REP(i,1,m)
	{
		int u=read(),w=read(),v=read();
		x[i]=u; y[i]=v; val[i]=w;
		rd[u]++;rd[v]++;
	}
}

int Rd[maxn];

inline void doing()
{
	int ans=0;
	for(del=0;del<=m;del++)
	{
		REP(i,1,n)fa[i]=i,s[i]=0,Rd[i]=0;
		REP(i,1,m)if(i!=del)
			merge(x[i],y[i]),Rd[x[i]]++,Rd[y[i]]++;
		REP(i,1,m)if(i!=del)
			s[fin(x[i])]+=val[i];
		REP(i,1,4)if(fin(i)==i)
		{
			int tmp=0;
			REP(j,1,4)if(fin(j)==i)tmp+=Rd[j]&1;
			if(tmp<=2)chkmax(ans,s[i]);
		}
	}
	printf("%d\n",ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("matching.in","r",stdin);
	freopen("matching.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}