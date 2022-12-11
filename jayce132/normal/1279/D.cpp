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
const int mod=998244353;

int inv[maxn];

inline void prepare()
{
	inv[1]=1;
	REP(i,2,1e6)inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
}

int n;
int tag[maxn];
vector<int>a[maxn];

inline void init()
{
	n=read();
	REP(i,1,n)
	{
		int x=read(),t;
		REP(j,1,x)t=read(),a[i].push_back(t),tag[t]++;
	}
}

inline void doing()
{
	int ans=0;
	REP(i,1,n)
	{
		int sum=0;
		for(int x:a[i])
		{
			sum=(sum+(ll)tag[x]*inv[n])%mod;
		}
		sum=(ll)sum*inv[SZ(a[i])]%mod;
		ans=(ans+sum)%mod;
	}
	ans=(ll)ans*inv[n]%mod;
	printf("%d\n",ans);
}

int main()
{
	prepare();
	init();
	doing();
	return 0;
}