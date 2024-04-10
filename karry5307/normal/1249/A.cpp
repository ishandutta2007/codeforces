#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=1e5+51;
ll test,cnt;
ll num[MAXN];
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
	memset(num,0,sizeof(num));
	cnt=read();
	for(register int i=0;i<cnt;i++)
	{
		num[i]=read();
	} 
	sort(num,num+cnt);
	for(register int i=1;i<cnt;i++)
	{
		if(num[i]-num[i-1]==1)
		{
			puts("2");
			return;
		} 
	}
	puts("1");
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}