#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51; 
ll test,n,x;
vector<ll>odd,even;
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
	n=read(),odd.clear(),even.clear();
	for(register int i=1;i<=n;i++)
	{
		x=read(),x&1?odd.push_back(x):even.push_back(x);
	}
	if((odd.size()&1)!=(even.size()&1))
	{
		return (void)puts("No");
	}
	if(!(odd.size()&1))
	{
		return (void)puts("Yes");
	}
	for(register int i:odd)
	{
		for(register int j:even)
		{
			if(i-j==1||i-j==-1)
			{
				return (void)puts("Yes");
			}
		}
	}
	puts("No");
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}