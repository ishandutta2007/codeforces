#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,pos,res;
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
	n=read()*2;
	for(register int i=1;i<=n;i++)
	{
		x[i]=read();
	}
	for(register int i=1;i<=n;i+=2)
	{
		for(register int j=i+1;j<=n;j++)
		{
			if(x[j]==x[i])
			{
				pos=j;
				break;
			}
		}
		for(register int j=pos;j>i+1;j--)
		{
			swap(x[j],x[j-1]),res++;
		}
	}
	printf("%d\n",res);
}