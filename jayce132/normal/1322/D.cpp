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

const int maxn=5e3+20;
const ll inf=1ll<<60;

int n,m;
int c[maxn],s[maxn],l[maxn];


inline void init()
{
	n=read();m=read();
	REP(i,1,n)l[i]=read();
	REP(i,1,n)s[i]=read();
	REP(i,1,n+m)c[i]=read();
}

ll dp[2020][maxn],LIM[maxn];
ll pre[2020][maxn];

inline ll solve(int x,int n,int st)
{
	ll ans=0;
	while(x && n)
	{
		ans+=x*c[st];
		st++; x>>=1;
		n--;
	}
	return ans;
}

struct Fenwick_Tree {
	ll s[2020];
	inline void Add(ll x,ll d) { for(;x<=m;x+=x&(-x))chkmax(s[x],d);}
	inline ll Sum(ll x){ ll res=-inf;for(;x;x-=x&(-x))chkmax(res,s[x]);return res;}
}S[maxn];//j,l

inline void doing()
{
	REP(i,1,n)LIM[l[i]]++;
	REP(i,1,n+m)LIM[i]+=LIM[i-1]>>1;
	memset(dp,-63,sizeof(dp));
	memset(pre,-63,sizeof(pre));
	REP(i,0,n)memset(S[i].s,-63,sizeof(S[i].s));
	dp[n+1][0]=0;
	ll ans=0;
	DREP(i,n+1,1)
	{
		int x=l[i];
		REP(j,0,LIM[x])
		{
			chkmax(dp[i][j],S[j].Sum(l[i])-s[i]);
			chkmax(dp[i][j],pre[j][x]-s[i]);
/*REP(k,1,i-1)if(l[k]>=l[i])
			{
				chkmax(dp[k][(j>>l[k]-l[i])+1],dp[i][j]+solve(j,l[k]-l[i],l[i]) -s[k]);
				}*/
			chkmax(ans,dp[i][j]+solve(j,1000,x));
		}
		REP(j,0,LIM[x])
		{
			int x=j; ll dj=0; ll L=l[i];
			while(x)
			{
				chkmax(pre[x+1][L],dp[i][j]+dj);//S[x+1].Add(L,dp[i][j]+dj);
				dj+=x*c[L];
				L++; x>>=1;
			}
			S[x+1].Add(max(L,1ll),dp[i][j]+dj);
		}
	}
	printf("%lld\n",ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}