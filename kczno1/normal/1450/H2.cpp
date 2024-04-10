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
	if(m<0||m>n)return 0;
	return jie[n]*niv_jie[m]%D*niv_jie[n-m]%D;
}
struct Data
{
	int u,x;
	s64 sum;//sum of C(u,i) i=0..x
	s64 query(int u1,int x1)
	{
		if(x<10 || x1<10)
		{
			u=u1;x=x1;sum=0;
			rep(i,0,x)sum+=C(u,i);
			sum%=D;
			return sum;
		}
		while(u<u1)
		{
			sum=(sum*2-C(u,x))%D;
			++u;
		}
		while(u>u1)
		{
			--u;
			sum=(sum+C(u,x))*((D+1)/2)%D;
		}
		while(x<x1)
		{
			++x;
			sum=(sum+C(u,x))%D;
		}
		while(x>x1)
		{
			sum=(sum-C(u,x))%D;
			--x;
		}
		return sum;
	}
}A[2],B[2];

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
	int u=0,x=n/2;
	auto add=[&](int i,int w)
	{
		if(str[i]=='?')u+=w;
		else if((str[i]=='b')^(i%2))x-=w;
	};
	auto query=[&](int i,int m)
	{
		chmin(m,u);
		if((m-x)%2)--m;
		if(m<=5)
		{
			s64 ans=0;
			for(int j=m;j>=0;j-=2)(ans+=(j-x)*C(u,j))%=D;
			return ans;
		}
		return (B[i].query(u-2,m-1)*u-A[i].query(u-1,m)*x)%D;
	};
	rep(i,0,n-1)add(i,1);
	rep(query_id,0,m)
	{
		if(query_id)
		{
			int i=read()-1;char c=readc();
			add(i,-1);
			str[i]=c;
			add(i,1);
		}
		s64 ans=query(0,u)-2*query(1,x);
		printf("%d\n", int((ans%D+D)*mi(mi(2,u))%D) );
	}
}
 
/* stuff you should look for
	* int overflow, array bounds, uppercase/lowercase 
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/