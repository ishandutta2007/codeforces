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
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int st[N][25];
int st1[N][25];
const int inv2=500000004ll;
int n;
int lst[N];
int nxt[N];
map<int,int>Mp;
int a[N];
struct node
{
	int a[7];
	node()
	{
		for (int i=0;i<7;i++) a[i]=0;
	}
};
node tr[N<<1];
int queryf(int l,int r)
{
	int t=log2(r-l+1);
	return max(st[l][t],st[r-(1<<t)+1][t]);
}
int queryg(int l,int r)
{
	int t=log2(r-l+1);
	return min(st1[l][t],st1[r-(1<<t)+1][t]);
}
int chk(int l,int r)
{
	return (l>=queryf(l,r))&&(r<=queryg(l,r));
}
node merge(node x,node y)
{
	for (int i=1;i<=3;i++) (x.a[i]+=y.a[i])%=mod;
	x.a[4]=x.a[5]=0;
	(x.a[6]+=y.a[6])%=mod;
	return x;
}
void pushup(int k)
{
	tr[k]=merge(tr[k<<1],tr[k<<1|1]);
}
void pushtag1(int k,int l,int r,int x)
{
	// cout<<"pgtg "<<k<<" "<<l<<" "<<r<<" "<<x<<endl;
	tr[k].a[1]=x*(r-l+1)%mod;
	tr[k].a[3]=(mod-x)*tr[k].a[2]%mod;
	tr[k].a[4]=x;
}
void pushtag2(int k,int l,int r,int x)
{
	tr[k].a[2]=x*(r-l+1)%mod;
	tr[k].a[6]=x*(l+r)%mod*(r-l+1)%mod*inv2%mod;
	tr[k].a[3]=(mod-x)*tr[k].a[1]%mod;
	tr[k].a[5]=x;
}
void pushdown(int k,int l,int r)
{
	int mid=l+(r-l)/2;
	if (tr[k].a[4])
	{
		pushtag1(k<<1,l,mid,tr[k].a[4]);
		pushtag1(k<<1|1,mid+1,r,tr[k].a[4]);
		tr[k].a[4]=0;
	}
	if (tr[k].a[5])
	{
		pushtag2(k<<1,l,mid,tr[k].a[5]);
		pushtag2(k<<1|1,mid+1,r,tr[k].a[5]);
		tr[k].a[5]=0;
	}
}
void build(int k,int l,int r)
{
	if (l==r)
	{
		tr[k].a[1]=n+1;
		tr[k].a[2]=0;
		return;
	}
	int mid=l+(r-l)/2;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	pushup(k);
}
void update(int k,int l,int r,int L,int R,int x,int tp)
{
	if (L<=l&&r<=R)
	{
		if (tp==2)
			pushtag1(k,l,r,x);
		else pushtag2(k,l,r,x);
		return;
	}
	int mid=l+(r-l)/2;
	pushdown(k,l,r);
	if (L<=mid) update(k<<1,l,mid,L,R,x,tp);
	if (R>mid) update(k<<1|1,mid+1,r,L,R,x,tp);
	pushup(k);
}
node query(int k,int l,int r,int L,int R)
{
	if (L<=l&&r<=R) return tr[k];
	int mid=l+(r-l)/2;
	pushdown(k,l,r);
	if (R<=mid) return query(k<<1,l,mid,L,R);
	if (L>mid)  return query(k<<1|1,mid+1,r,L,R);
	return merge(query(k<<1,l,mid,L,R),query(k<<1|1,mid+1,r,L,R));
}
void BellaKira()
{
	n=read();
	for (int i=1;i<=n;i++)
		a[i]=read();
	for (int i=1;i<=n;i++)
	{
		if (!Mp.count(a[i]))
		{
			Mp[a[i]]=i;
		} else
		{
			lst[i]=Mp[a[i]];
			Mp[a[i]]=i;
		}
	}
	Mp.clear();
	for (int i=n;i>=1;i--)
	{
		if (!Mp.count(a[i]))
		{
			nxt[i]=n+1;
			Mp[a[i]]=i;
		} else
		{
			nxt[i]=Mp[a[i]];
			Mp[a[i]]=i;
		}
	}
	for (int i=1;i<=n;i++)
		st[i][0]=lst[i]+1,st1[i][0]=nxt[i]-1;
	for (int i=1;i<=20;i++)
		for (int j=1;j+(1<<i)-1<=n;j++)
			st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]),
			st1[j][i]=min(st1[j][i-1],st1[j+(1<<(i-1))][i-1]);
	build(1,1,n);
	int j=n;
	int ans=0;
	for (int i=n;i>=1;i--)
	{
		
		while (j>=i&&!chk(i,j)) j--;
		int l=i,r=n,now=i-1;
		while (l<=r)
		{
			int mid=l+(r-l)/2;
			if (queryf(i,mid)<=st[i][0])
			{
				now=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		// cout<<i<<" "<<now<<" "<<st[i][0]<<" upd1"<<endl;
		update(1,1,n,i,now,st[i][0],1);
		l=i,r=n,now=i-1;
		while (l<=r)
		{
			int mid=l+(r-l)/2;
			if (queryg(i,mid)>=st1[i][0])
			{
				now=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		update(1,1,n,i,now,st1[i][0],2);
		// cout<<i<<" "<<now<<" "<<st1[i][0]<<" upd2"<<endl;
		node qr=query(1,1,n,i,j);
		int lstans=ans;
		ans=(ans+qr.a[1]*i%mod)%mod;
		ans=(ans+qr.a[3])%mod;
		ans=(ans+qr.a[6])%mod;
		ans=(ans-i*(i+j)%mod*(j-i+1)%mod*inv2%mod+mod)%mod;
		// int add=ans-lstans;
		// int add1=0;
		// for (int k=i;k<=j;k++)
			// add1=add1+(i-queryf(i,k))*(queryg(i,k)-k);
		// cout<<i<<" "<<ans<<" "<<j<<" "<<queryf(i,j)<<" "<<queryg(i,j)<<" "<<add<<" "<<add1<<endl;
		// cout<<" "<<qr.a[1]<<" "<<qr.a[3]-mod<<" "<<qr.a[6]<<" "<<-i*(i+j)%mod*(j-i+1)%mod*inv2%mod<<" "<<queryf(i,j)<<" "<<queryg(i,j)<<" "<<st[i][0]<<endl;
		// cout<<i<<" "<<j<<" "<<qr.a[3]<<" "<<qr.a[1]<<" "<<qr.a[2]<<" "<<ans<<" "<<qr.a[6]<<endl;
	
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