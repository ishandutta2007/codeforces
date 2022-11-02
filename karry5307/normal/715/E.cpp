#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=351,MOD=998244353;
ll cnt,p,q,r,s,kk;
ll x[MAXN],y[MAXN],vis[MAXN],viss[MAXN],nxt[MAXN],barrel[MAXN];
ll f[MAXN],g[MAXN],h[MAXN],fact[MAXN],res[MAXN];
ll st[MAXN][MAXN],comb[MAXN][MAXN],ffp[MAXN][MAXN];
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
inline void dfs(ll x)
{
	if(!x)
	{
		return;
	}
	vis[x]=viss[x]=1;
	if(nxt[x]^x)
	{
		viss[nxt[x]]?s++:(dfs(nxt[x]),nxt[x]=nxt[nxt[x]]);
	}
	viss[x]=0;
}
int main()
{
	cnt=read();
	for(register int i=1;i<=cnt;i++)
	{
		x[i]=read();
	}
	for(register int i=1;i<=cnt;i++)
	{
		y[i]=read(),nxt[i]=i;
	}
	for(register int i=1;i<=cnt;i++)
	{
		if(x[i])
		{
			x[i]==y[i]?(s++,vis[x[i]]=1):nxt[x[i]]=y[i];
		}
		if(y[i])
		{
			barrel[y[i]]++;
		}
	}
	for(register int i=1;i<=cnt;i++)
	{
		if(!vis[i])
		{
			dfs(i);
		}
	}
	for(register int i=1;i<=cnt;i++)
	{
		if(!x[i])
		{
			nxt[y[i]]?q++:p++;
		}
		else
		{
			if(!barrel[x[i]]&&!nxt[y[i]])
			{
				r++;
			}
		}
	}
	st[0][0]=st[1][1]=comb[0][0]=ffp[0][0]=fact[0]=fact[1]=1;
	for(register int i=2;i<=cnt;i++)
	{
		fact[i]=(li)fact[i-1]*i%MOD;
		for(register int j=1;j<=i;j++)
		{
			st[i][j]=(st[i-1][j-1]+(li)(i-1)*st[i-1][j])%MOD;
		}
	}
	for(register int i=1;i<=cnt;i++)
	{
		ffp[i][0]=comb[i][0]=1;
		for(register int j=1;j<=i;j++)
		{
			comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%MOD;
			ffp[i][j]=(li)ffp[i][j-1]*(i-j+1)%MOD;
		}
	}
	for(register int i=0;i<=q;i++)
	{
		for(register int j=i;j<=q;j++)
		{
			kk=(li)st[j][i]*comb[q][j]%MOD*(p+q-j-1>=0?ffp[p+q-j-1][q-j]:1)%MOD;
			f[i]=(f[i]+kk)%MOD;
		}
	}
	for(register int i=0;i<=r;i++)
	{
		for(register int j=i;j<=r;j++)
		{
			kk=(li)st[j][i]*comb[r][j]%MOD*(p+r-j-1>=0?ffp[p+r-j-1][r-j]:1)%MOD;
			g[i]=(g[i]+kk)%MOD;
		}
	}
	for(register int i=0;i<=p;i++)
	{
		h[i]=(li)st[p][i]*fact[p]%MOD;
	}
	for(register int i=0;i<=cnt;i++)
	{
		for(register int j=0;j<=i;j++)
		{
			for(register int k=0;k<=i-j;k++)
			{
				res[i]=(res[i]+(li)f[k]*g[i-j-k]%MOD*h[j]%MOD)%MOD;
			}
		}
	}
	for(register int i=0;i<cnt;i++)
	{
		printf("%d ",cnt-i-s<0?0:res[cnt-i-s]);
	}
}