#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n;
ll x[3],y[3],u[6]={0,1,2,0,1,2},v[6]={0,1,2,2,0,1};
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
inline ll calc()
{
	ll res=0x3f3f3f3f,cur;
	ll p[6]={0,1,2,3,4,5},s[3],t[3];
	do
	{
		for(register int i=0;i<3;i++)
		{
			s[i]=x[i],t[i]=y[i];
		}
		for(register int i=0;i<6;i++)
		{
			cur=min(s[u[p[i]]],t[v[p[i]]]);
			s[u[p[i]]]-=cur,t[v[p[i]]]-=cur;
		}
		res=min(res,min(s[0],t[1])+min(s[1],t[2])+min(s[2],t[0]));	
	}
	while(next_permutation(p,p+6));
	return res;
}
int main()
{
	n=read();
	for(register int i=0;i<3;i++)
	{
		x[i]=read();
	}
	for(register int i=0;i<3;i++)
	{
		y[i]=read();
	}
	printf("%d %d\n",calc(),min(x[0],y[1])+min(x[1],y[2])+min(x[2],y[0]));
}