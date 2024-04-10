#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=1e6+51;
ll kk,qcnt,cur,x;
li c[6],f[MAXN];
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
inline void upd(ll v,li w)
{
	for(register int i=1e6;i>=v;i--)
	{
		f[i]=max(f[i],f[i-v]+w);
	}
}
inline void push(ll v,ll w)
{
	ll cur=min(kk,(ll)1e6/v);
	for(register int i=1;i<cur;i<<=1)
	{
		cur-=i,upd(v*i,(li)w*i);
	}
	upd(v*cur,(li)w*cur);
}
int main()
{
	kk=3*(read()-1);
	for(register int i=0;i<6;i++)
	{
		c[i]=read();
	}
	for(register int i=0;i<=1e6;i++)
	{
		cur=0,x=i;
		while(x)
		{
			x%10%3==0?f[i]+=(li)c[cur]*(x%10/3):1,x/=10,cur++;
		}
	}
	for(register int i=0,j=1;i<6;i++,j*=10)
	{
		push(j*3,c[i]);
	}
	qcnt=read();
	for(register int i=1;i<=qcnt;i++)
	{
		printf("%lld\n",f[read()]);
	}
}