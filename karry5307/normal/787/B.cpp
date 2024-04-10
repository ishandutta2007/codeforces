#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
unordered_map<ll,ll>mp;
ll n,m,c,x,flg;
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
	n=read(),m=read();
	for(register int i=1;i<=m;i++)
	{
		c=read(),flg=0,mp.clear();
		for(register int j=1;j<=c;j++)
		{
			x=read(),flg|=mp[-x],mp[x]=1;
		}
		if(!flg)
		{
			return puts("YES"),0;
		}
	}
	puts("NO");
}