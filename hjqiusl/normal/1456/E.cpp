//~~
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 105
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int dp[N][N][N][2][2][2][2];
int L[N][2];
int c[N];
int n,K;
int dfs(int k,int l,int r,int x,int y,int a,int b)
{
	if (k>=K) return (l>r)?0:inf;
	ll &res=dp[k][l][r][x][y][a][b];
	if (~res) return res;
	res=inf;
	int A=(L[l-1][x]>>k)%2,B=(L[r+1][y]>>k)%2;
	res=min(res,dfs(k+1,l,r,x,y,0,0)+(A^B^a^b)*(c[k]*(l>1&&r<n)));
	for (int i=l;i<=r;i++)
		for (int j=0;j<=1;j++)
		{
			if (!k)
				res=min(res,dfs(k,l,i-1,x,j,a,0)+dfs(k,i+1,r,j,y,0,b));
			int w=L[i][j];
			w&=(~((1LL<<k)-1));
			w^=(1ll<<k);
			// cout<<(w)<<"?"<<k<<" "<<(w)<<" "<<L[i][j^1]<<endl;
			if (L[i][0]<=w&&w+(1ll<<k)-1<=L[i][1]) 
				res=min(res,dfs(k,l,i-1,x,j,a,1)+dfs(k,i+1,r,j,y,1,b));
		}
	return res;
}
void BellaKira()
{
	n=read(),K=read();
	for (int i=1;i<=n;i++) L[i][0]=read(),L[i][1]=read();
	for (int i=1;i<=K;i++)
		c[i-1]=read();
	memset(dp,-1,sizeof(dp));
	writeln(dfs(0,1,n,0,0,0,0));
	// writeln(~((1ll<<10)-1));
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
/*

*/