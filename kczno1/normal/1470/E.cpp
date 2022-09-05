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

const int C=5,N=3e4+5;
s64 dp[C][N],sum[C][N],sum1[C][N];
int p[N];
vector<int>lk[N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	rep(c,0,4)
	{
		dp[c][0]=1;
		rep(n,1,30000)
		rep(i,0,min(n-1,c))dp[c][n]+=dp[c-i][n-i-1];
	}
	int tt=read();
	while(tt--)
	{
		int n=read(),c=read(),q=read();
		rep(i,1,n)p[i]=read();
		per(i,n,1)
		{
			lk[i].clear();
			rep(j,0,c)
			{
				if(i+j<=n)lk[i].push_back(j);
				sort(lk[i].begin(),lk[i].end(),[&](int x,int y){return p[i+x]<p[i+y];});
			}
		}
		rep(i,1,n)
		{
			rep(j,0,c)
			{
				sum[j][i]=sum[j][i-1];
				rep(k,0,j)
				if(i+k<=n && p[i+k]<p[i])sum[j][i]+=dp[j-k][n-i-k];
				sum1[j][i]=sum[j][i]+dp[j][n-i];
			}
		}
		while(q--)
		{
			int query_i=read();
			s64 k;
			scanf("%lld",&k);
			if(k>dp[c][n])
			{
				puts("-1");
				continue;
			}
			int i=1,nc=c;
			while(i<=n)
			{
				int j=0;
				s64 now;
				while(1)
				{
					while(lk[i][j]>nc)++j;
					if(k<=(now=dp[nc-lk[i][j]][n-i-lk[i][j]]))break;
					k-=now;
					++j;
				}
				nc-=lk[i][j];
				int i1=i+lk[i][j];
				if(i1>=query_i)
				{
					printf("%d\n",p[i+i1-query_i]);
					break;
				}
				i=i1+1;
				i1=min(lower_bound(sum[nc]+i,sum[nc]+n,k+sum[nc][i-1])-sum[nc],
				lower_bound(sum1[nc]+i,sum1[nc]+n,k+sum[nc][i-1]-1,greater<s64>())-sum1[nc]);
				if(i1>query_i)
				{
					printf("%d\n",p[query_i]);
					break;
				}
				k-=sum[nc][i1-1]-sum[nc][i-1];
				i=i1;
			}
		}
	}	
}
 
/* stuff you should look for
	* int overflow, array bounds, uppercase/lowercase 
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/