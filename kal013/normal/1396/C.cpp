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
    const static long long N = (1'000'000'000'000'000'000);
    if (T < 0){
        os << '-';
        T *= -1;
    }

    unsigned long long b = T%N;
    T /= N;
    if (T == 0)
        return os << b ;
    unsigned long long a = T % N;
    T /= N;
    if (T == 0){
        os << a;
        __int128 mul = 10;
        int cnt = 0;
        while( mul*b < N && cnt < 17){
            os << '0';
            mul *= 10;
            ++cnt;
        }
        return os << b;
    }
    os << ((long long) T);
    
     __int128 mul = 10;
      int cnt = 0;
    while( mul*a < N && cnt < 17){
        os << '0';
        mul *= 10;
        ++cnt;
    }
    os << a;
    mul = 10;
    cnt = 0;
    while( mul*b < N && cnt < 17){
        os << '0';
        mul *= 10;
        ++cnt;
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



const ll is_query = -(1LL<<63);
struct Line {
	ll m, b;
	mutable function<const Line*()> succ;
	bool operator<(const Line& rhs) const {
		if (rhs.b != is_query) return m < rhs.m;
		const Line* s = succ(); if(!s)return 0;
		ll x = rhs.m; return b-s->b < (s->m -m)*x;}
}; // will maintain upper hull for maximum
struct HullDynamic : public multiset<Line> { 
	bool bad(iterator y) { auto z = next(y);
		if (y == begin()) { if (z == end()) return 0;
			return y->m == z->m && y->b <= z->b;
		} auto x = prev(y);
		if (z==end())return y->m==x->m && y->b <= x->b;
		// return frac2(x->b-y->b , y->b-z->b , y->m-x->m , z->m-y->m)>=0; //prevents overflow
		return ((__int128)(x->b - y->b))*(__int128)(z->m - y->m) >= ((__int128)(y->b - z->b))* (__int128)(y->m - x->m);
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
		return l.m * x + l.b; }
};


void solve(){
	ll n, r1, r2, r3, d;
	cin >> n >> r1 >> r2 >> r3 >> d;


	vector<ll> a(n);
	cin >> a;


	vector<ll> dp(n);
	dp[0] = min(r1 * a[0] + r3,  min(r2, r1 * (a[0] + 1)) + r1 + 2 * d);


	vector<ll> prf(n + 1);


	for(int i = 0; i < n; ++i){
		prf[i + 1] = min(r1 * a[i] + r3 + 3 * d, min(r2, r1 * (a[i] + 1)) + r1 + 3 * d);
	}
	for(int i = 1; i <= n; ++i){
		prf[i] += prf[i - 1];
	}

	ll mn = - 4 * d;
	// mn = min(mn, - 3 * d);
	// trace(mn);
	for(int i = 1; i < n; ++i){
		dp[i] = dp[i - 1] + r1 * a[i] + r3 + d;
		// dp[i] = min(dp[i], dp[i - 1] + min(r2, r1 * (a[i] + 1)) + r1 + 3 * d);
		dp[i] = min(dp[i], mn + prf[i + 1] + d);
		mn = min(mn, dp[i - 1] - prf[i] - 3 * d);
	}	
	ll ans = dp[n - 1];

	ll cc = a[n - 1] * r1 + r3;
	for(int i = n - 2; i >= 0; --i){
		cc += 2 * d + min(r1 * a[i] + r3, min(r2, r1 * (a[i] + 1)) + r1);
		if (i > 0){
			ans = min(ans, cc + dp[i - 1] + d);
		}
		else{
			ans = min(ans, cc);
		}
	}
	cout << ans << endl;
	// HullDynamic convex;
	// vector<ll> dp(n, -1);
	// dp[n - 1] = min(r1 * a[n - 1] + r3, r2 + r1 + 2 * d);

	// vector<ll> prf(n, 0);
	// for(int i = 0; i < n; ++i){
	// 	prf[i] = min(r1 * a[i] + min( 2 * r1, r3), r2 + r1);
	// }

	// for(int i = n - 2; i >= 0; --i){
	// 	prf[i] += prf[i + 1];
	// }

	// for(int i = n - 2; i >= 0; --i){
	// 	dp[i] = r1 * a[i] + r3 + dp[i + 1] + d;
		
	// 	dp[i] = min(dp[i], min(r2, (a[i] + 1)* r1) + r1 + 3 * d + dp[i + 1]);

		

	// 	dp[i] = min(dp[i], prf[i] + 2 * (n - 1 - i) * d -  prf[n - 1] + a[n - 1] * r1 + r3);
		
	// 	if (convex.size() == 0){
	// 		convex.insert_line(-i - 1, prf[i + 1] - dp[i + 1]);

	// 		continue;
	// 	}
	// 	ll eval = convex.eval(3 * d);
	// 	eval *= -1;

	// 	eval -= ( 3 * d) * i;
	// 	eval -= 2 * d;
	// 	eval += prf[i];

	// 	dp[i] = min(dp[i], eval);
	// 	convex.insert_line(-i - 1, prf[i + 1] - dp[i + 1]);
	// }
	// cout << dp[0]<< endl;

}
int main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Or use gp_hash_table<X,null_type>
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cout<<fixed<<setprecision(25);
    cerr<<fixed<<setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();
    int t=1;
    //cin >> t;
    while(t--) {
        solve();
    }
    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start); 
    
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     
}