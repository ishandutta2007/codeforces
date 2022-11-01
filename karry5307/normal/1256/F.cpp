#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll test,cnt,res,rres,flag;
ll occ[26];
char s[MAXN],t[MAXN];
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
	cnt=read(),res=rres=flag=0;
	scanf("%s%s",s,t);
	for(register int i=0;i<cnt;i++)
	{
		occ[s[i]-97]++,flag|=(occ[s[i]-97]>1);
	}
	for(register int i=0;i<cnt;i++)
	{
		occ[t[i]-97]--;
	}
	for(register int i=0;i<26;i++)
	{
		if(occ[i])
		{
			puts("NO");
			return;
		}
	}
	if(flag)
	{
		puts("YES");
		return;
	}
	memset(occ,0,sizeof(occ));
	for(register int i=0;i<cnt;i++)
	{
		for(register int j=s[i]-96;j<26;j++)
		{
			res+=occ[j];
		}
		occ[s[i]-97]++;
	}
	memset(occ,0,sizeof(occ));
	for(register int i=0;i<cnt;i++)
	{
		for(register int j=t[i]-96;j<26;j++)
		{
			res+=occ[j];
		}
		occ[t[i]-97]++;
	}
	puts((res-rres)&1?"NO":"YES");
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
		memset(occ,0,sizeof(occ));
	}
}