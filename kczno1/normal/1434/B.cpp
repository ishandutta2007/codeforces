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
char readc()
{
	char c;
	while(gc<'+');
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
int ans[N],st[N],a[N],top;

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n=read();
	int m=0;
	rep(i,1,2*n)
	{
		char c=readc();
		if(c=='+')
		{
			++top;
			st[top]=++m;
			a[top]=0;
		}
		else 
		{
			int x=read();
			if(!top||a[top]>x)
			{
				//cerr<<x<<" "<<top<<" "<<a[top]<<endl;
				puts("NO");
				exit(0);
			}
			ans[st[top]]=x;
			chmax(a[--top],x);
		}
	}	
	puts("YES");
	rep(i,1,n)printf("%d%c",ans[i]," \n"[i==n]);
}