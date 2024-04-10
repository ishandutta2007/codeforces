#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=2e5+51;
ll cnt,l,r,x;
char op;
ll num[MAXN<<2],ind[MAXN];
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
	l=r=(MAXN<<1),r++;
	for(register int i=0;i<cnt;i++)
	{
		op=getchar();
		while(op<=' ')
		{
			op=getchar();
		}
		x=read(); 
		if(op=='L')
		{
			num[l]=x,ind[x]=l--;
		}
		if(op=='R')
		{
			num[r]=x,ind[x]=r++;
		}
		if(op=='?')
		{
			printf("%d\n",min(ind[x]-l-1,r-ind[x]-1));
		}
	}
}