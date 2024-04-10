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
#define N 55
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,f[N][N];
void LYC_music()
{
	n=read(),m=read();
	n=min(n,50ll);
	for (int i=1;i<=n;i++) f[i][i]=114514;
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		if (x<=50&&y<=50)
		{
			f[x][y]=f[y][x]=1;
		}
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			for (int k=1;k<=n;k++)
				for (int x=1;x<=n;x++)
					for (int y=1;y<=n;y++)
						if (f[i][j]+f[i][k]+f[i][x]+f[i][y]+f[j][k]+f[j][x]+f[j][y]+f[k][x]+f[k][y]+f[x][y]==10
						||f[i][j]+f[i][k]+f[i][x]+f[i][y]+f[j][k]+f[j][x]+f[j][y]+f[k][x]+f[k][y]+f[x][y]==0) 
						{
							cout<<i<<" "<<j<<" "<<k<<" "<<x<<" "<<y<<endl;
							return;
						} 
	cout<<-1<<endl;
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