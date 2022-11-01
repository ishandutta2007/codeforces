#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=100;
ll test,flag;
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
	cin>>str,flag=0;
	if(str[0]=='?')
	{
		for(register char j='a';j<='z';j++)
		{
			if(j!=str[1])
			{
				str[0]=j;
				break;
			}
		}
	}
	for(register int i=1;i<str.length()-1;i++)
	{
		if(str[i]=='?')
		{
			for(register char j='a';j<='z';j++)
			{
				if(j!=str[i-1]&&j!=str[i+1])
				{
					str[i]=j;
					break;
				}
			}
		}
		else
		{
			if(str[i]==str[i-1])
			{
				return void(puts("-1"));
			}
		}
	}
	if(str[str.length()-1]==str[str.length()-2])
	{
		puts("-1");
		return;
	}
	if(str[str.length()-1]=='?')
	{
		for(register char j='a';j<='z';j++)
		{
			if(j!=str[str.length()-2])
			{
				str[str.length()-1]=j;
				break;
			}
		}
	}
	cout<<str<<endl;
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}