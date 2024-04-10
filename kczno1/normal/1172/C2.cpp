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

const int N=2e5+5,M=3000+5,D=998244353;
s64 mi(s64 x,int y=D-2)
{
	s64 ans=1;
	while(y)
	{
		if(y&1)ans=ans*x%D;
		x=x*x%D;y>>=1; 
	}
	return ans;
}
int a[N],w[N];
namespace DP1
{
s64 dp[M],dp0[M],niv[2*M];
void work(int s0,int s1,int m)
{
	rep(i,0,2*M-1)niv[i]=mi(s0+s1+i-M);
	dp[0]=1;
	rep(i,1,m)
	{
		rep(j,0,i){dp0[j]=dp[j];dp[j]=0;}
		rep(j,0,i-1)
		{
			s64 p=(s1+j)*niv[j-(i-1-j)+M]%D;
			(dp[j]+=dp0[j]*(1-p))%=D;
			(dp[j+1]+=dp0[j]*p)%=D;
		}
	}
}
};
namespace F1
{
s64 niv[M];
map<s64,s64>mp;
s64 work(int a,int m)
{
	if(mp.count(a))return mp[a];
	s64 ans=0,sum=0;
	rep(i,1,m)
	{
		(sum+=(sum+a)*niv[i-1])%=D;
		(ans+=sum*DP1::dp[i])%=D; 
	}
	return mp[a]=ans;
}
};
namespace F0
{
s64 niv[M];
map<s64,s64>mp;
s64 work(int a,int m)
{
	if(mp.count(a))return mp[a];
	s64 ans=0,sum=0;
	rep(i,1,m)
	{
		(sum+=(a-sum)*niv[i-1])%=D;
		(ans+=sum*DP1::dp[m-i])%=D; 
	}
	return mp[a]=ans;
}
};

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n,m;
	cin>>n>>m;
	rep(i,1,n)a[i]=read();
	int s[2]={};
	rep(i,1,n)s[a[i]]+=(w[i]=read());
	DP1::work(s[0],s[1],m);	
	rep(i,0,m){F1::niv[i]=mi(s[1]+i);F0::niv[i]=mi(s[0]-i);}
	rep(i,1,n)
	{
		s64 ans;
		if(a[i])ans=w[i]+F1::work(w[i],m);
		else ans=w[i]-F0::work(w[i],m);
		printf("%d\n",int((ans%D+D)%D));
	}
}