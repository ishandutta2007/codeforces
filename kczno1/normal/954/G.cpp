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

const int N=2e6+5;
int n,r;ll k;
ll ad[N],ad0[N];

bool ok(ll ans)
{
	ll can=k;
	memcpy(ad,ad0,sizeof(ad));
	rep(i,1,n)
	{
		ad[i]+=ad[i-1];
		if(ad[i]<ans)
		{
			ll x=ans-ad[i];
			can-=x;
			if(can<0)return 0;
			ad[i]+=x;
			ad[i+2*r+1]-=x;
		}
	}
	return 1;
}

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	cin>>n>>r>>k;
	rep(i,1,n)
	{
		int x=read();
		ad[max(1,i-r)]+=x;ad[i+r+1]-=x;
	}
	memcpy(ad0,ad,sizeof(ad));
	ll l=0,r=2e18;
	while(l+1!=r)
	{
		ll mid=l+r>>1;
		if(ok(mid))l=mid;
		else r=mid;
	}
	cout<<l;
}