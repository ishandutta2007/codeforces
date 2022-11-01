#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll cnt,p,q;
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
	cnt=read();
	for(register int i=0;i<cnt;i++)
	{
		x[i]=read();
	}
	sort(x,x+cnt);
	for(register int i=0;i<cnt/2;i++)
	{
		p+=x[i];
	}
	for(register int i=cnt/2;i<cnt;i++)
	{
		q+=x[i];
	}
	printf("%lld\n",p*p+q*q);
}