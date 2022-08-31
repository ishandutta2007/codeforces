/*/ Author: kal013 /*/
// #pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

template<class T> 
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

template<class T>
using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T> >; 

/*/---------------------------IO(Debugging)----------------------/*/

template<typename T_container, typename T = typename std::enable_if<!std::is_same<T_container, std::string>::value, typename T_container::value_type>::type> 
std::istream& operator >> (std::istream &is, T_container &v) { 
   for(T &x : v) {is >> x;} return is;
}
#ifdef __SIZEOF_INT128__
std::ostream& operator << (std::ostream &os, __int128 const& value){
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
std::istream& operator >> (std::istream& is, __int128& T){
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

#ifdef __LOCAL_KAL013__
    #include "debug.h"
#else
    #define trace(...) 1
#endif

/*/---------------------------RNG----------------------/*/
inline int64_t random_long(int64_t l = LLONG_MIN, int64_t r = LLONG_MAX){
    static std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int64_t> generator(l,r);
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
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    template<typename L, typename R>
    size_t operator()(std::pair<L,R> const& Y) const{
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(Y.first * 31ull + Y.second + FIXED_RANDOM);
    }
};
/*/-----------------------------Code begins----------------------------------/*/


namespace Math{
	template<typename T>
	inline constexpr T numeric_max() {
	    return numeric_limits<T>::max();
	}

	#ifdef __SIZEOF_INT128__
	    template<>
	    inline constexpr __uint128_t numeric_max(){
	        return __uint128_t(-1);
	    }
	    template<>
	    inline constexpr __int128_t numeric_max(){
	        return (__uint128_t(-1) >> 1);
	    }
	#endif
};

namespace Math{
	template<typename T>
	struct xor_basis{ // maintains basis with unique msbs sorted and those msbs not set in any other vector.
		vector<T> values;
		inline T set_size() const {
			return (T(1) << values.size());
		}
		inline T minimize(T v) const { // returns the minimum of (whole set xorred with v). 
			for(int i = 0; i < values.size() && v > 0; ++i){
				v = min(v, v ^ values[i]);
			}
			return v;
		}

		void add(T x) {
			x = minimize(x);
			if (x > 0){
				values.push_back(x);
				for(int j = static_cast<int>(values.size()) - 1; j > 0 && values[j - 1] > values[j]; --j){
					values[j - 1] = min(values[j - 1], values[j - 1] ^ values[j]);
					swap(values[j - 1], values[j]);
				}
			}
		}
		inline bool contains(T x) const {
			x = minimize(x);
			return (x == 0);
		}

		inline T get_kth_smallest(T k, T v = T(0)) const { // kth (0-indexed) smallest element if every element is xored with v.
			for(const T& x: values){
				v = (((k & 1) == 1) ? max(v, v ^ x) : min(v, v ^ x));
				k >>= 1;
			}
			return v;
		}
		inline T get_kth_biggest(T k, T v = T(0)) const { // kth (0-indexed) biggest element if every element is xored with v.
			for(const T& x: values){
				v = (((k & 1) == 0) ? max(v, v ^ x) : min(v, v ^ x));
				k >>= 1;
			}
			return v;	
		}
		T lower_bound(const T& _lb, T v = T(0)) const { // lowest value of v ^ z >= _lb; returns numeric_max if doesnt exist.
			v = minimize(v);
			T _ans = numeric_max<T>();
			for(int i = static_cast<int>(values.size()) - 1; i >= 0; --i){
				T cur = max(v, v ^ values[i]);
				if (cur >= _lb) _ans = min(_ans, cur);
				else v = cur;
			}
			return _ans;
		}
		T count_bigger(const T& _lb, T v = T(0)) const { // number of z such that v ^ z >= _lb;
			v = minimize(v);
			T _ans = 0;
			for(int i = static_cast<int>(values.size()) - 1; i >= 0; --i){
				T cur = max(v, v ^ values[i]);
				if (cur >= _lb) _ans |= (T(1) << i);				
				else v = cur;
			}
			return _ans;
		}
		inline bool xor_in_range(T x, const T& l, const T& r) const { // can x be xorred to be in [l, r]. 
			return lower_bound(l, x) <= r;
		}

		vector<T> whole_set(T v = T(0)) const { // sorted (set xorred with v). O(set_size)
			v = minimize(v);
			vector<T> ans(1, v);
			ans.reserve(set_size());
			for(const T& x: values){
				const int n = ans.size();
				for(int i = 0; i < n; ++i){
					ans.push_back(ans[i] ^ x);
				}
			}
			return ans;
		}

		xor_basis<T> intersection(const xor_basis<T>& other) const { // O((|b1| + |b2|) * |b2|). hence swap 
			if (values.size() < other.values.size()){
				return other.intersection((*this));
			}
			xor_basis<T> ans;

			vector<T> extended, masks;
			for(const T& x: other.values){
				T y = minimize(x);
				T cur_mask = x ^ y;
				for(int i = 0; i < static_cast<int>(extended.size()); ++i){
					if ((y ^ extended[i]) < y){
						y ^= extended[i];
						cur_mask ^= masks[i];
					}
				}
				if (y == 0){
					ans.add(cur_mask);
				}
				else{
					extended.push_back(y);
					masks.push_back(cur_mask);
				}
			}
			return ans;
		}
		inline void clear() {
			values.clear();
		}
	};
};

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    vector<vector<int>> adj(n);
    for(int i = 1; i < n; ++i){
    	int u, v;
    	cin >> u >> v; --u; --v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    vector<int> sub(n), heavy(n);

    auto dfs = [&] (const auto& self, int n, int p) -> void {
    	sub[n] = 1;
    	heavy[n] = -1;
    	for(int nbr: adj[n]){
    		if (nbr != p){
    			a[nbr] ^= a[n];
    			self(self, nbr, n);
    			sub[n] += sub[nbr];
    			if (heavy[n] == -1 || sub[heavy[n]] < sub[nbr])
    				heavy[n] = nbr;
    		}
    	}
    };
    dfs(dfs, 0, -1);


    vector<gp_hash_table<int, null_type, custom_hash>> q(n);
    auto dfs2 = [&] (const auto& self, int n, int p, int root) -> int {
    	int ans = 0;

    	int own_value = (a[n] ^ (p >= 0 ? a[p] : 0));
    	if (heavy[n] != -1){
    		ans += self(self, heavy[n], n, root);
    	}
    	bool take = false;
    	if (q[root].find(a[n] ^ own_value) != q[root].end()){
    		take = true;
    	}
    	q[root].insert(a[n]);


    	for(int nbr: adj[n]){
    		if (nbr != p && nbr != heavy[n]){
    			ans += self(self, nbr, n, nbr);

    			for(int x: q[nbr]){
    				if (q[root].find(x ^ own_value) != q[root].end()){
    					take = true;
    				}
    			}
    			for(int x: q[nbr]){
    				q[root].insert(x);
    			}
    		}
    	}

    	if (take){
    		q[root].clear();
    		++ans;
    	}
    	return ans;
    };

    cout << dfs2(dfs2, 0, -1, 0) << "\n";


}  

int main(){
    
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); 
    std::cout << std::fixed << std::setprecision(25);
    std::cerr << std::fixed << std::setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();

    int t = 1;
    // std::cin >> t;

    for(int testcase = 1; testcase <= t; ++testcase) {
        // std::cout << "Case #" << testcase << ": ";
        solve();
    }

    auto stop = std::chrono::high_resolution_clock::now(); 
    long double duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
    #ifdef __LOCAL_KAL013__
        std::cerr << "Time taken : " << duration / 1e9 << "s" << std::endl;     
    #endif
}