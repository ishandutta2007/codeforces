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
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=4e5+20;

int fa[maxn];

int fin(int x){ return x==fa[x]?x:fa[x]=fin(fa[x]);}
inline void merge(int x,int y){ x=fin(x);y=fin(y);fa[y]=x;}

int main()
{
	int n=read(),m=read(),q=read();
	REP(i,1,n+m)fa[i]=i;
	REP(i,1,q)
	{
		int x=read(),y=read();
		merge(x,y+n);
	}
	int res=0;
	REP(i,1,n+m)res+=fin(i)==i;
	printf("%d\n",res-1);
	return 0;
}