#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51; 
vector<ll>v;
ll test,n,x;
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
	n=read(),x=1,v.clear();
	while(n)
	{
		if(n%10)
		{
			v.push_back(n%10*x);
		}
		n/=10,x*=10;
	}
	printf("%d\n",v.size());
	for(register int i:v)
	{
		printf("%d ",i);
	}
	puts("");
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}