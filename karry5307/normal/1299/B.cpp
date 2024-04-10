#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=1e5+51;
ll cnt,x0,y0;
vector<ll>x(MAXN),y(MAXN);
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
	if(cnt&1)
	{
		return puts("No"),0;
	}
	for(register int i=0;i<cnt;i++)
	{
		x[i]=read(),y[i]=read();
	}
	x0=x[0]+x[cnt>>1],y0=y[0]+y[cnt>>1];
	for(register int i=0;i<(cnt>>1);i++)
	{
		if(x[i]+x[(cnt>>1)+i]!=x0)
		{
			return puts("No"),0;		
		}	
	}
	for(register int i=0;i<(cnt>>1);i++)
	{
		if(y[i]+y[(cnt>>1)+i]!=y0)
		{
			return puts("No"),0;
		}
	}
	puts("Yes");
}