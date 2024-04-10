#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51,MOD=998244353;
ll n,kk,l,p;
ll x[MAXN],f[MAXN][101],len[MAXN][101],s[MAXN];
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
	n=read(),kk=read(),l=read(),s[0]=1;
	if(l==1)
	{
		return puts("0"),0;
	}
	for(register int i=1;i<=n;i++)
	{
		x[i]=read();
		for(register int j=1;j<=kk;j++)
		{
			len[i][j]=len[i-1][j]+(x[i]==-1||x[i]==j);
		}
	}
	if(x[1]==-1)
	{
		for(register int i=1;i<=kk;i++)
		{
			f[1][i]=1;
		}
		s[1]=kk;
	}
	else
	{
		f[1][x[1]]=1,s[1]=1;
	}
	for(register int i=2;i<=n;i++)
	{
		for(register int j=1;j<=kk;j++)
		{
			if(x[i]==-1||x[i]==j)
			{
				f[i][j]=s[i-1];
				if(i>=l)
				{
					p=i-l;
					if(len[i][j]-len[p][j]==l)
					{
						f[i][j]=((li)f[i][j]+f[p][j]-s[p]+MOD)%MOD;
					}
				}
			}
			s[i]=(s[i]+f[i][j])%MOD;
		}
	}
	printf("%d\n",s[n]);
}