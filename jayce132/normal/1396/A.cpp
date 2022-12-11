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

const int maxn=1e5+20;

int n;
ll a[maxn];

int main()
{
	n=read();
	REP(i,1,n)cin>>a[i];
	if(n==1)
	{
		REP(i,1,3)
		{
			printf("%d %d\n",1,1);
			printf("%lld ",i==3?-a[1]:0);puts("");
		}
		return 0;
	}
	
	printf("%d %d\n",1,n-1);
	REP(i,1,n-1)
	{
		ll x=(a[i]%n+n)%n;
		a[i]+=x*(n-1);
		printf("%lld ",x*(n-1));
	}puts("");

	{
		printf("%d %d\n",n,n);
		ll x=(a[n]%n+n)%n;
		printf("%lld \n",-x);
		a[n]-=x;
	}
	printf("%d %d\n",1,n);
	REP(i,1,n)
	{
		printf("%lld ",-a[i]);
	}puts("");
	return 0;
}