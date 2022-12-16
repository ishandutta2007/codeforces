#include<bits/stdc++.h>
using namespace std;
const int M=1000000007,N=1000005;
int n,m,ch[N][26],len[N],tot,k,i,j,las,fail[N];
int d[N],g[N];
char cc[N],c[N];
long long dp[N],f[N];
int main()
{
	scanf("%s",cc+1);
	n=strlen(cc+1);
	len[1]=-1;
	fail[0]=1;
	for(i=1;i<=n/2;++i)
	{
		c[++k]=cc[i];
		c[++k]=cc[n-i+1];
	}
	tot=1;
	dp[0]=1;
	for(i=1;i<=n;++i)
	{
		int p=las;
		while(c[i-len[p]-1]!=c[i])
			p=fail[p];
		if(ch[p][c[i]-'a']==0)
		{
			int v=p;
			p=fail[p];
			while(c[i-len[p]-1]!=c[i])
				p=fail[p];
			fail[++tot]=ch[p][c[i]-'a'];
			ch[v][c[i]-'a']=tot;
			len[tot]=len[v]+2;
			las=tot;
			d[tot]=len[tot]-len[fail[tot]];
			if(d[tot]==d[fail[tot]])
				g[tot]=g[fail[tot]];
			else
				g[tot]=fail[tot];
		}
		else
			las=ch[p][c[i]-'a'];
		p=las;
		while(p)
		{
			f[p]=dp[i-d[p]-len[g[p]]];
			if(g[p]!=fail[p])
				f[p]=(f[p]+f[fail[p]])%M;
			if((i&1)^1)
				dp[i]=(dp[i]+f[p])%M;
			p=g[p];
		}
		//cout<<dp[i]<<' ';
	}
	cout<<dp[n];
}