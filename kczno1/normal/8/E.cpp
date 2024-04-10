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
int n;ll k;
void write(const ll &s)
{
	per(i,n-1,0)
	if((s>>i)&1)putchar('1');
	else putchar('0');
}
namespace ou
{
void solve()
{
	int m=n/2-1;
	int u=1<<m;
	int i=0,f;
	for(;i<u;++i)
	{
		f=2*(u-i);
		if(k>f)k-=f;
		else break;
	}
	if(i>=u)
	{
		puts("-1");
		return ;
	}
	int ans1=i;
	int ans2;
	int j=0,rev=0;
	++m;u*=2;
	int r=u-1-i;
	while(1)
	{
		if(rev>=i&&rev<=r)
		{
			if(!--k)break;
		}
		int low=0;
		for(;j&(1<<low);++low)
			rev-=1<<m-1-low;
		rev+=1<<m-1-low;
		++j;
	}
	ans2=j;
	write(((ll)ans1<<m)+ans2);	
}
};
namespace ji
{
void solve()
{
	int m=n/2-1;
	int u=1<<m;
	int i=0,f;
	for(;i<u;++i)
	{
		f=4*(u-i)-1;
		if(k>f)k-=f;
		else break;
	}
	if(i>=u)
	{
		puts("-1");
		return ;
	}
	f=(f+1)/2;
	int ans1=i,ans2;
	ans1*=2;
		int j=0,rev=0;
		++m;u*=2;
		int r=u-1-i;
	if(k>f)
	{
		k-=f;
		++ans1;
		--r;
	}
		while(1)
		{
			if(rev>=i&&rev<=r)
			{
				if(!--k)break;
			}
			int low=0;
			for(;j&(1<<low);++low)
				rev-=1<<m-1-low;
			rev+=1<<m-1-low;
			++j;
		}
		ans2=j;
	write(((ll)ans1<<m)+ans2);	
}
};
int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","r",stdin);
	cin>>n>>k;
	++k;
	if(n%2==0)ou::solve();
	else ji::solve();
}