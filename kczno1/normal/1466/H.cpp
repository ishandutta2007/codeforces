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

const int N=40+5,U=1440+5,D=1e9+7;
s64 dp[U],f[N][N],C[N][N],jie[N];
int sz[U];
int p[N],cnt_of_len[N],prod[N];
bool vis[N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
/*	int n=40;
	rep(i,0,n)dp[i]=1;
	rep(sz,1,n)
	per(i,n,sz)
	rep(j,1,i/sz)chmax(dp[i],dp[i-j*sz]*(j+1));
	cout<<dp[n]<<endl;*/	
	int n;
	cin>>n;
	rep(i,1,n)cin>>p[i];
	rep(i,1,n)
	if(!vis[i])
	{
		int len=0;
		for(int j=i;!vis[j];j=p[j])
		{
			vis[j]=1;
			++len;
		}
		++cnt_of_len[len];
	}

	rep(i,0,n)
	{
		C[i][0]=1;
		rep(j,1,i)C[i][j]=(C[i-1][j]+C[i-1][j-1])%D;
	}
	jie[0]=1;
	rep(i,1,n)jie[i]=jie[i-1]*i%D;
	rep(y,0,n-1)
	{
		rep(i,0,y)(f[y][1]+=C[y][i]*jie[i]%D*jie[n-1-i])%=D;
		f[y][0]=1;
		rep(x,2,n)f[y][x]=f[y][x-1]*f[y][1]%D;
	}

	prod[0]=1;
	rep(i,1,n)prod[i]=prod[i-1]*(cnt_of_len[i]+1);
	int u=prod[n]-1;
	dp[0]=1;
	rep(s,1,u)
	{
		static int q[U];
		static s64 w[U];
		int t=0;
		q[0]=0;w[0]=-1;
		rep(i,1,n)
		{
			int t0=t;
			int nmx=(s/prod[i-1])%(cnt_of_len[i]+1);
			sz[s]+=nmx*i;
			per(j,nmx,1)
			rep(h,0,t0)
			{
				q[++t]=q[h]+j*prod[i-1];
				w[t]=(j%2?-1:1)*w[h]*C[nmx][j]%D;
			}
		}

		s64 ans=0;
		rep(h,1,t)
			(ans+=w[h]*dp[s-q[h]]%D*f[sz[s]-sz[q[h]]][sz[q[h]]])%=D;
		dp[s]=ans;
	}
	cout<<(dp[u]%D+D)%D<<endl;
}
 
/* stuff you should look for
	* int overflow, array bounds, uppercase/lowercase 
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/