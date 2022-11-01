#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=128;
ll test,flag;
string s,t;
ll occ[MAXN],occr[MAXN];
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
	cin>>s>>t,memset(occ,0,sizeof(occ));
	for(register int i=0;i<s.length();i++)
	{
		occ[s[i]]++;
	}
	if(t.length()<s.length())
	{
		puts("NO");
		return;
	}
	for(register int i=0;i<=t.length()-s.length();i++)
	{
		memset(occr,0,sizeof(occr));
		for(register int j=i,k=0;k<s.length();k++,j++)
		{
			occr[t[j]]++;
		}
		flag=1;
		for(register int j=0;j<128;j++)
		{
			if(occ[j]!=occr[j])
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			puts("YES");
			return;
		}
	}
	puts("NO");
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	} 
}