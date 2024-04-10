#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll n,m,x,y,z,syk;
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
	n=read(),m=read(),syk=x=read(),y=read(),x=y-x;
	for(register int i=3;i<=n;i++)
	{
		x=__gcd(x,(z=read())-y),y=z;
	 } 
	 for(register int i=1;i<=m;i++)
	 {
	 	if(x%read()==0)
	 	{
	 		return printf("YES\n%lld %d\n",syk,i),0;
		}
	 }
	 puts("NO");
}