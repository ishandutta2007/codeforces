#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n;
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
		x[i]=read();
	}
	if(n==1)
	{
		return puts(!x[1]?"UP":x[1]==15?"DOWN":"-1"),0;
	}
	if(x[n]==15||!x[n])
	{
		return puts(x[n]?"DOWN":"UP"),0;
	}
	puts(x[n]>x[n-1]?"UP":"DOWN");
}