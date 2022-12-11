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

const int maxn=2e5+20;
const int mod=998244353;

int n,k,p[maxn],id[maxn];
int vis[maxn];

int main()
{
	n=read();k=read();
	REP(i,1,n)p[i]=read(),id[p[i]]=i;
	ll ans=0,num=1;
	REP(i,n-k+1,n)ans+=i,vis[id[i]]=1;
	vis[0]=vis[n+1]=1;
	int s=-2*n;
	REP(i,1,n)
	{
		++s;
		if(vis[i])num=(ll)num*max(s,1)%mod,s=0;
	}
	printf("%lld %lld\n",ans,num);
	
	return 0;
}