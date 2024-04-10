#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll test,cnt,res,p;
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
	cnt=read(),res=p=0;
	for(register int i=0;i<cnt;i++)
	{
		cin>>str;
		res+=str.length()&1;
		for(register int i=0;i<str.length();i++)
		{
			p^=(str[i]-'0');
		}
	}
	printf("%d\n",res>=(p&1)?cnt:cnt-1);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}