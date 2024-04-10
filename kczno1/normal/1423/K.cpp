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

const int N=1e6+5;
int ans[N],mn[N];

void init(int n)
{
	rep(i,1,n)mn[i]=n+1;
	rep(d,2,n)
	rep(x,1,n/d)
		if(2*x-1>d)mn[x*d]=x*d;
		else 
		{
			int y=max(x+1,d-x+1);		
			if(y<=n/d)chmin(mn[x*d],y*d);
		}
	rep(i,1,n)++ans[mn[i]];
	rep(i,1,n)ans[i]+=ans[i-1];
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	init(1e6);
	int tt;
	cin>>tt;
	while(tt--)
	{
		int n=read();
		printf("%d\n",n-ans[n]);
	}
}