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
#define N 505
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,a[N],b[N],c[N],f[N][N],ans;
void LYC_music()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),b[i]=read(),c[i]=read();
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if (b[i]<b[j])
			{
				swap(a[i],a[j]);
				swap(b[i],b[j]);
				swap(c[i],c[j]);
			}
	memset(f,-0x3f,sizeof(f));
	f[0][0]=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=i;j>=0;j--)
		{
			f[i][j]=f[i-1][j]+max(0ll,a[i]-b[i]*c[i]);
			if (j) f[i][j]=max(f[i][j],f[i-1][j-1]+a[i]-min(c[i],j-1)*b[i]);
		}
	}
	for (int i=0;i<=n;i++) ans=max(ans,f[n][i]);
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