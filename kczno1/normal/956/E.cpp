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
char readc()
{
	char c;
	while(gc<'-');
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

const int N=1e4+5;
bitset<N>dp[2];
int a[N],b[N];
int main()
{
//	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	int n=read(),l=read(),r=read();
	rep(i,1,n)a[i]=read();
	rep(i,1,n)b[i]=read();
	dp[1][0]=1;
	int top=0;
	rep(i,1,n)
	if(!b[i])dp[1]|=dp[1]<<a[i];
	else a[++top]=a[i];
	sort(a+1,a+top+1);
	int sum=0;
	rep(i,1,top)sum+=a[i];
	for(int i=top;i>=1;--i)
	{
		sum-=a[i];
		dp[0]=dp[1]|(dp[0]<<a[i]);
		dp[1]|=dp[1]<<a[i];
		if(dp[0]._Find_next(l-1)+sum<=r)
		{
			cout<<i<<endl;
			return 0;
		}
	}
	puts("0");
}