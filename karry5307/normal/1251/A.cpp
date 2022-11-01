#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll test,tot,cur;
string str;
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
inline void solve()
{
	cin>>str;
	tot=0;
	for(register int i=0;i<str.length();i++)
	{
		if(str[i]==str[i+1])
		{
			i++;
		}
		else
		{
			ch[++tot]=str[i];
		}
	}
	sort(ch+1,ch+tot+1),tot=unique(ch+1,ch+tot+1)-ch;
	for(register int i=1;i<tot;i++)
	{
		printf("%c",ch[i]);
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