#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<map>
#include<stack>
#include<vector>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
inline int read()
{
    int sum=0,p=1;char ch=getchar();
    while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
    if(ch=='-')p=-1,ch=getchar();
    while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
    return sum*p;
}

inline ll lcm(int a,int b){ return (ll)a*b/__gcd(a,b);}


ll Multi(ll a,ll b,ll MOD)
{
    ll s=0;
    while(b){if(b&1)s=(s+a)%MOD;a=(a+a)%MOD;b>>=1;}
    return s;
}
ll fpow(ll a,ll b,ll MOD)
{
    ll s=1;
    while(b){if(b&1)s=Multi(s,a,MOD);a=Multi(a,a,MOD);b>>=1;}
    return s;
}
bool Miller_Rabin(ll x)
{
    if(x==2)return true;
    for(int tim=10;tim;--tim)
    {
        ll a=rand()%(x-2)+2;
        if(fpow(a,x-1,x)!=1)return false;
        ll p=x-1;
        while(!(p&1))
        {
            p>>=1;ll nw=fpow(a,p,x);
            if(Multi(nw,nw,x)==1&&nw!=1&&nw!=x-1)return false;
        }
    }
    return true;
}
ll Pollard_rho(ll n,int c)
{
    ll i=0,k=2,x=rand()%(n-1)+1,y=x;
    while(233)
    {
        ++i;x=(Multi(x,x,n)+c)%n;
        ll d=__gcd((y-x+n)%n,n);
        if(d!=1&&d!=n)return d;
        if(x==y)return n;
        if(i==k)y=x,k<<=1;
    }
}
vector<ll> fac;
void Fact(ll n,int c)
{
    if(n==1)return;
    if(Miller_Rabin(n)){fac.push_back(n);return;}
    ll p=n;while(p>=n)p=Pollard_rho(n,c--);
    Fact(p,c);Fact(n/p,c);
}



int main()
{
	int n=read();ll ans=0;
	
	REP(i,1,n)
	{
		ll a=read(),b=read();
		a=lcm(a,b);
		ans=__gcd(ans,a);
	}
	
	if(ans>1)
	{
		fac.clear();
		Fact(ans,233);
		
		printf("%lld\n",fac[0]);
	}else puts("-1");
	return 0;
}