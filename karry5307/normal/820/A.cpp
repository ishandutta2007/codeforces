#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll c,v0,v1,x,p,s,res,cc;
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
	c=read(),s=v0=read(),v1=read(),x=read(),p=read(),res=1;
	while(s<c)
	{
		cc=p,(v0+=x)>v1?cc+=v0-v1:1,s+=v0-cc,res++;
	}
	printf("%d\n",res);
}