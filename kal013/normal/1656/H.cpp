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

template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> 
istream& operator >> (istream &is, T_container &v) { 
   for(T &x : v) is >> x; return is;
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
ostream& operator << (ostream &os, __uint128_t const& value){
    static char buffer[64];
    int index = 0;
    // __uint128_t T = (value < 0) ? (-(value + 1)) + __uint128_t(1) : value;
    __uint128_t T = value;
    // if (value < 0) 
        // os << '-';
    if (T == 0)
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
istream& operator >> (istream& is, __uint128_t& T){
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

template<typename A, typename B> 
ostream& operator<<(ostream &os, const pair<A, B> &p) { 
   return os << '(' << p.first << ", " << p.second << ')'; 
}

template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> 
ostream& operator << (ostream &os, const T_container &v) { 
   os << '{'; string sep; 
   for (const T &x : v) os << sep << x, sep = ", "; 
   return os << '}'; 
}
template<class P, class Q = vector<P>, class R = less<P> > ostream& operator << (ostream& out, priority_queue<P, Q, R> const& M){
    static priority_queue<P, Q, R> U;
    U = M;
    out << "{ ";
    while(!U.empty())
        out << U.top() << " ", U.pop();
    return (out << "}");
}
template<class P> ostream& operator << (ostream& out, queue<P> const& M){
    static queue<P> U;
    U = M;
    out << "{"; string sep;
    while(!U.empty()){
        out << sep << U.front(); sep = ", "; U.pop();
    }
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
         int count_open = 0, len = 1;
         for(int k = 1; ; ++k){
            char cur = *(names + k);
            count_open += (cur == '(' ? 1 : (cur == ')' ? -1: 0));
            if (cur == ',' && count_open == 0){
               const char* comma = names + k;
               cerr.write(names, len) << " : " << arg1 << " | ";
               __f(comma + 1, args...);
               return;
            }
            len = (cur == ' ' ? len : k + 1);
         }
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
    static uint64_t splitmix64(uint64_t x) { // http://xorshift.di.unimi.it/splitmix64.c
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
        return splitmix64(Y.first * 31ull + Y.second + FIXED_RANDOM);
    }
};

/*/---------------------------Defines----------------------/*/
#define endl "\n"
#define all(v) (v).begin(),(v).end()
/*/-----------------------------Code begins----------------------------------/*/

inline int ctz(__uint128_t x) {
	long long a = (x & (uint64_t(-1)));
	if (a == 0){
		return __builtin_ctzll((long long)(x >> 64)) + 64;
	}
	return __builtin_ctzll(a);
}
 

inline __int128 gcd(__int128 a, __int128 b) {
	return __gcd(a, b);
	if(b == 0) return a;
	if(a == 0) return b;
 
	int az = ctz(a);
	int bz = ctz(b);
	int shift = min(az, bz);
	b >>= bz;
 
	while(a != 0) {
		a >>= az;
		__int128 diff = b - a;
		if(diff) az = ctz(diff);
		b = min(a, b);
		a = (diff < 0 ? -diff: diff);
	}
	return b << shift;
}

template<typename T>
struct segtree{
	vector<T> seg;
	int n;
	segtree() {};

	void clear(){ 
		n = 0; 
		seg.clear(); 
	}
	void build(const vector<T>& z){ 
		n = z.size();
		seg.resize(2 * n);
		copy(z.begin(), z.end(), seg.begin() + n);

		for(int i = n - 1; i > 0; --i){
			seg[i] = gcd(seg[i << 1], seg[(i << 1) | 1]);
		}
	}
	void update(int p,int v){ 
		p += n; 
		seg[p] = v;
		for(int i = p; i > 1; i >>= 1) {
			T old = seg[i >> 1];
			seg[i >> 1] = gcd(seg[i], seg[i ^ 1]);
			if (old == seg[i >> 1])
				break;
		}
	}
	T query(int l,int r){
		/*assert(l<=r);*/ T ans = 0;
		for(l += n, r += n + 1; l < r; l>>=1, r>>=1){
			if(l & 1) ans = gcd(ans, seg[l++]); 
			if(r & 1) ans = gcd(ans, seg[--r]);
		} 
		return ans;
} };


 

void solve(){
	
	vector<vector<__int128_t>> pts(2);
	vector<vector<segtree<__int128>>> g(2);
	vector<vector<bool>> alive(2);
	array<int, 2> sizes;
	cin >> sizes;


	set<int> iter[2];

	for(int i = 0; i < 2; ++i){
		int n = sizes[i];
		pts[i].resize(n);
		g[i].resize(n);
		alive[i].assign(n, true);

		for(int j = 0; j < n; ++j)
			iter[i].insert(j);
		cin >> pts[i];
	}


	vector<array<int, 2>> bfs;



	for(int i = 0; i < 2; ++i){
		int n = pts[i].size(), m = pts[i ^ 1].size();
		for(int j = 0; j < n; ++j){
			vector<__int128> cur(m);
			for(int k = 0; k < m; ++k){
				cur[k] = pts[i][j] / gcd(pts[i][j], pts[i ^ 1][k]);
			}
			g[i][j].build(cur);

			if (g[i][j].seg[1] != 1){
				bfs.push_back({i, j});
				alive[i][j] = false;
			}
		}
	}



	for(int z = 0; z < bfs.size() && !iter[0].empty() && !iter[1].empty(); ++z){
		auto [x, y] = bfs[z];
		assert (!alive[x][y]);

		int n = pts[x].size(), m = pts[x ^ 1].size();
		iter[x].erase(y);
		for(int i : iter[x ^ 1]){
			if (!alive[x ^ 1][i])
				continue;
			// assert (g[x ^ 1][i].query(0, n - 1) == 1);

			g[x ^ 1][i].update(y, 0);
			if (g[x ^ 1][i].seg[1] != 1){
				alive[x ^ 1][i] = false;
				bfs.push_back({x ^ 1, i});
			}
		}
	}

	vector<int> a, b;
	for(int i = 0; i < alive[0].size(); ++i){
		if (alive[0][i])
			a.push_back(i);
	}
	for(int j = 0; j < alive[1].size(); ++j){
		if (alive[1][j]){
			b.push_back(j);
		}
	}
	if (a.empty() || b.empty()){
		cout << "NO\n";
	}
	else{
		cout << "YES\n";
		cout << a.size() << " " << b.size() << endl;
		for(int x: a){
			cout << pts[0][x] << " ";
		}
		cout << endl;
		for(int x: b){
			cout << pts[1][x] << " ";
		}
		cout << endl;
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
    cin >> t;
    while (t--) {
        solve();
    }

    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     
}