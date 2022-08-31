/*/ Author: kal013 /*/
// #pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

template<class T> 
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

template<class T>
using min_heap = priority_queue<T,vector<T>,greater<T> >; 

/*/---------------------------IO(Debugging)----------------------/*/
template<class T> istream& operator >> (istream &is, vector<T>& V) {
    for(auto &e : V)
        is >> e;
    return is;
}
#ifdef __SIZEOF_INT128__
ostream& operator << (ostream &os, __int128 const& value){
    static char buffer[64];
    int index = 0;
    __uint128_t T = (value < 0) ? (-(value + 1)) + __uint128_t(1) : value;
    if (value < 0) 
        os << '-';
    else if (T == 0)
        return os << '0';
    for(; T > 0; ++index){
        buffer[index] = static_cast<char>('0' + (T % 10));
        T /= 10;
    }    
    while(index > 0)
        os << buffer[--index];
    return os;
}
istream& operator >> (istream& is, __int128& T){
    static char buffer[64];
    is >> buffer;
    size_t len = strlen(buffer), index = 0;
    T = 0; int mul = 1;
    if (buffer[index] == '-')
        ++index, mul *= -1;
    for(; index < len; ++index)
        T = T * 10 + static_cast<int>(buffer[index] - '0');
    T *= mul;    
    return is;
}
#endif
template<typename CharT, typename Traits, typename T>
ostream& _containerprint(std::basic_ostream<CharT, Traits> &out, T const &val) {
    return (out << val << " ");
}
template<typename CharT, typename Traits, typename T1, typename T2>
ostream& _containerprint(std::basic_ostream<CharT, Traits> &out, pair<T1, T2> const &val) {
    return (out << "(" << val.first << "," << val.second << ") ");
}
template<typename CharT, typename Traits, template<typename, typename...> class TT, typename... Args>
ostream& operator << (std::basic_ostream<CharT, Traits> &out, TT<Args...> const &cont) {
    out << "[ ";
    for(auto&& elem : cont) _containerprint(out, elem);
    return (out << "]");
}
template<class L, class R> ostream& operator << (ostream& out, pair<L, R> const &val){
    return (out << "(" << val.first << "," << val.second << ") ");
}
template<typename L, size_t N> ostream& operator << (ostream& out, array<L, N> const &cont){
    out << "[ ";
    for(auto&& elem : cont) _containerprint(out, elem);
    return (out << "]");    
}
template<class T> ostream& operator<<(ostream &out, ordered_set<T> const& S){
    out << "{ ";
    for(const auto& s:S) out << s << " ";
    return (out << "}");
}
template<class L, class R, class chash = std::hash<L> > ostream& operator << (ostream &out, gp_hash_table<L, R, chash> const& M) {
    out << "{ ";
    for(const auto& m: M) out << "(" << m.first << ":" << m.second << ") ";
    return (out << "}");
}
template<class P, class Q = vector<P>, class R = less<P> > ostream& operator << (ostream& out, priority_queue<P, Q, R> const& M){
    static priority_queue<P, Q, R> U;
    U = M;
    out << "{ ";
    while(!U.empty())
        out << U.top() << " ", U.pop();
    return (out << "}");
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

/*/---------------------------RNG----------------------/*/
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int64_t random_long(long long l = LLONG_MIN,long long r = LLONG_MAX){
    uniform_int_distribution<int64_t> generator(l,r);
    return generator(rng);
}
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
    template<typename L, typename R>
    size_t operator()(pair<L,R> const& Y) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(Y.first * 31 + Y.second + FIXED_RANDOM);
    }
};

/*/---------------------------Defines----------------------/*/
#define ll long long
#define pb push_back
#define endl "\n"
#define all(v) (v).begin(),(v).end()
/*/-----------------------Modular Arithmetic---------------/*/
const int mod = 1e9 + 7;
struct fraction {
	// User: neal's implementation
    // CHECK_OVERFLOW64 = true can run up to 2.5 times slower (particularly on CF).
    static const bool CHECK_OVERFLOW64 = true;
 
    static const bool AUTO_REDUCE = true;
 
    static int cross_sign(const fraction &a, const fraction &b) {
        if (CHECK_OVERFLOW64) {
            long double double_value = (long double) a.numer * b.denom - (long double) b.numer * a.denom;
 
            if (abs(double_value) > 1e18)
                return double_value > 0 ? +1 : -1;
        }
 
        uint64_t uint64_value = (uint64_t) a.numer * b.denom - (uint64_t) b.numer * a.denom;
 
        if (uint64_value == 0)
            return 0;
 
        return uint64_value >> 63 ? -1 : +1;
    }
 
    int64_t numer, denom;
 
    fraction(int64_t n = 0, int64_t d = 1) : numer(n), denom(d) {
        check_denom();
 
        if (AUTO_REDUCE)
            reduce();
    }
 
    void check_denom() {
        assert(denom != 0);
 
        if (denom < 0) {
            numer = -numer;
            denom = -denom;
        }
    }
 
    void reduce() {
        int64_t g = __gcd(abs(numer), denom);
        numer /= g;
        denom /= g;
    }
 
    bool is_integer() const {
        return denom == 1;
    }
 
    friend fraction operator+(const fraction &a, const fraction &b) {
        return fraction(a.numer * b.denom + b.numer * a.denom, a.denom * b.denom);
    }
 
    friend fraction operator-(const fraction &a, const fraction &b) {
        return fraction(a.numer * b.denom - b.numer * a.denom, a.denom * b.denom);
    }
 
    friend fraction operator*(const fraction &a, const fraction &b) {
        return fraction(a.numer * b.numer, a.denom * b.denom);
    }
 
