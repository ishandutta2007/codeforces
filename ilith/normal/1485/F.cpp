//#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define PLL pair<ll,ll>
#define fi first
#define se second
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define int ll
#define gc getchar()//(_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
	int x=0,f=1;
	char ch=gc;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=gc;
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=gc;
	}
	return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=2e5+5,mod=1e9+7;
int b[maxn],dp[maxn],n;
ll pre[maxn];
inline void init()
{
	FOR(i,1,n)b[i]=dp[i]=pre[i]=0;
}
inline void input()
{
	n=gi();
	FOR(i,1,n)b[i]=gi();
	FOR(i,1,n)pre[i]=pre[i-1]+b[i];
}
map<int,int>mp;
inline void solve()
{
	mp.clear();
	dp[0]=1;
	int s=0;
//	FOR(i,1,n)
//	{
//		FOR(j,1,i)
//		{
//			if(pre[i-1]-pre[j-1]!=0)dp[i]+=dp[j];
//		}
//		if(pre[i-1]!=0)dp[i]+=dp[0];
//		s+=dp[i];
//	}
//	cout<<s<<endl;
	FOR(i,1,n)
	{
		dp[i]=s;
		if(pre[i-1]!=0)dp[i]+=dp[0];
		dp[i]%=mod;
		dp[i]-=mp[pre[i-1]];
		dp[i]=(dp[i]+mod)%mod;
		mp[pre[i-1]]=(mp[pre[i-1]]+dp[i])%mod;
		s=(s+dp[i])%mod;
	}
	printf("%lld\n",(s+1)%mod);
}
signed main()
{
	int T=1;
	T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}