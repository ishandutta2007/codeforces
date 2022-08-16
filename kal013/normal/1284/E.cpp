/*/ Author: kal013 /*/
//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define int long long
#define ll long long
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef vector<pii> vpi;
typedef priority_queue<ppi> max_heap_ppi;
#define For(i,n) for(int i=0;i<(int)n;i++)
#define Rev(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,n) for(int i=1;i<=n;++i)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define d0(x) cout<<(x)<<" "
#define d1(x) cout<<(x)<<endl
#define d2(x,y) cout<<(x)<<" "<<(y)<<endl
#define d3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
#define d4(a,b,c,d) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<endl
#define d5(a,b,c,d,e) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<" "<<(e)<<endl
#define d6(a,b,c,d,e,f) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<" "<<(e)<<" "<<(f)<<endl
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define all(v) (v).begin(),(v).end()
#define sz(v) (v).size()
 
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ ";
    for(auto v : V) os << v << " ";
    return os << "]";
}
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") ";
    return os<<"}";
}
#define cerr cout
#define TRACE
#ifdef TRACE
    #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " : " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');
        cerr.write(names, comma - names) << " : " << arg1<<" | ";
        __f(comma+1, args...);
    }
#else
    #define trace(...)
#endif
const int maxn=1e6+100;
const int MaxN=1e5+100;
const int mod=1e9+7;
#ifdef int
const int INF=1e16;
#else
const int INF=1e9;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp> 
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
// erase,insert same as normal set
#endif
 
inline int fast_expo(int base,int power,int modulo=mod){
    base%=modulo;
    if (base<0) base+=modulo;
    ll x=base,cnt=power,ans=1;
    while(cnt){
        if (cnt&1) ans=(ans*x)%modulo;
        x=(x*x)%modulo;
        cnt>>=1;
    }
    // int tmp=ans;
    return ans;
}
inline int inv(int base,int modulo=mod){
    return fast_expo(base,modulo-2,modulo);
}
 
 
/*/-----------------------------Code begins----------------------------------/*/
 
 #if defined(WIN32)
// no getchar_unlocked on Windows so call _getchar_nolock
inline int getchar_unlocked() { return _getchar_nolock(); }
#elif defined(_WIN32)
inline int getchar_unlocked() {return _getchar_nolock();}
#endif
// inline int getchar_unlocked() {return _getchar_nolock();}
inline ll read(){
	ll n= 0;
	bool neg = 0;
	char c = getchar_unlocked();
	if(c == '-')
		neg = 1;
	while(!('0'<=c && c <= '9')) {  c = getchar_unlocked() ; 
		if(c == '-')
			neg = 1;
	}  
	while('0' <= c && c <= '9'){n = n*10+c-'0';
	c = getchar_unlocked();}
	if(neg)
		n *= -1;
	return n;
}
 
 
inline bool lt(ll a,ll b){
	return a<b;
}
inline bool gt(ll a,ll b){
	return a>b;
}
inline bool eq(ll a,ll b){
	return a==b;
}
inline bool ge(ll a,ll b){
	return a>=b;
}
inline bool le(ll a,ll b){
	return a<=b;
}
struct pt{
		#define F1 ll
		#define F2 ll
		#define F3 ll
		F1 x,y; pt() {};
		pt(F1 _x): x(_x),y((F1)(0)){};
		pt(F1 _x, F1 _y): x(_x),y(_y){};
		pt operator + (const pt &p) const {return pt(x+p.x,y+p.y);}
		pt operator - (const pt &p) const {return pt(x-p.x,y-p.y);}
		F2 operator * (const pt &p) const {return x*p.x+y*p.y;}
		F2 operator ^ (const pt &p) const {return x*p.y-y*p.x;}
		pt operator * (const F3 c) const {return pt(x*c,y*c);}
		pt operator / (const F3 c) const {return pt(x/c,y/c);}
		pt operator += (const pt &p) {this->x+=p.x;this->y+=p.y;return *this;}
		pt operator -= (const pt &p) {this->x-=p.x;this->y-=p.y;return *this;}
		pt operator *= (const F3 c) {this->x*=c;this->y*=c; return *this;}
		pt operator /= (const F3 c) {this->x/=c;this->y/=c;return *this;}
		// COMPARES y first
		bool operator < (const pt &p) const{ return lt(y,p.y)||(eq(y,p.y)&&lt(x,p.x));}
		inline bool operator == (const pt &r) const {return (eq(y,r.y) && eq(x,r.x));}
		bool operator > (const pt &p) const{ return p<pt(x,y);}
		inline bool operator <= (const pt &r) const {return !(*this>r);}
		inline bool operator >= (const pt &r) const {return !(*this<r);}
		inline bool operator != (const pt &r) const {return !(*this==r);}
		friend istream& operator >> (istream& is, pt& p){return is>>p.x>>p.y;}
		friend ostream& operator << (ostream& os, const pt& p) {return os<<"("<<p.x<<","<<p.y<<")";}
};
 
 
pt Xy[maxn];
 
