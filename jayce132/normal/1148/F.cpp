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
inline ll read()
{
	ll sum=0;int p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=3e5+20;

int n;
ll val[maxn],mask[maxn];


inline void init()
{
	n=read();
	REP(i,1,n)val[i]=read(),mask[i]=read();
	ll s=0;
	REP(i,1,n)s+=val[i];
	if(s>0)REP(i,1,n)val[i]=-val[i];
}

ll ans;

inline void doing()
{
	REP(i,0,61)
	{
		ll res=0;
		REP(j,1,n)if(mask[j]>>i&1)
		{
			if(mask[j]<(1ll<<i+1))res+=val[j];
		}
		if(res<0)
		{
			ans|=1ll<<i;
			REP(j,1,n)if(mask[j]>>i&1)val[j]=-val[j];
		}
	}
	printf("%lld\n",ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("foo.in","r",stdin);
	freopen("foo.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}