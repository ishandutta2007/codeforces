//The Hunting Party - Keys To The Kingdom
#pragma GCC optimize(2, 3, "Ofast")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/hash_policy.hpp>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m;
unordered_map<int,int>Mp;
int f[2][N];
int stp=60;
int ans;
void LYC_music()
{
	n=read(),m=read();
	bool bl=0;
	if (n>m) swap(n,m),bl=1;
	int q=read();
	for (int i=1;i<=q;i++)
	{
		int x=read(),y=read();
		if (bl) Mp[y*(m)+x]=1;
		else
		Mp[x*(m)+y]=1;
	}
	ans=inf;
		for (int j=1;j<=n;j++)
			f[0][j]=-inf;
	f[0][1]=1;
	for (int i=1;i;i++)
	{
		for (int j=1;j<=n;j++)
			f[i%2][j]=-inf;
		for (int j=1;j<=n;j++)
			if (f[(i-1)%2][j]>=1)
				f[i%2][j]=max(f[i%2][j],min(m,f[(i-1)%2][j]+j+Mp[j*m+f[(i-1)%2][j]])),f[i%2][min(n,j+(f[(i-1)%2][j])+Mp[j*m+f[(i-1)%2][j]])]=max(f[i%2][min(n,j+(f[(i-1)%2][j])+Mp[j*m+f[(i-1)%2][j]])],f[(i-1)%2][j]);
		if (f[i%2][n]==m)
		{
			writeln(i);
			return;
		}
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