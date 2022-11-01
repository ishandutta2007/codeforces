#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=1e5+51;
ll test,x,y;
ll prefix[MAXN];
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
	x=read(),y=read();
	if(x<y)
	{
		swap(x,y);
	}
	x-=y;
	for(register int i=0;i<=50000;i++)
	{
		if(prefix[i]>=x&&(prefix[i]&1)==(x&1))
		{
			printf("%d\n",i);
			return;
		}
	}
}
int main()
{
	for(register int i=1;i<=50000;i++)
	{
		prefix[i]=prefix[i-1]+i;
	}
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}