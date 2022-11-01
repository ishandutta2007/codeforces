#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll cost,cost2,x,y,z,t1,t2,t3;
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
	x=read(),y=read(),z=read(),t1=read(),t2=read(),t3=read();
	cost=abs(x-y)*t1,cost2=(abs(x-z)+abs(x-y))*t2+3*t3;
	puts(cost2<=cost?"YES":"NO");
}