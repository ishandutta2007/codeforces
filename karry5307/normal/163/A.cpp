#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=5e3+51,MOD=1e9+7;
ll n,m,res;
ll f[MAXN][MAXN];
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
int main()
{
	scanf("%s%s",s+1,t+1),n=strlen(s+1),m=strlen(t+1);
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=m;j++)
		{
			f[i][j]=(f[i][j-1]+(s[i]==t[j]?f[i-1][j-1]+1:0))%MOD;
		}
	}
	for(register int i=1;i<=n;i++)
	{
		res=(res+f[i][m])%MOD;
	}
	printf("%d\n",res);
}