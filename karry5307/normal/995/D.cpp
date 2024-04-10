#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=262151;
ll n,kk,pos,v;
li sum;
ll x[MAXN];
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
	n=read(),kk=read();
	for(register int i=0;i<(1<<n);i++)
	{
		sum+=(x[i]=read());
	}
	printf("%.6lf\n",1.0*sum/(1<<n));
	for(register int i=1;i<=kk;i++)
	{
		pos=read(),v=read(),sum+=v-x[pos],x[pos]=v;
		printf("%.6lf\n",1.0*sum/(1<<n));
	}
}