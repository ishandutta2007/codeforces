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

const int maxn=1e5+20;
const int inf=0x3f3f3f3f;

#define pri pair<int,int>
#define mkr(a,b) make_pair(a,b)
#define fi first
#define se second

int n,m;
int p[maxn],a[maxn];
int sx[maxn];

inline bool cmp(int a,int b){ return p[a]<p[b];}
int nxt[maxn],lst[maxn];


inline int calc(int x,int y)
{
	if(x==y)return inf;
	int d=(p[y]-p[x]+m)%m;
	if(y<x)d=(d+a[y])%m;
	if(d<=a[x])return 1;
	if(a[x]<=a[y])return inf;
	return (d-a[y]-1)/(a[x]-a[y])+1;
}

set<pri >s;

inline void init()
{
	n=read();m=read();
	REP(i,1,n)p[i]=read()-1,a[i]=read();
	REP(i,1,n)sx[i]=i;
	sort(sx+1,sx+n+1,cmp);
	REP(i,1,n-1)nxt[sx[i]]=sx[i+1];nxt[sx[n]]=sx[1];
	REP(i,2,n)lst[sx[i]]=sx[i-1];lst[sx[1]]=sx[n];
	REP(i,1,n)s.insert(mkr(calc(i,nxt[i]),i));
	while(1)
	{
		pri x=*s.begin();if(x.fi==inf)break;
		s.erase(x);
		int now=x.se,ne=nxt[now],la=lst[now];
		s.erase(mkr(calc(ne,nxt[ne]),ne));
		if(la!=ne)s.erase(mkr(calc(la,now),la));
		p[now]+=x.fi;p[now]%=m;a[now]--;
		nxt[now]=nxt[ne];
		lst[nxt[ne]]=now;
		if(nxt[now]!=now)s.insert(mkr(calc(now,nxt[now]),now)),s.insert(mkr(calc(la,now),la));
		else puts("1"),printf("%d\n",now),exit(0);
	}
	printf("%d\n",s.size());
	for(pri x:s)printf("%d ",x.se);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("frog.in","r",stdin);
	freopen("frog.out","w",stdout);
#endif
	init();
	return 0;
}