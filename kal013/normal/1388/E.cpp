/*/ Author: kal013 /*/
// #pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

template<class T> 
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

template<class T>
using min_heap = priority_queue<T,vector<T>,greater<T> >; 

struct custom_hash { // Credits: https://codeforces.com/blog/entry/62393
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    size_t operator()(pair<int64_t,int64_t> Y) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(Y.first * 31 + Y.second + FIXED_RANDOM);
    }
};

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ ";
    for(auto v : V) os << v << " ";
    return os << "]";
}
template<class T> istream& operator>>(istream &is, vector<T>& V) {
    for(auto &e : V)
        is >> e;
    return is;
}

#ifdef __SIZEOF_INT128__
ostream& operator << (ostream &os, __int128 T){
    const static long long N = (long long)(1e18);
    if (T < 0){
        os << '-';
        T *= -1;
    }
    unsigned long long a = T / N, b = T % N;
    if (a == 0)
        return os << b ;
    os << a;
    __int128 mul = 10;
    while( mul*b < N){
        os << '0';
        mul *= 10;
    }
    return os << b;
}
istream& operator >> (istream& is, __int128& T){
    string U;
    is >> U;
    T = 0;
    size_t pos = 0;
    int mul = 1;
    if (U[pos] == '-'){
        ++pos;
        mul *= -1;
    }
    for(; pos < U.size(); ++pos){
        T *= 10;
        T += (U[pos] - '0');
    }
    T *= mul;

    return is;
}
#endif
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class T> ostream& operator<<(ostream &os, unordered_set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class T> ostream& operator << (ostream& os, multiset<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class T> ostream& operator<<(ostream &os, ordered_set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.first<<":"<<m.second<<") ";
    return os<<"}";
}
template<class L, class R, class chash = std::hash<R>> ostream& operator<<(ostream &os, unordered_map<L,R,chash> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.first<<":"<<m.second<<") ";
    return os<<"}";
}
template<class L, class R, class chash = std::hash<R> > ostream& operator<<(ostream &os, gp_hash_table<L,R,chash> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.first<<":"<<m.second<<") ";
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
    #define trace(...) 1
#endif

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline int64_t random_long(long long l,long long r){
    uniform_int_distribution<int64_t> generator(l,r);
    return generator(rng);
}
inline int64_t random_long(){
    uniform_int_distribution<int64_t> generator(LLONG_MIN,LLONG_MAX);
    return generator(rng);
}


/*/---------------------------Defines----------------------/*/
typedef vector<int> vi;
typedef pair<int,int> pii;

#define For(i,n) for(int i = 0; i < (int) n; ++i)
#define Rep(i,n) for(int i = 1; i <= (int) n; ++i)
#define ll long long
#define F first
#define S second
#define pb push_back
#define endl "\n"
#define all(v) (v).begin(),(v).end()
/*/-----------------------Modular Arithmetic---------------/*/

const int mod=1e9+7;

/*/-----------------------------Code begins----------------------------------/*/


#define ld double
#define PI acos(-1)
//atan2(y,x) slope of line (0,0)->(x,y) in radian (-PI,PI]
// to convert to degree multiply by 180/PI
ld INF = 1e100;
ld EPS = 1e-9;
inline bool eq(ld a,ld b){return fabs(a-b)<EPS;}
inline bool lt(ld a,ld b){return a+EPS<b;}
inline bool gt(ld a,ld b){return a>b+EPS;}
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


inline bool cmp_x(pt a,pt b){
	return (lt(a.x,b.x) || (eq(a.x,b.x) && lt(a.y,b.y)));
}
inline int ccw(pt a,pt b,pt c){
	F2 d=((b-a)^(c-a));
	if (d==0) return 0;   if (d<0) return -1;
	return 1;
}
// const ll INF=1e18;
struct convex_hull{
	vector<pt> down; // vector<pt> up;
	int n=0;
	convex_hull(): n(0ll) {};
	convex_hull(vector<pt> points,bool issort=false){
		down=points;
		if(!issort)sort(all(down),cmp_x);n=down.size();
		// up.resize(n);  For(i,n) up[i]=down[i];
		build();
	}
	convex_hull operator = (const convex_hull& a){
		down=a.down;n=down.size(); // up=a.up;
		return *this;
	}
	void build(){
		int m=0; if (n<=1){ return; }
		For(i,n){ while (m>1 && ccw(down[m-2],down[m-1],down[i])<=0) --m;
			down[m++]=down[i]; }
		down.resize(m);
		// m=0; //convert cht to convex hull
		// For(i,n){ while(m>1 && ccw(up[m-2],up[m-1],up[i])>=0) --m;
		//	 up[m++]=up[i]; }
		// up.resize(m);
		n=m;
	}
	void clear(){ down.clear();n=0;/*up.clear();*/ }
	convex_hull merger(const convex_hull& a) const {
		vector<pt> points(a.down.size()+down.size());
		merge(down.begin(),down.end(),a.down.begin(),a.down.end(),points.begin());
		convex_hull b(points,true); return b; }
	// vector<pt> All(){
	// 	vector<pt> cu=down; for(int i=(int)up.size()-2;i>0;--i) cu.pb(up[i]);
	// 	return cu; }
	ld min(ld x) const{
		if (n==0) return INF; int low=0,high=n-1;
		pt line={x,1};
		while (low<high){ int mid=(low+high)/2;
			if( lt(down[mid]*line,down[mid+1]*line))
				high=mid; 
			else low=mid+1;
		}
		 return down[low]*line; }
	friend ostream& operator<<(ostream& os,const convex_hull& p){return os<<"{"<<p.n<<" : "<<p.down<<"}";}
};




const int N = 2050;

int L[N], R[N], Y[N];



ld get_ans(ld slope, const convex_hull& Left, const convex_hull& Right){
	return (- Right.min(slope)) - (Left.min(slope));
}

ld get_ans(ld a, ld b, const convex_hull& Left, const convex_hull& Right){
	return get_ans((a / b), Left, Right);
}



void normalize(pair<long long, long long>& T){
	assert(T.second >= 0);

	long long g = __gcd(abs(T.first), T.second);
	T.first /= g;
	T.second /= g;
}

inline bool lt(const pair<long long,long long>& A, const pair<long long, long long>& B){
	return A.first * B.second < A.second * B.first;
}

inline bool gt(const pair<long long,long long>& A, const pair<long long, long long>& B){
	return lt(B,A);
}

inline bool eq(const pair<long long,long long>& A, const pair<long long, long long>& B){
	return A.first * B.second == A.second * B.first;
}

struct range{
	pair<long long,long long> l,r;

	range(const pair<long long, long long>& a, const pair<long long ,long long>& b) {
		if (lt(a,b)){
			l = a;
			r = b;
		}
		else{
			l = b;
			r = a;
		}
		normalize(l);
		normalize(r);
	}

	bool operator < (const range& p) const {
		if (eq(l, p.l)){
			return lt(r,p.r);
		}
		return lt(l,p.l);
	}

	friend ostream& operator<<(ostream& os,const range& p){
		return os << "{"  << p.l << " " << p.r << "}";
	}
};

const ld INF2 = 1e9;

ld convert_pll(pair<long long,long long>& T){
	if (T.second == 0){
		assert(T.first != 0);
		if (T.first < 0){
			return - INF2;
		}
		else{
			return INF2;
		}
	}
	assert(T.second > 0);
	long double num = T.first;
	num /= T.second;

	return num;
}

ld get_range(range& A, const convex_hull& Left, const convex_hull& Right){
	ld l = convert_pll(A.l), r = convert_pll(A.r);
	ld ans = min(get_ans(l,Left,Right),get_ans(r,Left,Right));

	// if (lt(l,0) && gt(r,0)){
	// 	ans = min(ans,get_ans(0,Left,Right));		
	// }

	for(int i = 0; i <300; ++i){

		if (!gt(l,r))
			break;
		ld m1 = (l*2 + r) / 3, m2 = (l + 2*r) / 3;


		ld a1 = get_ans(m1,Left,Right), a2 = get_ans(m2, Left, Right);

	
		if (lt(a1,a2)){
			r = m2;
			ans = min(ans,a1);
		}
		else{
			l = m1;
			ans = min(ans, a2);
		}
	}

	return ans;
}

void solve(){
	int n;
	cin >> n;

	for(int i = 0; i < n; ++i){
		cin >> L[i] >> R[i] >>  Y[i];
	}

	vector<pt> m1, m2;

	for(int i = 0; i < n; ++i){
		m1.push_back({Y[i],L[i]});
		m2.push_back({-Y[i], -R[i]});
	}

	convex_hull Left(m1), Right(m2);



	vector<range> cur;

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if (Y[i] >= Y[j])
				continue;

			pair<long long,long long> p1, p2;
			p1 = {R[i] - L[j], Y[j] - Y[i]};
			p2 = {L[i] - R[j], Y[j] - Y[i]};

			cur.push_back({p1,p2});
		}
	}

	sort(all(cur));


	pair<long long,long long> low = {-1,0};

	ld ans = INF;
	for(auto e: cur){

		if (!gt(low,e.l)){
			range cu(low,e.l);
			ans = min(ans,get_range(cu,Left,Right));
		}
	

		if (gt(e.r,low)){
			low = e.r;
		}		

	}

	range cu(low,{1,0});
	ans = min(ans,get_range(cu,Left,Right));


	cout << ans << endl;



}
int main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Or use gp_hash_table<X,null_type>
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cout<<fixed<<setprecision(25);
    cerr<<fixed<<setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();
    int t=1;
    while(t--) {
        solve();
    }
    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start); 
    
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     
}