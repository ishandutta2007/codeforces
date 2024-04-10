#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=1e5+51;
ll cnt,l,t,x,p0,p1;
li res,ress;
ll num[MAXN],maxn[MAXN],minn[MAXN],p[MAXN],q[MAXN];
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
	cnt=read(),memset(minn,0x3f,sizeof(minn));
	for(register int i=1;i<=cnt;i++)
	{
		l=read(),maxn[i]=-1;
		for(register int j=0;j<l;j++)
		{
			x=read();
			if(x>minn[i])
			{
				p[i]=1;
			}
			maxn[i]=max(maxn[i],x),minn[i]=min(minn[i],x);
		}
		if(p[i])
		{
			q[++t]=maxn[i];
		}
	}
	sort(maxn+1,maxn+cnt+1),sort(q+1,q+t+1);
	for(register int i=1;i<=cnt;i++)
	{
		if(p[i])
		{
			res+=cnt;
			continue;
		}
		p0=cnt-(upper_bound(maxn+1,maxn+cnt+1,minn[i])-maxn)+1;
		p1=t-(upper_bound(q+1,q+t+1,minn[i])-q)+1;
		res+=p0+t-p1;
	}
	printf("%lld\n",res);
}