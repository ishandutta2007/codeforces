#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=1;
ll test,x,p,kk;
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
	p=read(),x=read(),kk=x%p;
	cout<<(x/p+1)*(x/p+1)*kk+(x/p)*(x/p)*(p-kk)<<endl;
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	} 
}