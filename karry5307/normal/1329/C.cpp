#include<bits/stdc++.h>
#define re register
#define ls node<<1
#define rs (node<<1)|1
using namespace std;
typedef long long int ll;
const ll MAXN=4000051;
ll test,g,h,tot,p,res;
ll x[MAXN],d[MAXN],rres[MAXN];
inline ll read()
{
    re ll num=0,neg=1;
    re char ch=getchar();
    while(!isdigit(ch)&&ch!='-')
    {
		ch=getchar();
	}
    if(ch=='-')
	{
    	neg=-1,ch=getchar();
	}
    while(isdigit(ch))
	{
    	num=(num<<3)+(num<<1)+(ch-'0');
		ch=getchar();
	}
    return neg==1?num:-num;
}
inline void del(ll node)
{
	if(!x[ls]&&!x[rs])
	{
		x[node]=0;
		return;
	}
	ll p=x[ls]>x[rs]?ls:rs;
	x[node]=x[p],del(p);
}
inline ll chk(ll node)
{
	if(!x[ls]&&!x[rs])
	{
		return d[node];
	}
	return chk(x[ls]>x[rs]?ls:rs);
}
inline void solve()
{
	g=read(),h=read(),res=0;
	for(register int i=1;i<1<<(g+1);i++)
	{
		x[i]=0;
	} 
	for(register int i=1;i<=(1<<g)-1;i++)
	{
		x[i]=read(),res+=x[i];
	}
	p=1,tot=(1<<g)-(1<<h);
	for(re int i=1;i<=tot;i++)
	{
		while(!p||chk(p)<=h)
		{
			p++;
		}
		res-=x[p],del(p),rres[i]=p;
	}
	printf("%lld\n",res);
	for(register int i=1;i<=tot;i++)
	{
		printf("%lld ",rres[i]);
	}
	puts("");
}
int main()
{
	test=read(),d[1]=1;
	for(re int i=2;i<=(1<<20);i++)
	{
		d[i]=d[i/2]+1;
	}
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}