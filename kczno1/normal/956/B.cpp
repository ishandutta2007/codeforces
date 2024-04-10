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

const int N=1e5+5;
ll ansa,ansb;
int a[N];

void up(ll a,ll b)
{
	if(a*ansb>b*ansa){ansa=a;ansb=b;}
}

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	int n=read(),U=read();
	rep(i,1,n)a[i]=read();
	int k=1;
	ansa=0;ansb=1;
	rep(i,1,n)
	{
		while(k<n&&a[k+1]-a[i]<=U)++k;
		if(k>i+1)up(a[k]-a[i+1],a[k]-a[i]);
	}
	if(!ansa)puts("-1");
	else printf("%.9lf\n",(double)ansa/ansb);
}