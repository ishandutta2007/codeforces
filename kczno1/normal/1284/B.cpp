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
int mn[N],mx[N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n;
	cin>>n;
	int t=0;
	rep(i,1,n)
	{
		int l=read(),mn=1e6+5,mx=0,ap=0;
		rep(j,1,l)
		{
			int x=read();
			if(x>mn)ap=1;
			chmin(mn,x);
			chmax(mx,x);
		}
		if(!ap){++t;::mn[t]=mn;::mx[t]=mx;}
	}
	s64 ans=1LL*n*n-1LL*t*t;
	sort(mn+1,mn+t+1);
	sort(mx+1,mx+t+1);
	rep(i,1,t)ans+=lower_bound(mn+1,mn+t+1,mx[i])-mn-1;
	cout<<ans; 
}