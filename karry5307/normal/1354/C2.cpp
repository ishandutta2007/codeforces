#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
const double PI=acos(-1.0);
ll test,n;
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
	n=read()<<1;
	printf("%.12lf\n",1/sin(PI/n)*cos(PI/(n*2)));
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}