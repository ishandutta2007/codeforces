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
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
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
int n;
void o(int x)
{
	rep(i,1,x-1)printf("%d ",n+i+1);
	printf("%d ",n+1);
	n+=x;
}

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	int n,a,b;
	cin>>n>>a>>b;
	for(int x=0;x<=n/a;++x)
	if((n-a*x)%b==0)
	{
		rep(i,1,x)o(a);
		rep(i,1,(n-a*x)/b)o(b);
		return 0;
	}
	puts("-1");
}