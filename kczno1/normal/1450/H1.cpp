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

const int N=2e5+5,D=998244353;
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
s64 jie[N],niv_jie[N];

s64 C(int n,int m)
{
	return jie[n]*niv_jie[m]%D*niv_jie[n-m]%D;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n,m;
	cin>>n>>m;
	jie[0]=1;
	rep(i,1,n)jie[i]=jie[i-1]*i%D;
	niv_jie[n]=mi(jie[n]);
	per(i,n,1)niv_jie[i-1]=niv_jie[i]*i%D;

	string str;
	cin>>str;
	int x=n/2,u=0;
	rep(i,0,n-1)
	if(str[i]=='?')++u;
	else if((str[i]=='b')^(i%2))--x;

	s64 ans=0;
	rep(i,0,u)
	if((i-x)%2==0)(ans+=C(u,i)*abs(x-i))%=D;
	cout<< (ans%D+D)*mi(mi(2,u))%D <<endl;
}
 
/* stuff you should look for
	* int overflow, array bounds, uppercase/lowercase 
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/