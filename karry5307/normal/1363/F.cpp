#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e3+51; 
ll test,n,flg;
ll x1[MAXN][26],x2[MAXN][26],f[MAXN][MAXN];
char ch1[MAXN],ch2[MAXN];
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
	n=read(),scanf("%s%s",ch1+1,ch2+1),flg=0;
	for(register int i=1;i<=n;i++)
	{
		memcpy(x1[i],x1[i-1],sizeof(x1[i])),x1[i][ch1[i]-'a']++;
		memcpy(x2[i],x2[i-1],sizeof(x2[i])),x2[i][ch2[i]-'a']++;
	}
	for(register int i=0;i<26;i++)
	{
		if(x1[n][i]!=x2[n][i])
		{
			return (void)puts("-1");
		}
	}
	for(register int i=1;i<=n;i++)
	{
		if(ch1[i]!=ch2[i])
		{
			flg=1;
			break;
		}
	}
	if(!flg)
	{
		return (void)puts("0");
	}
	memset(f,0x3f,sizeof(f));
	for(register int i=0;i<=n;i++)
	{
		f[0][i]=0;
	}
	for(register int i=1;i<=n;i++)
	{
		for(register int j=i;j<=n;j++)
		{
			f[i][j]=f[i-1][j]+1;
			if(ch1[i]==ch2[j])
			{
				f[i][j]=min(f[i][j],f[i-1][j-1]);
				continue;
			}
			if(x1[i][ch2[j]-'a']<x2[j][ch2[j]-'a'])
			{
				f[i][j]=min(f[i][j-1],f[i][j]);
			}
		}
	}
	printf("%d\n",f[n][n]);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}