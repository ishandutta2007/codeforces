#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define FOR(i,a,b) for(rgi i=a;i<=b;++i)
#define ROF(i,a,b) for(rgi i=a;i>=b;--i) 
#define log(a) cerr<<#a<<'='<<(a)<<" @ line "<<__LINE__<<endl
typedef long long ll;
using namespace std;
const int N=2000010;
int a[N],b[N],n,m,p[N],c[N],T;
struct segment_tree{
	int l,r,mn,tag;
}t[N<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
inline void push_up(int p){
	t[p].mn=min(t[ls(p)].mn,t[rs(p)].mn);
}
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r;
	t[p].mn=t[p].tag=0;
	if(l==r)return;
	rgi mid=l+r>>1;
	build(ls(p),l,mid),build(rs(p),mid+1,r),push_up(p);
}
inline void add_tag(int p,int v){
	t[p].mn+=v;
	t[p].tag+=v;
}
inline void push_down(int p){
	if(!t[p].tag)return;
	add_tag(ls(p),t[p].tag);
	add_tag(rs(p),t[p].tag);
	t[p].tag=0;
}
#define no_intersection (t[p].l>r||l>t[p].r)
#define is_subset (l<=t[p].l&&t[p].r<=r)
void upd(int p,int l,int r,int v){
	if(no_intersection)return;
	if(is_subset){
		add_tag(p,v);
		return;
	}
	push_down(p);
	upd(ls(p),l,r,v);
	upd(rs(p),l,r,v),push_up(p);
}
inline int query(int p,int l,int r){
	if(no_intersection)return INT_MAX;
	if(is_subset)return t[p].mn;
	push_down(p);
	return min(query(ls(p),l,r),query(rs(p),l,r));
}
ll ans;
signed main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m),ans=0;
		FOR(i,1,n)scanf("%d",a+i),p[i]=i,c[i]=a[i];
		FOR(i,1,m)scanf("%d",b+i);
		sort(b+1,b+m+1),sort(p+1,p+n+1,[&](int x,int y){return a[x]<a[y];});
		sort(a+1,a+n+1),build(1,1,n+1);
		FOR(i,1,n){
			c[i]=lower_bound(a+1,a+n+1,c[i])-a;
			ans+=query(1,c[i],c[i]);
			upd(1,1,c[i]-1,1);
		}
		build(1,1,n+1);
		FOR(i,1,n){
			upd(1,i+1,n+1,1);
		}
		int l1=1,l2=1;
		FOR(i,1,m){
			while(b[i]>=a[l1]&&l1<=n){
				upd(1,p[l1]+1,n+1,-1),l1++;
			}
			while(b[i]>a[l2]&&l2<=n){
				upd(1,1,p[l2],1),l2++;
			}
			ans+=query(1,1,n+1);
		}
		printf("%lld\n",ans);
	} 
	return 0;
}