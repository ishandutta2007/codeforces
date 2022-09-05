#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)

template <typename T> inline void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> inline void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}

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

const int N=2e5+5,U=60000;
int n,m,k,num;

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	cin>>n;
	while(n--)
	{
		int a=read(),b=read();
		ll x=ll(a)*b;
		int y=pow(x,1.0/3)+1e-8;
		if(x==ll(y)*y*y&&a%y==0&&b%y==0) puts("Yes");
		else puts("No");
    }
}