#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=3e5+51;
ll n,kk,c;
ll f[MAXN];
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
	n=read(),kk=read(),scanf("%s",ch+1),f[n]=c=1;
	for(register int i=n-1;i;i--)
	{
		f[i]=(ch[i]=='#'?0:!!c),c=c+f[i]-(i+kk<=n?f[i+kk]:0);
	}
	puts(f[1]?"YES":"NO");
}