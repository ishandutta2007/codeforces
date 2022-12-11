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
#define SZ(A) ((int)A.size())
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=3e5+20;

struct node {
	int a,b,id;
};
node x[maxn],y[maxn];

int n,na,nb;

inline void init()
{
	n=read();
	REP(i,1,n)
	{
		int a=read(),b=read();
		if(a<b)x[++na]=(node){a,b,i};
		else y[++nb]=(node){a,b,i};
	}
}

inline void doing()
{
	if(na>nb)
	{
		sort(x+1,x+na+1,[](node a,node b){ return a.b>b.b;});
		printf("%d\n",na);
		REP(i,1,na)printf("%d ",x[i].id);puts("");
	}else
	{
		sort(y+1,y+nb+1,[](node a,node b){ return a.a<b.a;});
		printf("%d\n",nb);
		REP(i,1,nb)printf("%d ",y[i].id);puts("");
	}
}

int main()
{
	init();
	doing();
	return 0;
}