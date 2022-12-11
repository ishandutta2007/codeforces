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

const int maxn=4e5+20;

int n,a[maxn],b[maxn];
ll ans;

int main()
{
	n=read();
	REP(i,1,n)a[i]=read();
	REP(t,0,24)
	{
		REP(i,1,n)b[i]=a[i]&(1<<t+1)-1;
		int R=(1<<t+1)-1,L=1<<t;
		sort(b+1,b+n+1);
		int l=n+1,r=n;ll s=0;
		REP(i,1,n)
		{
			while(l>1 && b[i]+b[l-1]>=L)l--;
			while(r && b[i]+b[r]>R)r--;
			s+=max(r-l+1,0);
		}
		REP(i,1,n)if(L<=2*b[i] && 2*b[i]<=R)s--;
		s>>=1;
		ans^=(s&1)<<t;
	}

	REP(t,0,24)
	{
		REP(i,1,n)b[i]=a[i]&(1<<t+1)-1;
		int R=(1<<t+1)|(1<<t+1)-1,L=(1<<t+1)|1<<t;
		sort(b+1,b+n+1);
		int l=n+1,r=n;ll s=0;
		REP(i,1,n)
		{
			while(l>1 && b[i]+b[l-1]>=L)l--;
			while(r && b[i]+b[r]>R)r--;
			s+=max(r-l+1,0);
		}
		REP(i,1,n)if(L<=2*b[i] && 2*b[i]<=R)s--;
		s>>=1;
		ans^=(s&1)<<t;
	}
	printf("%lld\n",ans);
	return 0;
}