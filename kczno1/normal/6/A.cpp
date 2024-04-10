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

const char dy[3][100]={"IMPOSSIBLE","SEGMENT","TRIANGLE"};
int ans=0;
void check(int a,int b,int c)
{
	if(a+b>c&&b+c>a&&a+c>b)ans=2; else
	if(a+b>=c&&b+c>=a&&a+c>=b)chmax(ans,1);
}

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	check(a,b,c);
	check(a,b,d);
	check(a,c,d);
	check(b,c,d);
	printf("%s\n",dy[ans]);
}