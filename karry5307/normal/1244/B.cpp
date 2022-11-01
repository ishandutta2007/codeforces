#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=1e5+51;
ll test,cnt,res,kk;
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
	cnt=read(),cin>>str,res=kk=0;
	for(register int i=0;i<str.length();i++)
	{
		kk|=(str[i]-48);
		if(str[i]&1)
		{
			res=max(res,max((i+1)<<1,(cnt-i)<<1));	
		}
	}
	printf("%d\n",kk?res:cnt);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}