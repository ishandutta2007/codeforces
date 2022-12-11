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

int n,m;

inline void init()
{
	n=read();m=read();
}

inline void doing()
{
	int lx=1,rx=n;
	while(lx<=rx)
	{
		if(lx<rx)
		{
			REP(j,1,m)printf("%d %d\n",lx,j),printf("%d %d\n",rx,m-j+1);
			lx++; rx--;
		}else
		{
			REP(j,1,m>>1)printf("%d %d\n",lx,j),printf("%d %d\n",lx,m-j+1);
			if(m&1)printf("%d %d\n",lx,m+1>>1);
			lx++;rx--;
		}
	}
}

int main()
{
	init();
	doing();
	return 0;
}