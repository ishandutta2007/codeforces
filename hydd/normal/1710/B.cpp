#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int INF=1ll<<60;
typedef long long ll;
typedef pair<ll,ll> pii;
int T,n,m,cnt,val[1100000];
int x[1100000],p[1100000];
ll a[1100000],b[1100000],c[1100000];
map<int,pii> d;
struct ST{
	ll *val,tree[4100000];
	void init(ll *v){ val=v; build(1,1,cnt);}
	void build(int now,int l,int r){
		if (l==r){ tree[now]=val[l]; return;}
		int mid=(l+r)>>1;
		build(now<<1,l,mid); build(now<<1|1,mid+1,r);
		tree[now]=max(tree[now<<1],tree[now<<1|1]);
	}
	ll query(int now,int l,int r,int x,int y){
		if (l>r||x>y) return -INF;
		if (x<=l&&r<=y) return tree[now];
		ll res=-INF; int mid=(l+r)>>1;
		if (x<=mid) res=max(res,query(now<<1,l,mid,x,y));
		if (y>mid) res=max(res,query(now<<1|1,mid+1,r,x,y));
		return res;
	}
} A,B,C;
void addu(int l,int r,int i){
	int v=max(0ll,p[i]-abs(x[i]-l));
	d[l].first+=v-l; d[r+1].first-=v-l;
	d[l].second++; d[r+1].second--; 
}
void addd(int l,int r,int i){
	int v=max(0ll,p[i]-abs(x[i]-l));
	d[l].first+=v+l; d[r+1].first-=v+l;
	d[l].second--; d[r+1].second++;
}
ll queryu(int l,int r,int i){
	int ll=l;
	l=lower_bound(val+1,val+cnt+1,l)-val;
	r=upper_bound(val+1,val+cnt+1,r)-val-1;
	if (l>r) return 0;
	int v=max(0ll,p[i]-abs(x[i]-ll));
	return B.query(1,1,cnt,l,r)-(v-ll);
}
ll queryd(int l,int r,int i){
	int ll=l;
	l=lower_bound(val+1,val+cnt+1,l)-val;
	r=upper_bound(val+1,val+cnt+1,r)-val-1;
	if (l>r) return 0;
	int v=max(0ll,p[i]-abs(x[i]-ll));
	return C.query(1,1,cnt,l,r)-(v+ll);
}
ll query0(int l,int r){
	l=lower_bound(val+1,val+cnt+1,l)-val;
	r=upper_bound(val+1,val+cnt+1,r)-val-1;
	if (l>r) return 0;
	return A.query(1,1,cnt,l,r);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin>>T;
	while (T--){
		cin>>n>>m; d.clear();
		for (int i=1;i<=n;i++){
			cin>>x[i]>>p[i];
			addu(x[i]-p[i],x[i]-1,i);
			addd(x[i],x[i]+p[i],i);
		}

		int i=0; ll d1=0,d2=0;
		for (auto v:d){
			d1+=v.second.first; d2+=v.second.second;
			i++; val[i]=v.first;
			a[i]=d1+d2*v.first;
			b[i]=d1+(d2-1)*v.first;
			c[i]=d1+(d2+1)*v.first;
		}
		cnt=i;

		A.init(a); B.init(b); C.init(c);
		for (int i=1;i<=n;i++){
			ll val=query0(-INF,x[i]-p[i]-1);
			val=max(val,queryu(x[i]-p[i],x[i]-1,i));
			val=max(val,queryd(x[i],x[i]+p[i],i));
			val=max(val,query0(x[i]+p[i]+1,INF));
			if (val>m) putchar('0'); else putchar('1');
		}
		putchar('\n');
	}
	return 0;
}