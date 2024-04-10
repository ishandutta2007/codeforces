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
typedef long long s64;
typedef unsigned long long u64;
typedef unsigned int u32;
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

const int N=3e5+5;
int a[N],s[N],c[N][2];
int q[N],top;	

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n=read();
	rep(i,1,n)
	{
		s64 x;
		scanf("%lld",&x);
		rep(j,0,59)a[i]+=(x>>j)&1;
	}
	rep(i,1,n)
	{
		s[i]=s[i-1]+a[i];
		rep(j,0,1)c[i][j]=c[i-1][j];
		++c[i][s[i-1]%2];
	}
	s64 ans=0;
	rep(i,1,n)
	{
		while(top&&a[q[top]]<=a[i])--top;
		q[++top]=i;
		per(j,top,1)
		{
			int l=q[j-1]+1,r=q[j];
			while(r>=l&&2*a[q[j]]>s[i]-s[r-1])--r;
			ans+=c[r][s[i]%2]-c[l-1][s[i]%2];
		}
	}
	cout<<ans;
}