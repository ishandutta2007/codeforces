#include<bits/stdc++.h>
using namespace std;
typedef int ll; 
typedef long long int li;
const ll MAXN=2e5+51;
ll n,flg,rt;
ll fa[MAXN],c[MAXN],syk[MAXN],ccc[MAXN];
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
	n=read();
	for(register int i=1;i<=n;i++)
	{
		fa[i]=read(),c[i]=read();
		fa[i]!=-1?syk[fa[i]]++,ccc[fa[i]]+=c[i]:rt=i;
	}
	for(register int i=1;i<=n;i++)
	{
		if(c[i]&&(i==rt?1:syk[i]==ccc[i]))
		{
			printf("%d ",i),flg=1;
		}
	}
	!flg?puts("-1"):1;
}