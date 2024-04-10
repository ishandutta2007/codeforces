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
#define N 10000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,k,x,a[N],b[N],pw2[N];
int ans;
int quickPower(int x,int y)
{
	int res=1;
	while (y)
	{
		if (y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
void LYC_music()
{
	T=read();
	pw2[0]=1;
	for (int i=1;i<N;i++) pw2[i]=pw2[i-1]*2%mod;
	while (T--)
	{
		n=read();k=read();x=read();
		if (x==0)
		{
			if (n>k)
			{
				puts("0");
				continue;
			}
			ans=1;
			int now=1,now1=1;
			for (int i=1;i<=k;i++) now=now*2%mod;
			for (int i=0;i<=n-1;i++) ans=ans*(now-now1+mod)%mod,now1=now1*2%mod;
		} else
		{
			ans=0;
			b[k]=1;
			for (int i=k-1;i>=0;i--)
			{
				a[i]=pw2[i]*b[i+1]%mod;
				b[i]=(pw2[i]-1+mod)*b[i+1]%mod;
//				cout<<"?"<<a[i]<<" "<<b[i]<<endl;
			}
			int now=1,x=quickPower(2,n);
//			cout<<x<<endl;
			for (int i=0;i<k;i++)
			{
				ans=(ans+((k-i-1)&1?(mod-1):1ll)*a[i]%mod*now%mod)%mod;
				now=now*x%mod;
			}
		}
		writeln(ans);
	}
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