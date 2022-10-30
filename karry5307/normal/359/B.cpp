#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,kk,u,v;
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
	n=read(),kk=read();
	for(register int i=1;i<=n;i++)
	{
		u=i*2-1,v=i*2,kk?swap(u,v),kk--:1,printf("%d %d ",u,v);
	}
}