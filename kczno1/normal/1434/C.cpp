#pragma GCC target("avx,avx2")	
#include<bits/stdc++.h>
#include<immintrin.h>
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

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int tt;
	cin>>tt;
	while(tt--)	
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		if(a>1LL*b*c)
		{
			puts("-1");
			continue;
		}
		auto check=[&](int m)->s64
		{
			if(m<0)return 0;
			int i=min(m-1,c/d);
			return 1LL*m*a-b*( 1LL*d*i*(i+1)/2+1LL*(m-1-i)*c );
		};		
		int l=0,r=c/d+5;
		while(l+1!=r)
		{
			int mid=(l+r)/2;
			if(check(mid)<check(mid+1))l=mid;
			else r=mid;
		}
		printf("%lld\n",check(r));
	}
}