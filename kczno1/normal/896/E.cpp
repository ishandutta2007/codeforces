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

const int N=1e5+5;		
int a[N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n=read(),m=read();
	rep(i,1,n)a[i]=read();
	while(m--)
	{
		int ty=read(),l=read(),r=read(),x=read();
		__m256i _x=_mm256_set_epi32(x,x,x,x,x,x,x,x);
		if(ty==1)
		{
			for(;l<=r&&u64(a+l)%32;++l)a[l]>x?a[l]-=x:0;
			for(;l+7<=r;l+=8)
			{
				__m256i v=*(__m256i*)(a+l);
				__m256i c=_mm256_cmpgt_epi32(v,_x);
				*(__m256i*)(a+l)=_mm256_sub_epi32(v,_mm256_and_si256(c,_x));
			}
			for(;l<=r;++l)a[l]>x?a[l]-=x:0;
		}
		else 
		{
			int ans=0;
			for(;l<=r&&u64(a+l)%32;++l)a[l]==x?++ans:0;
			__m256i sum=_mm256_setzero_si256();
			for(;l+7<=r;l+=8)
			{
				__m256i v=*(__m256i*)(a+l);
				sum=_mm256_sub_epi32(sum,_mm256_cmpeq_epi32(v,_x));
			}
			rep(i,0,7)ans+=((int*)&sum)[i];
			for(;l<=r;++l)a[l]==x?++ans:0;
			printf("%d\n",ans);
		}
	}
}