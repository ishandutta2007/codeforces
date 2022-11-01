#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=1;
ll test,l,r,u,d;
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
	cin>>str,l=r=u=d=0;
	for(register int i=0;i<str.length();i++)
	{
		if(str[i]=='U')
		{
			u++;
		}
		if(str[i]=='D')
		{
			d++;
		}
		if(str[i]=='L')
		{
			l++;
		}
		if(str[i]=='R')
		{
			r++;
		}
	}
	l=min(l,r),u=min(u,d);
	if(u==0)
	{
		l=min(l,1);
	}
	if(l==0)
	{
		u=min(u,1);
	}
	printf("%d\n",(l+u)<<1);
	for(register int i=0;i<l;i++)
	{
		printf("L");
	}
	for(register int i=0;i<u;i++)
	{
		printf("U");
	}
	for(register int i=0;i<l;i++)
	{
		printf("R");
	}
	for(register int i=0;i<u;i++)
	{
		printf("D");
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