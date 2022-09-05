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
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;
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
pii p[N];
s64 s[N];

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	int n,a,b;
	cin>>n>>a>>b;
	rep(i,1,n){p[i].first=read();p[i].second=read();p[i].first-=p[i].second;}
	sort(p+1,p+n+1,greater<pii>());
	rep(i,1,n)s[i]=s[i-1]+max(0,p[i].first);
	rep(i,n+1,b)s[i]=s[i-1];
	s64 ans=s[b];
	if(b)
	rep(i,1,n)chmax(ans,((i<b)?s[b]-max(0,p[i].first):s[b-1])+((s64)(p[i].first+p[i].second)<<a)-p[i].second);
	rep(i,1,n)ans+=p[i].second;
	cout<<ans;
}