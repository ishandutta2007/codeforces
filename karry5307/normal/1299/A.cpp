#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=1e5+51;
ll cnt,res,pos,rest,x;
ll num[MAXN],prefix[MAXN],suffix[MAXN];
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
	for(register int i=1;i<=cnt;i++)
	{
		num[i]=read();
		prefix[i]=prefix[i-1]|num[i];
	}
	for(register int i=cnt;i;i--)
	{
		suffix[i]=suffix[i+1]|num[i];
	}
	pos=1; 
	for(register int i=1;i<=cnt;i++)
	{
		rest=prefix[i-1]|suffix[i+1];
		x=(num[i]|rest)-rest;
		if(x>res)
		{
			res=x,pos=i;
		}
	}
	printf("%d ",num[pos]);
	for(register int i=1;i<=cnt;i++)
	{
		if(i^pos)
		{
			printf("%d ",num[i]);
		}
	}
}