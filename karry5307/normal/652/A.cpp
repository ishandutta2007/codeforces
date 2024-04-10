#include<bits/stdc++.h>
using namespace std;
typedef int ll; 
typedef long long int li;
const ll MAXN=2e5+51;
ll c,d,u,v;
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
	c=read(),d=read(),u=read(),v=read();
	if(u<=v&&c+8*u<d)
	{
		return puts("-1"),0;
	}
	if(c+8*u>=d)
	{
		return puts("0"),0;
	}
	c=d-c-8*u,d=(u-v)*12;
	printf("%d\n",c/d+(!!(c%d)));
}