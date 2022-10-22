//The Hunting Party - Keys To The Kingdom
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e9
#define mod 998244353
//#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int a[N<<2],b[N<<2],c[N<<2],bc[N<<2],ab[N<<2],abc[N<<2];
string st;

int n,q;
void pushup(int k)
{
	a[k]=a[k<<1]+a[k<<1|1];
	b[k]=b[k<<1]+b[k<<1|1];
	c[k]=c[k<<1]+c[k<<1|1];
	ab[k]=max(ab[k<<1]+b[k<<1|1],a[k<<1]+ab[k<<1|1]);
	bc[k]=max(bc[k<<1]+c[k<<1|1],b[k<<1]+bc[k<<1|1]);
	abc[k]=max({abc[k<<1],abc[k<<1|1],abc[k<<1]+c[k<<1|1],a[k<<1]+abc[k<<1|1],ab[k<<1]+bc[k<<1|1]});
//	cout<<"??? "<<k<<" "<<a[k]<<" "<<b[k]<<" "<<c[k]<<" "<<ab[k]<<" "<<bc[k]<<" "<<abc[k]<<endl;
//	cout<<"??"<<a[k<<1]<<" "<<b[k<<1]<<" "<<c[k<<1]<<endl;
}
void build(int k,int l,int r)
{
	if (l==r)
	{
		a[k]=(st[l]!='a');
		b[k]=(st[l]!='b');
		c[k]=(st[l]!='c');
		ab[k]=a[k]|b[k];
		bc[k]=b[k]|c[k];
		abc[k]=a[k]|b[k]|c[k];
		return;
	}
	int mid=l+(r-l)/2;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
//	cout<<"pushup "<<l<<" "<<r<<endl;
	pushup(k);
}
void update(int k,int l,int r,int L)
{
	if (l==r)
	{
		a[k]=(st[l]!='a');
		b[k]=(st[l]!='b');
		c[k]=(st[l]!='c');
		ab[k]=a[k]|b[k];
		bc[k]=b[k]|c[k];
		abc[k]=a[k]|b[k]|c[k];
//		cout<<"?"<<k<<" "<<l<<" "<<r<<" "<<a[k]<<" "<<b[k]<<" "<<c[k]<<endl;
		return;
	}
	int mid=l+(r-l)/2;
	if (L<=mid) update(k<<1,l,mid,L);
	else update(k<<1|1,mid+1,r,L);
//	cout<<"pushup "<<l<<" "<<r<<endl;
	pushup(k);
}
		
void LYC_music()
{
	cin>>n>>q;
	cin>>st;
	st=' '+st;
	build(1,1,n);
	for (int i=1;i<=q;i++)
	{
		int x;
		char y;
		cin>>x>>y;
		st[x]=y;
		update(1,1,n,x);
//		cout<<abc[1]<<" "<<a[1]<<" "<<b[1]<<" "<<c[1]<<" "<<bc[1]<<endl;
		cout<<n-abc[1]<<endl;
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