#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,m;
ll f[MAXN][5];
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
	n=read(),m=read();
	for(register int i=1;i<=min(m,2*n);i++)
	{
		f[(i+1)>>1][((i*i-1)&3)+1]=i;
	}
	for(register int i=1,j=2*n+1;j<=m;i++,j++)
	{
		f[(i+1)>>1][(((i-1)*(i-1))&3)+2]=j;
	}
	for(register int i=1;i<=n;i++)
	{
		f[i][2]?printf("%d ",f[i][2]):1,f[i][1]?printf("%d ",f[i][1]):1;
		f[i][3]?printf("%d ",f[i][3]):1,f[i][4]?printf("%d ",f[i][4]):1; 
	}
}