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

const int N=3e5+5;
int a[N],b[N],pre[N],nex[N],mx_dep[N];
char ans[N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int tt;
	cin>>tt;
	while(tt--)
	{
		int n=read();
		rep(i,1,n)
		{
			a[i]=read();b[i]=i;
			nex[i]=i+1;
			pre[i]=i-1;
			mx_dep[i]=0;
		}
		sort(b+1,b+n+1,[&](int x,int y){return a[x]<a[y];});
		rep(i,1,n)ans[i]='1';ans[n+1]=0;
		int mx=0,mx2=0;
		per(i,n,1)
		{
			int x=b[i];
			int l=pre[x],r=nex[x];
			nex[l]=r;pre[r]=l;
			++l;--r;
			//cout<<x<<" "<<l<<" "<<r<<endl;
			if(l<x&&x<r)chmax(mx,r-l);
			int now=r-l+1;
			chmax(mx2,min(now,mx_dep[a[x]]));
			chmax(mx_dep[a[x]],now);
		}
		rep(i,2,mx)ans[i]='0';
		rep(i,1,mx2)ans[i]='0';
		int nmx=0;
		rep(i,2,n)
		{
			chmax(nmx,mx_dep[n+2-i]);
			if(nmx>=i)ans[i]='0';
		}
		printf("%s\n",ans+1);
	}	
}