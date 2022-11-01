#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=1;
ll x,y;
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
	x=read(),y=read();
	if(x==y)
	{
		return printf("%d1 %d2\n",x,x),0;
	}
	if(x+1==y)
	{
		return printf("%d9 %d0\n",x,x+1),0;
	}
	if(x==9&&y==1)
	{
		return printf("9 10\n"),0;
	}
	puts("-1");
}