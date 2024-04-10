#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
const ll MAXN=2e5+51;
ll l1,r1,l2,r2,kk,l,r;
inline ll read()
{
    register ll num=0;
    register char ch=getchar();
    while(!isdigit(ch))
    {
        ch=getchar();
    }
    while(isdigit(ch))
    {
        num=(num<<3)+(num<<1)+(ch-'0');
        ch=getchar();
    }
    return num;
}
int main()
{
	l1=read(),r1=read(),l2=read(),r2=read(),kk=read();
	if(r1<l2||l1>r2)
	{
		return puts("0"),0;
	}
	l=max(l1,l2),r=min(r1,r2);
	printf("%llu\n",r-l+1-(l<=kk&&kk<=r));
}