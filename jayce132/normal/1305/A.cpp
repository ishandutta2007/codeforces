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
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
inline int read()
{
	int s=0,f=1; char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

int a[120],b[120],c[120];

int main()
{
	int t=read();
	while(t--)
	{
		int n=read();
		REP(i,1,n)a[i]=read(); sort(a+1,a+n+1);
		REP(i,1,n)b[i]=read(); sort(b+1,b+n+1);
		REP(i,1,n)printf("%d ",a[i]);puts("");
		REP(i,1,n)printf("%d ",b[i]);puts("");
	}
	return 0;
}