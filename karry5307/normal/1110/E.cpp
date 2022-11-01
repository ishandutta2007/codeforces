#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
unordered_map<ll,ll>mp;
ll n;
ll x[MAXN],y[MAXN];
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
    n=read();
    for(register int i=1;i<=n;i++)
    {
    	x[i]=read(),mp[x[i]-x[i-1]]++;
	}
	for(register int i=1;i<=n;i++)
	{
		y[i]=read();
		if(!mp[y[i]-y[i-1]]--)
		{
			return puts("No"),0;
		}
	}
	puts(x[1]==y[1]?"Yes":"No");
}