#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e3+51;
ll n;
char ch[MAXN][MAXN];
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
		scanf("%s",ch[i]+1);
	}
	for(register int i=1;i<=n;i++)
	{
		if(ch[i][i]!=ch[1][1]||ch[i][n-i+1]!=ch[1][1])
		{
			return puts("NO"),0;
		}
	}
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=n;j++)
		{
			if(i!=j&&n-i+1!=j&&ch[i][j]!=ch[1][2])
			{
				return puts("NO"),0;
			}
		}
	}
	puts(ch[1][1]!=ch[1][2]?"YES":"NO");
}