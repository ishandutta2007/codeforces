#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
typedef unsigned long long int ull;
const ll MAXN=2e5+51;
ll n;
ull res;
ull x[MAXN];
inline ull read()
{
    register ull num=0,neg=1;
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
	n=read();
	for(register int i=1;i<=n;i++)
	{
		x[i]=read();
	}
	if(n<=3)
	{
		for(register int i=1;i<=n;i++)
		{
			res|=x[i];
		}
		return printf("%llu\n",res),0;
	}
	for(register int i=1;i<=n;i++)
	{
		for(register int j=i+1;j<=n;j++)
		{
			for(register int k=j+1;k<=n;k++)
			{
				res=max(res,x[i]|x[j]|x[k]);
			}
		}
	}
	printf("%llu\n",res);
}