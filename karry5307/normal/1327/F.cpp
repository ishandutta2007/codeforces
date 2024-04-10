#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=5e5+51,MOD=998244353;
ll n,kk,m,res=1,sum,ptr;
ll l[MAXN],r[MAXN],x[MAXN],pos[MAXN],sel[MAXN],f[MAXN];
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
inline void calc(ll bit)
{
	for(register int i=1;i<=m;i++)
	{
		if(x[i]&(1<<bit))
		{
			sel[l[i]]++,sel[r[i]+1]--;
		}
		else
		{
			pos[r[i]+1]=max(pos[r[i]+1],l[i]);
		}
	}
	f[0]=sum=1,ptr=0;
	for(register int i=2;i<=n+1;i++)
	{
		sel[i]+=sel[i-1],pos[i]=max(pos[i],pos[i-1]);
	}
	for(register int i=1;i<=n+1;i++)
	{
		for(;ptr<pos[i];sum=(sum-f[ptr]+MOD)%MOD,f[ptr++]=0);
		f[i]=sel[i]?0:sum,sum=(sum+f[i])%MOD;
	}
	res=(li)res*f[n+1]%MOD;
	for(register int i=0;i<=n+1;i++)
	{
		sel[i]=pos[i]=f[i]=0;
	}
}
int main()
{
	n=read(),kk=read(),m=read();
	for(register int i=1;i<=m;i++)
	{
		l[i]=read(),r[i]=read(),x[i]=read();
	}
	for(register int i=0;i<kk;i++)
	{
		calc(i);
	}
	printf("%d\n",res);
}