    friend fraction operator/(const fraction &a, const fraction &b) {
        return fraction(a.numer * b.denom, a.denom * b.numer);
    }
 
    fraction& operator+=(const fraction &other) { return *this = *this + other; }
    fraction& operator-=(const fraction &other) { return *this = *this - other; }
    fraction& operator*=(const fraction &other) { return *this = *this * other; }
    fraction& operator/=(const fraction &other) { return *this = *this / other; }
 
    fraction& operator++() { numer += denom; return *this; }
    fraction& operator--() { numer -= denom; return *this; }
 
    fraction operator++(int) { fraction before = *this; ++*this; return before; }
    fraction operator--(int) { fraction before = *this; --*this; return before; }
 
    fraction operator-() const {
        return fraction(-numer, denom);
    }
 
    fraction inv() const {
        return fraction(denom, numer);
    }
 
    bool operator==(const fraction &other) const { return cross_sign(*this, other) == 0; }
    bool operator!=(const fraction &other) const { return cross_sign(*this, other) != 0; }
    bool operator<(const fraction &other) const { return cross_sign(*this, other) < 0; }
    bool operator>(const fraction &other) const { return cross_sign(*this, other) > 0; }
    bool operator<=(const fraction &other) const { return cross_sign(*this, other) <= 0; }
    bool operator>=(const fraction &other) const { return cross_sign(*this, other) >= 0; }
 
    double to_double() const {
        return double(numer) / double(denom);
    }
 
    fraction to_abs() const {
        return fraction(abs(numer), denom);
    }
 
    friend ostream& operator<<(ostream& out, const fraction &frac) {
        return out << frac.numer << '/' << frac.denom;
    }
};
/*/-----------------------------Code begins----------------------------------/*/
const int N = 5e5 + 10;
set<int> adj[N];
vector<array<int, 2>> G[N];
int dsu[N];

bool use[N], vis[N];
int Find(int n){
	return (dsu[n] < 0) ? n : dsu[n] = Find(dsu[n]);
}

bool Merge(int x, int y){
	x = Find(x);
	y = Find(y);
	if (x == y){
		return false;
	}
	assert(dsu[x] < 0 && dsu[y] < 0);
	if (dsu[x] > dsu[y])
		swap(x, y);
	dsu[x] += dsu[y];
	dsu[y] = x;

	return true;
}
void solve(){
	int n;
	cin >> n;   

	vector<array<fraction, 2>> pts(n);
	for(auto& e: pts){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		e = {fraction(a, b), fraction(c, d)};
	}

	vector<array<int,2>> mp(n);

	for(auto&e: mp){
		e[0] = -1;
		e[1] = -1;
	} 
	gp_hash_table<pair<long long, long long>, vector<int>, custom_hash> st;

	for(int i = 0; i < n; ++i){
		auto e = pts[i];
		fraction cur = (e[0] + 1) / e[1];
		fraction cur2 = (e[0]) / (e[1] + 1);
		st[{cur.numer, cur.denom}].push_back(i);
		st[{cur2.numer, cur2.denom}].push_back(i);
	}

	vector<pair<int,int>> edges;
	int c = 0;

	for(auto &e: st){
		vector<int>& z = e.second;
		for(auto e: z){
			adj[c].insert(e);
			if (mp[e][0] == -1){
				mp[e][0] = c; 
			}
			else{
				mp[e][1] = c;
			}
		}
		// sort(all(adj[c]));
		++c;

		e.second.clear();
	}
	st.clear();

	for(int i = 0; i < c; ++i){
		// trace(adj[i]);
		dsu[i] = -((int)adj[i].size());
	}

	auto can_pair = [&] (int i, int j){
		return ((mp[i][0] == mp[j][0]) || (mp[i][0] == mp[j][1]) || (mp[i][1] == mp[j][0]) || (mp[i][1] == mp[j][1]));
	};



	for(int i = 0; i < n; ++i){
		auto e = mp[i];
		assert(e[0] >= 0 && e[1] >= 0 && e[0] < c && e[1] < c);
		if (Merge(e[0], e[1])){
			//tree.push_back({e[0], e[1]});
			G[e[0]].push_back({e[1], i});
			G[e[1]].push_back({e[0], i});
		}
	}

	function<void(int, int, int)> dfs = [&] (int n, int p, int ex){
		vis[n] = true;
		for(auto e: G[n]){
			if (e[0] != p){
				dfs(e[0], n, e[1]);
			}
		}
		set<int> cur;
		for(auto e: adj[n]){
			if (!use[e]){
				cur.insert(e);
			}
		}
		int k = cur.size();

		if (k & 1){
			if (cur.find(ex) != cur.end()){
				cur.erase(ex);
			}
		}
		while(cur.size() > 1){
			auto x1 = *cur.begin();
			cur.erase(x1);
			auto x2 = *cur.begin();
			cur.erase(x2);
			use[x1] = true;
			use[x2] = true;
			edges.push_back({x1, x2});

		}
	};	


	for(int i = 0; i < c; ++i){
		if (!vis[i]){
			dfs(i, -1, -1);
		}
	}
	// int ans = 0;
	// for(int i = 0; i < c;++i){
	// 	if (Find(i) == i){
	// 		int sz = -dsu[i];
	// 		ans += (sz >> 2);
	// 	}
	// }
	// cout << ans << endl;

	// trace(edges);
	cout << edges.size() << endl;
	for(auto e: edges){
		cout << e.first + 1 << " " << e.second + 1 << endl;
	}
}
int main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Or use gp_hash_table<X,null_type>
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << fixed << setprecision(25);
    cerr << fixed << setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     
}