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
//#define int ll
#define N 55
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,r,C,b[N],s[N],c[N],ss[N];
char a[N][N];
char A[N][N];
void BellaKira()
{
	cin>>n>>m>>r>>C;
	int sm=0;
	for (int i=1;i<=n;i++)
		b[i]=1,s[i]=0;
	for (int i=1;i<=m;i++) c[i]=1,ss[i]=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			b[i]&=(a[i][j]=='B');
			c[j]&=(a[i][j]=='B');
			s[i]+=(a[i][j]=='B');
			ss[j]+=(a[i][j]=='B');
			sm+=a[i][j]=='B';
		}
	}
	if (!sm) puts("-1");
	else
	{
		if (a[r][C]=='B') puts("0");
		else 
		{
			if (s[r]||ss[C]) puts("1");
			else puts("2");
		}
	}
			
}
signed main()
{
	int T=read(); 
	while (T--)
	{
		BellaKira();
	}
}
/*

*/