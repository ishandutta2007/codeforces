#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=1e5+51;
ll cnt,st,ed,res,minn,cur,dis;
ll x[MAXN],p[MAXN],q[MAXN],r[MAXN],s[MAXN],nxt[MAXN];
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
inline ll dist(ll st,ll ed)
{
	if(ed<st)
	{
		return llabs(x[st]-x[ed])+r[st]+q[ed];
	}
	return llabs(x[st]-x[ed])+s[st]+p[ed];
}
int main()
{
	cnt=read(),st=read(),ed=read();
	for(register int i=1;i<=cnt;i++)
	{
		x[i]=read();
	}
	for(register int i=1;i<=cnt;i++)
	{
		p[i]=read();
	}
	for(register int i=1;i<=cnt;i++)
	{
		q[i]=read();
	}
	for(register int i=1;i<=cnt;i++)
	{
		r[i]=read();
	}
	for(register int i=1;i<=cnt;i++)
	{
		s[i]=read();
	}
	res=dist(st,ed),nxt[st]=ed;
	for(register int i=1;i<=cnt;i++)
	{
		if(i==st||i==ed)
		{
			continue;
		}
		minn=0x3f3f3f3f3f3f3f3f,cur=0;
		for(register int j=st;j!=ed;j=nxt[j])
		{
			dis=dist(j,i)+dist(i,nxt[j])-dist(j,nxt[j]);
			if(dis<minn)
			{
				cur=j,minn=dis;
			}
		}
		res+=minn,nxt[i]=nxt[cur],nxt[cur]=i;
	}
	printf("%lld",res);
}