#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=1;
ll x[4];
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
	x[0]=read(),x[1]=read(),x[2]=read(),x[3]=read();
	sort(x,x+4);
	if(x[0]+x[1]+x[2]==x[3])
	{
		return puts("YES"),0;
	}
	if(x[0]+x[2]==x[1]+x[3])
	{
		return puts("YES"),0;
	}
	if(x[0]+x[3]==x[1]+x[2])
	{
		return puts("YES"),0;
	}
	puts("NO");
}