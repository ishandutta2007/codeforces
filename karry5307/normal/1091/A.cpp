#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll x,y,z,num;
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
	x=read(),y=read(),z=read();
	num=min(x,min(y-1,z-2));
	printf("%d",num*3+3);
}