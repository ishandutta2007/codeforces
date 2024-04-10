#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51,MOD=1e9+7,INV3=333333336;
ll n,m,pw=1;
char ch[MAXN];
ll f[MAXN][3];
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
	n=read(),scanf("%s",ch+1);
	for(register int i=1;i<=n;i++)
	{
		ch[i]=='?'?m++,pw=(li)pw*3%MOD:1;
	}
	for(register int i=1;i<=n;i++)
	{
		f[i][1]=f[i-1][1],f[i][2]=f[i-1][2],f[i][3]=f[i-1][3];
		if(ch[i]=='a')
		{
			f[i][1]=(f[i][1]+pw)%MOD;
		}
		if(ch[i]=='b')
		{
			f[i][2]=(f[i][2]+f[i-1][1])%MOD;
		}
		if(ch[i]=='c')
		{
			f[i][3]=(f[i][3]+f[i-1][2])%MOD;
		}
		if(ch[i]=='?')
		{
			f[i][1]=(f[i][1]+(li)pw*INV3%MOD)%MOD;
			f[i][2]=(f[i][2]+(li)f[i-1][1]*INV3)%MOD;
			f[i][3]=(f[i][3]+(li)f[i-1][2]*INV3)%MOD;
		}
	}
	printf("%d\n",f[n][3]);
}