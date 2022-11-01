#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll test;
string s,t;
ll p[128];
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
inline void solve()
{
	cin>>s>>t;
	memset(p,0,sizeof(p));
	for(register int i=0;i<s.length();i++)
	{
		p[s[i]]=1;
	}
	for(register int i=0;i<t.length();i++)
	{
		if(p[t[i]])
		{
			return (void)(puts("YES"));
		}
	}
	puts("NO");
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}