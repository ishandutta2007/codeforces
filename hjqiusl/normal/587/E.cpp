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
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int a[N];
int sm[N<<2];
int n,q;
struct node
{
	int a[35];
	node()
	{
		memset(a,0,sizeof(a));
	}
	void clr()
	{
		memset(a,0,sizeof(a));
	}
	void ins(int x)
	{
		for (int i=34;i>=0;i--)
		{
			if (!((x>>i)%2)) continue;
			if (!a[i]) 
			{
				a[i]=x;
				break;
			}
			else x^=a[i];
		}
	}
	int query()
	{
		int res=0;
		for (int j=34;j>=0;j--) res+=(a[j]!=0);
		// for (int j=34;j>=0;j--) cout<<j<<" "<<a[j]<<endl;
		return res;
	}
}tr[N<<2];
node merge(node x,node y)
{
	for (int i=34;i>=0;i--)
		if (y.a[i]) x.ins(y.a[i]);
	return x;
}
void pushup(int k)
{
	tr[k]=merge(tr[k<<1],tr[k<<1|1]);
	sm[k]=sm[k<<1]^sm[k<<1|1];
}
void build(int k,int l,int r)
{
	if (l==r)
	{
		tr[k].ins(a[l]);
		sm[k]=a[l];
		return;
	}
	int mid=l+(r-l)/2;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	pushup(k);
}
void update(int k,int l,int r,int L,int val)
{
	if (l==r)
	{
		tr[k].clr();
		a[l]^=val;
		tr[k].ins(a[l]);
		sm[k]=a[l];
		return;
	}
	int mid=l+(r-l)/2;
	if (L<=mid) update(k<<1,l,mid,L,val);
	else update(k<<1|1,mid+1,r,L,val);
	pushup(k);
}
int querys(int k,int l,int r,int L,int R)
{
	if (L>R) return 0;
	if (L<=l&&r<=R) return sm[k];
	int mid=l+(r-l)/2;
	if (R<=mid) return querys(k<<1,l,mid,L,R);
	if (L>mid) return querys(k<<1|1,mid+1,r,L,R);
	return querys(k<<1,l,mid,L,R)^querys(k<<1|1,mid+1,r,L,R);
}
node query(int k,int l,int r,int L,int R)
{
	if (L>R) return node();
	if (L<=l&&r<=R) return tr[k];
	int mid=l+(r-l)/2;
	if (R<=mid) return query(k<<1,l,mid,L,R);
	if (L>mid) return query(k<<1|1,mid+1,r,L,R);
	return merge(query(k<<1,l,mid,L,R),query(k<<1|1,mid+1,r,L,R));
}
void BellaKira()
{
	n=read(),q=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=n;i>=1;i--) a[i]=a[i]^a[i-1];
	build(1,1,n);
	for (int i=1;i<=q;i++)
	{
		int opt=read();
		if (opt==2)
		{
			int l=read(),r=read();
			node u=query(1,1,n,l+1,r);
			int x=querys(1,1,n,1,l);
			u.ins(x);
			writeln((1ll<<u.query()));
		}
		else
		{
			int l=read(),r=read(),k=read();
			update(1,1,n,l,k);
			if (r+1<=n) update(1,1,n,r+1,k);
		}
	}
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