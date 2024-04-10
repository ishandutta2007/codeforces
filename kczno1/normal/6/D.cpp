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

const int N=10+2,U=15+2;
int dp[N][U][U],mn[N][U][U],need[U];
int n,a,b,h[N];

int main()
{
	//freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	cin>>n>>a>>b;
	rep(i,1,n)h[i]=read();
	memset(dp,(1<<6)-1,sizeof(dp));
	rep(i,0,U-1)
	if(i*b>h[n])dp[n][i][0]=0;
	rep(i,0,U-1)need[i]=i/b+1;
	per(i,n,1)
	{
		if(i<n)
		{
			rep(j,0,U-1)
			{
				int v=h[i]-j*b;
				rep(k,0,U-1)
				{
					dp[i][j][k]=k+mn[i+1][k][v<0?0:need[v]];
					v-=a;
				}
			}
		}
		rep(j,0,U-1)
		{
			mn[i][j][U-1]=dp[i][j][U-1];
			per(k,U-2,0)mn[i][j][k]=min(mn[i][j][k+1],dp[i][j][k]);
		}
	}
	int i=1,j=0,k=0;
	printf("%d\n",dp[i][j][k]);
	while(++i<n)
	{
		int v=h[i-1]-j*b-k*a;
		int l=v<0?0:need[v];
		while(dp[i][k][l]!=dp[i-1][j][k]-k)++l;
		j=k;k=l;
		rep(o,1,l)printf("%d ",i);
	}
}