#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,u) for(int i=start[u];i;i=e[i].next)
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
#define SZ(A) ((int)A.size())
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
inline int read()
{
    int s=0,f=1; char ch=getchar();
    while(!isdigit(ch) && ch!='-')ch=getchar();
    if(ch=='-')ch=getchar(),f=-1;
    while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
    return ~f?s:-s;
}

const int maxn=1e5+20;

int n;
ll k;
ll a[maxn];

inline void init()
{
    n=read();cin>>k;
    REP(i,1,n)a[i]=read();
}

ll b[maxn];
const double eps=1e-10;

inline ll check(ll x)
{
    ll num=0;
    REP(i,1,n)
    {
	ll c=1+x-a[i];
	ll l=0,r=a[i]-1;
	if(a[i]<x){ b[i]=0; continue;}
	while(l<r)
	{
	    ll mid=l+r+1>>1;
	    if(a[i]-3*mid*mid-3*mid-1<x)
		r=mid-1;
	    else l=mid;
	}
	b[i]=l+1; num+=l+1;
    }
    return num;
}

inline void doing()
{
    ll l=-4e18-2e10,r=1e9+1;
    ll dd=0;
    while(l<r)
    {
	ll mid=l+r+1>>1;
	if(check(mid)>=k)l=mid;
	else r=mid-1;
    }
    check(l);
    REP(i,1,n)dd+=b[i]; dd-=k;
    REP(i,1,n)if(a[i]-(ll)3*((b[i]-1)*(b[i]-1)+(b[i]-1))-1==l && dd>0)
	b[i]--,dd--;
    REP(i,1,n)printf("%lld ",b[i]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("639d.in","r",stdin);
    freopen("639d.out","w",stdout);
#endif
    init();
    doing();
    return 0;
}