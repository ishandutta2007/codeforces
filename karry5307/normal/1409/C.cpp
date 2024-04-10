#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll test,n,x,y,l;
vector<ll>v;
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
	n=read(),x=read(),y=read(),v.clear();
	for(register int i=1;i<=y-x;i++)
	{
		if((y-x)%i==0&&(y-x)/i+1<=n)
		{
			l=i;
			break;
		}
	}
	for(register int i=x;i<=y;i+=l)
	{
		v.push_back(i),n--;
	}
	for(register int i=x-l;i>0&&n;i-=l)
	{
		v.push_back(i),n--;
	}
	for(register int i=y+l;n;i+=l)
	{
		v.push_back(i),n--;
	}
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