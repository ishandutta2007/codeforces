#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll u,v,x,y,xx,yy;
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
	read(),u=read(),v=read(),x=read(),y=read(),xx=read(),yy=read();
	if(xx==u||yy==v||abs(u-xx)==abs(v-yy))
	{
		return puts("NO"),0;
	}
	if((x<u&&xx>u)||(x>u&&xx<u)||(y<v&&yy>v)||(y>v&&yy<v))
	{
		return puts("NO"),0;
	}
	puts("YES");
}