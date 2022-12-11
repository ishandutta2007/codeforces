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

const int maxn=1e6+20;

int n;
ll r1,r2,r3;
ll d;
ll a[maxn];
ll dp[maxn];

inline ll Cost(int i){ return min(r2+r1,min(r1*(a[i]+2),r1*a[i]+r3));}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	n=read();
	cin>>r1>>r2>>r3>>d;
	REP(i,1,n)a[i]=read();

	dp[0]=-d;
	ll pre=1ll<<60;

	REP(i,1,n)
	{
		dp[i]=1ll<<60;
		chkmin(dp[i],dp[i-1]+r1*a[i]+r3+d);
		if(i>=2)
		{
			pre+=Cost(i);
			chkmin(pre,dp[i-2]-3ll*(i-2)*d-2*d+Cost(i-1)+Cost(i));
			chkmin(dp[i],pre+3*i*d);
		}
	}
	ll ans=dp[n],sum=Cost(n-1)+(r1*a[n]+r3);
	DREP(i,n-2,0)
	{
		chkmin(ans,dp[i]+(2*(n-i-1)+1)*d+sum);
		sum+=Cost(i);
	}
	printf("%lld\n",ans);

	
	return 0;
}