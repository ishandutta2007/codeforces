#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll test,cnt,r,p,s,win;
string str;
ll res[MAXN];
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
	cnt=read(),r=read(),p=read(),s=read();
	cin>>str;
	memset(res,0,sizeof(res)),win=0;
	for(register int i=0;i<cnt;i++)
	{
		if(str[i]=='R')
		{
			if(p)
			{
				res[i]='P',win++,p--;
			}
		}
		if(str[i]=='P')
		{
			if(s)
			{
				res[i]='S',win++,s--;
			}
		}
		if(str[i]=='S')
		{
			if(r)
			{
				res[i]='R',win++,r--;
			}
		}
	}
	if(win<(cnt+1)>>1)
	{
		puts("NO");
		return;
	}
	puts("YES");
	for(register int i=0;i<cnt;i++)
	{
		if(res[i])
		{
			putchar(res[i]);
			continue;
		}
	    if(r)
		{
			putchar('R'),r--;
			continue;
		}
		if(s)
		{
			putchar('S'),s--;
			continue;
		}
		if(p)
		{
			putchar('P'),p--;
			continue;
		}
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