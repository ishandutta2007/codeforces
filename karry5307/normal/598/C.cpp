#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
typedef long double db;
const ll MAXN=2e5+51;
struct Vector{
	ll x,y,id;
	db theta;
	inline bool operator <(const Vector &rhs)const
	{
		return theta<rhs.theta;
	}
};
ll n,x,y,c;
db r=1e18;
Vector v[MAXN];
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
int main()
{
	n=read();
	for(register int i=1;i<=n;i++)
	{
		x=read(),y=read(),v[i]=(Vector){x,y,i,atan2(y,x)};
	}
	sort(v+1,v+n+1),v[n+1]=v[1],v[n+1].theta+=2*acos(-1.0L);
	for(register int i=1;i<=n;i++)
	{
		if(v[i+1].theta-v[i].theta<r)
		{
			r=v[i+1].theta-v[i].theta,c=i;
		}
	}
	printf("%d %d\n",v[c].id,v[c+1].id);
}