#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,r;
ll f[MAXN],g[3];
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
	scanf("%s",ch+1),n=strlen(ch+1),memset(g,-1,sizeof(g)),g[0]=0;
	for(register int i=1;i<=n;i++)
	{
		r=(r*10+ch[i])%3,f[i]=f[i-1],~g[r]?f[i]=max(f[i],f[g[r]]+1):1,g[r]=i;
	}
	printf("%d\n",f[n]);
}