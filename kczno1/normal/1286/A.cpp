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

const int N=100+5;
int p[N],dp[N][N][2];
bool ap[N]; 

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n=read();
	rep(i,1,n)p[i]=read(); 
	rep(i,1,n)
	{
		rep(j,0,i)
		rep(k,0,1)dp[i][j][k]=N;
		ap[p[i]]=1;
		rep(k,0,1)
		if(p[i]==0||p[i]%2==k)
		rep(j,0,i-1)
		rep(k0,0,1)chmin(dp[i][j+k][k],dp[i-1][j][k0]+(k!=k0)); 
	}
/*	int c=0;
	rep(i,1,n)
	if(i%2&&!ap[i])++c;*/
	//cerr<<c<<endl;
	int c=(n+1)/2;	
	cout<<min(dp[n][c][0],dp[n][c][1]);	
}