bool Up(pt x){
	return (x.y>0 || (x.y==0 && x.x>0));
}
 
bool cmp(pt z,pt w){
	bool upa=Up(z);
	bool upb=Up(w);
	if (upa!=upb){
		return upa;
	}
	return ((z^w)>0);
}
 
#define M ((s+e)/2)
 
 
struct Node{
	int sum=0,cnt=0;
	Node():sum(0),cnt(0){};
	Node(int x,int y):sum(x),cnt(y){};
 
	Node operator + (const Node& n) const{
		return Node{n.sum+sum,n.cnt+cnt};
	}
	Node operator - (const Node& n) const{
		return Node{sum-n.sum,cnt-n.cnt};
	}
	Node operator += (const Node& n){
		sum+=n.sum;cnt+=n.cnt; return *this;
	}
	Node operator -= (const Node& n){
		sum-=n.sum;cnt-=n.cnt; return *this;
	}
	inline bool operator == (const Node &r) const {return ((sum==r.sum) && (cnt==r.cnt));}
	inline bool operator != (const Node &r) const {return ((sum!=r.sum) || (cnt!=r.cnt));}
 
 
	friend ostream& operator << (ostream& os, const Node& p) {return os<<"("<<p.sum<<","<<p.cnt<<")";}
};
 
 
 
 struct bit{
 	vector<Node> seg;
 	int n;
//  	Node tot;
 	bit() {};
 	void clear() {n=0;seg.clear();}
 	void build(int N){
 		n=N;
 		seg.assign(n+1,{0,0});
//  		tot={0,0};
 	}
 	inline void update(int p,Node v){
 		++p;
//  		tot+=v;
 		while(p<=n){
 			seg[p]+=v;
 			p+=(p&(-p));
 		}
 	}
 	inline void update(int p,int v) {
		update(p,Node{p*v,v});
	}
 	Node sum(int l){
 		++l;
//  		if (l==n) return tot;
 		Node ans;
 		while(l){
 			ans+=seg[l];
 			l-=(l&(-l));
 		}
 		return ans;
 	}
 	Node query(int l,int r){
 		if (l==0) return sum(r);
 		return sum(r)-sum(l-1);
 	}
 };
 
struct segtree{
	vector<Node> seg; /*O based */  int n;
	segtree() {};
	void clear(){ n=0; seg.clear(); }
	void build(vector<Node> val){ n=val.size();seg.resize(2*n);
		for(int i=n;i<2*n;++i){ seg[i]=val[i-n]; }
		for(int i=n-1;i>0;--i) 
			seg[i]=seg[i<<1]+seg[(i<<1)|1];}
	void update(int p,Node v){ 
		p+=n; 
		seg[p]+=v;
		for(int i=p;i>1;i>>=1)seg[i>>1]=seg[i]+seg[i^1];
	}
 
