#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=1e6+51;
ll n,pos;
li l,r;
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
	scanf("%s",ch+1),n=strlen(ch+1);
	for(register int i=1;i<=n;i++)
	{
		if(ch[i]=='^')
		{
			pos=i;
			break;
		}
	}
	for(register int i=pos-1,j=1;i;i--,j++)
	{
		ch[i]!='='?l+=(li)j*(ch[i]-'0'):1;
	}
	for(register int i=pos+1,j=1;i<=n;i++,j++)
	{
		ch[i]!='='?r+=(li)j*(ch[i]-'0'):1;
	}
	puts(l==r?"balance":l<r?"right":"left");
}