#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=5e3+51;
ll n,res;
ll x[MAXN],f[MAXN][MAXN],mx[8],mx2[100051];
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
		x[i]=read();
	}
	for(register int i=0;i<=n;i++)
	{
		memset(mx,0,sizeof(mx)),memset(mx2,0,sizeof(mx2));
		for(register int j=1;j<=i;j++)
		{
			mx[x[j]%7]=max(mx[x[j]%7],f[i][j]);
			mx2[x[j]]=max(mx2[x[j]],f[i][j]);
		}
		for(register int j=i+1;j<=n;j++)
		{
			f[i][j]=max(f[i][j],max(f[i][0]+1,mx[x[j]%7]+1));
			f[i][j]=max(f[i][j],max(mx2[x[j]-1]+1,mx2[x[j]+1]+1));
			mx[x[j]%7]=max(mx[x[j]%7],f[i][j]),res=max(res,f[j][i]=f[i][j]);
			mx2[x[j]]=max(mx2[x[j]],f[i][j]);
		}
	}
	printf("%d\n",res);
}