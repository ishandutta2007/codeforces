#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n;
ll f[10];
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
		ch[i]^='0';
		ch[i]==2?f[2]++:1,ch[i]==3?f[3]++:1,ch[i]==4?f[3]++,f[2]+=2:1;
		ch[i]==5?f[5]++:1,ch[i]==6?f[5]++,f[3]++:1,ch[i]==7?f[7]++:1;
		ch[i]==8?f[7]++,f[2]+=3:1,ch[i]==9?f[7]++,f[3]+=2,f[2]++:1;
	}
	for(register int i=9;i;i--)
	{
		for(register int j=1;j<=f[i];j++)
		{
			putchar(i+'0');
		}
	}
}