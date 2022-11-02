#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll num[25],tmp[25];
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
inline void cyclicShift(ll *x)
{
	ll p=num[x[0]],q=num[x[1]];
	for(register int i=0;i<6;i++)
	{
		num[x[i]]=num[x[i+2]];
	}
	num[x[6]]=p,num[x[7]]=q;
}
inline void rotate(ll type,ll x)
{
	static ll r[8]={2,4,6,8,10,12,23,21};
	static ll u[8]={13,14,5,6,17,18,21,22};
	static ll f[8]={3,4,17,19,10,9,16,14};
	for(register int i=0;i<x;i++)
	{
		cyclicShift(type?(type==1?u:f):r);
	}
}
inline bool check()
{
	for(register int i=1;i<24;i+=4)
	{
		for(register int j=i;j<=i+3;j++)
		{
			for(register int k=j+1;k<=i+3;k++)
			{
				if(num[j]!=num[k])
				{
					return 0;
				}
			}
		}
	}
	return 1;
}
int main()
{
	for(register int i=1;i<=24;i++)
	{
		tmp[i]=num[i]=read();
	}
	for(register int i=0;i<3;i++)
	{
		for(register int j=1;j<=24;j++)
		{
			num[j]=tmp[j];
		}
		rotate(i,1);
		if(check())
		{
			return puts("YES"),0;
		}
		for(register int j=1;j<=24;j++)
		{
			num[j]=tmp[j];
		}
		rotate(i,3);
		if(check())
		{
			return puts("YES"),0;
		}
	}
	puts("NO");
}