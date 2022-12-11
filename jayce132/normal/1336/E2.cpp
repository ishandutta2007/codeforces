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
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
inline int read()
{
    int s=0,f=1; char ch=getchar();
    while(!isdigit(ch) && ch!='-')ch=getchar();
    if(ch=='-')ch=getchar(),f=-1;
    while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
    return ~f?s:-s;
}

const int maxn=120;
const int mod=998244353;

int n,m,k;
ll rk[maxn],s[maxn];

inline void insert(ll x)
{
    DREP(i,m-1,0)if(x>>i&1)
    {
	if(!s[i]){ s[i]=x; k++; break;}
	else x^=s[i];
    }
}

inline void init()
{
    n=read();m=read();
    REP(i,1,n)
    {
	ll x; scanf("%lld",&x);
	insert(x);
    }
}

ll cnt[100],C[maxn][maxn];
ll ans[100],tp;

void dfs(int u,ll s)
{
    if(u==tp+1)return cnt[__builtin_popcountll(s)]++,void();
    dfs(u+1,s);
    dfs(u+1,s^rk[u]);
}

inline void doing()
{
    REP(i,0,m-1)if(s[i])REP(j,i+1,m-1)if(s[j]>>i&1)s[j]^=s[i];
    REP(i,0,m-1)if(s[i])rk[++tp]=s[i];
    if(k<=m/2)
    {
	dfs(1,0);
	ll mult=1;
	REP(i,1,n-k)mult=(ll)mult*2%mod;
	REP(i,0,m)printf("%lld ",(ll)cnt[i]*mult%mod);
    }else
    {
	tp=0;
	REP(i,0,m-1)if(!s[i])
	{
	    ll x=1ll<<i;
	    REP(j,0,m-1)if(s[j] & (1ll<<i))
		x|=1ll<<j;
	    rk[++tp]=x;
	}
	dfs(1,0);
	REP(i,0,m)C[i][0]=1;
	REP(i,1,m)REP(j,1,i)C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	REP(x,0,m)
	{
	    REP(y,0,m)REP(p,0,min(y,x))
	    {
		ans[x]=(ans[x]+(ll)cnt[y]*C[y][p]%mod*C[m-y][x-p]*(p&1?-1:1))%mod;
	    }
	    ans[x]=(ans[x]+mod)%mod;
	}
	ll mult=1;
	REP(i,1,n)mult=(ll)mult*2%mod;
	REP(i,1,m)mult=(ll)mult*(mod+1>>1)%mod;
	REP(i,0,m)printf("%lld ",(ll)ans[i]*mult%mod);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("e.in","r",stdin);
    freopen("e.out","w",stdout);
#endif
    init();
    doing();
    return 0;
}