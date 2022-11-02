#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=551;
struct Matrix{
	ll n;
	ll mat[MAXN][MAXN];
	Matrix()
	{
		memset(mat,n=0,sizeof(mat));
	}
	inline void add(ll x,ll y)
	{
		mat[x][y]--,mat[y][x]--,mat[x][x]++,mat[y][y]++;
	}
	inline ll det();
};
Matrix g[2];
ll n,m,MOD,c;
ll id[MAXN][MAXN],pos[MAXN*MAXN],ffa[MAXN*MAXN];
char ch[MAXN][MAXN];
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
inline ll find(ll x)
{
	return x==ffa[x]?x:ffa[x]=find(ffa[x]);
}
inline void merge(ll x,ll y)
{
	ll fx=find(x),fy=find(y);
	fx!=fy?ffa[fy]=fx:(puts("0"),exit(0),1);
}
inline ll qpow(ll base,ll exponent)
{
	ll res=1;
	while(exponent)
	{
		if(exponent&1)
		{
			res=(li)res*base%MOD;
		}
		base=(li)base*base%MOD,exponent>>=1;
	}
	return res;
}
inline ll Matrix::det()
{
	ll res=1,cof,pivot;
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=n;j++)
		{
			mat[i][j]+=(mat[i][j]>>31)&MOD;
		}
	}
	for(register int i=1;i<n;i++)
	{
		pivot=i;
		while(!mat[pivot][i]&&pivot<n)
		{
			pivot++;
		}
		pivot!=i?swap(mat[pivot],mat[i]),res=MOD-res:1;
		for(register int j=i+1;j<n;j++)
		{
			cof=(li)mat[j][i]*qpow(mat[i][i],MOD-2)%MOD;
			for(register int k=i;k<n;k++)
			{
				mat[j][k]=(mat[j][k]-(li)mat[i][k]*cof%MOD+MOD)%MOD;
			}
		}
	}
	for(register int i=1;i<n;i++)
	{
		res=(li)res*mat[i][i]%MOD;
	}
	return res;
}
int main()
{
	n=read(),m=read(),MOD=read();
	for(register int i=1;i<=n;i++)
	{
		scanf("%s",ch[i]+1);
	}
	for(register int i=1;i<=n+1;i++)
	{
		for(register int j=1;j<=m+1;j++)
		{
			id[i][j]=++c,ffa[c]=c;
		}
	}
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=m;j++)
		{
			ch[i][j]=='/'?merge(id[i+1][j],id[i][j+1]):(void)1;
			ch[i][j]=='\\'?merge(id[i][j],id[i+1][j+1]):(void)1;
		}
	}
	for(register int i=1;i<=n+1;i++)
	{
		for(register int j=1;j<=m+1;j++)
		{
			find(id[i][j])==id[i][j]?pos[id[i][j]]=++g[(i+j)&1].n:1;
		}
	}
	for(register int i=1;i<=n+1;i++)
	{
		for(register int j=1;j<=m+1;j++)
		{
			if(ch[i][j]=='*')
			{
				g[(i+j)&1].add(pos[find(id[i][j])],pos[find(id[i+1][j+1])]);
				g[(i+j+1)&1].add(pos[find(id[i+1][j])],pos[find(id[i][j+1])]);
			}
		}
	}
	printf("%d\n",(g[0].det()+g[1].det())%MOD);
}