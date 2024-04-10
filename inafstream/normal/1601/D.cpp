#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

int n,m;

struct intval
{
	int l,r;
}a[500005];
bool cmp(intval x,intval y)
{
	if(min(x.l,x.r)!=min(y.l,y.r)) return min(x.l,x.r)<min(y.l,y.r);
	return x.r<y.r;
}

vector<int> lsh;

int mx[4000005],tag[4000005];
void build(int x,int l,int r)
{
	mx[x]=-0x3f3f3f3f;tag[x]=0;
	if(l==r) return;
	
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
}
void update(int x,int l,int r,int L,int R,int v)
{
	if(L>R) return;
	if(L<=l&&r<=R)
	{
		mx[x]+=v;tag[x]+=v;
		return;
	}
	
	int mid=(l+r)/2;
	if(L<=mid) update(x*2,l,mid,L,R,v);
	if(R>mid) update(x*2+1,mid+1,r,L,R,v);
	
	mx[x]=max(mx[x*2],mx[x*2+1]);
	mx[x]+=tag[x];
}
void modify(int x,int l,int r,int p,int t)
{
	if(l==r)
	{
		mx[x]=max(mx[x],t);
		return;
	}
	
	mx[x]=max(mx[x],t);
	t-=tag[x];
	int mid=(l+r)/2;
	if(p<=mid) modify(x*2,l,mid,p,t); else modify(x*2+1,mid+1,r,p,t);
}
int query(int x,int l,int r,int L,int R)
{
	if(L<=l&&r<=R) return mx[x];
	int mid=(l+r)/2,ans=-0x3f3f3f3f;
	if(L<=mid) ans=max(ans,query(x*2,l,mid,L,R));
	if(R>mid) ans=max(ans,query(x*2+1,mid+1,r,L,R));
	return ans+tag[x];
}

void solve()
{
	int i;
	scanf("%d%d",&n,&m);
	lsh.push_back(m);
	rep(i,n) scanf("%d%d",&a[i].l,&a[i].r);
	
	rep(i,n) lsh.push_back(a[i].l);
	rep(i,n) lsh.push_back(a[i].r);
	
	sort(lsh.begin(),lsh.end());
	lsh.resize(unique(lsh.begin(),lsh.end())-lsh.begin());
	
	m=upper_bound(lsh.begin(),lsh.end(),m)-lsh.begin();
	rep(i,n) a[i].l=upper_bound(lsh.begin(),lsh.end(),a[i].l)-lsh.begin();
	rep(i,n) a[i].r=upper_bound(lsh.begin(),lsh.end(),a[i].r)-lsh.begin();
	
	build(1,1,lsh.size());
	modify(1,1,lsh.size(),m,0);
	
	sort(a+1,a+n+1,cmp);
	rep(i,n)
	{
		if(a[i].l<=a[i].r)
		{
			int t=query(1,1,lsh.size(),1,a[i].l)+1;
			modify(1,1,lsh.size(),a[i].r,t);
		}
		else
		{
			int t=query(1,1,lsh.size(),1,a[i].r)+1;
			modify(1,1,lsh.size(),a[i].r,t);
			update(1,1,lsh.size(),a[i].r+1,a[i].l,1);
		}
	}
	
	printf("%d\n",mx[1]);
}

int main()
{
	solve();
	return 0;
}