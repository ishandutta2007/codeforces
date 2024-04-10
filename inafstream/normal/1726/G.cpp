#include <bits/stdc++.h>
#define rep(i,n) for (int i=1;i<=(n);i++)
#define per(i,n) for (int i=(n);i>=1;i--)
using namespace std;

const int mod=998244353;
int n,m;
int a[1000005],b[1000005];
int c0[1000005],c1[1000005],pre[1000005];

namespace s0
{
	pair<int,int> mi[4000005];
	int tag[4000005];
	void pushup(int x)
	{
		mi[x]=min(mi[x+x],mi[x+x+1]);
		mi[x].first+=tag[x];
	}
	void upd(int x,int c)
	{
		mi[x].first+=c;
		tag[x]+=c;
	}
	void build(int x,int l,int r)
	{
		if(l==r)
		{
			if(c0[l]) mi[x]=make_pair(l+pre[l-1],-l);
			else mi[x]=make_pair(0x3fffffff,-1);
			return;
		}
		int mid=(l+r)/2;
		build(x*2,l,mid);
		build(x*2+1,mid+1,r);
		pushup(x);
	}
	void erase(int x,int l,int r,int y)
	{
		if(l==r)
		{
			if(c0[l]) mi[x]=make_pair(l+pre[l-1],-l);
			else mi[x]=make_pair(0x3fffffff,-1);
			return;
		}
		int mid=(l+r)/2;
		if(y<=mid) erase(x*2,l,mid,y); else erase(x*2+1,mid+1,r,y);
		pushup(x);
	}
	void update(int x,int l,int r,int ql,int qr,int c)
	{
		if(ql>qr) return;
		if(ql<=l&&r<=qr){upd(x,c);return;}
		int mid=(l+r)/2;
		if(ql<=mid) update(x*2,l,mid,ql,qr,c);
		if(qr>mid) update(x*2+1,mid+1,r,ql,qr,c);
		pushup(x);
	}
}
namespace s1
{
	pair<int,int> mx[4000005];
	int tag[4000005];
	void pushup(int x)
	{
		mx[x]=max(mx[x+x],mx[x+x+1]);
		mx[x].first+=tag[x];
	}
	void upd(int x,int c)
	{
		mx[x].first+=c;
		tag[x]+=c;
	}
	void build(int x,int l,int r)
	{
		if(l==r)
		{
			if(c1[l]) mx[x]=make_pair(l+(n-pre[l]),l);
			else mx[x]=make_pair(-0x3fffffff,-1);
			return;
		}
		int mid=(l+r)/2;
		build(x*2,l,mid);
		build(x*2+1,mid+1,r);
		pushup(x);
	}
	void erase(int x,int l,int r,int y)
	{
		if(l==r)
		{
			if(c1[l]) mx[x]=make_pair(l+(n-pre[l]),l);
			else mx[x]=make_pair(-0x3fffffff,-1);
			return;
		}
		int mid=(l+r)/2;
		if(y<=mid) erase(x*2,l,mid,y); else erase(x*2+1,mid+1,r,y);
		pushup(x);
	}
	void update(int x,int l,int r,int ql,int qr,int c)
	{
		if(ql>qr) return;
		if(ql<=l&&r<=qr){upd(x,c);return;}
		int mid=(l+r)/2;
		if(ql<=mid) update(x*2,l,mid,ql,qr,c);
		if(qr>mid) update(x*2+1,mid+1,r,ql,qr,c);
		pushup(x);
	}
}

int calc(int tar)
{
	for(int i=tar+1;i<=m;i++)if(c0[i]||c1[i]) return 0;
	int coef=1;
	rep(i,tar)rep(j,c0[i]) coef=1ll*coef*j%mod;
	int mem=c1[tar];int tn=n-c1[tar];c1[tar]=0;

	rep(i,m) pre[i]=pre[i-1]+c0[i]+c1[i];
	s0::build(1,1,m);
	s1::build(1,1,m);
	rep(i,tn)
	{
		pair<int,int> t0=s0::mi[1];t0.second*=-1;
		pair<int,int> t1=s1::mx[1];
		if(t0.first<tar){return 0;}
		if(t1.first>tar){return 0;}
		pair<int,int> op=make_pair(-0x3fffffff,-2);
		if(t0.first==tar) op=max(op,make_pair(t0.second,0));
		if(t1.first==tar) op=max(op,make_pair(t1.second,1));
		if(op.second==-2){return 0;}
		int p=op.first;
		if(op.second==0)
		{
			if(!--c0[p]) s0::erase(1,1,m,p);
		}
		else
		{
			if(!--c1[p]) s1::erase(1,1,m,p);
		}
		s0::update(1,1,m,p+1,m,-1);
		s1::update(1,1,m,p,m,1);
	}

	while(mem--) coef=1ll*coef*(++tn)%mod;
	return coef;
}

void solve()
{
	scanf("%d",&n);m=n+n;
	rep(i,n) scanf("%d",&a[i]);
	rep(i,n) scanf("%d",&b[i]);
	rep(i,n) if(b[i]) c1[a[i]]++; else c0[a[i]]++;
	int p=1;
	while(!c1[p]&&!c0[p]) p++;
	int ans=0;
	if(c0[p]) ans=calc(p); else ans=calc(p+(n-c1[p]));
	printf("%d\n",ans);
}

int main()
{
	solve();
	return 0;
}