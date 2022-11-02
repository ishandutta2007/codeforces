#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
vector<ll>v;
unordered_map<char,ll>mp;
ll n;
string s="AGCT";
char ch[MAXN];
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
	n=read(),scanf("%s",ch+1);
	if(n&3)
	{
		return puts("==="),0;
	}
	for(register int i=1;i<=n;i++)
	{
		if(ch[i]!='?'&&++mp[ch[i]]>n>>2)
		{
			return puts("==="),0;
		}
		ch[i]=='?'?v.push_back(i):(void)1;
	}
	for(register int i=0;i<=3;i++)
	{
		while(mp[s[i]]!=n>>2)
		{
			ch[v.back()]=s[i],mp[s[i]]++,v.pop_back();
		}
	}
	printf("%s",ch+1);
}