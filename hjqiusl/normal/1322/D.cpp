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
#define N 4005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,l[N],s[N],c[N];
int f[N][N];
void LYC_music()
{
	n=read();m=read();
	m+=n;
	for (int i=1;i<=n;i++)
		l[i]=read();
	for (int i=1;i<=n;i++) s[i]=read();
	memset(f,-0x3f,sizeof(f));
	for (int i=1;i<=m;i++) c[i]=read();
	for (int i=0;i<=m;i++) f[i][0]=0;
	for (int i=n;i>=1;i--)
	{
		for (int j=n;j>=1;j--)
			f[l[i]][j]=max(f[l[i]][j],f[l[i]][j-1]-s[i]+c[l[i]]);
		for (int j=l[i];j<=m;j++)
			for (int k=0;k<=(n>>(j-l[i]));k++)
				f[j+1][k/2]=max(f[j+1][k/2],f[j][k]+k/2*c[j+1]);
	}
	writeln(f[m][0]);
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