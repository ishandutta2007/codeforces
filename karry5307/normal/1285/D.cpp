#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
struct Node{
	ll res,depth;
	ll ch[2];
	Node()
	{
		ch[0]=ch[1]=res=depth=0;
	}
};
Node nd[MAXN*20];
ll cnt,cur,bit,curb,res,maxb,sz;
ll x[MAXN];
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
inline void insert(ll val,ll depth,ll node)
{
	nd[node].depth=depth;
	if(!depth)
	{
		return;
	}
	if(!nd[node].ch[(val>>depth-1)&1])
	{
		nd[node].ch[(val>>depth-1)&1]=++sz;
	}
	insert(val,depth-1,nd[node].ch[(val>>depth-1)&1]); 
}
inline void dfs(ll node)
{
	ll ls=nd[node].ch[0],rs=nd[node].ch[1];
	if(ls)
	{
		dfs(ls);
	}
	if(rs)
	{
		dfs(rs); 
	}
	if(ls&&rs)
	{
		nd[node].res=min(nd[ls].res,nd[rs].res)+(1<<nd[node].depth-1);
	}
	else
	{
		nd[node].res=nd[ls].res+nd[rs].res; 
	}
}
int main()
{
	cnt=read(),sz=1;
	for(register int i=0;i<cnt;i++)
	{
		insert(x[i]=read(),30,1);
	}
	dfs(1),printf("%lld\n",nd[1].res);
}