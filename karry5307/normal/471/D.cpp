#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51,BASE=20050103,MOD=853071677;
ll n,m,hv,hsh,r,res;
ll x[MAXN],y[MAXN],dx[MAXN],dy[MAXN],pw[MAXN];
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
	n=read(),m=read(),pw[0]=1;
	if(m>n||m==1)
	{
		return printf("%d\n",m>n?0:n),0;
	}
	for(register int i=1;i<=n;i++)
	{
		dx[i]=((x[i]=read())-x[i-1]+MOD)%MOD;
	}
	for(register int i=1;i<=m;i++)
	{
		dy[i]=((y[i]=read())-y[i-1]+MOD)%MOD,pw[i]=(li)pw[i-1]*BASE%MOD;
	}
	for(register int i=2;i<=m;i++)
	{
		hv=((li)hv*BASE+dy[i])%MOD,hsh=((li)hsh*BASE+dx[i])%MOD;
	}
	for(register int i=2;i<=n-m+2;i++)
	{
		res+=(hsh==hv),hsh=(hsh-(li)dx[i]*pw[m-2]%MOD+MOD)%MOD;
		hsh=((li)hsh*BASE+dx[i+m-1])%MOD;
	}
	printf("%d\n",res);
}