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

const int maxn=1e6+20;

int sx,sy,tx,ty,ex,ey,n;

int fa[maxn];
int vis[maxn];

#define A(i,j) (((i)-1)*(n)+j)

int fin(int x){ return x==fa[x]?x:fa[x]=fin(fa[x]);}
inline void merge(int x,int y){ x=fin(x);y=fin(y);fa[y]=x;}

int main()
{
	n=read();tx=read();ty=read();
	sx=read();sy=read();
	ex=read();ey=read();
	REP(i,1,n)REP(j,1,n)fa[A(i,j)]=A(i,j);
	REP(i,1,n)REP(j,1,n)if(i==tx || j==ty || i+j==tx+ty || i-j==tx-ty)vis[A(i,j)]=1;
	REP(i,1,n)REP(j,1,n)if(!vis[A(i,j)])
	{
		if(i-1)if(!vis[A(i-1,j)])merge(A(i-1,j),A(i,j));
		if(j-1)if(!vis[A(i,j-1)])merge(A(i,j-1),A(i,j));
		if(i-1 && j-1)if(!vis[A(i-1,j-1)])merge(A(i-1,j-1),A(i,j));
		if(i-n && j-1)if(!vis[A(i+1,j-1)])merge(A(i+1,j-1),A(i,j));
	}
	if(fin(A(sx,sy))==fin(A(ex,ey)))puts("YES"); else puts("NO");
	return 0;
}