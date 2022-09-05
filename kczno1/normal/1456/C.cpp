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

const int N=5e5+5;
int a[N];
s64 s0[N],s1[N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n,k;
	cin>>n>>k;
	rep(i,1,n)a[i]=read();
	sort(a+1,a+n+1);
	per(i,n,1)
	{
		s0[i]=s0[i+1]+a[i];
		s1[i]=s1[i+1]+1LL*a[i]*i;
	}
	s64 ans=-1e18,base=0;
	int len=0;
	rep(i,1,n)
	{
		chmax(ans,base+s1[i]+s0[i]*(-i+len));
//		cout<<ans<<endl;
		if(k==0 || i%(k+1)==1)++len;
		base+=1LL*a[i]*(len-1);
	}
	chmax(ans,base);
	cout<<ans<<endl;
}
 
/* stuff you should look for
	* int overflow, array bounds, uppercase/lowercase 
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/