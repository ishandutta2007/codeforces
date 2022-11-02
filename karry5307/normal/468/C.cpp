#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
li mod,x=1e18;
inline li read()
{
    register li num=0,neg=1;
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
	mod=read(),x=x%mod*9%mod*9%mod;
	printf("%lld %lld",mod-x,(li)1e18+mod-x-1);
}