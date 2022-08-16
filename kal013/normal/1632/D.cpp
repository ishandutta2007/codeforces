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
template<class T, size_t N> istream& operator >> (istream &is, array<T, N>& V) {
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
template<class P> ostream& operator << (ostream& out, queue<P> const& M){
    static queue<P> U;
    U = M;
    out << "{ ";
    while(!U.empty())
        out << U.front() << " ", U.pop();
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
        return splitmix64(Y.first * 31ull + Y.second + FIXED_RANDOM);
    }
};

/*/---------------------------Defines----------------------/*/
#define ll long long
#define endl "\n"
#define all(v) (v).begin(),(v).end()
/*/-----------------------Modular Arithmetic---------------/*/
const int mod = 1e9 + 7;

/*/-----------------------------Code begins----------------------------------/*/

namespace RMQ {
	template<typename T, T (*op)(const T& ,const  T&), const bool indexable, const bool idempotent>
	struct static_rmq{
		static_assert (!indexable && !idempotent);
		vector<T> a;	
		vector<vector<T>> table;
		static_rmq(const vector<T>& arr): a(arr){
			int n = 1; while (n < arr.size()) n <<= 1;
			a.resize(n);
			int range, half;
		    for(int h = 0, range = 2; range <= n; h++, range <<= 1) {
		    	table.emplace_back(n);
		        half = range >> 1;
		        for(int i = half; i < n; i += range) {
		            table[h][i] = a[i];
		            table[h][i - 1] = a[i - 1];
		            for(int j = i - 2; j >= i - half; j--){
		                table[h][j] = op(table[h][j + 1], a[j]);
		            }

		            for(int j = i + 1; j < i + half; j++){
		                table[h][j] = op(table[h][j - 1], a[j]);
		            }
		        }
		    }
		}
		T query(int l, int r){
			if (l == r) 
				return a[l];
			int h = 31 ^ __builtin_clz(l ^ r);
			return op(table[h][l], table[h][r]);
		}
	};

	template<typename T, T (*op)(const T& ,const  T&), const bool indexable>
	struct static_rmq<T, op, indexable, true>{
		static_assert (!indexable);
		vector<vector<T>> table;
		static_rmq(const vector<T>& arr){
			int n = arr.size();
			table.emplace_back(arr);
			for(int h = 1, range = 2; range <= n; ++h, range <<= 1){
				table.emplace_back(n - range + 1);
				int half = range >> 1;
				for(int i = 0; i + range <= n; ++i){
					table[h][i] = op(table[h - 1][i], table[h - 1][i + half]);
				}
			}
		}	

		static inline uint32_t msb_index(uint32_t x){
			return 31 ^ __builtin_clz(x);
		}

		T query(int l, int r){
			if (l == r)
				return table[0][l];
			int j = msb_index(r - l);
			return op(table[j][l], table[j][r - (1 << j) + 1]);
		}
	};

	template<uint32_t (*op)(const uint32_t&, const uint32_t&)>
	struct static_rmq<uint32_t, op, true, true> {

		static constexpr uint32_t b = 32;
		static constexpr uint32_t shift = 5;
	    static constexpr uint32_t all_mask = -1U;
	    static constexpr uint32_t masks[] = {
	        (1U << 0) - 1,  (1U << 1) - 1,  (1U << 2) - 1, (1U << 3) - 1,  (1U << 4) - 1,  (1U << 5) - 1,
	        (1U << 6) - 1,  (1U << 7) - 1,  (1U << 8) - 1, (1U << 9) - 1,  (1U << 10) - 1, (1U << 11) - 1,
	        (1U << 12) - 1, (1U << 13) - 1, (1U << 14) - 1, (1U << 15) - 1, (1U << 16) - 1, (1U << 17) - 1,
	        (1U << 18) - 1, (1U << 19) - 1, (1U << 20) - 1, (1U << 21) - 1, (1U << 22) - 1, (1U << 23) - 1,
	        (1U << 24) - 1, (1U << 25) - 1, (1U << 26) - 1, (1U << 27) - 1, (1U << 28) - 1, (1U << 29) - 1,
	      	(1U << 30) - 1, (1U << 31) - 1, -1U};

