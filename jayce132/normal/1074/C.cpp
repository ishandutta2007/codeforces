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

const int maxn=3e5+20;
const int inf=0x3f3f3f3f;

int n,px[maxn],py[maxn],mnx,mxx,mxy,mny;
int All;

inline void doing()
{
	mnx=1e9; mxx=-1e9; mxy=-inf; mny=inf;
	n=read();
	REP(i,1,n)px[i]=read(),py[i]=read(),chkmin(mnx,px[i]),chkmax(mxx,px[i]),chkmin(mny,py[i]),chkmax(mxy,py[i]);
	All=2*(mxy-mny+mxx-mnx);

	int ans=0;
	REP(i,1,n)
	{
		int A=max(px[i]-mnx,mxx-px[i]),B=max(py[i]-mny,mxy-py[i]);
		chkmax(ans,A+B);
	}
	printf("%d ",ans<<1);
	REP(i,4,n)printf("%d ",All);
}

int main()
{
	doing();
	return 0;
}