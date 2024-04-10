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

const int N=2e5+5;
int a[N];
pii p[N];

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	int n=read();
	rep(i,1,n)a[i]=read();
	int y=1;
	rep(i,2,n)
	if(abs(a[i]-a[i-1])!=1)y=abs(a[i]-a[i-1]);
	if(!y)
	{
		puts("NO");
		return 0;
	}
	rep(i,1,n)p[i]=mp( (a[i]-1)/y+1,(a[i]-1)%y+1 );
	rep(i,2,n)
	if(abs(p[i].first-p[i-1].first)+abs(p[i].second-p[i-1].second)!=1)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	printf("%d %d\n",1000000000,y);
}