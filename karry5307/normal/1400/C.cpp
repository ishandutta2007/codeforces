#include<bits/stdc++.h>
using namespace std;
typedef int ll; 
typedef long long int li;
const ll MAXN=2e5+51;
ll test,n,x,syk;
char ch[MAXN],r[MAXN];
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
	scanf("%s",ch+1),x=read(),n=strlen(ch+1);
	for(register int i=1;i<=n;i++)
	{
		r[i]='1';
	}
	r[n+1]=0,syk=0;
	for(register int i=1;i<=n;i++)
	{
		if(ch[i]=='0')
		{
			i-x>0?r[i-x]='0':1,i+x<=n?r[i+x]='0':1; 
		}
	}
	for(register int i=1;i<=n;i++)
	{
		if(ch[i]=='1'&&(i-x<=0||r[i-x]=='0')&&(i+x>n||r[i+x]=='0'))
		{
			syk=1;
			break;
		}
	}
	syk?puts("-1"):printf("%s\n",r+1);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}