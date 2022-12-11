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

vector<int>a,b,c;

inline void init()
{
    int na=read(),nb=read(),nc=read();
    a.clear(); b.clear();c.clear();
    REP(i,1,na)a.push_back(read());
    REP(i,1,nb)b.push_back(read());
    REP(i,1,nc)c.push_back(read());
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
}

inline ll sqr(ll x){ return x*x;}

inline ll calc(ll x,ll y,ll z)
{
    return sqr(x-y)+sqr(z-x)+sqr(z-y);
}

inline ll solve(vector<int>a,vector<int>b,vector<int>c)
{
    ll ans=1ll<<62;
    int j=-1,k=0;
    REP(i,0,SZ(a)-1)
    {
	while(j<SZ(b)-1 && b[j+1]<=a[i] )j++;
	while(k<SZ(c)-1 && c[k]<a[i] )k++;
	if(~j && ~k)chkmin(ans,calc(a[i],b[j],c[k]));
    }
    return ans;
}

inline void doing()
{
    ll ans=1ll<<62;
    chkmin(ans,solve(a,b,c));
    chkmin(ans,solve(a,c,b));
    chkmin(ans,solve(b,a,c));
    chkmin(ans,solve(b,c,a));
    chkmin(ans,solve(c,a,b));
    chkmin(ans,solve(c,b,a));
    printf("%lld\n",ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
#endif
    int t=read();
    while(t--)
    {
	init();
	doing();
    }
    return 0;
}