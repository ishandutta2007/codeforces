#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=4e5+51;
ll test,cnt,med,g,s,b,l,tot,p,nxt;
ll num[MAXN],occ[MAXN],prefix[MAXN];
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
inline void solve()
{
	cnt=read(),g=s=b=tot=l=0;
	for(register int i=1;i<=cnt;i++)
	{
		num[i]=read();
		if(i>1&&(num[i]!=num[i-1]))
		{
			occ[++tot]=l,l=1;
		}
		else
		{
			l++;
		}
	}
	occ[++tot]=l;
	for(register int i=1;i<=tot;i++)
	{
		prefix[i]=prefix[i-1]+occ[i];
	}
	if(tot<=3||prefix[3]>cnt/2)
	{
		return (void)(puts("0 0 0"));
	}
	for(register int i=1;i<=cnt;i++)
	{
		if(prefix[i]>cnt/2)
		{
			p=i-1;
			break;
		}
	}
	nxt=p;
	while(nxt>=3&&prefix[p]-prefix[nxt-1]<=occ[1])
	{
		nxt--;
	}
	b=prefix[p]-prefix[nxt-1],s=prefix[nxt-1]-prefix[1],g=prefix[1];
	if(g>=s||g>=b)
	{
		return (void)(puts("0 0 0"));
	}
	printf("%d %d %d\n",g,s,b);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}