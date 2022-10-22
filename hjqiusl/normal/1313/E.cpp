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
#define int ll
#define N 2000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int f[N],tr[N],tr1[N];
int n,m;
int g[N];
string st,st1,st2;
int ans;
void Z(int *z,int m,string c)
{
	z[1]=m;
	int l=0,r=0;
	for (int i=2;i<=m;i++)
	{
		if (i<=r) z[i]=min(r-i+1,z[i-l+1]);
		while (i+z[i]<=m&&c[i+z[i]]==c[z[i]+1]) z[i]++;
		if (z[i]+i-1>r) l=i,r=z[i]+i-1;
	}
}
void update(int x,int y)
{
	while (x<=n+1) tr[x]+=y,x+=(x&-x);
}
int query(int x)
{
	int res=0;
	while (x>0) res+=tr[x],x-=(x&-x);
	return res;
}
void update1(int x,int y)
{
	while (x<=n+1) tr1[x]+=y,x+=(x&-x);
}
int query1(int x)
{
	int res=0;
	while (x>0) res+=tr1[x],x-=(x&-x);
	return res;
}
void ins(int x)
{
	// cout<<"ins "<<g[x]<<" "<<n-g[x]+1<<endl;
	update(n-g[x]+1,g[x]);
	update1(n-g[x]+1,1);
}
void ers(int x)
{
	// cout<<"ers "<<g[x]<<endl;
	update(n-g[x]+1,-g[x]);
	update1(n-g[x]+1,-1);
}
int calc(int x)
{
	int p=max(0ll,m-1-f[x]);
	// cout<<x<<" "<<f[x]<<" "<<n-p+1<<" "<<query(n-p+1)<<" "<<query1(n-p+1)*(f[x]-m+1)<<endl;
	return (query(n-p+1)+query1(n-p+1)*(f[x]-m+1));
}
	
void BellaKira()
{
	cin>>n>>m;
	cin>>st>>st1>>st2;
	char chp=st2.back();
	st2.pop_back();
	string p=' '+st2+'#'+st;
	Z(f,n+m+1,p);
	// cout<<p<<endl;
	for (int i=1;i<=n;i++)
		f[i]=f[i+m];
	st2+=chp;
	reverse(st2.begin(),st2.end());
	st2.pop_back();
	reverse(st2.begin(),st2.end());
	p=st1+'#'+st2;
	reverse(p.begin(),p.end());
	p=' '+p;
	Z(g,n+m+1,p);
	for (int i=1;i<=n;i++)
		g[i]=g[i+m];
	for (int i=1;i<=n-i+1;i++)
		swap(g[i],g[n-i+1]);
	// for (int i=1;i<=n;i++) cout<<f[i]<<" "<<g[i]<<endl;
	// cout<<p<<endl;
	for (int i=1;i<=min(n,m-1);i++)
	{
		ins(i);
	}
	for (int i=1;i<=n;i++)
	{
		ans+=calc(i);
		ers(i);
		if (i+m-1<=n) ins(i+m-1);
	}
	writeln(ans);
	// ans=0;
	// for (int i=1;i<=n;i++)
	// {
		// int totx=0;
		// for (int j=i;j<=n;j++)
			// if (j-i+1<m&&f[i]!=0&&g[j]!=0)
				// ans+=max(f[i]+g[j]-m+1,0ll),totx+=max(f[i]+g[j]-m+1,0ll),cout<<i<<","<<j<<" "<<max(f[i]+g[j]-m+1,0ll)<<" "<<f[i]<<" "<<g[j]<<endl;
		// writeln(totx);
	// }
	// writeln(ans);		
// 		
	
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

*/