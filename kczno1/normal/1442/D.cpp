//#pragma GCC target("avx,avx2")	
#include<bits/stdc++.h>
//#include<immintrin.h>
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

const int N=3000+5,L=15;
vector<int>a[N];s64 s[N],ans,dp[L][N];
int n,k; 
void trans(s64 dp[N],int i)
{
	int sz=a[i].size();
	per(j,k,sz)chmax(dp[j],dp[j-sz]+s[i]);
}
void work(int d,int l,int r)
{
	if(l==r)
	{
		//if(l==1)cerr<<dp[d][2]<<endl;
		int m=min(int(a[l].size()),k);
		s64 ns=0;
		rep(i,0,m-1)
		{
			ns+=a[l][i];
			chmax(ans,ns+dp[d][k-1-i]);
		}
		return ;
	}
	int mid=(l+r)/2;
	memcpy(dp[d+1],dp[d],(k+1)*sizeof(s64));
	rep(i,l,mid)trans(dp[d+1],i);
	work(d+1,mid+1,r);
	memcpy(dp[d+1],dp[d],(k+1)*sizeof(s64));
	rep(i,mid+1,r)trans(dp[d+1],i);
	work(d+1,l,mid);
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	n=read();k=read();	
	rep(i,1,n)
	{
		int t=read();
		a[i].resize(t);
		rep(j,0,t-1)s[i]+=(a[i][j]=read());
	}
	work(0,1,n);
	cout<<ans<<endl;
}