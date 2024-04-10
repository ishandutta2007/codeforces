#include<bits/stdc++.h>
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
int a[N],ans[N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n;
	cin>>n;
	rep(i,1,n)a[i]=read();
	printf("%d %d\n",1,n);
	rep(i,1,n)
	{
		int s=a[i]/n;
		int y=n*s-a[i];
		printf("%lld%c",-1LL*(s-y)*n," \n"[i==n]);
		ans[i]=y;
	}
	if(n==1)
	{
		rep(tmp,1,2)
		{
			printf("%d %d\n",1,n);
			puts("0");
		}
		exit(0);
	}
	printf("%d %d\n",1,n-1);
	rep(i,1,n-1)
		printf("%lld%c",-1LL*ans[i]*(n-1)," \n"[i==n-1]);
	printf("%d %d\n",2,n);
	rep(i,2,n)
		printf("%lld%c",(i==n)?-1LL*ans[i]*(n-1):0," \n"[i==n]);
}