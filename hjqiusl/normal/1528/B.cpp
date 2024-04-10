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
#define N 1000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int f[N],s[N],g[N];
int n;
void ad(int &x,int y)
{
	x=(x+y+mod)%mod;
}
void LYC_music()
{
	n=read();
	f[0]=1,f[1]=1,f[2]=3;
	s[2]=5;
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j+=i)
			ad(g[j],1);
	for (int i=3;i<=n;i++)
	{
		ad(f[i],s[i-1]);
		ad(f[i],g[i]-1);
		int now=i;
		ad(s[i],s[i-1]);
		ad(s[i],f[i]);
	}
	writeln(f[n]);	
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