	void update(int p,int v) {
		update(p,Node{p*v,v});
	}
	Node query(int l,int r){
		/*assert(l<=r);*/ Node ans={0,0};
		for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
			if(l&1)ans+=seg[l++]; if(r&1) ans+=seg[--r];
		} return ans;
} 
 
};
bit F,P;
segtree G,Q;
inline void build(int node,int s,int e){
	F.clear();
	F.build(e+1);
	P.clear();
	P.build(e+1);
}
void update(bool typ,int node,int s,int e,int l,int v){
	if (typ) F.update(l,v);
	else P.update(l,v);
}
Node query(bool typ,int node,int s,int e,int l,int r){
	if (r<l) return {0,0};
	return (typ)?F.query(l,r):P.query(l,r);
}
 
 
inline int getF(int j,int fj,int n,int lo){
	if (j>=n || lo>=n) return 0; 
	Node q1=query(false,1,0,n,0,fj); // pk<=fj
	int c1=max(fj-lo,0ll); // fj>k
	Node q2=query(false,1,0,n,0,j); //pk<j+1
	int res=(q1.cnt-c1)*fj+(c1*(c1+1))/2+c1*(lo-1); 
	res-=q1.sum-q2.sum;
	res-=q2.cnt*(j+1);
	return res;
}
inline int getP(int k,int pk,int n,int lo,int hi){
	if (lo>hi) return 0;
	Node q1=query(true,1,0,n,pk,n); //pk<=fj;
	Node q2=query(true,1,0,n,k+1,n); // fj>k
	int c1=max(hi-pk+1,0ll)-max(lo-pk,0ll); // pk<j+1
	int res=(q1.cnt-c1)*pk+(c1*(c1+1))/2+(c1*(hi-c1+1));
	res-=q1.sum-q2.sum;
	res-=q2.cnt*k;
	return -res;
}
int nx[MaxN],prv[MaxN];
inline int sol(vector<pt> A){
	sort(all(A),cmp);
	int n=A.size();
 
	// vi nx(n);
	// vi prv(n);
	build(1,0,n);
	int r=0;
	For(i,n){
		r=max(r,i+1);
		while (r<n && ((A[i]^A[r])>0)) ++r;
		nx[i]=r;
	}
	r=n-1;
	for(int i=n-1;i>=0;--i){
		r=min(r,i-1);
		while(r>=0 && ((A[r]^A[i])>=0)) --r;
		prv[i]=r+1;
	}
	int kol=0;
	int res=0;
	r=1;
	int l=n;
	while(l>nx[0]){
		--l; update(false,1,0,n,prv[l],1);
	}
	for(int i=0;i<A.size();++i){
		if (nx[i]==n) {break;}
		while(r<nx[i]){
			res+=getF(r,nx[r],n,l);
			update(true,1,0,n,nx[r],1);
			++r;
		}
		while(l<nx[i]){
			res-=getP(l,prv[l],n,i+1,r-1);
			update(false,1,0,n,prv[l],-1);
			++l;
		}
 
		kol+=res;
		if (i!=n-1){
			res-=getF(i+1,nx[i+1],n,l);
			update(true,1,0,n,nx[i+1],-1);
			r=max(i+2,r);
		}
	}
	return kol;
}
 
void solve(){
	int n;
	n=read();
// 	cin>>n;
	Rep(i,n){ Xy[i].x=read();Xy[i].y=read();
// 		cin>>Xy[i];
	}
 
	ll res=0;
	Rep(i,n){
		vector<pt> V;
		Rep(j,n) if (i!=j) V.pb(Xy[j]-Xy[i]);
		res+=sol(V);
 
 
	}
	cout<<res<<endl;
}
signed main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Uncomment codechef for large input files. Doesn't work on codeforces.
   
    fio;
    int t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
}