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

const int maxn=5e5+20;
const int maxp=1e7+20;
const int mod=1e9+7;

int prime[maxp],mark[maxp],d[maxp],mu[maxp],ptot;

inline void prepare()
{
	mu[1]=1;
	REP(i,2,1e7)
	{
		if(!mark[i])prime[++ptot]=i,d[i]=i,mu[i]=-1;
		for(int j=1,k;j<=ptot && (ll)i*prime[j]<=maxp;j++)
		{
			k=i*prime[j]; mark[k]=1; d[k]=prime[j];
			if(!(i%prime[j])){ mu[k]=0; break;}
			else mu[k]=-mu[i];
		}
	}
}

int n,tag[maxp],p2[maxn];

#define pii pair<int,int>

vector<pii>a;

inline void fj(int x,int ad)
{             
	a.clear();
	while(x>1)
	{
		int p=d[x],s=0;
		while(!(x%p))x/=p,s++;
		a.push_back(mkr(p,s));	
	}
	if(x>1)a.push_back(mkr(x,1));
	function <void(int u,int s)> dfs=[&](int u,int s) {
		if(u==SZ(a))
		{
			tag[s]+=ad;
			return;
		}
		REP(j,0,1)dfs(u+1,s),s*=a[u].fi;
	};
	dfs(0,1);
}

inline void init()
{
	n=read();
	REP(i,1,n)tag[read()]++;
	p2[0]=1; REP(i,1,n)p2[i]=(ll)p2[i-1]*2%mod;
	REP(i,2,1e7)if(tag[i])
	{
		int t=tag[i]; tag[i]=0;
		fj(i,t);
	}
}

inline void doing()
{
	int ans=0;
	REP(i,1,1e7)if(tag[i] && mu[i])
	{
		int res=(ll)p2[tag[i]]*(tag[i]-n)%mod+n;
		ans=(ans+res*mu[i])%mod;
	}
	ans=(ans+mod)%mod;
	printf("%d\n",ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("CF585E.in","r",stdin);
	freopen("CF585E.out","w",stdout);
#endif
	prepare();
	init();
	doing();
	return 0;
}