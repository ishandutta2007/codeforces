//The Hunting Party - Keys To The Kingdom
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 1000000007
#define int ll
#define N 200005 
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int powp[N],invp[N],n;
int q,p=19260817;
string st;
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
pa del(pa x,pa y)
{
	return mp((x.fi-y.fi+mod)*invp[y.se]%mod,x.se-y.se);
}
pa ad(pa x,pa y)
{
	return mp((x.fi*powp[y.se]%mod+y.fi)%mod,x.se+y.se);
}
struct node
{
	int L,R,r;
	pa now;
	node()
	{
		L=0,R=0,r=0;
		now=mp(0,0);
	}
	friend node operator +(node x,node y)
	{
		if (y.now.se==0)
		{
			y.r+=x.r;
			y.L=x.L;
			y.now=x.now;
			return y;
		}
		if (y.L==0)
		{
			if (x.r&1)
			{
				y.r+=x.r-1;
				if (x.now.se!=0) y.L=x.L;
				else y.L=1;
				y.now=ad(y.now,mp(4,1));
				y.now=ad(y.now,x.now);
			} else
			{
				y.r+=x.r;
				if (x.now.se!=0) y.L=x.L;
				y.now=ad(y.now,x.now);
			}
		} else
		{
			if (x.r&1)
			{
				y.r+=x.r+1;
				if (x.now.se!=0) y.L=x.L;
				else y.L=0;
				y.now=del(y.now,mp(4,1));
				y.now=ad(y.now,x.now);
			} else
			{
				y.r+=x.r;
				if (x.now.se!=0) y.L=x.L;
				y.now=ad(y.now,x.now);
			}
		}
		return y;
	}
	friend bool operator ==(node x,node y)
	{
		return (x.L==y.L)&&(x.R==y.R)&&(x.r==y.r)&&(x.now==y.now);
	}
}tr[N<<2];
void build(int k,int l,int r)
{
	if (l==r)
	{
		if (st[l]=='0')
		{
			tr[k].L=0;
			tr[k].R=0;
			tr[k].r=0;
			tr[k].now=mp(1,1);
		} else
		{
			tr[k].L=0;
			tr[k].R=0;
			tr[k].r=1;
			tr[k].now=mp(0,0);
		}
		return;
	}
	int mid=l+(r-l)/2;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	tr[k]=tr[k<<1]+tr[k<<1|1];
}
node query(int k,int l,int r,int L,int R)
{
	if (L<=l&&r<=R) return tr[k];
	int mid=l+(r-l)/2;
	if (R<=mid) return query(k<<1,l,mid,L,R);
	if (L>mid) return query(k<<1|1,mid+1,r,L,R);
	return query(k<<1,l,mid,L,R)+query(k<<1|1,mid+1,r,l,R);
}
void LYC_music()
{
	IOS;
	cin>>n>>st;
	powp[0]=1;
	for (int i=1;i<=n;i++) powp[i]=powp[i-1]*p%mod;
	invp[n]=quickPower(powp[n],mod-2);
	for (int i=n;i>=1;i--)
		invp[i-1]=invp[i]*p%mod;
	st=' '+st;
	cin>>q;
	build(1,1,n);
	for (int i=1;i<=q;i++)
	{
		int l,L,len;
		cin>>l>>L>>len; 
		node x=query(1,1,n,l,l+len-1),y=query(1,1,n,L,L+len-1);
		if (x==y) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
//		cout<<x.L<<" "<<x.now.fi<<" "<<x.now.se<<endl;
//		cout<<y.L<<" "<<y.now.fi<<" "<<y.now.se<<endl;
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
12
111001101101
1
1 7 6
*/