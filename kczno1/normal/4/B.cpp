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

const int N=30+5;
int mn[N],mx[N],a[N],s[N];

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	int d=read(),sum=read();
	rep(i,1,d)
	{
		mn[i]=read();mx[i]=read();
		sum-=mn[i];
		a[i]=mx[i]-mn[i];
	}
	per(i,d,1)s[i]=s[i+1]+a[i];
	if(sum<0||sum>s[1])puts("NO");
	else
	{
		puts("YES");
		rep(i,1,d)
		{
			int x=min(sum,a[i]);
			printf("%d ",mn[i]+x);
			sum-=x;
		}
	}
}