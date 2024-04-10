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
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,a[N],b[N],ans;
bool check(int x)
{
	int now=0;
	for (int i=1;i<=n;i++)
		if (b[i]>=now&&a[i]>=x-now-1)
		{
			now++;
		}
	if (now>=x) return 1;
	return 0;
}
			
void LYC_music()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),b[i]=read();
	ans=0;
	int l=1,r=n;
	while (l<=r)
	{
		int mid=l+(r-l)/2;
		if (check(mid))
		{
			ans=mid;
			l=mid+1;
		} else r=mid-1;
	}
	writeln(ans);
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