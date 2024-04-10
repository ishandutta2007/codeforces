//~~
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
#define N 400005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,q,a[N],len[N];
pa b[N];
int ans;
int L,R;
int cnt;
bool check(int x)
{
	int sm=0;
	for (int i=1;i<=m;i++)
		sm+=(len[i]/x);
	return sm-m>=q;
}
bool check1(int x)
{
	int sm=0;
	for (int i=1;i<=m;i++)
		sm+=(len[i]+x-1)/x;
	return sm-m<=q;
}
void BellaKira()
{
	n=read(),m=read(),q=read();
	for (int i=1;i<=m;i++) a[i]=read(),len[i]=a[i]-a[i-1];
	a[++m]=n;
	len[m]=a[m]-a[m-1];
	int l=1,r=n;
	L=R=0;
	while (l<=r)
	{
		int mid=l+(r-l)/2;
		if (check(mid))
		{
			L=mid;
			l=mid+1;
		} else r=mid-1;
	}
	// return;
	l=1,r=n;
	while (l<=r)
	{
		int mid=l+(r-l)/2;
		if (check1(mid))
		{
			R=mid;r=mid-1;
		} else 
			l=mid+1;
	}
	// cout<<"?"<<L<<" "<<R<<endl;
	if (L>=R){
		puts("0");
		return;
		}
	cnt=0;
	for (int i=1;i<=m;i++)
	{
		if ((len[i]+R-1)/R<=len[i]/L) continue;
		b[++cnt]=mp(len[i]/((len[i]+R-1)/R),(len[i]/L)?(len[i]+len[i]/L-1)/(len[i]/L):inf);
	}
	b[++cnt]=mp(-inf,R);
	b[++cnt]=mp(L,inf);
	sort(b+1,b+cnt+1);
	int nowmx=0;
	ans=inf;
	for (int i=1;i<cnt;i++)
	{
		nowmx=max(nowmx,b[i].se);
		ans=min(ans,nowmx-b[i+1].fi);
	}
	writeln(ans);
		
	
	
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