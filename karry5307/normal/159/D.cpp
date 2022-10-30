#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,lx,rx;
li res;
string s;
ll h[MAXN],f[MAXN],g[MAXN];
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
	cin>>s,n=s.length(),ch[0]='@',ch[n*2+1]='|';
	for(register int i=0;i<n;i++)
	{
		ch[i*2+1]='|',ch[i*2+2]=s[i];
	}
	for(register int i=1;i<=n*2+1;i++)
	{
		lx=rx=i,ch[i]!='|'?f[i>>1]++,g[i>>1]++:1;
		while(ch[lx-1]==ch[rx+1])
		{
			lx--,rx++,!(lx&1)?f[lx>>1]++,g[rx>>1]++:1;
		}
	}
	for(register int i=1;i<=n;i++)
	{
		g[i]+=g[i-1];
	}
	for(register int i=1;i<=n;i++)
	{
		res+=g[i-1]*f[i];
	}
	printf("%lld\n",res);
}