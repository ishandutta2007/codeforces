#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,xorv,r;
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
	n=read();
	for(register int i=1;i<=n;i++)
	{
		x[i]=read(),xorv^=x[i];
	}	
	if(n%2==0&&xorv)
	{
		return puts("No"),0;
	}
	puts("Yes"),r=n-((n&1^1)),printf("%d\n",r-1);
	for(register int i=1;i<=r-1;i+=2)
	{
		printf("%d %d %d\n",i,i+1,r);
	}
	for(register int i=1;i<=r-1;i+=2)
	{
		printf("%d %d %d\n",i,i+1,r);
	}
}