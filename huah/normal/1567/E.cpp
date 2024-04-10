#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define nep(i, r, l) for (int i = r; i >= l; i--)
void sc(int &x) { scanf("%d", &x); }
void sc(int &x, int &y) { scanf("%d%d", &x, &y); }
void sc(int &x, int &y, int &z) { scanf("%d%d%d", &x, &y, &z); }
void sc(ll &x) { scanf("%lld", &x); }
void sc(ll &x, ll &y) { scanf("%lld%lld", &x, &y); }
void sc(ll &x, ll &y, ll &z) { scanf("%lld%lld%lld", &x, &y, &z); }
void sc(char *x) { scanf("%s", x); }
void sc(char *x, char *y) { scanf("%s%s", x, y); }
void sc(char *x, char *y, char *z) { scanf("%s%s%s", x, y, z); }
void out(int x) { printf("%d\n", x); }
void out(ll x) { printf("%lld\n", x); }
void out(int x, int y) { printf("%d %d\n", x, y); }
void out(ll x, ll y) { printf("%lld %lld\n", x, y); }
void out(int x, int y, int z) { printf("%d %d %d\n", x, y, z); }
void out(ll x, ll y, ll z) { printf("%lld %lld %lld\n", x, y, z); }
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
using namespace std;
#define inf 0x3f3f3f3f
#define fi first
#define se second
const int N=2e5+5,mod=1e9+7;
int n,q,a[N];
struct node
{
	ll ans,len,lways,rways,lval,rval;
	node operator+(const node&o)const
	{
		node res;
		res.ans=ans+o.ans;
		res.lways=lways;
		res.rways=o.rways;
		res.lval=lval;
		res.rval=o.rval;
		res.len=len+o.len;
		if(rval<=o.lval)
		{
			res.ans+=rways*o.lways;
			if(lways==len) res.lways+=o.lways;
			if(o.rways==o.len) res.rways+=rways;
		}
		return res;
	}
}t[N<<2];
void build(int l,int r,int k)
{
	if(l==r)
	{
		t[k].len=t[k].ans=t[k].lways=t[k].rways=1;
		t[k].lval=t[k].rval=a[l];
		return;
	}
	int m=(l+r)>>1;
	build(l,m,k<<1);build(m+1,r,k<<1|1);
	t[k]=t[k<<1]+t[k<<1|1];
}
void fix(int l,int r,int k,int x)
{
	if(l==r)
	{
		t[k].len=t[k].ans=t[k].lways=t[k].rways=1;
		t[k].lval=t[k].rval=a[l];
		return;
	}
	int m=(l+r)>>1;
	if(x<=m) fix(l,m,k<<1,x);
	else fix(m+1,r,k<<1|1,x);
	t[k]=t[k<<1]+t[k<<1|1];
}
node query(int l,int r,int k,int x,int y)
{
	if(l>=x&&r<=y) return t[k];
	int m=(l+r)>>1;
	if(x<=m&&y>m) return query(l,m,k<<1,x,y)+query(m+1,r,k<<1|1,x,y);
	else if(x<=m) return query(l,m,k<<1,x,y);
	return query(m+1,r,k<<1|1,x,y);
}
void sol(int cas)
{
	sc(n,q);
	rep(i,1,n) sc(a[i]);
	build(1,n,1);
	while(q--)
	{
		int op,x,y;sc(op,x,y);
		if(op==1)
		{
			a[x]=y;
			fix(1,n,1,x);
		}
		else out(query(1,n,1,x,y).ans);
	}
}
int main()
{
  // freopen("1.in", "r",stdin);
  // freopen("1.out", "w", stdout);
  srand(time(0));
  int t=1,cas=0;
//   scanf("%d",&t);
  while(t--)
  {
    sol(++cas);
  }
  return 0;
}
/*
befor submit code check:
freopen
size of N
mod
debug output
*/