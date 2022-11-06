#include<bits/stdc++.h>
using namespace std;
#define ll long long
namespace io{
	const int l=1<<20;
	char buf[l],*s,*t;
	inline char gc(){
		if(s==t){
			t=(s=buf)+fread(buf,1,l,stdin);
			return s==t?EOF:*s++;
		}
		return *s++;
	}
	char c;
	template<class IT>inline void gi(IT &x){
		x=0;c=gc();while(c<'0'||c>'9')c=gc();
		while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^'0');c=gc();}
	}
};
using io::gi;
struct qwq{
	int a,b;
	inline bool operator<(const qwq &x)const{
		return a<x.a;
	}
};
template<class IT>inline void cmin(IT &a,IT b){if(b<a)a=b;}
template<class IT>inline void cmax(IT &a,IT b){if(a<b)a=b;}
const ll inf=1000000000000000000ll;
const int N=200005;
ll tre[N<<2],tag[N<<2];int p[N];
#define mid ((l+r)>>1)
#define ls o<<1,l,mid
#define rs o<<1|1,mid+1,r
inline void pt(int o,ll x){tre[o]+=x;tag[o]+=x;}
inline void pd(int o){
	if(tag[o]){
		pt(o<<1  ,tag[o]);
		pt(o<<1|1,tag[o]);
		tag[o]=0ll;
	}
}
void build(int o,int l,int r){
	if(l==r){scanf("%I64d",&tre[o]);return;}
	build(ls);build(rs);
	tre[o]=min(tre[o<<1],tre[o<<1|1]);
}
void upd(int o,int l,int r,int x){
	if(l==r){tre[o]=inf;return;}
	pd(o);
	if(x<=mid)upd(ls,x);else upd(rs,x);
	tre[o]=min(tre[o<<1],tre[o<<1|1]);
}
void add(int o,int l,int r,int L,ll v){
	if(L<=l){pt(o,v);return;}
	pd(o);
	if(L<=mid)add(ls,L,v);add(rs,L,v);
	tre[o]=min(tre[o<<1],tre[o<<1|1]);
}
int query(int o,int l,int r){
	if(l==r)return l;
	pd(o);
	if(tre[o<<1|1])return query(ls);
	return query(rs);
}
int main(){
	int n,d,i;
	scanf("%d",&n);
	build(1,1,n);
	for(i=1;i<=n;++i){
		p[d=query(1,1,n)]=i;
//		printf("id of %d is %d\n",i,d);
		upd(1,1,n,d);
		add(1,1,n,d,-i);
//		dbg(1,1,n);printf("\n");
	}
	for(i=1;i<=n;++i)printf("%d ",p[i]);
	return 0;
}