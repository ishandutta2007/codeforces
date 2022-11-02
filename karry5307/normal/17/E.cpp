#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=4e6+51,MOD=51123987,INV2=25561994;
ll n,mxr,mid,c,res,lx,rx;
ll rad[MAXN],f[MAXN],g[MAXN];
char s[MAXN],ch[MAXN];
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
	n=read(),scanf("%s",s+1),ch[0]='~',ch[n*2+1]='|';
	for(register int i=1;i<=n;i++)
	{
		ch[i*2-1]='|',ch[i*2]=s[i];
	}
	for(register int i=1;i<=2*n+1;i++)
	{
		rad[i]=i<mxr?min(rad[(mid<<1)-i],rad[mid]+mid-i):1;
		while(ch[i+rad[i]]==ch[i-rad[i]])
		{
			rad[i]++;
		}
		rad[i]+i>mxr?mxr=rad[i]+i,mid=i:1;
	}
	for(register int i=1;i<=2*n+1;i++)
	{
		lx=i-rad[i]+1,rx=i+rad[i]-1,lx+=lx&1,rx-=rx&1;
		if(lx<=rx)
		{
			lx>>=1,rx>>=1,f[lx]++,f[(i>>1)+1]--,g[(i+1)>>1]++,g[rx+1]--;
			c=(c+(i>>1)-lx+1)%MOD;
		}
	}
	for(register int i=1;i<=n;i++)
	{
		f[i]+=f[i-1],g[i]+=g[i-1];
	}
	for(register int i=1;i<=n;i++)
	{
		g[i]=(g[i]+g[i-1])%MOD,res=(res+(li)f[i]*g[i-1]%MOD)%MOD;
	}
	printf("%d\n",((li)c*(c-1)%MOD*INV2%MOD-res+MOD)%MOD);
}