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



namespace RMQ {
	template<typename T, class F, const bool indexable, const bool idempotent>
	struct static_rmq{
		static_assert (!indexable && !idempotent);
		vector<T> a;	
		vector<vector<T>> table;
		F op;
		static_rmq(const vector<T>& arr, F _op): op(_op){
			build(arr);
		}
		static_rmq(F _op): op(_op) {}

		inline void clear() {
			a.clear(); 
			table.clear();
		}
		void build(const vector<T>& arr) {
			clear();
			a = arr; 
			int n = 1; while (n < static_cast<int>(arr.size())) n <<= 1;
			a.resize(n);
			int half;
		    for(int h = 0, _range = 2; _range <= n; h++, _range <<= 1) {
		    	table.emplace_back(n);
		        half = _range >> 1;
		        for(int i = half; i < n; i += _range) {
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

		inline T query(int l, int r) const {
			if (l == r) 
				return a[l];
			int h = 31 ^ __builtin_clz(l ^ r);
			return op(table[h][l], table[h][r]);
		}
	};

	template<typename T, class F, const bool indexable>
	struct static_rmq<T, F, indexable, true>{
		static_assert (!indexable);
		vector<vector<T>> table;
		F op;
		static_rmq(F _op): op(_op) {}	
		static_rmq(const vector<T>& arr, F _op): op(_op) {
			build(arr);
		}

		inline void clear() {
			table.clear();
		}
		void build(const vector<T>& arr) {
			clear();
			int n = static_cast<int>(arr.size());
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

		inline T query(int l, int r) const {
			if (l == r)
				return table[0][l];
			int j = msb_index(r - l);
			return op(table[j][l], table[j][r - (1 << j) + 1]);
		}
	};

	template<class F>
	struct static_rmq<uint32_t, F, true, true> {

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
		F op;
		inline uint32_t small_query(uint32_t r, uint32_t size = b) const {
			uint32_t dist_from_r = msb_index(mask[r] & masks[size]);
			return r - dist_from_r;
		}

		static_rmq(int _n, F _op): op(_op) { build(_n); }
		static_rmq(F _op): op(_op) {}
		template<typename T>
		static_rmq(const vector<T>& a, F _op): static_rmq(a.size(), _op) {}

		inline void clear(){
			mask.clear();
			table.clear();
		}
			

		void build(int _n) {
			clear();
			n = _n; mask.resize(_n);

			uint32_t curr_mask = 0;
			for (int i = 0; i < static_cast<int>(n); i++) {
				curr_mask = (curr_mask << 1) & all_mask;
				while (curr_mask > 0){
					uint32_t lo = lsb(curr_mask);
					if (static_cast<int>(op(i - msb_index(lo), i)) == i){
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
			for (int i = 0; i < static_cast<int>(small_n); i++) 
				table[0][i] = small_query(b * i + b - 1);

			for (uint32_t j = 1, pow_2 = 2, base_ = 1; pow_2 <= small_n; pow_2 <<= 1, base_ <<= 1, ++j){
				table.emplace_back(small_n - pow_2 + 1);
				for (int i = 0; i + pow_2 <= small_n; i++){
					table[j][i] = op(table[j - 1][i], table[j - 1][i + base_]);
				}
			}
		}
		
		inline uint32_t query(int l, int r) const {
			if (r - l + 1 <= static_cast<int>(b))
				return small_query(r, r - l + 1);
			
			uint32_t ans = small_query(l + b - 1);
			uint32_t r_ans = small_query(r);
			l = (l >> shift) + 1;
			r >>= shift;
	        if (l < r) {
	            int j = msb_index(r - l);
	            ans = op(ans, op(table[j][l], table[j][r - (1 << j)]));
	        }
			return op(ans, r_ans);
		}
	};

	template<class F>
	constexpr uint32_t RMQ::static_rmq<uint32_t, F, true, true>::masks[];

};

template<class F>
using indexed_rmq = RMQ::static_rmq<uint32_t, F, true, true>;

template<typename T, class F>
using idempotent_rmq = RMQ::static_rmq<T, F, false, true>;

template<typename T, class F>
using disjoint_rmq = RMQ::static_rmq<T, F, false, false>;


/*/-----------------------------Code begins----------------------------------/*/

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	cin >> a;
	// for(int i = 0; i + 1 < n; ++i){
	// 	if (min(a[i], a[i + 1]) > 0){
	// 		cout << "NO\n";
	// 		return;
	// 	}
	// }

	vector<array<int, 2>> ranges(n, {n + 1, -1});

	{
		vector<int> stk;
		for(int i = 0; i < n; ++i){
			while (!stk.empty() && a[stk.back()] <= a[i]){
				stk.pop_back();
			}
			if (!stk.empty()){
				ranges[i][0] = stk.back() + 1;
			}
			else{
				ranges[i][0] = 0;
			}
			stk.push_back(i);
		}
	}

	{
		vector<int> stk;
		for(int i = n - 1; i >= 0; --i){
			while (!stk.empty() && a[stk.back()] < a[i]){
				stk.pop_back();
			}
			if (!stk.empty()){
				ranges[i][1] = stk.back() - 1;
			}
			else{
				ranges[i][1] = n - 1;
			}
			stk.push_back(i);
		}
	}

	vector<long long> p(n + 1);


	for(int i = 1; i <= n; ++i) p[i] = a[i - 1] + p[i - 1];


	auto cmp_max = [&] (int i, int j){
		return p[i] > p[j] ? i : j;
	};

	auto cmp_min = [&] (int i, int j){
		return p[i] < p[j] ? i : j;
	};

	indexed_rmq<decltype(cmp_max)> dev_max(n + 1, cmp_max);
	indexed_rmq<decltype(cmp_min)> dev_min(n + 1, cmp_min);


	for(int x = 0; x < n; ++x){
		auto [l, r] = ranges[x];

		int y = dev_min.query(l, x);
		int z = dev_max.query(x + 1, r + 1);

		if (p[z] - p[y] > a[x]){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";



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