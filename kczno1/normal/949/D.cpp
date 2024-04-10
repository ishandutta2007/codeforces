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
int n,d,b,l1,l2;
int a[N];ll s[N];

bool ok(int now)
{
	rep(i,now+1,l1)
	if(s[min((ll)n,i+(ll)i*d)]-s[0]<(i-now)*b)return 0;
	per(i,n-now,n-l2+1)
	if(s[n]-s[max((ll)0,i-(ll)(n-i+1)*d-1)]<(n-now-i+1)*b)return 0;
	return 1;
}

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	n=read();d=read();b=read();
	rep(i,1,n)a[i]=read();
	rep(i,1,n)s[i]=s[i-1]+a[i];
	l2=n/2;l1=n-l2;
	int l=-1,r=l1;
#define mid (l+r>>1)
	while(l+1!=r)
	if(ok(mid))r=mid;
	else l=mid;
	cout<<r;
}