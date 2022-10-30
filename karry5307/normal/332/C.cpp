#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=1e5+51;
struct Tuple{
	ll ang,hair,ord,ordd;
	inline bool operator <(const Tuple &rhs)const
	{
		return this->ang==rhs.ang?this->hair<rhs.hair:this->ang>rhs.ang;
	}
	inline bool operator >(const Tuple &rhs)const
	{
		return this->hair==rhs.hair?this->ang>rhs.ang:this->hair>rhs.hair;
	}
};
Tuple x[MAXN],y[MAXN];
ll cnt,p,q,t;
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
	cnt=read(),p=read(),q=read();
	for(register int i=1;i<=cnt;i++)
	{
		x[i].hair=read(),x[i].ang=read(),x[i].ord=i;
	}
	sort(x+1,x+cnt+1),memcpy(y,x,sizeof(x));
	for(register int i=1;i<=cnt;i++)
	{
		x[i].ordd=i;
	}
	sort(x+1,x+cnt-p+q+1,greater<Tuple>());
	for(register int i=1;i<=q;i++)
	{
		t=max(t,x[i].ordd);
		printf("%d ",x[i].ord);
	}
	sort(y+t+1,y+cnt+1);
	for(register int i=t+1;i<=t+p-q;i++)
	{
		printf("%d ",y[i].ord);
	}
}