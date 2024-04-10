#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=7e3+51;
ll cnt,qcnt,op,x,y,z;
bitset<MAXN>tmp,factor[MAXN],mu[MAXN];
bitset<MAXN>st[(ll)(1e5+51)];
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
inline void sieve(ll limit)
{
	tmp.set();
	for(register int i=2;i*i<=limit;i++)
	{
		for(register int j=1;i*i*j<=limit;j++)
		{
			tmp[i*i*j]=0;
		}
	}
	for(register int i=1;i<=limit;i++)
	{
		for(register int j=1;i*j<=limit;j++)
		{
			factor[i*j][i]=1,mu[i][i*j]=tmp[j];
		}
	}
}
int main()
{
	sieve(7000),cnt=read(),qcnt=read();
	for(register int i=0;i<qcnt;i++)
	{
		op=read();
		if(op==1)
		{
			x=read(),y=read();
			st[x]=factor[y];
		}
		if(op==2)
		{
			x=read(),y=read(),z=read();
			st[x]=st[y]^st[z];
		}
		if(op==3)
		{
			x=read(),y=read(),z=read();
			st[x]=st[y]&st[z];
		}
		if(op==4)
		{
			x=read(),y=read();
			printf("%d",(st[x]&mu[y]).count()&1);
		}
	}
	
}