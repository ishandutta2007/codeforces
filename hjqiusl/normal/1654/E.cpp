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
#define N 100005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int f[40000000],a[N];
int ans;
int n;
void BellaKira()
{
	n=read();
	ans=0;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=0;i<=320;i++)
	{
		for (int j=1;j<=n;j++)
		{
			f[i*j-a[j]+100000]++;
			ans=max(ans,f[i*j-a[j]+100000]);
		}
		for (int j=1;j<=n;j++)
		{
			f[i*j-a[j]+100000]--;
		}
	}
	// writeln(ans);
	for (int i=1;i<=n;i++)
	{
		int x=-1;
		for (int j=i+1;j<=min(n,i+320);j++)
		{
			// cout<<"?"<<i<<" "<<a[i]<<" "<<a[j]<<endl;
			if (a[j]-a[i]>320*(j-i)&&(a[j]-a[i])%(j-i)==0)
				f[(a[j]-a[i])/(j-i)]++;
		}
		for (int j=i-1;j>=max(1,i-320);j--)
		{
			if (a[i]-a[j]>320*(i-j)&&(a[i]-a[j])%(i-j)==0)
				f[(a[i]-a[j])/(i-j)]++,ans=max(ans,f[(a[i]-a[j])/(i-j)]+1);
		}
		for (int j=i-1;j>=max(1,i-320);j--)
			if (a[i]-a[j]>320*(i-j)&&(a[i]-a[j])%(i-j)==0)
				f[(a[i]-a[j])/(i-j)]--;
		for (int j=i+1;j<=min(n,i+320);j++)
			if (a[j]-a[i]>320*(j-i)&&(a[j]-a[i])%(j-i)==0)
				f[(a[j]-a[i])/(j-i)]--;
	}
	// writeln(ans);
	reverse(a+1,a+n+1);
	for (int i=0;i<=320;i++)
	{
		for (int j=1;j<=n;j++)
		{
			f[i*j-a[j]+100000]++;
			ans=max(ans,f[i*j-a[j]+100000]);
		}
		for (int j=1;j<=n;j++)
		{
			f[i*j-a[j]+100000]--;
		}
	}
	// writeln(ans);
	for (int i=1;i<=n;i++)
	{
		int x=-1;
		for (int j=i+1;j<=min(n,i+320);j++)
		{
			if (a[j]-a[i]>320*(j-i)&&(a[j]-a[i])%(j-i)==0)
				f[(a[j]-a[i])/(j-i)]++;
		}
		for (int j=i-1;j>=max(1,i-320);j--)
		{
			if (a[i]-a[j]>320*(i-j)&&(a[i]-a[j])%(i-j)==0)
				f[(a[i]-a[j])/(i-j)]++,ans=max(ans,f[(a[i]-a[j])/(i-j)]+1);
		}
		for (int j=i-1;j>=max(1,i-320);j--)
			if (a[i]-a[j]>320*(i-j)&&(a[i]-a[j])%(i-j)==0)
				f[(a[i]-a[j])/(i-j)]--;
		for (int j=i+1;j<=min(n,i+320);j++)
			if (a[j]-a[i]>320*(j-i)&&(a[j]-a[i])%(j-i)==0)
				f[(a[j]-a[i])/(j-i)]--;
	}
	// writeln(ans);
	writeln(n-ans);
	
		
			
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
/*
64 32 16 8 4 20000 2 60000 1 100000
100000 1 60000 2 20000 4 8 16 32 64
*/