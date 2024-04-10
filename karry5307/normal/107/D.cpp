#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
typedef map<vector<ll>,ll>::iterator iter;
const ll MAXN=251,MOD=12345;
struct Matrix{
	ll num[MAXN][MAXN];
	Matrix()
	{
		memset(num,0,sizeof(num));
	}
	inline ll* operator [](const ll &x)
	{
		return num[x];
	}
	inline const ll* operator[](const ll &x)const
	{
		return num[x];
	}
};
Matrix x;
map<vector<ll>,ll>mp;
vector<ll>v(31),r;
li n,m,kk,mx,cnt,s,res,flg;
ll vis[MAXN],f[MAXN][MAXN],h[MAXN][MAXN];
char ch[MAXN];
inline li read()
{
    register li num=0,neg=1;
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
inline Matrix operator *(Matrix x,Matrix y)
{
	Matrix res;
	for(register int i=0;i<mx;i++)
	{
		for(register int j=0;j<mx;j++)
		{
			for(register int k=0;k<mx;k++)
			{
				res[i][j]=(res[i][j]+(li)x[i][k]*y[k][j]%MOD)%MOD;
			}
		}
	}
	return res;
}
inline Matrix qpow(Matrix base,li exponent)
{
	Matrix res;
	for(register int i=0;i<mx;i++)
	{
		res[i][i]=1;
	}
	while(exponent)
	{
		if(exponent&1)
		{
			res=res*base;
		}
		base=base*base,exponent>>=1;
	}
	return res;
}
inline void dfs(ll cur)
{
	if(cur==26)
	{
		return (void)(mp[v]=cnt++);
	}
	for(register int i=0;i<=max(vis[cur]-1,0);i++)
	{
		v[cur]=i,dfs(cur+1);
	}
}
int main()
{
	n=read(),m=read(),mx=1;
	for(register int i=1;i<=m;i++)
	{
		scanf("%s",ch),kk=read(),vis[ch[0]-'A']=f[ch[0]-'A'][kk]=1;
	}
	for(register int i=0;i<26;i++)
	{
		if(!vis[i])
		{
			continue;
		}
		for(register int j=0;j<133;j++)
		{
			f[i][j]?vis[i]=vis[i]*j/__gcd(vis[i],j):1;
		}
		mx*=vis[i];
		for(register int j=0;j<133;j++)
		{
			if(f[i][j])
			{
				for(register int k=0;k<vis[i];k+=j)
				{
					h[i][k]=1;
				}
			}
		}
	}
	dfs(0);
	for(register iter it=mp.begin();it!=mp.end();++it)
	{
		r=(*it).first,s=(*it).second;
		for(register int i=0;i<26;i++)
		{
			if(vis[i])
			{
				r[i]=(r[i]+1)%vis[i],x[mp[r]][s]++,r[i]=(r[i]+vis[i]-1)%vis[i];
			}
		}
	}
	x=qpow(x,n);
	for(register iter it=mp.begin();it!=mp.end();++it)
	{
		r=(*it).first,s=(*it).second,flg=0;
		for(register int i=0;i<26;i++)
		{
			flg|=(vis[i]&&!h[i][r[i]]);
		}
		res=(res+(flg?0:x[s][0]))%MOD;
	}
	printf("%d\n",res);
}