#include<bits/stdc++.h>
using namespace std;
typedef int ll; 
typedef long long int li;
const ll MAXN=2e5+51;
ll r,c,x,y;
char ch[10][10][10];
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
inline ll check(ll x)
{
	for(register int i=1;i<=3;i++)
	{
		for(register int j=1;j<=3;j++)
		{
			if(ch[x][i][j]=='.')
			{
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	for(register int i=1;i<=9;i++)
	{
		r=(i-1)/3*3+1,c=(i-1)%3+1;
		scanf("%s %s %s",ch[r][c]+1,ch[r+1][c]+1,ch[r+2][c]+1);
	}
	x=read(),y=read(),r=(x-1)%3+1,c=(y-1)%3+1,r=(r-1)*3+c;
	if(check(r))
	{
		for(register int i=1;i<=3;i++)
		{
			for(register int j=1;j<=3;j++)
			{
				ch[r][i][j]=='.'?ch[r][i][j]='!':1;
			}
		}
	}
	else
	{
		for(register int i=1;i<=9;i++)
		{
			for(register int j=1;j<=3;j++)
			{
				for(register int k=1;k<=3;k++)
				{
					ch[i][j][k]=='.'?ch[i][j][k]='!':1;
				}
			}
		}
	}
	for(register int i=1;i<=9;i++)
	{
		r=(i-1)/3*3+1,c=(i-1)%3+1;
		printf("%s %s %s\n",ch[r][c]+1,ch[r+1][c]+1,ch[r+2][c]+1);
		i==3||i==6?puts(""):1;
	}
}