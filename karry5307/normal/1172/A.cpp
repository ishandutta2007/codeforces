#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=3e5+51,inf=0x3f3f3f3f;
ll cnt,res,ress=inf;
ll hand[MAXN],pile[MAXN],pos[MAXN];
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
		hand[i]=read();
	}
	for(register int i=1;i<=cnt;i++)
	{
		pos[(pile[i]=read())]=i;
	}
	for(register int i=1;i<=cnt;i++)
	{
		res=max(res,pos[i]-i+cnt+1);
	}
	for(register int i=1;i<=cnt;i++)
	{
		if(pos[i]>=i)
		{
			ress=pos[i]-i;
			break;
		}
	}
	for(register int i=1;i<=cnt;i++)
	{
		if((pos[i]<i&&ress<pos[i]-i+cnt+1)||(pos[i]>=i&&ress!=pos[i]-i))
		{
			ress=inf;
			break;
		}
	}
	printf("%d\n",ress==inf?res:ress);
}