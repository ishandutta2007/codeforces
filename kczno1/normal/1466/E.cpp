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

const int D=1e9+7;

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int tt=read();	
	while(tt--)
	{
		int n=read();
		vector<s64>x(n),cnt(60);
		rep(i,0,n-1)
		{
			scanf("%lld",&x[i]);
			rep(j,0,59)cnt[j]+=(x[i]>>j)&1;
		}
		s64 ans=0;
		rep(i,0,n-1)
		{
			s64 sum_and=0,sum_or=0;
			rep(j,0,59)
			if((x[i]>>j)&1)
			{
				(sum_and+=s64(cnt[j])*((s64(1)<<j)%D))%=D;
				(sum_or+=s64(n)*((s64(1)<<j)%D))%=D;
			}
			else 
			{
				(sum_or+=s64(cnt[j])*((s64(1)<<j)%D))%=D;
			}
			(ans+=sum_and*sum_or)%=D;
		}
		cout<<ans<<endl;
	}
}
 
/* stuff you should look for
	* int overflow, array bounds, uppercase/lowercase 
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/