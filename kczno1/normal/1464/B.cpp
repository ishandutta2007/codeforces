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

const int N=1e5+5;
char s[N];
int n,c0[N],c1[N],cm[N];
s64 p0[N],s1[N],w01,w10;

s64 work()
{
	s64 base=0;
	rep(i,1,n)
	{
		c0[i]=c0[i-1];
		c1[i]=c1[i-1];
		cm[i]=cm[i-1];
		if(s[i]=='?')++cm[i];
		else 
		if(s[i]=='0')
		{
			++c0[i];
			base+=c1[i]*w10;
		}
		else if(s[i]=='1')
		{
			++c1[i];
			base+=c0[i]*w01;
		}
	}
	rep(i,1,n)
	{
		p0[i]=p0[i-1];
		if(s[i]=='?')
		{
			p0[i]+=c1[i]*w10+(c1[n]-c1[i])*w01;
		}
	}
	per(i,n,1)
	{
		s1[i]=s1[i+1];
		if(s[i]=='?')
		{
			s1[i]+=(c0[n]-c0[i])*w10+c0[i]*w01;
		}
	}
	s64 ans=1e18;
	rep(i,0,n)chmin(ans,p0[i]+s1[i+1]+w01*cm[i]*(cm[n]-cm[i]));
	return ans+base;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	scanf("%s",s+1);
	cin>>w01>>w10;
	n=strlen(s+1);
	s64 ans=work();
	reverse(s+1,s+n+1);
	swap(w01,w10);
	cout<<min(ans,work())<<endl;	
}
 
/* stuff you should look for
	* int overflow, array bounds, uppercase/lowercase 
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/