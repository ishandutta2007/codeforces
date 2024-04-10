#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n;
char ch[1024][1024];
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
inline void calc(ll l,ll r,ll u,ll d,ll sgn)
{
	if(l==r)
	{
		return (void)(ch[l][u]="+*"[sgn]);
	}
	ll mid=(l+r)>>1,mid2=(u+d)>>1;
	calc(l,mid,u,mid2,sgn),calc(l,mid,mid2+1,d,sgn);
	calc(mid+1,r,u,mid2,sgn),calc(mid+1,r,mid2+1,d,sgn^1);
}
int main()
{
	n=read(),calc(1,1<<n,1,1<<n,0);
	for(register int i=1;i<=(1<<n);i++)
	{
		printf("%s\n",ch[i]+1);
	}
}