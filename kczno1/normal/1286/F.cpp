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

const int N=20+5,U=1<<20,U1=1<<10;
s64 a[N],sum[U];
int dp[U];

int n,m;
vector<s64>al[U1],ar[U1];

vector<s64> add(const vector<s64> &a,const s64 &d)
{
	int n=a.size();
	vector<s64>ans;
	int j=0;
	rep(i,0,n-1)
	{
		while(j<n&&a[j]+d<a[i])ans.push_back(a[j++]+d);
		ans.push_back(a[i]);
	}
	while(j<n)ans.push_back(a[j++]+d);
	return ans;
}

bool work(const vector<s64> &a,const vector<s64> &b,s64 l,s64 r,int cnt)
{
	int n=a.size(),m=b.size();
	if(n>m)return work(b,a,l,r,cnt);
	//rep(i,1,n-1)assert(a[i]>=a[i-1]);
	//rep(i,1,m-1)assert(b[i]>=b[i-1]);	
	auto j=b.begin();
	per(i,n-1,0)
	{
		j=lower_bound(j,b.end(),l-a[i]);
		if(j==b.end())return 0;
		if(*j<=r-a[i])
		{
			auto j1=j;
			while(j1<b.end()&&*j1<=r-a[i])
			{
				if(!cnt)return 1;
				--cnt;
				++j1;
			}
		}
	}
	return 0;
}

bool ok(int s)
{
	int m=__builtin_popcount(s);
	if(m<=1)return 0;
	if((sum[s]-m+1)%2)return 0;
	int sl=s&(1<<::m)-1,sr=s>>::m;
	s64 l=(sum[s]-(m-1))/2,r=(sum[s]+m-1)/2;
/*	for(int t=s;t;(--t)&=s)
	if(sum[t]>=(sum[s]-(m-1))/2&&sum[t]<=(sum[s]+m-1)/2)return 1;*/
	/*if(s==3)
	{
		cerr<<l<<" "<<r<<endl;
		for(auto x:al[sl])cerr<<x<<" ";cerr<<endl;
		for(auto x:ar[sr])cerr<<x<<" ";cerr<<endl;
	}*/
	
	int cnt=(l<=0&&0<=r)+1;
	/*for(auto x:al[sl])
	for(auto y:ar[sr]) 
	if(x+y>=l&&x+y<=r)++cnt;
	return cnt>0;*/
	return work(al[sl],ar[sr],l,r,cnt);
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n0;
	cin>>n0;
	n=0;
	rep(tmp,1,n0)
	{
		s64 x;
		cin>>x;
		if(x)a[n++]=x;
	}
	int u=(1<<n)-1;
	rep(s,1,u)
	rep(i,0,n-1)
	if(s&(1<<i)){sum[s]=sum[s-(1<<i)]+a[i];break;}
	
	m=n/2;
	al[0].resize(1);
	rep(s,1,(1<<m)-1)
	rep(i,0,m-1)
	if(s&(1<<i)){al[s]=add(al[s-(1<<i)],a[i]);break;}
	ar[0].resize(1);
	rep(s,1,(1<<n-m)-1)
	rep(i,0,n-m-1)
	if(s&(1<<i)){ar[s]=add(ar[s-(1<<i)],a[m+i]);break;}
//	exit(0);
	rep(s,1,u)dp[s]=__builtin_popcount(s);
	rep(s,1,u)
	{
		int i=n-1;
		while(!(s&(1<<i)))--i;
		chmin(dp[s],dp[s-(1<<i)]+1);
		if(dp[s]==__builtin_popcount(s)&&ok(s))
		{
			--dp[s];
			int nu=(u-s)&((1<<i)-1);
			for(int t=nu;t;(--t)&=nu)
				chmin(dp[s+t],dp[s]+dp[t]);
		}
	}
	cout<<dp[u];
}