#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll test,cnt,x,xorv,sum;
char sw[64];
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
inline void write(ll x,char ch=' ')
{
    ll tp=0;
    while(x)
    {
        sw[++tp]=x%10+'0',x/=10;
    }
    while(tp)
    {
        putchar(sw[tp--]);
    }
    putchar(ch);
}
inline void solve()
{
	cnt=read(),sum=xorv=0;
	for(register int i=0;i<cnt;i++)
	{
		x=read(),sum+=x,xorv^=x;
	}
	cout<<2<<endl<<xorv<<" "<<xorv+sum<<endl;
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}