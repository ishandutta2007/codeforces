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
#define inf 1e9
#define mod 998244353
// #define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
vector<int>tr[N<<2],tr1[N<<2],G[N];
int ans;
int n,a[N];
int gt(int x)
{
	if (x==0) return 1;
	int t=ceil(log2(x));
	// cout<<"?"<<(1<<t)<<" "<<x<<endl;
	return (1<<t)-x;
}
void update(int k,int l,int r,int L,int val)
{
	tr[k].push_back(val);
	if (l==r) return;
	int mid=l+(r-l)/2;
	if (L<=mid) update(k<<1,l,mid,L,val);
	else update(k<<1|1,mid+1,r,L,val);
}
void build(int k,int l,int r)
{
	sort(tr[k].begin(),tr[k].end());
	tr1[k].resize(tr[k].size());
	if (tr[k].size())
	{
		for (int j=tr[k].size()-1;j>=0;j--)
		{
			if (j==tr[k].size()-1)
			{
				tr1[k][j]=gt(n-tr[k][j]+1)+(n-tr[k][j]+1);
			}
			else tr1[k][j]=min(tr1[k][j+1],gt(n-tr[k][j]+1)+(n-tr[k][j]+1));
		}
	}
	if (l==r) return;
	int mid=l+(r-l)/2;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}
void build1(int k,int l,int r)
{
	tr[k].clear(),tr1[k].clear();
	if (l==r) return;
	int mid=l+(r-l)/2;
	build1(k<<1,l,mid);
	build1(k<<1|1,mid+1,r);
}
int query(int k,int l,int r,int L,int R,int val)
{
	if (L>R) return inf;
	// cout<<k<<" "<<l<<" "<<r<<" "<<L<<" "<<R<<" "<<val<<endl;
	if (L<=l&&r<=R)
	{
		int x=lower_bound(tr[k].begin(),tr[k].end(),val)-tr[k].begin();
		if (x==tr[k].size()) return inf;
		return tr1[k][x];
	}
	int mid=l+(r-l)/2,res=inf;
	if (L<=mid) res=min(res,query(k<<1,l,mid,L,R,val));
	if (R>mid) res=min(res,query(k<<1|1,mid+1,r,L,R,val));
	return res;
}
		
void BellaKira()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	a[n+1]=0;
	build1(1,0,n);
	update(1,0,n,0,n+1);
	for (int i=n;i>=1;i--)
	{
		if (a[i]!=a[i-1])
		{
			int x=(n-i+1);
			update(1,0,n,x,i);
			// cout<<"upd "<<x<<" "<<i<<endl;
			G[x].push_back(i);
		}
	}
	build(1,0,n);
	// return;
	ans=inf;
	for (int i=1;i<=n;i++)
	{
		if (a[i]==a[i-1]) continue;
		int x=i-1;
		for (int j=1;j<=n-i+1;j*=2)
		{
			int y=lower_bound(G[n-i+1-j].begin(),G[n-i+1-j].end(),i)-G[n-i+1-j].begin();
			if (y==G[n-i+1-j].size()) continue;
			ans=min(ans,gt(i-1)+gt(n-i+1-j));
		}
		ans=min(ans,gt(i-1)+gt(n-i+1)+1);
		// cout<<i<<" "<<gt(i-1)+gt(n-i+1)+1<<endl;
		for (int j=1;j<=n-i+1;j*=2)
		{
			int l=j+1,r=j*2-1;
			if (l>r) continue;
			int val=query(1,0,n,max(0,n-i+1-r),min(n,n-i+1-l),i);
			// cout<<i<<" "<<j<<" "<<j*2<<" "<<l<<" "<<r<<" "<<val<<" "<<j*2-(n-i+1)+val<<endl;
			ans=min(ans,j*2-(n-i+1)+val+gt(i-1));
		}
	}
	for (int i=0;i<=n;i++) G[i].clear();
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