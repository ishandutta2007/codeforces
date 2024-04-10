#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=1e6+51;
ll n,kk,l,r,resl,resr,cur;
ll barrel[MAXN],x[MAXN];
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
	n=read(),kk=read(),l=r=cur=1;
	for(register int i=1;i<=n;i++)
	{
		x[i]=read();
	}
	barrel[x[1]]=1;
	for(register int i=1;i<=n;i++)
	{
		while(cur<=kk&&r<=n)
		{
			!barrel[x[++r]]++?cur++:1;
		}
		r-l>resr-resl?resr=r,resl=l:1,!--barrel[x[l++]]?cur--:1;
	}
	printf("%d %d\n",resl,resr-1);
}