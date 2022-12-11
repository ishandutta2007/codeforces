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
inline void myassert(bool a,string s){ if(!a)cerr<<s<<endl,exit(0);}
inline int read()
{
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxn=2e5+20;

int n,m,d;
vector<int>A,B;

vector<int>tA[maxn],tB[maxn];

inline void init()
{
	n=read();m=read();d=__gcd(n,m);
	int num=read();
	while(num--)A.push_back(read());
	num=read(); while(num--)B.push_back(read());

	if(n<m)swap(n,m),swap(A,B);
	
	if(d>SZ(A)+SZ(B))puts("-1"),exit(0);
	for(int x:A)tA[x%d].push_back(x/d);
	for(int y:B)tB[y%d].push_back(y/d);
	n/=d; m/=d;
}

int vA[maxn],vB[maxn];

void exgcd(int a,int &x,int b,int &y)
{
	if(!b)x=1,y=0;
	else exgcd(b,y,a%b,x),y-=(a/b)*x;
}

inline int Inv(int t,int mod)
{
	int a=t,b=mod,x,y;
	exgcd(a,x,b,y);
	return (x+mod)%mod;
}

#define pii pair<int,int>

inline void doing()
{
	ll ans=0;
	int inv=Inv(m,n);
	REP(re,0,d-1)
	{
		if(tA[re].empty() && tB[re].empty())puts("-1"),exit(0);
		vector<int>T;
		if(SZ(tA[re])+SZ(tB[re])>=n)
		{
			memset(vA,0,sizeof(int)*(n+1));
			memset(vB,0,sizeof(int)*(m+1));
			int sum=0;
			for(int x:tA[re])vA[x]=1,++sum;
			for(int x:tB[re])vB[x]=1,++sum;
			int flg=0;
			if(sum==n+m)continue;
			REP(i,0,m-1)if(vA[i]^vB[i])
			{
				vA[i]=vB[i]=1,++sum;
				if(sum==n+m){ chkmax(ans,(ll)i*d+re);flg=1; break;}
			}
			if(flg)continue;
		}
		T=tA[re]; for(int x:tB[re])T.push_back(x);
		sort(T.begin(),T.end());
		int len=unique(T.begin(),T.end())-T.begin();
		T.resize(len);
		vector<pii >S;
		REP(i,0,SZ(T)-1)S.push_back(mkr((ll)T[i]*inv%n,T[i]));
		sort(S.begin(),S.end());
		ll mx=0;
		REP(i,0,SZ(S)-2)
		{
			chkmax(mx,(ll)(S[i+1].fi-S[i].fi-1)*m+S[i].se);
		}
		chkmax(mx,(ll)(S.front().fi-S.back().fi-1+n)%n*m+S.back().se);
		chkmax(ans,mx*d+re);
	}
	printf("%lld\n",ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("516e.in","r",stdin);
	freopen("516e.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}