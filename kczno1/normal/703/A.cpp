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
#define rep(i,l,r) for(int i=l,i##_r=r;i<=i##_r;++i)
#define per(i,r,l) for(int i=r,i##_l=l;i>=i##_l;--i)
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

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	int n=read();
	int w=0;
	while(n--)
	{
		int x=read(),y=read();
		if(x!=y)w+=(x>y)?1:-1;
	}
	if(w>0)puts("Mishka"); else
	if(w<0)puts("Chris"); else
		puts("Friendship is magic!^^");
}