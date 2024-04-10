//by kcz 1552920354@qq.com
//if you find any bug in my code
//please tell me
#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
typedef long long ll;
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

const int N=35+2;
ll dp[N][N];

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","r",stdin);
	int n,h;
	cin>>n>>h;
	dp[0][0]=1;
	rep(j,1,n)
	{
		dp[j][0]=1;
		rep(i,1,n)
		rep(l,0,i-1)dp[j][i]+=dp[j-1][l]*dp[j-1][i-1-l];
	}
	cout<<dp[n][n]-dp[h-1][n];
}