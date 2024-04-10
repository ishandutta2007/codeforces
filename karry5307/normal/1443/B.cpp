#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll test,n,x,y,c;
ll prefix[MAXN],f[MAXN];
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
inline void solve()
{
	x=read(),y=read(),scanf("%s",ch+1),n=strlen(ch+1),c=0;
	for(register int i=1;i<=n;i++)
	{
		prefix[i]=prefix[i-1]+(ch[i]=='0');
		f[i]=ch[i]-'0'?c+prefix[i]*y+x:f[i-1],c=min(c,f[i]-prefix[i]*y);
	}
	printf("%d\n",f[n]);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}