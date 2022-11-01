#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=2e5+51;
ll test,cnt,kk,d,res,rres;
ll occ[MAXN*5],num[MAXN];
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
	cnt=read(),kk=read(),d=read(),rres=0;
	for(register int i=0;i<cnt;i++)
	{
		num[i]=read();
	}
	for(register int i=0;i<d;i++)
	{
		if(++occ[num[i]]==1)
		{
			rres++;
		}
	}
	res=rres;
	for(register int i=d,j=0;i<cnt;i++,j++)
	{
		if(++occ[num[i]]==1)
		{
			rres++;
		}
		if(--occ[num[j]]==0)
		{
			rres--;
		}
		res=min(res,rres);
	}
	printf("%d\n",res),memset(occ,0,sizeof(occ));
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}