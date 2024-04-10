#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll x,y,res;
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
	x=read(),y=read(),x-=y;
	if(!x)
	{
		return puts("infinity"),0;
	}
	if(x<0)
	{
		return puts("0"),0;
	}
	for(register int i=1;i<=sqrt(x);i++)
	{
		x%i==0?res+=(i>y)+(x/i>y)-(i*i==x&&i>y):1;
	}
	printf("%d\n",res);
}