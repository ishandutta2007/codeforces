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

const int N=2000+5;
int s[2][N],mn[2][N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n=read(),m=read();
	rep(i,1,n)s[0][i]=s[0][i-1]+read();
	rep(i,1,m)s[1][i]=s[1][i-1]+read();
	rep(i,1,n)
	{
		mn[0][i]=s[0][i];
		rep(j,i+1,n)chmin(mn[0][i],s[0][j]-s[0][j-i]);
	}
	rep(i,1,m)
	{
		mn[1][i]=s[1][i];
		rep(j,i+1,m)chmin(mn[1][i],s[1][j]-s[1][j-i]);
	}
	int x=read(),ans=0;
	rep(i,1,n)
	rep(j,1,m)
	if(s64(mn[0][i])*mn[1][j]<=x)chmax(ans,i*j);
	cout<<ans;
}