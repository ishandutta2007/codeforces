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

const int N=5000+5,D=1e9+7;
ll sqr(const ll &x)
{
	return x*x%D;
}
ll mi(ll x,int y=D-2)
{
	ll ans=1;
	while(y)
	{
		if(y&1)ans=ans*x%D;
		x=x*x%D;y>>=1;
	}
	return ans;
}
int n;
ll a[N],s[N];
ll ans[N*2],ns[N*2];

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	n=read();
	rep(i,1,n-1)a[i]=read();
	s[1]=1;
	rep(i,2,n)s[i]=s[i-1]*a[i-1]%D;
	per(i,n-1,1)ans[i]=(ans[i+1]+s[i+1])%D;
	per(i,n,1)
	{
		ll x=s[i]*((a[i]*(a[i]-1)/2)%D)%D*sqr(mi(s[i+1]))%D;
		rep(k,2,2*(n-i))
			ans[k]+=x*ns[2*i+k-2]%D;
		rep(j,i,n)(ns[i+j-2]+=s[i]*s[j])%=D;
		rep(j,i+1,n)(ns[i+j-2]+=s[j]*s[i])%=D;
	}
	rep(i,1,2*n-2)printf("%d ",int(ans[i]%D));
}