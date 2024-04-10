#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T&x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define gc (c=getchar())
char readc()
{
	char c;
	while(isspace(gc));
	return c;
}
int read()
{
	char c;
	while(gc<'-');
	if(c=='-')
	{
		int x=gc-'0';
		while(gc>='0')x=x*10+c-'0';
		return -x;
	}
	int x=c-'0';
	while(gc>='0')x=x*10+c-'0';
	return x;
}
#undef gc

const int N=1e6+5;
vector<int>son[N];int ty[N],n;
s64 dp[N];

int build()
{
	int x=++n;
	son[x].clear();
	if(readc()=='*')
	{
		ty[x]=2;
		dp[x]=1;
		return x;
	}
	son[x].push_back(build());
	ty[x]=readc()=='P';
	while(son[x].push_back(build()),readc()!=')');
	if(ty[x]==0)
	{
		dp[x]=dp[son[x][0]];
		for(auto y:son[x])chmin(dp[x],dp[y]);
	}
	else
	{
		dp[x]=0;
		for(auto y:son[x])dp[x]+=dp[y];
	}
	return x;
}
void dfs(int x,s64 p,s64 q)
{
	//cerr<<ty[x]<<endl;
	s64 d=__gcd(p,q);
	p/=d;q/=d;
	if(ty[x]==2)
	{
		printf(" %lld",s64(p));
		return ;
	}
	if(ty[x]==0)
	{
		for(auto y:son[x])
		if(dp[x]==dp[y])
		{
			dfs(y,p,q);
			p=0;
		}
		else 
		{
			dfs(y,0,1);
		}
	}
	else
	{
		for(auto y:son[x])dfs(y,p*dp[x],q*dp[y]);
	}
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int tt;
	cin>>tt;
	while(tt--)
	{
		int r=read();
		n=0;
		int rt=build();
		printf("REVOLTING");
		//cerr<<rt<<endl;
		dfs(rt,r,1);
		puts("");
	}
}