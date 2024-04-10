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

const int N=500+5;
s64 f[N][N],g[N][N],C[N][N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int N,M,p;
	cin>>N>>M>>p;
	rep(i,0,N)
	{
		C[i][0]=1;
		rep(j,1,i)C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;
	}
	rep(n,0,N)
	{
		f[n][0]=1;
		rep(m,1,min(M,n))
		{
			s64 ans_f=f[n][m-1]*n*2%p,ans_g=g[n][m-1]*n*2%p;
			rep(l,1,m-1)
			{
				(ans_f-=2*C[m-1][l]*f[l][l]%p*f[n-1-l][m-1-l]%p*l)%=p;
				(ans_g-=2*C[m-1][l]*
					((f[l][l]*g[n-1-l][m-1-l]+f[n-1-l][m-1-l]*g[l][l])%p)%p*l)%=p;
				(ans_g+=2*C[m-1][l]*f[l][l]%p
					*(f[n-l-1][m-1-l]*(n-m+1)%p)%p*(s64(l)*(l+1)/2%p))%=p;
			}
			f[n][m]=ans_f;
			g[n][m]=ans_g;
		}
	}
	cout<<(g[N][M]%p+p)%p<<endl;
}
 
/* stuff you should look for
	* int overflow, array bounds, uppercase/lowercase 
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/