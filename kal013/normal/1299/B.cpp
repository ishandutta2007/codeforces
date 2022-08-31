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


#define ld long long
#define PI acos(-1)
//atan2(y,x) slope of line (0,0)->(x,y) in radian (-PI,PI]
// to convert to degree multiply by 180/PI
// ld INF = 1e100;
// ld EPS = 1e-9;
inline bool eq(ld a,ld b){return a==b;}
inline bool lt(ld a,ld b){return a<b;}
inline bool gt(ld a,ld b){return a>b;}
inline bool le(ld a,ld b){return lt(a,b)||eq(a,b);}
inline bool ge(ld a,ld b){return gt(a,b)||eq(a,b);}
struct pt{
		#define F1 ld
		#define F2 ld
		#define F3 ld
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
ld dot(pt p,pt q) {return p.x*q.x+p.y*q.y;}
ld dist2(pt p, pt q) {return dot(p-q,p-q);}
ld dist(pt p,pt q) {return sqrt(dist2(p,q));}
ld norm2(pt p) {return dot(p,p);}
ld norm(pt p) {return sqrt(norm2(p));}
ld cross(pt p, pt q) { return p.x*q.y-p.y*q.x;}
int orient(pt a,pt b,pt c){ pt p=b-a,q=c-b; 
	double cr=cross(p,q); if(eq(cr,0))return 0;
	if(lt(cr,0))return 1; return -1;}


int x[maxn],y[maxn];
pt xy[maxn];
int N;
#define prv(i) ((i-1+N)%N) 
#define nxt(i) ((i+1)%N)
bool chk(int i,int j){
	if (dist2(xy[i],xy[nxt(i)])!=dist2(xy[j],xy[nxt(j)])) {
		return false;
	}
	ll z1=cross(xy[i]-xy[nxt(i)],xy[nxt(nxt(i))]-xy[nxt(i)]);
	ll z2=cross(xy[j]-xy[nxt(j)],xy[nxt(nxt(j))]-xy[nxt(j)]);
	return (z1==z2);
}

void solve(){
	int n;
	cin>>n;
	N=n;
	For(i,n){
		cin>>xy[i];
	}

	if (n&1){

		cout<<"NO"<<endl;
		return;
	}

	int k=n>>1;
	int p1=0,p2=k;

	bool same=1;
	for(int i=0;i<n;++i){
		if (!chk(p1,p2)) {same=0;break;}
		p1=nxt(p1);
		p2=nxt(p2);

	}
	if (same) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;

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