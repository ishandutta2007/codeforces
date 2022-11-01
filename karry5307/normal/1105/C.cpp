#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51,MOD=1e9+7;
ll n,l,r;
ll f[MAXN][3],c[3];
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
	n=read(),l=read(),r=read(),f[1][0]=c[0]=r/3-(l-1)/3;
	f[1][1]=c[1]=(r+2)/3-(l+1)/3,f[1][2]=c[2]=(r+1)/3-l/3;
	for(register int i=2;i<=n;i++)
	{
		f[i][0]=(f[i-1][0]*c[0]+f[i-1][1]*c[2]+f[i-1][2]*c[1])%MOD;
		f[i][1]=(f[i-1][0]*c[1]+f[i-1][1]*c[0]+f[i-1][2]*c[2])%MOD;
		f[i][2]=(f[i-1][0]*c[2]+f[i-1][1]*c[1]+f[i-1][2]*c[0])%MOD;
	}
	printf("%lld\n",f[n][0]);
}