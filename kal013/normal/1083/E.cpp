/*/ Author: kal013 /*/
//#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <cstdio>
using namespace std;
#define int long long
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
#define ll long long

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
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
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


inline bool lt(ll a,ll b) {return a<b;}
inline bool gt(ll a,ll b) {return a>b;}
inline bool le(ll a,ll b) {return a<=b;}
inline bool ge(ll a,ll b) {return a>=b;}
inline bool eq(ll a,ll b) {return a==b;}
struct pt{
    #define F1 ll
    #define F2 ll
    #define F3 ll
    F1 x,y;
 
    pt() {};
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

inline int frac(int a,int b,int c,int d){
    // returns sign of a/b-c/d
    // a>=0,b>0,c>=0,d>0
    if (a/b>c/d) return 1;
    if (a/b<c/d) return -1;
    a%=b;
    c%=d;
    if (a==0){
    	return (c==0)?0:-1;
    }
    return (c==0)?1:frac(d,c,b,a);
}
inline int frac2(int a,int b,int c,int d){
    // returns sign of a*d-b*c;
    if (d==0){
        if (b==0 || c==0) return 0;
        return ((b<0)==(c<0))?-1:1;
    }
    if (b==0){
        if (a==0) return 0;
        return ((a<0)==(d<0))?1:-1;
    }
    if (b<0) {
        c*=-1;
        b*=-1;
    }
    if (d<0){
        a*=-1;
        d*=-1;
    }
    if ((a<0)!=(c<0)) return (a>0)?1:-1;
	return frac(abs(a),b,abs(c),d)*((a<0)?-1:1);
}
// inline int frac(int a,int b,int c,int d){
//     // returns sign of a/b-c/d
//     // a>=0,b>0,c>=0,d>0
//     if (a/b>c/d) return 1;
//     if (a/b<c/d) return -1;
//     a%=b;
//     c%=d;
//     if (a==0){
//         if (c==0) return 0;
//         return -1;
//     }
//     if (c==0) return 1;
//     return frac(d,c,b,a);
// }
// inline int frac2(int a,int b,int c,int d){
//     // returns sign of a*d-b*c;
//     if (d==0){
//         if (b==0 || c==0) return 0;
//         if ((b<0)==(c<0)) return -1;
//         return 1;
//     }
//     if (b==0){
//         if (a==0) return 0;
//         if ((a<0)==(d<0)) return 1;
//         return -1;
//     }
//     if (b<0) {
//         c*=-1;
//         b*=-1;
//     }
//     if (d<0){
//         a*=-1;
//         d*=-1;
//     }
//     if (a<0 && c>0) return -1;
//     if (a>0 && c<0) return 1;
//     if (a<0 && c<0) return -frac(-a,b,-c,d);
//     return frac(a,b,c,d);
// }

inline bool cmp_x(pt a,pt b){
    return (lt(a.x,b.x) || (eq(a.x,b.x) && lt(a.y,b.y)));
}
inline int ccw(pt a,pt b,pt c){
    // checks whether b to c is ccw wrt a
    pt B=b-a,C=c-a;
    return frac2(B.x,B.y,C.x,C.y); // for overflow
    // F2 d=((b-a)^(c-a));
    // if (d==0) return 0;
    // if (d<0) return -1;
    // return 1;
}
// const ll INF=1e18;
struct convex_hull{
    vector<pt> down;
    // vector<pt> up;
    int n=0;
    convex_hull(): n(0ll) {};
    convex_hull(vector<pt> points,bool issort=false){
        down=points;
        if (!issort) sort(all(down),cmp_x);
        n=down.size();
        // up.resize(n);
        // For(i,n) up[i]=down[i];
        build();
    }
    convex_hull operator = (const convex_hull& a){
        down=a.down;
        n=down.size();
        // up=a.up;
        return *this;
    }
    void add(pt x){
        // increasing x required
    	int m=down.size();
    	while(m>=2 && ccw(down[m-2],down[m-1],x)<=0) --m;
    	down.resize(m);down.pb(x);
    	n=down.size();
    }
    void build(){
        int m=0;
        if (n<=1){
        	return;
        }
        For(i,n){
            while (m>1 && ccw(down[m-2],down[m-1],down[i])<=0) --m;
            down[m++]=down[i];
        }
        down.resize(m);
        // m=0; //convert convex hull trick to convex hull
        // For(i,n){
        //     while(m>1 && ccw(up[m-2],up[m-1],up[i])>=0) --m;
        //     up[m++]=up[i];
        // }
        // up.resize(m);
        n=m;
    }
    void clear(){
        down.clear();
        // up.clear();
        n=0;
    }
    convex_hull merger(const convex_hull& a) const {
        vector<pt> points(a.down.size()+down.size());
        merge(down.begin(),down.end(),a.down.begin(),a.down.end(),points.begin());
        convex_hull b(points,true);
        return b;
    }
    // vector<pt> All(){
    // 	vector<pt> cu=down;
    // 	for(int i=(int)up.size()-2;i>0;--i) cu.pb(up[i]);
    // 	return cu;
    // }
    ll min(ll x){
        if (n==0) return INF;
        int low=0,high=n-1;
        pt line={x,1};
        while (low<high){
            int mid=(low+high)/2;
            if (down[mid]*line<down[mid+1]*line){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return down[low]*line;
    }
    friend ostream& operator << (ostream& os, const convex_hull& p) {return os<<"{"<<p.n<<" : "<<p.down<<"}";}
};


const ll is_query = -(1LL<<63);
struct Line {
    ll m, b;
    mutable function<const Line*()> succ;
    bool operator<(const Line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const Line* s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};
struct HullDynamic : public multiset<Line> { // will maintain upper hull for maximum
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;
        return frac2(x->b-y->b , y->b-z->b , y->m-x->m , z->m-y->m)>=0;
        // return (x->b - y->b)*(z->m - y->m) >= (y->b - z->b)*(y->m - x->m);
    }
    void insert_line(ll m, ll b) {
        auto y = insert({ m, b });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    ll eval(ll x) {
        auto l = *lower_bound((Line) { x, is_query });
        return l.m * x + l.b;
    }
};
pt B[maxn];
int a[maxn];
int idx[maxn];
bool cmp(int i,int j){
    return cmp_x(B[i],B[j]);
}

int dp[maxn];

inline char get() {
	static char buf[100000], *S=buf, *T=buf;
	if(S==T) {
		T = (S=buf) + fread(buf, 1, 100000, stdin);
		if(S==T) return EOF;
	}
	return *S++;
}
 
inline ll read() {
	static char c; ll x = 0;
	for(c=get();c<'0'||c>'9';c=get());
	for(;c>='0'&&c<='9';c=get()) x = x*10+c-'0';
	return x;
}


void solve(){
    int n;
    // cin>>n;
    n=read();
    Rep(i,n){
        B[i].x=read();
        B[i].y=read();
        a[i]=read();
        // cin>>B[i]>>a[i];
        idx[i]=i;
    }
    sort(idx+1,idx+n+1,cmp);
    dp[0]=0;
    // convex_hull U;
    // U.add(pt(0,0));
    HullDynamic U;
    U.insert_line(0,0);
    int ans=0;
    Rep(i,n){
        int k=idx[i];
        // int z=-U.min(B[k].y);
        int z=U.eval(B[k].y);
        dp[i]=B[k].x*B[k].y+z-a[k];
        ans=max(ans,dp[i]);
        U.insert_line(-B[k].x,dp[i]);
        // U.add(pt(B[k].x,-dp[i]));
        
    }
    cout<<ans<<endl;
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