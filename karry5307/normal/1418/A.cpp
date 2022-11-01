#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll test,s,y,kk,syk,res;
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
	s=read(),y=read(),kk=read(),res=0;
	printf("%lld\n",kk+(kk+y*kk-1)/(s-1)+(!!((kk+y*kk-1)%(s-1))));
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}