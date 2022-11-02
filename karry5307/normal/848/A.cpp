#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,c,cur;
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
	n=read(),cur=97;
	if(!n)
	{
		return puts("ab"),0;
	}
	for(register int i=1;i<=1000;i++)
	{
		x[i]=i*(i-1)/2;
	}
	while(n)
	{
		c=upper_bound(x+1,x+1001,n)-x-1;
		for(register int i=1;i<=c;i++)
		{
			putchar(cur);
		}
		n-=x[c],cur++;
	}
}