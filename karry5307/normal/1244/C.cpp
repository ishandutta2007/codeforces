#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll cnt,p,win,draw,x,y,gcds,pp;
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
	cnt=read(),p=read(),win=read(),draw=read();
	while(y<win&&(p-1ll*draw*y)%win)
	{
		y++;
	}
	if(y==win)
	{
		return puts("-1"),0;
	}
	x=(p-1ll*draw*y)/win;
	if(x<0||x+y>cnt)
	{
		return puts("-1"),0;
	}
	printf("%lld %lld %lld\n",x,y,cnt-x-y);
}