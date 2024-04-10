//The Hunting Party - Keys To The Kingdom
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 85
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m;
int dis[N][N],g[N][N][N],F[N][N];
int a[N];
int ans;
mt19937_64 jiaran(1144);
void LYC_music()
{
	n=read();m=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			dis[i][j]=read();
			if (i==j) dis[i][j]=inf;
		}
	ans=inf;
	for (int tim=0;tim<=10000;tim++)
	{
		for (int i=1;i<=n;i++)
			a[i]=jiaran()%2;
		memset(F,0x3f,sizeof(F));
		F[1][0]=0;
		for (int k=0;k<m;k++)
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
					if (a[i]!=a[j])
						F[j][k+1]=min(F[j][k+1],F[i][k]+dis[i][j]);
		ans=min(ans,F[1][m]);
	}
	writeln(ans);
				
}
signed main()
{
	int T=1;
	while (T--)
	{
		LYC_music();
	}
}
/*

*/