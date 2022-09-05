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
const int K=5000+5,D=1e9+7;
ll mi(ll x,int y)
{
	ll ans=1;
	while(y)
	{
		if(y&1)ans=ans*x%D;
		x=x*x%D;y>>=1;
	}
	return ans;
}
ll f[K][K];

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	int n,k;
	cin>>n>>k;
	f[0][0]=1;
	rep(i,0,k-1)
	{
		int mj=min(n,i);
		rep(j,0,mj)
		{
			(f[i+1][j]+=f[i][j]*j)%=D;
			(f[i+1][j+1]+=f[i][j]*(n-j))%=D;
		}
	}
	ll ans=0;
	int mi=min(n,k);
	rep(i,0,mi)(ans+=f[k][i]*::mi(2,n-i))%=D;
	cout<<ans;
}