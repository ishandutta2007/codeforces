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
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int mod=1e9+7;

inline void pls(int &a,int b){ a+=b;if(a>=mod)a-=mod;}

#define pii pair<int,int>

pii dp[100][2][2][2];

inline int Calc(int x,int y,int k)
{
	if(x==-1 || y==-1 || k==-1)return 0;
	memset(dp,0,sizeof(dp));
	dp[31][1][1][1]=mkr(0,1);
	DREP(i,30,0)REP(opx,0,1)REP(opy,0,1)REP(opk,0,1)if(dp[i+1][opx][opy][opk].se || dp[i+1][opx][opy][opk].fi)
	{
		REP(ix,0,opx?(x>>i&1):1)REP(iy,0,opy?(y>>i&1):1)
		{
			int ik=ix^iy;
			if(opk && ik>(k>>i&1))continue;
			pii t=dp[i+1][opx][opy][opk];
			int tx=ix==(x>>i&1),ty=iy==(y>>i&1),tk=ik==(k>>i&1);
			pls(dp[i][opx&tx][opy&ty][opk&tk].fi,(t.fi+(ll)t.se*(ik<<i))%mod);
			pls(dp[i][opx&tx][opy&ty][opk&tk].se,t.se);
		}
	}
	int ans=0;
	REP(opx,0,1)REP(opy,0,1)REP(opk,0,1)ans=(ans+dp[0][opx][opy][opk].fi+1ll*dp[0][opx][opy][opk].se)%mod;
	return ans;
}

inline void init()
{
	int x1=read()-1,y1=read()-1,x2=read()-1,y2=read()-1,k=read()-1;
	printf("%lld\n",(Calc(x2,y2,k) - Calc(x1-1,y2,k) - Calc(x2,y1-1,k) + Calc(x1-1,y1-1,k) +1ll*mod*2)%mod);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("car.in","r",stdin);
	freopen("car.out","w",stdout);
#endif
	int t=read();
	while(t--)
	{
		init();
	}
	return 0;
}