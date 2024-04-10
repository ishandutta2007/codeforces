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
#define N 500005
#define p 2333
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int powp[N],invp[N];
struct node
{
	int val,len;
	node()
	{
		val=0,len=0;
	}
	node(int x,int y)
	{
		val=x,len=y;
	}
	friend node operator +(node x,node y)
	{
		node res;
		res.val=(y.val+x.val*powp[y.len])%mod;
		res.len=x.len+y.len;
		return res;
	}
	friend node operator -(node x,node y)
	{
		node res;
		res.val=(x.val-y.val+mod)%mod*invp[y.len]%mod;
		res.len=x.len-y.len;
		return res;
	}
};
struct Nd
{
	bool bl;
	node vl,vr;
	Nd(){bl=0;}
};
Nd tr[N<<2];
int n,m,q;
node s[N];
int a[N];
int sta[N],tp;
int quickPower(int x,int y)
{
	int res=1;
	while (y)
	{
		if (y&1) res=res*x%mod;
		y>>=1;
		x=x*x%mod;
	}
	return res;
}
node getR(int k,int len)
{
	if (!k) return node();
	if (len==tr[k].vr.len)
	{
		return tr[k].vr;
	}
	if (len<=tr[k<<1|1].vr.len) return getR(k<<1|1,len);
	return getR(k<<1,len-tr[k<<1|1].vr.len+tr[k<<1|1].vl.len)-tr[k<<1|1].vl+tr[k<<1|1].vr;
}
node getL(int k,int len)
{
	if (!k) return node();
	if (len==tr[k].vl.len)
	{
		return tr[k].vl;
	}
	if (len<=tr[k<<1].vl.len) return getL(k<<1,len);
	return getL(k<<1|1,len-tr[k<<1].vl.len+tr[k<<1].vr.len)-tr[k<<1].vr+tr[k<<1].vl;
}
void pushup(int k)
{
	tr[k].bl=tr[k<<1].bl&tr[k<<1|1].bl;
	if (tr[k].bl) 
	{
		if (tr[k<<1].vr.len<tr[k<<1|1].vl.len)
		{
			int x=tr[k<<1].vr.len;
			node now=getL(k<<1|1,x);
			if (now.val==tr[k<<1].vr.val)
			{
				tr[k].vl=tr[k<<1|1].vl-tr[k<<1].vr+tr[k<<1].vl;
				tr[k].vr=tr[k<<1|1].vr;
				return;
			}
			tr[k].bl=0;
			return;
		}
		else
		{
			int x=tr[k<<1|1].vl.len;
			node now=getR(k<<1,x);
//			cout<<"dz "<<k<<" "<<x<<" "<<now.val<<" "<<now.len<<" "<<((tr[k<<1].vr).val)<<" "<<((tr[k<<1|1].vl).val)<<endl;
			if (now.val==tr[k<<1|1].vl.val)
			{
				tr[k].vr=(tr[k<<1].vr-tr[k<<1|1].vl);
				tr[k].vr=tr[k].vr+tr[k<<1|1].vr;
//				cout<<"?"<<tr[k].vr.val<<endl;
				tr[k].vl=tr[k<<1].vl;
				return;
			}
			tr[k].bl=0;
			return;
		}
	}
}
void build(int k,int l,int r)
{
	if (l==r)
	{
		int i=l;
		tr[k].bl=1;
		if (a[i]<0)
		{
			tr[k].vl=node(-a[i],1);
		} else tr[k].vr=node(a[i],1);
		return;
	}
	int mid=l+(r-l)/2;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	pushup(k);
//	cout<<"?"<<k<<" "<<l<<" "<<r<<" "<<tr[k].bl<<" "<<tr[k].vr.len<<" "<<tr[k].vl.len<<" "<<tr[k].vr.val<<endl;
}
void update(int k,int l,int r,int L,int val)
{
	if (l==r)
	{
		tr[k].vl=node();
		tr[k].vr=node();
		if (val<0)
		{
			tr[k].vl=node(-val,1);
		} else tr[k].vr=node(val,1);
		return;
	}
	int mid=l+(r-l)/2;
	if (L<=mid) update(k<<1,l,mid,L,val);
	else update(k<<1|1,mid+1,r,L,val);
	pushup(k);
}
void query(int k,int l,int r,int L,int R)
{
	if (L<=l&&r<=R)
	{
		sta[++tp]=k;
		return;
	}
	int mid=l+(r-l)/2;
	if (L<=mid) query(k<<1,l,mid,L,R);
	if (R>mid) query(k<<1|1,mid+1,r,L,R);
}
node getV(int k,int len)
{
	if (!k) return node();
	if (len==s[k].len) return s[k];
	if (len<=tr[sta[k]].vr.len) return getR(sta[k],len);
	return getV(k-1,len-tr[sta[k]].vr.len+tr[sta[k]].vl.len)-tr[sta[k]].vl+tr[sta[k]].vr;
}
bool work()
{
	node now;
	s[0]=now;
	for (int i=1;i<=tp;i++)
	{
		if (!tr[sta[i]].bl) return 0;
		if (now.len<tr[sta[i]].vl.len) return 0;
		int x=tr[sta[i]].vl.len;
		node y=getV(i-1,x);
//		cout<<"?"<<i<<" "<<s[i].len<<" "<<s[i].val<<endl;
		if (y.val==tr[sta[i]].vl.val)
		{
			now=now-y;
			now=now+tr[sta[i]].vr;
		} else return 0;
		s[i]=now;
//		cout<<"?"<<i<<" "<<s[i].len<<" "<<s[i].val<<endl;
	}
	if (now.len==0) return 1;
	return 0;
}		
void LYC_music()
{
	n=read(),m=read();
	powp[0]=1;
	for (int i=1;i<=n;i++) powp[i]=powp[i-1]*p%mod;
	invp[n]=quickPower(powp[n],mod-2);
	for (int i=n;i>=1;i--)
		invp[i-1]=invp[i]*p%mod;
//		cout<<"?"<<i-1<<" "<<powp[i-1]<<endl;
	for (int i=1;i<=n;i++) a[i]=read();
	build(1,1,n);
	q=read();
	while (q--)
	{
		int opt=read(),l=read(),r=read();
		if (opt==1)
		{
			update(1,1,n,l,r);
		}
		else
		{
			tp=0;
			query(1,1,n,l,r);
			if (work()) puts("Yes");
			else puts("No");
		}
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
6 2
1 2 -2 -1 1 -1
3
2 2 3
2 1 4
2 2 5
*/