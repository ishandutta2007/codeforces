#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=1e5+51;
vector<ll>nxt[27];
ll test,cur,res,flg;
string s,t;
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
	cin>>s>>t,flg=res=cur=0;
	for(register int i=0;i<s.length();i++)
	{
		nxt[s[i]-'a'].push_back(i+1);
	}
	for(register int i=0;i<t.length();i++)
	{
		if(nxt[t[i]-'a'].empty())
		{
			puts("-1");
			return;
		}
	}
	for(register int i=0;i<t.length();i++)
	{
		auto it=lower_bound(nxt[t[i]-'a'].begin(),nxt[t[i]-'a'].end(),cur+1);
		if(it==nxt[t[i]-'a'].end())
		{
			res++,it=lower_bound(nxt[t[i]-'a'].begin(),nxt[t[i]-'a'].end(),1);
		}
		cur=*it;
	}
	printf("%d\n",res+1);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
		for(register int i=0;i<27;i++)
		{
			nxt[i].clear();
		}
	}
}