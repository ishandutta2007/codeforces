#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,m,l,r;
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
	n=read(),m=read(),l=1,r=n;
	for(register int i=1;i<=m;i++)
	{
		printf("%d ",i&1?l++:r--);
	}
	if(m&1)
	{
		for(register int i=l;i<=r;i++)
		{
			printf("%d ",i);
		}
		return 0;
	}
	for(register int i=r;i>=l;i--)
	{
		printf("%d ",i);
	}
}