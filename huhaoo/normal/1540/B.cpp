#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<assert.h>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
#define i64 long long
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
const int N=410,mod=1000000007,i2=(mod+1)/2;
i64 power(i64 a,i64 b,i64 p=mod)
{
	i64 r=1; a%=p;
	for(;b;b>>=1,a=a*a%p) if(b&1) r=r*a%p;
	return r;
}
i64 inv(i64 a){ return power(a,mod-2); }
int n;
i64 f[N][N];
int vis[N],Vis[N];
int s[N],t,d[N];
i64 ans;
std::vector<int> e[N];
void dfs(int u)
{
//	printf("%d\n",u);
	Vis[u]=1;
	for(auto v:e[u]) if(!vis[v]&&!Vis[v]) dfs(v);
}
void DFS(int u)
{
	s[t++]=u; vis[u]=1;
	if(u>s[0])
	{
//		printf("%d %d\n",s[0],u);
		fr(i,0,t-1)
		{
			vis[s[i]]=0; d[i]=0; memset(Vis,0,sizeof(Vis)); dfs(s[i]); vis[s[i]]=1;
			fr(j,1,n) d[i]+=Vis[j];
		}
		fr(j,0,t-1) ans+=f[t-1][t-1-j]*d[j]%mod;
//		fr(i,0,t-1) printf("%d%c",s[i],i==t-1?'\n':' ');
//		fr(i,0,t-1) printf("%d%c",d[i],i==t-1?'\n':' ');
//		printf("%I64d\n",ans*2%mod);
	}
	for(auto v:e[u]) if(!vis[v]) DFS(v);
	t--; vis[u]=0;
}
int main()
{
	n=read();
	fr(i,1,n-1){ int u=read(),v=read(); e[u].push_back(v); e[v].push_back(u); }
	fr(i,1,n)
	{
		f[i][0]=1;
		fr(j,1,i-1) f[i][j]=(f[i-1][j]+f[i-1][j-1])*i2%mod;
	}
	fr(i,1,n)
	{
		memset(vis,0,sizeof(vis));
		DFS(i);
	}
	printf("%I64d\n",ans%mod*inv(n)%mod);
	return 0;
}