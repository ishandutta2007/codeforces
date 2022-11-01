#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

int n,m;
int a[1000005],b[1000005];

long long ans;

vector<int> lsh;

int mi[4000005],tag[4000005];
void build(int x,int l,int r)
{
	mi[x]=tag[x]=0;
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
		mi[x]+=v;tag[x]+=v;
		return;
	}
	
	int mid=(l+r)/2;
	if(L<=mid) update(x*2,l,mid,L,R,v);
	if(R>mid) update(x*2+1,mid+1,r,L,R,v);
	
	mi[x]=min(mi[x*2],mi[x*2+1]);
	mi[x]+=tag[x];
}

int c[2000005];
void add(int x,int y)
{
	while(x) c[x]+=y,x-=(x&-x);
}
int query(int x)
{
	int s=0;
	while(x<=lsh.size()) s+=c[x],x+=(x&-x);
	return s;
}

struct opt
{
	int h,l,r,v;
}d[2000005];
bool cmp(opt x,opt y)
{
	return x.h<y.h;
}

void solve()
{
	int i;
	scanf("%d%d",&n,&m);
	rep(i,n) scanf("%d",&a[i]);
	rep(i,m) scanf("%d",&b[i]);
	
	lsh.clear();
	rep(i,n) lsh.push_back(a[i]);
	rep(i,m) lsh.push_back(b[i]);
	
	sort(lsh.begin(),lsh.end());
	lsh.resize(unique(lsh.begin(),lsh.end())-lsh.begin());
	
	rep(i,n) a[i]=upper_bound(lsh.begin(),lsh.end(),a[i])-lsh.begin();
	rep(i,m) b[i]=upper_bound(lsh.begin(),lsh.end(),b[i])-lsh.begin();
	rep(i,n) d[i]=(opt){a[i],i,n,-1},d[i+n]=(opt){a[i]+1,0,i-1,1};
	
	ans=0;
	rep(i,lsh.size()) c[i]=0;
	rep(i,n) ans+=query(a[i]+1),add(a[i],1);
	
	build(1,0,n);
	rep(i,n) update(1,0,n,i,n,1);
	sort(d+1,d+n+n+1,cmp);
	sort(b+1,b+m+1);
	
	int p=1;
	rep(i,m)
	{
		while(p<=n+n&&d[p].h<=b[i])
		{
			update(1,0,n,d[p].l,d[p].r,d[p].v);
			p++;
		}
		ans+=mi[1];
	}
	
	printf("%lld\n",ans);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}