#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51; 
ll n,m,w,l,r,mid,res;
ll x[MAXN],diff[MAXN];
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
inline ll check(ll mid)
{
	ll c=0,cur=m,p;
	for(register int i=1;i<=n;i++)
	{
		diff[i]=x[i]-x[i-1];
	}
	for(register int i=1;i<=n-w+1;i++)
	{
		c+=diff[i];
		if(cur>0&&c<mid)
		{
			p=min(cur,mid-c),diff[i]+=p,diff[i+w]-=p,cur-=p,c+=p;
		}
	}
	diff[n-w+1]+=cur,diff[n+1]-=cur,c=0;
	for(register int i=1;i<=n;i++)
	{
		c+=diff[i];
		if(c<mid)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	n=read(),m=read(),w=read(),l=0x3f3f3f3f,r=0x3f3f3f3f;
	for(register int i=1;i<=n;i++)
	{
		x[i]=read(),l=min(l,x[i]);
	}
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		check(mid)?l=mid+1,res=mid:r=mid-1;
	}
	printf("%d\n",res);
}