#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
typedef long double db;
const ll MAXN=2e5+51;
ll n;
db l,r,mid;
ll x[MAXN],v[MAXN];
inline ll read()
{
    register ll num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-')
    {
        ch=getchar();
    }
    if(ch=='-')
    {
        neg=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        num=(num<<3)+(num<<1)+(ch-'0');
        ch=getchar();
    }
    return num*neg;
}
inline ll check(db mid)
{
	db lmx=-1e18,rmn=1e18;
	for(register int i=1;i<=n;i++)
	{
		lmx=max(lmx,x[i]-mid*v[i]),rmn=min(rmn,x[i]+mid*v[i]);
	}
	return lmx<=rmn;
}
int main()
{
	n=read();
	for(register int i=1;i<=n;i++)
	{
		x[i]=read(),r=max(r,1.0L*x[i]);
	}
	for(register int i=1;i<=n;i++)
	{
		v[i]=read();
	}
	while(r-l>=1e-8)
	{
		mid=(l+r)/2;
		check(mid)?r=mid:l=mid;
	}
	cout<<fixed<<setprecision(12)<<l<<endl;
}