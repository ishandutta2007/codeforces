#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
unordered_map<string,unordered_set<ll> >mp;
ll n;
string s[MAXN];
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
inline string calc(ll x)
{
	for(register int i=1;i<=9;i++)
	{
		for(register int j=0;j<=9-i;j++)
		{
			if(mp[s[x].substr(j,i)].size()==1)
			{
				return s[x].substr(j,i);
			}
		}
	}
}
int main()
{
	n=read();
	for(register int i=1;i<=n;i++)
	{
		cin>>s[i];
		for(register int j=1;j<=9;j++)
		{
			for(register int k=0;k<=9-j;k++)
			{ 
				mp[s[i].substr(k,j)].insert(i);
			}
		}
	}
	for(register int i=1;i<=n;i++)
	{
		cout<<calc(i)<<endl;
	}
}