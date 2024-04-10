//The Hunting Party - Keys To The Kingdom
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 1000000007
#define int ll
#define N 2000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
//map<int,int>Mp;
//multiset<int>S;
int d[N];
int n,sm,a[N];
int fac[N];
int ans;
void LYC_music()
{
	n=read();
	sm=0;
	int inv2=(mod+1)/2;
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		d[a[i]-1+1000000]++;
		d[-(a[i]-1)+1000000-2]--;
		sm+=a[i];
	}
	int ans1=1;
	fac[0]=1;
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	int len=sm;
	for (int i=2e6;i>=0;i--)
	{
		d[i]+=d[i+2];
		ans=(ans+(len+(len-d[i]+1))%mod*d[i]%mod*inv2%mod*(i-1000000)%mod)%mod;
		ans=(ans+mod)%mod;
//		if (d[i]) cout<<"?"<<i<<" "<<d[i]<<endl;
		ans1=ans1*fac[d[i]]%mod;
		len-=d[i];
	}
	writesp(ans);
	writeln(ans1);
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