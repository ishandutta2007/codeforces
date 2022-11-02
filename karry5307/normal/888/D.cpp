#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll n,kk,binom,res;
ll d[10]={1,0,1,2,9};
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
	n=read(),kk=read(),binom=1;
	for(register int i=0;i<=kk;i++)
	{
		res+=d[i]*binom,binom=binom*(n-i)/(i+1);
	}
	printf("%lld\n",res);
}