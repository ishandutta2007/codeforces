#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=1;
ll test,x[3],t,res;
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
	x[0]=read(),x[1]=read(),x[2]=read(),res=0;
	sort(x,x+3),res=min((x[0]+x[1]+x[2])/2,x[0]+x[1]);
	printf("%lld\n",res);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}