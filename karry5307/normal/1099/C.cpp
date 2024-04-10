#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll len,n,kk,u,v,flg;
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
	scanf("%s",ch+1),len=strlen(ch+1),kk=read();
	for(register int i=1;i<=len;i++)
	{
		ch[i]=='*'?u++:ch[i]=='?'?v++:n++;
	}
	if(n-u-v>kk||(n<kk&&!u))
	{
		return puts("Impossible"),0;
	}
	if(n<kk)
	{
		for(register int i=1;i<=len;i++)
		{
			if(ch[i+1]=='*'&&!flg)
			{
				flg=1;
				for(register int j=1;j<=kk-n;j++)
				{
					putchar(ch[i]);
				}
			}
			ch[i]!='?'&&ch[i]!='*'?putchar(ch[i]):1;
		}
		return 0;
	}
	for(register int i=1;i<=len;i++)
	{
		if((ch[i+1]=='*'||ch[i+1]=='?')&&flg<n-kk)
		{
			flg++;
			continue;
		}
		ch[i]!='?'&&ch[i]!='*'?putchar(ch[i]):1;
	}
}