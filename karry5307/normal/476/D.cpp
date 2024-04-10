#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,kk;
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
int main()
{
	n=read(),kk=read(),printf("%d\n",(n*6-1)*kk);
	for(register int i=1;i<=n;i++)
	{
		printf("%d %d %d %d\n",(i*6-5)*kk,(i*6-4)*kk,(i*6-3)*kk,(i*6-1)*kk);
	}
}