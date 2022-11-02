// syksykCCC yyds
#include<bits/stdc++.h>
using namespace std;
typedef int ll; 
typedef long long int li;
const ll MAXN=2e5+51;
ll n;
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
	n=read(),n==1?puts("-1"):printf("%d %d %d\n",n,n+1,n*(n+1));
}