#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=3e5+51;
struct BIT{
	ll sz;
	ll num[MAXN];
	inline void add(ll pos,ll val)
	{
		for(;pos<=sz;pos+=pos&-pos)
		{
			num[pos]+=val;
		}
	}
	inline ll query(ll pos)
	{
		ll res=0;
		for(;pos;pos-=pos&-pos)
		{
			res+=num[pos];
		}
		return res;
	}
};
BIT bit;
ll cnt,x=-1,y=-1,res;
ll nxt[MAXN],prv[MAXN];
char ch[MAXN];
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
	bit.sz=cnt=read(),scanf("%s",ch+1);
	for(register int i=1;i<=cnt;i++)
	{
		if(ch[i]=='A')
		{
			nxt[x]=(x==-1?0:i),x=i;
		}
		if(ch[i]=='B')
		{
			nxt[y]=(y==-1?0:i),y=i;
		}
	}
	for(register int i=1;i<=cnt;i++)
	{
		if(nxt[i])
		{
			prv[nxt[i]]=i;
		}
	}
	for(register int i=1;i<=cnt;i++)
	{
		if(prv[i])
		{
			bit.add(prv[i],1);
		}
		res+=bit.query(prv[i]);
	}
	printf("%lld\n",res);
}