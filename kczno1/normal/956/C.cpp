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
int a[N],mn[N];

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	int n=read();
	rep(i,1,n)a[i]=read();
	rep(i,1,n)mn[i]=max(mn[i-1],a[i]+1);
	per(i,n,1)chmax(mn[i],mn[i+1]-1);
	ll ans=0;
	rep(i,1,n)ans+=mn[i]-a[i]-1;
	cout<<ans<<endl;
}