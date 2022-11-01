#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
struct Vector{
    ll x,y;
    inline bool operator <(const Vector &rhs)const;
};
ll n,tp;
li res;
ll x[MAXN],y[MAXN];
Vector st[MAXN];
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
inline li cross(Vector x,Vector y)
{
    return (li)x.x*y.y-(li)x.y*y.x;
}
inline bool Vector::operator <(const Vector &rhs)const
{
    ll dirx=y<0||(y==0&&x>0),diry=rhs.y<0||(rhs.y==0&&rhs.x>0);
    return dirx!=diry?dirx<diry:cross(*this,rhs)>0;
}
int main()
{
    n=read(),res=(li)n*(n-1)*(n-2)*(n-3)*(n-4)/24;
    for(register int i=1;i<=n;i++)
    {
	x[i]=read(),y[i]=read();
    }
    for(register int i=1;i<=n;i++)
    {
	tp=0;
	for(register int j=1;j<=n;j++)
	{
	    if(i!=j)
	    {
		st[++tp]=(Vector){x[j]-x[i],y[j]-y[i]};
	    }
	}
	sort(st+1,st+tp+1);
	for(register int j=1;j<=tp;j++)
	{
	    st[j+tp]=st[j];
	}
	for(register int j=1,k=1;j<=tp;j++)
	{
	    while(k<j+tp&&cross(st[j],st[k])>=0)
	    {
		k++;
	    }
	    res-=(li)(k-j-1)*(k-j-2)*(k-j-3)/6;
	}
    }
    printf("%lld\n",res);
}