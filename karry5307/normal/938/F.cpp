#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
char str[MAXN];
char ch;
ll n,s,kk;
bool dp[MAXN];
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
int main()
{
	scanf("%s",str+1),n=strlen(str+1),s=log2(n);
	memset(dp,1,sizeof(dp)),kk=n-(1<<s)+1;
	for(register int i=1;i<=kk;i++)
	{
		ch='z';
		for(register int j=0;j<(1<<s);j++)
		{
			if(dp[j])
			{
				for(register int k=0;k<s;k++)
				{
					dp[j|(1<<k)]=1;
				}
			}
		}
		for(register int j=0;j<(1<<s);j++)
		{
			if(dp[j])
			{
				ch=min(ch,str[i+j]);
			}
		}
		for(register int j=0;j<(1<<s);j++)
		{
			dp[j]&=(str[i+j]==ch);
		}
		putchar(ch);
	}
}