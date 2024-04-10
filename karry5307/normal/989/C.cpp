#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=51;
ll p,q,r,s,px,py;
char ch[MAXN][MAXN];
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
inline void fill(ll lx,ll ly,ll rx,ll ry,char ch)
{
	for(register int i=lx;i<=rx;i++)
	{
		for(register int j=ly;j<=ry;j++)
		{
			::ch[i][j]=ch;
		}
	}
}
int main()
{
	p=read()-1,q=read()-1,r=read()-1,s=read()-1,puts("50 50");
	fill(1,1,25,25,'A'),fill(26,1,50,25,'B');
	fill(1,26,25,50,'C'),fill(26,26,50,50,'D');
	px=2,py=27;
	for(register int i=0;i<p;i++)
	{
		ch[px][py]='A',py+=2,py>50?(py=27,px+=2):1;
	}
	px=27,py=27;
	for(register int i=0;i<q;i++)
	{
		ch[px][py]='B',py+=2,py>50?(py=27,px+=2):1;
	}
	px=27,py=2;
	for(register int i=0;i<r;i++)
	{
		ch[px][py]='C',py+=2,py>25?(py=2,px+=2):1;
	}
	px=2,py=2;
	for(register int i=0;i<s;i++)
	{
		ch[px][py]='D',py+=2,py>25?(py=2,px+=2):1;
	}
	for(register int i=1;i<=50;i++)
	{
		for(register int j=1;j<=50;j++)
		{
			putchar(ch[i][j]);
		}
		puts("");
	}
}