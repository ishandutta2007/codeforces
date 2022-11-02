#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,qcnt,op,c;
ll r[2],x[MAXN];
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
	n=read(),qcnt=read();
	for(register int i=1;i<=n;i++)
	{
		r[x[i]=read()]++;
	}
	for(register int i=1;i<=qcnt;i++)
	{
		op=read(),c=read();
		if(op==1)
		{
			r[x[c]]--,r[x[c]^=1]++;
		}
		if(op==2)
		{
			printf("%d\n",c<=r[1]);
		}
	}
}