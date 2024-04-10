//by kcz 1552920354@qq.com
//if you find any bug in my code
//please tell me
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
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned short us;
typedef unsigned int ui;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define mp make_pair
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
const int N=1000+5;
int a[N][N],c[2][N][N];
int dp[2][N][N];
int n,x,y;
int count(int x,int y)
{
	int c=0;
	while(x%y==0){x/=y;++c;}
	return c;
}
void init(int dp[N][N],int c[N][N])
{
	dp[1][1]=c[1][1];
	rep(i,2,n)dp[1][i]=dp[1][i-1]+c[1][i];
	rep(i,2,n)dp[i][1]=dp[i-1][1]+c[i][1];
	rep(i,2,n)
	rep(j,2,n)dp[i][j]=min(dp[i-1][j],dp[i][j-1])+c[i][j];
}
void write(int dp[N][N])
{
	printf("%d\n",dp[n][n]);
	int x=n,y=n;
	static char st[N*2];int top=0;
#define p(x) st[++top]=*#x;
	while(x>1&&y>1)
	{
		if(dp[x-1][y]<dp[x][y-1])
		{
			--x;
			p(D)
		}
		else
		{
			--y;
			p(R)
		}
	}
	while(--x>=1)p(D)
	while(--y>=1)p(R)
	reverse(st+1,st+top+1);
	printf("%s\n",st+1);
}
#undef p
int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	n=read();
	rep(i,1,n)
	rep(j,1,n)
	{
		a[i][j]=read();
		if(!a[i][j]){x=i;y=j;continue;}
		c[0][i][j]=count(a[i][j],2);
		c[1][i][j]=count(a[i][j],5);
	}
	rep(o,0,1)init(dp[o],c[o]);
	if(dp[0][n][n]&&dp[1][n][n]&&x)
	{
		puts("1");
#define p(x) putchar(*#x);
		rep(i,1,x-1)p(D)
		rep(i,1,y-1)p(R)
		rep(i,x,n-1)p(D)
		rep(i,y,n-1)p(R)
#undef p
		return 0;
	}
	if(dp[0][n][n]<=dp[1][n][n])write(dp[0]);
	else write(dp[1]);
}