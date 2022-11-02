// syksykCCC yyds
#include<bits/stdc++.h>
using namespace std;
typedef int ll; 
typedef long long int li;
const ll MAXN=1e6+51,MOD=1e9+7;
ll n,syk;
char ch[MAXN];
ll c[MAXN];
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
inline ll fail()
{
	return puts("0"),exit(0),1;
}
inline ll qpow(ll base,ll exponent)
{
	ll res=1;
	while(exponent)
	{
		if(exponent&1)
		{
			res=(li)res*base%MOD;
		}
		base=(li)base*base%MOD,exponent>>=1;
	}
	return res;
}
int main()
{
	scanf("%s",ch+1),n=strlen(ch+1),c[0]=c[n+1]=1;
	for(register int i=1;i<=n;i++)
	{
		ch[i]!='?'&&ch[i]!='*'?c[i]==-1?fail():c[i]=1:1;
		ch[i]=='*'?c[i]==1?fail():c[i]=-1:1;
		ch[i]=='0'?c[i-1]==-1?fail():c[i-1]=c[i+1]=1:1;
		ch[i]=='2'?c[i-1]==1?fail():c[i-1]=c[i+1]=-1:1;
	}
	for(register int i=1;i<=n;i++)
	{
		ch[i]=='1'&&c[i-1]?c[i-1]==c[i+1]?fail():c[i+1]=-c[i-1]:1;
	}
	for(register int i=n;i;i--)
	{
		ch[i]=='1'&&c[i+1]?c[i-1]==c[i+1]?fail():c[i-1]=-c[i+1]:1;
	}
	for(register int i=1;i<=n;i++)
	{
		ch[i]=='1'&&!c[i-1]&&!c[i+1]?syk--:syk+=!c[i];
	}
	printf("%d\n",qpow(2,syk));
}