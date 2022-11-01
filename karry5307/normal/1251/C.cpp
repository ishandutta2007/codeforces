#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=3e5+51;
queue<ll>odd,even;
ll test;
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
inline void solve()
{
	cin>>str;
	for(register int i=0;i<str.length();i++)
	{
		str[i]&1?odd.push(str[i]-'0'):even.push(str[i]-'0');
	}
	while(!even.empty()&&!odd.empty())
	{
		if(even.front()<odd.front())
		{
			printf("%d",even.front()),even.pop();
			continue;
		}
		printf("%d",odd.front()),odd.pop();
	}
	while(!even.empty())
	{
		printf("%d",even.front()),even.pop();
	}
	while(!odd.empty())
	{
		printf("%d",odd.front()),odd.pop();
	}
	puts("");
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}