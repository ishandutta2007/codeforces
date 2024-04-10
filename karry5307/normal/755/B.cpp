#include<bits/stdc++.h>
using namespace std;
typedef int ll; 
typedef long long int li;
const ll MAXN=2e5+51;
unordered_map<string,ll>mp;
ll n,m,r;
string str;
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
	if(n!=m)
	{
		return puts(n>m?"YES":"NO"),0;
	}
	for(register int i=1;i<=n+m;i++)
	{
		cin>>str,r+=!mp[str],mp[str]=1;
	}
	puts(r&1?"YES":"NO");
}