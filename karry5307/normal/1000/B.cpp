#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,m,res;
ll x[MAXN],len[MAXN],s[MAXN],t[MAXN];
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
	n=read(),m=read(),x[n+1]=m;
	for(register int i=1;i<=n;i++)
	{
		x[i]=read();
	}
	sort(x,x+n+2);
	for(register int i=1;i<=n+1;i++)
	{
		len[i]=x[i]-x[i-1],res+=(i&1?len[i]:0);
		s[i]=s[i-1]+(i&1?len[i]:0),t[i]=t[i-1]+(i&1?0:len[i]);
	}
	for(register int i=1;i<=n+1;i++)
	{
		if(len[i]!=1)
		{
			res=max(res,s[i-1]+len[i]-1+t[n+1]-t[i]);
		}
	}
	printf("%d\n",res);
}