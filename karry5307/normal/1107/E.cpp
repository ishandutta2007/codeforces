#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=151;
ll n;
ll f[MAXN][MAXN][MAXN],x[MAXN];
char ch[MAXN];
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
		x[i]=read();
	}
	for(register int i=n;i;i--)
	{
		for(register int j=i;j<=n;j++)
		{
			for(register int k=0;k<n;k++)
			{
				f[i][j][k]=f[i][j-1][0]+x[k+1];
				for(register int l=i;l<j;l++)
				{
					if(ch[l]==ch[j])
					{
						f[i][j][k]=max(f[i][j][k],f[l+1][j-1][0]+f[i][l][k+1]);
					}
				}
			}
		}
	}
	printf("%lld\n",f[1][n][0]);
}