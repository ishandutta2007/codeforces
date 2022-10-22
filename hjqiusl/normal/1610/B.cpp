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
//#define int ll
#define N 1000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,a[N],ans;
void chk(int x)
{
	vector<int>g;
	for (int i=1;i<=n;i++)
		if (a[i]!=x) g.push_back(a[i]);
	for (int i=0;i<g.size()-1-i;i++)
		if (g[i]!=g[g.size()-1-i]) return;
		ans=1;
}
void LYC_music()
{
	ans=0;
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	int l=1,r=n;
	while (l<r)
	{
		if (a[l]!=a[r])
		{
			chk(a[l]);
			chk(a[r]);
			break;
		}
		l++,r--;
	}
	if (l>=r) ans=1;
	if (ans) puts("Yes");
	else puts("No");
		
}
signed main()
{
	int T=read();
	while (T--)
	{
		LYC_music();
	}
}
/*

*/