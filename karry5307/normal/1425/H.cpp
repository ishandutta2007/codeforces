#include<bits/stdc++.h>
using namespace std;
typedef int ll; 
typedef long long int li;
const ll MAXN=2e5+51;
ll test,s,t,u,v;
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
inline void op(ll x)
{
	printf(x?"Ya ":"Tidak ");
}
inline void solve()
{
	s=read(),t=read(),u=read(),v=read();
	(s+t)&1?(v||s?v=0,s=1:1,t||u?t=1,u=0:1):(v||s?v=1,s=0:1,t||u?t=0,u=1:1);
	op(s),op(t),op(u),op(v),puts("");
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}