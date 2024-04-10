#include<bits/stdc++.h>
#include<bits/stdc++.h>
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
#define lwb lower_bound
#define upb upper_bound
using namespace std;
typedef int ll;
const ll MAXN=1;
ll test,odd1,odd2;
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
	read(),cin>>str,odd1=odd2=0;
	for(register int i=0;i<sz(str);i++)
	{
		if(str[i]&1)
		{
			odd1?odd2=str[i]-'0':odd1=str[i]-'0';
		}
	}
	if(odd2==0)
	{
		puts("-1");
	}
	else
	{
		printf("%d%d\n",odd1,odd2);
	}
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}