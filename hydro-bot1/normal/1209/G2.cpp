// Hydro submission #62c6cec48672efa577c017c1@1657196229472
#include<bits/stdc++.h>
namespace imzzy{
	typedef long long ll;
	typedef std::pair<int,int> pii;
	#define rgi int
	#define endl '\n'
	#define fi first
	#define se second
	using std::cerr;
	class fastin{public:int c,f;
	inline fastin&operator>>(char&x){return x=getchar(),*this;}
	template<typename T>inline fastin&operator>>(T&x){x=0;
	while(!isdigit(c))f|=(c=='-'),c=getchar();
	while(isdigit(c))x=x*10+(c^'0'),c=getchar();
	if(f)x=-x,f=0;return *this;}fastin(){c=f=0;}
	}fin;
	class fastout{public:template<typename T>inline void write(T x){
	if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar(x%10+'0');}
	inline fastout&operator<<(char c){return putchar(c),*this;}
	template<typename T>inline fastout&operator<<(T x){return write(x),*this;}
	}fout;
}using namespace imzzy;
const ll mod=998244353,G=3,iG=(mod+1)/G,i2=(mod+1)/2,inf=1e9+7;
const int maxn=200004,maxm=754;

struct DATA{int sum,mxl,mxr,mxv,mnd;};
inline DATA merge(DATA x,DATA y) {
	DATA res;
	res.mnd=std::min(x.mnd,y.mnd),res.mxv=std::max(x.mxv,y.mxv);
	if(x.mnd==y.mnd) res.sum=x.sum+y.sum+std::max(x.mxr,y.mxl),res.mxl=x.mxl,res.mxr=y.mxr;
	if(x.mnd<y.mnd) res.sum=x.sum,res.mxl=x.mxl,res.mxr=std::max(x.mxr,y.mxv);
	if(x.mnd>y.mnd) res.sum=y.sum,res.mxr=y.mxr,res.mxl=std::max(y.mxl,x.mxv);
	return res;
}
class segment_tree{
#define mid ((l+r)>>1)
private:
	int siz,ql,qr,qp,qv;
	int tag[maxn<<2];
	DATA val[maxn<<2];
	inline void pushdown(int p) {
		if(!tag[p]) return;
		tag[p<<1]+=tag[p],tag[p<<1|1]+=tag[p];
		val[p<<1].mnd+=tag[p],val[p<<1|1].mnd+=tag[p];
		tag[p]=0;
	}
	void update1(int p,int l,int r) {
		if(l>=ql&&r<=qr) return tag[p]+=qv,val[p].mnd+=qv,void();
		pushdown(p);
		if(ql<=mid) update1(p<<1,l,mid);
		if(qr>mid) update1(p<<1|1,mid+1,r);
		val[p]=merge(val[p<<1],val[p<<1|1]);
	}
	void update2(int p,int l,int r) {
		if(l==r) return val[p].mxl=val[p].mxv=qv,void();
		pushdown(p);
		if(qp<=mid) update2(p<<1,l,mid); else update2(p<<1|1,mid+1,r);
		val[p]=merge(val[p<<1],val[p<<1|1]);
	}
public:
	inline void build(int n) {siz=n;}
	inline void add(int l,int r,int v) {/*cerr<<"add "<<l<<' '<<r<<' '<<v<<endl; */if(l<=r) ql=l,qr=r,qv=v,update1(1,1,siz);}
	inline void modify(int p,int v) {/*cerr<<"modify "<<p<<' '<<v<<endl; */qp=p,qv=v,update2(1,1,siz);}
	inline int query() {return val[1].sum+val[1].mxl;}
#undef mid
} sgt;

std::set<int> p[maxn];
int n,q,a[maxn];
inline void add(int x) {
	if(!p[x].size()) return;
	int l=*p[x].begin(),r=*p[x].rbegin(),v=p[x].size();
	sgt.add(l,r-1,1),sgt.modify(l,v);
}
inline void del(int x) {
	if(!p[x].size()) return;
	int l=*p[x].begin(),r=*p[x].rbegin(),v=p[x].size();
	sgt.add(l,r-1,-1),sgt.modify(l,0);
}
signed main() {
	fin>>n>>q;
	for(rgi i=1;i<=n;++i) fin>>a[i],p[a[i]].insert(i);
	sgt.build(n);
	for(rgi i=0;i<maxn;++i) if(p[i].size()) add(i);
	fout<<n-sgt.query()<<endl;
	for(int x,y;q;--q) {
		fin>>x>>y;
		del(a[x]),del(y);
		p[a[x]].erase(x),std::swap(a[x],y),p[a[x]].insert(x);
		add(a[x]),add(y);
		fout<<n-sgt.query()<<endl;
	}
	return 0;
}