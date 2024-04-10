#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=1;
ll test,r,b,kk;
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
inline ll gcd(ll x,ll y)
{
	return !y?x:gcd(y,x%y);
}
inline void solve()
{
	r=read(),b=read(),kk=read();
	if(r>b)
	{
		swap(r,b);
	}
	puts((gcd(r,b)+r*(kk-1)<b)?"REBEL":"OBEY");
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}