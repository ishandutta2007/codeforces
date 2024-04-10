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

const int maxn=3e5+20;
const int mod=998244353;
inline int power(int a,int b)
{
    int ans=1;
    while(b)
    {
	if(b&1)ans=(ll)ans*a%mod;
	b>>=1;
	a=(ll)a*a%mod;
    }
    return ans;
}

#define pii pair<int,int>

int n,m,a[maxn];
int f[maxn];
pii g[maxn];

inline pii operator +(pii a,pii b){ return mkr((a.fi+b.fi)%mod,(a.se+b.se)%mod);}
inline pii operator -(pii a,pii b){ return mkr((a.fi-b.fi)%mod,(a.se-b.se)%mod);}
inline pii operator *(pii a,int b){ return mkr((ll)a.fi*b%mod,(ll)a.se*b%mod);}

inline void init()
{
    n=read();
    REP(i,1,n)a[i]=read(),m+=a[i];
    g[0]=mkr(1,0);
    REP(i,0,m-1)
    {
	pii t=mkr(0,0);
	int xs=0;
	if(i)
	{
	    xs=(ll)i*power(m,mod-2)%mod;
	    t=g[i-1]*xs;
	}
	t.se=(t.se+xs)%mod;
	xs=(m+(ll)(n-2)*i)%mod*power((ll)m*(n-1)%mod,mod-2)%mod;
	t=t-g[i]*xs;
	xs=(ll)m*(n-1)%mod*power(m-i,mod-2)%mod;
	g[i+1]=(mkr(0,0)-t)*xs;
    }
    f[0]=(ll)g[m].se*power(-g[m].fi,mod-2)%mod;
    REP(i,1,m)f[i]=((ll)g[i].fi*f[0]+g[i].se)%mod;
}

inline void doing()
{
    int ans=0;
    REP(i,1,n)ans=(ans+f[a[i]])%mod;
    ans=(ans-(ll)f[0]*(n-1)-f[m])%mod;
    ans=(ans+mod)%mod;
    printf("%d\n",ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("cf1349d.in","r",stdin);
    freopen("cf1349d.out","w",stdout);
#endif
    init();
    doing();
    return 0;
}