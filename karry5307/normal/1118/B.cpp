#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,res;
ll f[MAXN][2];
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
	n=read();
	for(register int i=1;i<=n;i++)
	{
		f[i][0]=f[i-1][0],f[i][1]=f[i-1][1],f[i][i&1]+=read();
	}
	for(register int i=1;i<=n;i++)
	{
		res+=(f[n][1]-f[i][1]+f[i-1][0]==f[n][0]-f[i][0]+f[i-1][1]);
	}
	printf("%d\n",res);
}