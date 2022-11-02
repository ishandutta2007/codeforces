#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll r,d,n,x,y,z,res;
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
	r=read(),d=read(),n=read();
	for(register int i=1;i<=n;i++)
	{
		x=read(),y=read(),z=read();
		res+=(r-d<=hypot(x,y)-z&&r>=hypot(x,y)+z);
	}
	printf("%lld\n",res);
}