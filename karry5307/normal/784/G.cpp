#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll len,res,cur,sgn;
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
inline void calc(ll x)
{
	if(x<=9)
	{
		for(register int i=1;i<=48+x;i++)
		{
			putchar('+');
		}
		return (void)(putchar('.'),putchar('>'));
	}
	calc(x/10);
	for(register int i=1;i<=48+x%10;i++)
	{
		putchar('+');
	}
	putchar('.'),putchar('>');
}
int main()
{
	scanf("%s",ch+1),len=strlen(ch+1),sgn=1;
	for(register int i=1;i<=len;i++)
	{
		ch[i]=='+'?res+=cur*sgn,sgn=1,cur=0:1;
		ch[i]=='-'?res+=cur*sgn,sgn=-1,cur=0:1;
		isdigit(ch[i])?cur=cur*10+ch[i]-'0':1;
	}
	res+=cur*sgn,calc(res);
}