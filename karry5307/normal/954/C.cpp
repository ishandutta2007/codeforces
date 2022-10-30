#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,c;
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
int main()
{
	n=read(),c=1e9;
	for(register int i=1;i<=n;i++)
	{
		x[i]=read();
		if(x[i]==x[i-1])
		{
			return puts("NO"),0;
		}
		if(abs(x[i]-x[i-1])!=1&&i!=1)
		{
			if(c==1e9)
			{
				c=abs(x[i]-x[i-1]);
			}
			if(c!=1e9&&abs(x[i]-x[i-1])!=c)
			{
				return puts("NO"),0;
			}
		}
	}
	for(register int i=1;i<n;i++)
	{
		if((x[i]%c==1&&x[i+1]==x[i]-1)||(x[i]%c==0&&x[i+1]==x[i]+1))
		{
			return puts("NO"),0;
		}
	}
	printf("YES\n1000000000 %d\n",c);
}