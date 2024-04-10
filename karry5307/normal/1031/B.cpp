#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,flg;
ll x[MAXN],y[MAXN],t[MAXN];
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
	for(register int i=2;i<=n;i++)
	{
		x[i]=read();
	}
	for(register int i=2;i<=n;i++)
	{
		y[i]=read();
	}
	for(register int i=0;i<=3;i++)
	{
		t[1]=i,flg=1;
		for(register int j=2;j<=n;j++)
		{
			t[j]=x[j]+y[j]-t[j-1];
			flg&=(((t[j]|t[j-1])==x[j])&&((t[j]&t[j-1])==y[j]));
		}
		if(flg)
		{
			puts("YES");
			for(register int j=1;j<=n;j++)
			{
				printf("%d ",t[j]);
			}
			return 0;	
		}
	}
	return puts("NO"),0;
}