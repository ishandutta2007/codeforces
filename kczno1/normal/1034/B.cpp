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
typedef long long s64;
typedef unsigned long long u64;
typedef unsigned int u32;
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

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n,m;
	cin>>n>>m;
	if(m==1)swap(n,m);
	if(n==1)
	{
		cout<<m-m%6+2*max(0,m%6-3);
		exit(0);
	}
	if(m>=4&&m%2==0)swap(n,m);
	if(n>=4&&n%2==0)
	{
		cout<<(s64)n*m;
		exit(0);
	}
	if(m==2)swap(n,m);
	if(n==2)
	{
		cout<<((m<=2)?0:(n*m-2*(m==3||m==7)));
		exit(0);
	}
	cout<<(s64)n*m-1;
}