	   	static_assert (all_mask == masks[b] && (1u << shift) == b);
		static inline uint32_t lsb(uint32_t x) {
			return x & -x;
		}
		static inline uint32_t msb_index(uint32_t x){
			return 31 ^ __builtin_clz(x);
		}

		uint32_t n;
		vector<uint32_t> mask;
		vector<vector<int>> table;

		inline uint32_t small_query(uint32_t r, uint32_t size = b){
			uint32_t dist_from_r = msb_index(mask[r] & masks[size]);
			return r - dist_from_r;
		}
		static_rmq(int n): n(n), mask(n){
			uint32_t curr_mask = 0;
			for (int i = 0; i < n; i++) {
				curr_mask = (curr_mask << 1) & all_mask;
				while (curr_mask > 0){
					uint32_t lo = lsb(curr_mask);
					if (op(i, i - msb_index(lo)) == i){
						curr_mask ^= lo;
					}
					else
						break;
				}
				curr_mask |= 1;
				mask[i] = curr_mask;
			}
			uint32_t small_n = n / b;
			table.resize(1, vector<int>(small_n));
			for (int i = 0; i < small_n; i++) 
				table[0][i] = small_query(b * i + b - 1);

			for (uint32_t j = 1, pow_2 = 2, base_ = 1; pow_2 <= small_n; pow_2 <<= 1, base_ <<= 1, ++j){
				table.emplace_back(small_n - pow_2 + 1);
				for (int i = 0; i + pow_2 <= small_n; i++){
					table[j][i] = op(table[j - 1][i], table[j - 1][i + base_]);
				}
			}
		};
		template<typename T>
		static_rmq(const vector<T>& a): static_rmq(a.size()) {}
		uint32_t query(int l, int r){
			if (r - l + 1 <= b)
				return small_query(r, r - l + 1);
			
			uint32_t ans = op(small_query(l + b - 1), small_query(r));
			
			l = (l >> shift) + 1;
			r >>= shift;
	        if (l < r) {
	            int j = msb_index(r - l);
	            ans = op(ans, op(table[j][l], table[j][r - (1 << j)]));
	        }
			return ans;
		}
	};
};

template<uint32_t (*op)(const uint32_t& ,const  uint32_t&)>
using indexed_rmq = RMQ::static_rmq<uint32_t, op, true, true>;

template<typename T, T (*op)(const T& ,const  T&)>
using idempotent_rmq = RMQ::static_rmq<T, op, false, true>;

template<typename T, T (*op)(const T& ,const  T&)>
using disjoint_rmq = RMQ::static_rmq<T, op, false, false>;


vector<uint32_t> a;


uint32_t f (const uint32_t& x, const uint32_t& y){
	return a[x] < a[y] ? x : y;
}
uint32_t g(const uint32_t& x, const uint32_t& y){
	return __gcd(x, y);
}

void solve(){
	int n;
	cin >> n;

	vector<uint32_t> a(n);
	cin >> a;


	idempotent_rmq<uint32_t, g> rmq(a);


	int last = -1, ans = 0;

	auto is_good = [&] (int l, int r){
		assert (l <= r);

		int lo = l, hi = r;

		while (lo <= hi){
			int mid = (lo + hi) >> 1;
			uint32_t g = rmq.query(mid, r);
			if (g == (r - mid + 1))
				return false;
			if (g > (r - mid + 1)){
				hi = mid - 1;
			}
			else{
				lo = mid + 1;
			}
		}
		return true;
	};

	for(int i = 0; i < n; ++i){
		if (!is_good(last + 1, i)){
			last = i;
			++ans;
		}

		cout << ans << " ";
	}
	cout << endl;
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