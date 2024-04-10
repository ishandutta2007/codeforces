#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
typedef double db; 
const ll MAXN=2e5+51;
const db pi=acos(-1.0);
ll n,r;
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
	n=read(),r=read(),printf("%.7lf\n",1.0*r*sin(pi/n)/(1-sin(pi/n)));
}