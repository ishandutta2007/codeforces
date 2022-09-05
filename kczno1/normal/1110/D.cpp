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

const int N=1e6+5;
int a[N],dp[N][3][3];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n=read(),m=read();
	rep(i,1,n)++a[read()];
	rep(i,0,m+1)
	rep(j,0,2)
	rep(k,0,2)dp[i][j][k]=-N;
	dp[0][0][0]=0;
	rep(i,1,m+1)
	rep(j,0,2)
	rep(k,0,2)
	rep(x,0,min(2,a[i-1]-j-k))chmax(dp[i][j][k],dp[i-1][x][j]+x+(a[i-1]-j-k-x)/3);
	cout<<dp[m+1][0][0];
}