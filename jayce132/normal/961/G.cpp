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

const int mod=1e9+7;
const int maxn=2e5+20;
inline int power(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=(ll)ans*a%mod;
		b>>=1;
		a=(ll)a*a%mod;
	}return ans;
}

int n,k;
int W;
int jc[maxn],jcn[maxn],inv[maxn];

inline void init()
{
	n=read();k=read();
	REP(i,1,n)W=(W+read())%mod;
	jc[0]=jc[1]=jcn[0]=jcn[1]=inv[1]=1;
	REP(i,2,n)jc[i]=(ll)i*jc[i-1]%mod,inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod,jcn[i]=(ll)jcn[i-1]*inv[i]%mod;
}

inline int S(int n,int m)
{
	int ans=0;
	REP(i,1,m)ans=(ans+(ll)(m-i&1?-1:1)*jcn[i]*jcn[m-i]%mod*power(i,n))%mod;
	return (ans+mod)%mod;
}

inline void doing()
{
	int res=(S(n,k)+(ll)(n-1)*S(n-1,k))%mod;
	printf("%lld\n",(ll)W*res%mod);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("pa.in","r",stdin);
	freopen("pa.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}