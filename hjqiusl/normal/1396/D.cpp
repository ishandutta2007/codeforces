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
#define mod 1000000007
#define int ll
#define N 2005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int tr[N<<2],tag[N<<2];
int mn[N<<2],mx[N<<2];
struct node
{
	int x,y,c;
}a[N];
int n,m,L;
vector<int>G,P[N],G1;
multiset<int>S[N];
int ans;
int GG(int x)
{
	if (x==0) return 0;
	return G1[x-1];
}
int gg(int x)
{
	if (x==0) return 0;
	return G[x-1];
}
void build(int k,int l,int r)
{
	tr[k]=0;tag[k]=0;
	mx[k]=mn[k]=0;
	if (l==r) return;
	int mid=l+(r-l)/2;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}
void pushdown(int k,int l,int r)
{
	if (!tag[k]) return;
	int mid=l+(r-l)/2;
	mx[k<<1]=tag[k];
	tr[k<<1]=(GG(mid)-GG(l-1))%mod*tag[k]%mod;
	mn[k<<1]=tag[k];
	tag[k<<1]=tag[k];
	
	mx[k<<1|1]=tag[k];
	tr[k<<1|1]=(GG(r)-GG(mid))%mod*tag[k]%mod;
	mn[k<<1|1]=tag[k];
	tag[k<<1|1]=tag[k];
	tag[k]=0;
}
void pushup(int k)
{
	tr[k]=(tr[k<<1]+tr[k<<1|1])%mod;
	mn[k]=min(mn[k<<1],mn[k<<1|1]);
	mx[k]=max(mx[k<<1],mx[k<<1|1]);
}
	
void update(int k,int l,int r,int L,int R,int val)
{
	int mid=l+(r-l)/2;
	if (L<=l&&r<=R)
	{
		if (mn[k]>=val) return;
		if (mx[k]<=val)
		{
			// cout<<k<<" "<<mx[k]<<" "<<val<<" "<<GG(r)<<" "<<r<<" "<<G1.size()<<endl;
			tr[k]=(GG(r)-GG(l-1))%mod*val%mod;
			tag[k]=val;
			mx[k]=val;
			mn[k]=val;
			return;
		}
		pushdown(k,l,r);
		update(k<<1,l,mid,L,R,val);
		if (mn[k<<1|1]<val)
		{
			update(k<<1|1,mid+1,r,L,R,val);
		}
		pushup(k);
		return;
	}
	pushdown(k,l,r);
	if (L<=mid) update(k<<1,l,mid,L,R,val);
	if (R>mid) update(k<<1|1,mid+1,r,L,R,val);
	pushup(k);
}
void BellaKira()
{
	n=read(),m=read(),L=read();
	for (int i=1;i<=n;i++)
	{
		a[i].x=read()+1,a[i].y=read()+1,a[i].c=read();
		G.push_back(a[i].x);
	}
	
	sort(G.begin(),G.end());
	G.erase(unique(G.begin(),G.end()),G.end());
	while (G.size()!=n) G.push_back(L);
	for (int i=1;i<=n;i++) a[i].x=lower_bound(G.begin(),G.end(),a[i].x)-G.begin()+1;
	for (int i=1;i<=n;i++) G1.push_back(a[i].y);
	sort(G1.begin(),G1.end());
	G1.erase(unique(G1.begin(),G1.end()),G1.end());
	for (int i=1;i<=n;i++) a[i].y=lower_bound(G1.begin(),G1.end(),a[i].y)-G1.begin()+1,P[a[i].x].push_back(i);
	while (G1.size()!=n) G1.push_back(L);
	G1.push_back(L+1);
	G.push_back(L+1);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
			S[j].clear();
		for (int j=1;j<=n;j++)
			if (a[j].x>=i) S[a[j].c].insert(a[j].y);
		build(1,1,n);
		for (int j=1;j<=m;j++)
		{
			int lst=0;
			auto it=S[j].begin();
			while (it!=S[j].end())
			{
				update(1,1,n,lst+1,(*it),G1[(*it)-1]);
				lst=(*it);
				it++;
			}
			if (lst+1<=n)
			update(1,1,n,lst+1,n,G1.back());
		}
		for (int j=1;j<=m;j++) 
		{
			S[j].insert(0),S[j].insert(n+1);
		}
		for (int j=n;j>=i;j--)
		{
			// cout<<"?"<<i<<" "<<j<<" "<<tr[1]<<endl;
			// <<" "<<((gg(j+1)-gg(j))*(gg(i)-gg(i-1)))<<endl;
			ans+=(G1.back()*(G1[n-1])%mod-tr[1]+mod)%mod*((gg(j+1)-gg(j))%mod*(gg(i)-gg(i-1))%mod)%mod;
			ans%=mod;
			for (auto u:P[j])
			{
				S[a[u].c].erase(S[a[u].c].find(a[u].y));
				int lst=(*--S[a[u].c].lower_bound(a[u].y));
				int nxt=(*S[a[u].c].lower_bound(a[u].y));
				// cout<<"upd "<<lst+1<<" "<<a[u].y<<" "<<nxt<<" "<<G1[nxt-1]<<endl;
				update(1,1,n,lst+1,a[u].y,G1[nxt-1]);
			}
		}
		// cout<<"???"<<i<<" "<<ans<<endl;
	}
	writeln(ans);
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