//The Hunting Party - Keys To The Kingdom
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2)

#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf (1e18+10)
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
ll sufmn[N],sufmx[N];
int ppcmn[N],ppcmx[N];
int cnt[N>>1][61];
ll ans;
ll s[N];
ll a[N];
int n;
int ppc(ll x)
{
	return __builtin_popcountll(x);
}
void solve(int l,int r)
{
	if (l==r) 
	{
		ans+=1;
		return;
	}
	int mid=l+(r-l)/2;
	solve(l,mid);
	solve(mid+1,r);
	sufmx[mid+1]=-inf;sufmn[mid+1]=inf;
	s[l-1]=0;
	for (int i=mid;i>=l;i--)
	{
		sufmn[i]=min(sufmn[i+1],a[i]);ppcmn[i]=ppc(sufmn[i]);
		sufmx[i]=max(sufmx[i+1],a[i]);ppcmx[i]=ppc(sufmx[i]);
	}
	memset(cnt[mid-l+2],0,sizeof(cnt[mid-l+2]));
	for (int i=mid;i>=l;i--)
	{
		for (int j=0;j<=60;j++)
			cnt[i-l+1][j]=cnt[i-l+1+1][j];
		cnt[i-l+1][ppcmx[i]]++;
	}
	for (int i=l;i<=mid;i++)
		s[i]=s[i-1]+(ppcmn[i]==ppcmx[i]);
	int L=mid+1,R=mid+1;
	ll nowmn=inf,nowmx=-inf;
	for (int i=mid+1;i<=r;i++)
	{
		nowmn=min(nowmn,a[i]);
		nowmx=max(nowmx,a[i]);
		while (L>l)
		{
			if (sufmn[L-1]<nowmn) break;
			L--;
		}
		while (R>l)
		{
			if (sufmx[R-1]>nowmx) break;
			R--;
		}
		if (L<R) ans+=cnt[L-l+1][ppc(nowmn)]-cnt[R-l+1][ppc(nowmn)];
	}
	memset(cnt[mid-l+2],0,sizeof(cnt[mid-l+2]));
	L=mid+1,R=mid+1;
	nowmn=inf,nowmx=-inf;
	for (int i=mid;i>=l;i--)
	{
		for (int j=0;j<=60;j++)
			cnt[i-l+1][j]=cnt[i-l+1+1][j];
		cnt[i-l+1][ppcmn[i]]++;
	}
	for (int i=mid+1;i<=r;i++)
	{
		nowmn=min(nowmn,a[i]);
		nowmx=max(nowmx,a[i]);
		while (L>l)
		{
			if (sufmn[L-1]<nowmn) break;
			L--;
		}
		while (R>l)
		{
			if (sufmx[R-1]>nowmx) break;
			R--;
		}
		if (ppc(nowmn)==ppc(nowmx))
			ans+=mid+1-max(L,R);
		ans+=s[min(L,R)-1];
		if (L>R) ans+=cnt[R-l+1][ppc(nowmx)]-cnt[L-l+1][ppc(nowmx)];
	}
}
void LYC_music()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	solve(1,n);
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