/*/ Author: kal013 /*/
#ifndef __LOCAL_KAL013__
    #pragma GCC optimize("O3,unroll-loops")
    // #pragma GCC target("avx,avx2,sse4.2,bmi,bmi2,popcnt,lzcnt") // Gives SIGILL on SPOJ
#endif

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

namespace Graphs{
	struct DAG{
		int n;
		vector<vector<int>> adj;

		DAG(int _n = 0) { init(_n); }
		
		DAG(const vector<vector<int>>& _adj) {
			init(_adj);
		}

		inline void init(int _n){
			n = _n;
			adj.assign(n, {});
		}
		inline void init(const vector<vector<int>>& _adj){
			n = static_cast<int>(_adj.size());
			adj = _adj;
		}


		inline void add_edge(int a, int b){
			adj[a].push_back(b);
		}

		void dfs_topo(int u, vector<int>& order, vector<bool>& visited) {
			visited[u] = true;
			for(int v: adj[u]){
				if (!visited[v]){
					dfs_topo(v, order, visited);
				}
			}
			order.push_back(u);
		}
		vector<int> toposort() {
			vector<bool> visited(n, false);
			vector<int> ans;
			for(int i = 0; i < n; ++i){
				if (!visited[i]){
					dfs_topo(i, ans, visited);
				}
			}
			reverse(ans.begin(), ans.end());
			return ans;
		}

		void dfs_scc(int v, int& index, vector<int>& r_index, vector<int>& S, int& c){ // D.J. Pearce algo 3.
			bool root = true;
			r_index[v] = index++;

			for(int w: adj[v]){
				if (r_index[w] == -1) dfs_scc(w, index, r_index, S, c);
				if (r_index[w] < r_index[v]){
					r_index[v] = r_index[w];
					root = false;
				}
			}
			if (root){
				--index;
				while (!S.empty() && r_index[v] <= r_index[S.back()]){
					int w = S.back(); S.pop_back();
					r_index[w] = c;
					--index;
				}
				r_index[v] = c;
				--c;
			}
			else{
				S.push_back(v);
			}
		}

		vector<int> scc_condense() { // returns comp s.t. comp[i] == comp[j] iff i, j in same scc and if i ---> j then comp[i] < comp[j]
			vector<int> comp(n, -1);
			int index = 1, c = n - 1;
			vector<int> S;
			for(int i = 0; i < n; ++i){
				if (comp[i] == -1){
					dfs_scc(i, index, comp, S, c);
				}
			}
			for(auto &e: comp){
				e -= c + 1;
			}
			return comp;
		}

		vector<vector<int>> scc_condense_adj(const vector<int>& comp) {
			const int m = (*max_element(comp.begin(), comp.end())) + 1;
			vector<vector<int>> ans(m);
			for(int u = 0; u < n; ++u){
				ans[comp[u]].push_back(u);
			}
			vector<bool> taken(m, false);
			for(int i = 0; i < m; ++i){
				vector<int> dp;
				for(int u: ans[i]){
					for(int v: adj[u]){
						int V = comp[v];
						if (V == i || taken[V])
							continue;
						dp.push_back(V);
						taken[V] = true;
					}
				}
				for(int V: dp){
					taken[V] = false;
				}
				ans[i].swap(dp);
			}
			return ans;
		}
		DAG scc_condense_graph(const vector<int>& comp) {
			DAG(scc_condense_adj(comp));
		}
		DAG scc_condense_graph() {
			return scc_condense_graph(scc_condense());
		}
		vector<vector<int>> scc_condense_adj() {
			return scc_condense_adj(scc_condense());
		}
	};


	struct TwoSat{
		int n;
		DAG g;
		TwoSat(int _n = 0) {init(_n);}

		void init(int _n){
			n = _n;
			g.init(_n);
		}

		inline void set(int x, int value_x) {
			assert (0 <= x && x < n); 
			assert (0 <= value_x && value_x <= 1);
			g.add_edge(2 * x + (value_x ^ 1), 2 * x + value_x);
		}

		inline void add_or_clause(int x, int value_x, int y, int value_y){
		    assert(0 <= x && x < n && 0 <= y && y < n);
			assert(0 <= value_x && value_x <= 1 && 0 <= value_y && value_y <= 1);

    		g.add_edge(2 * x + (value_x ^ 1), 2 * y + value_y);
    		g.add_edge(2 * y + (value_y ^ 1), 2 * x + value_x);
		}

		inline void add_implication(int x, int value_x, int y, int value_y){
			assert(0 <= x && x < n && 0 <= y && y < n);
			assert(0 <= value_x && value_x <= 1 && 0 <= value_y && value_y <= 1);		

			g.add_edge(2 * x + value_x, 2 * y + value_y);
		}

		inline vector<int> solve() {
		    int cnt;
		    vector<int> c = g.scc_condense();
		    vector<int> res(n);
		    for (int i = 0; i < n; i++) {
		    	if (c[2 * i] == c[2 * i + 1]) {
		       		return vector<int>();
		      	}
		      	res[i] = (c[2 * i] < c[2 * i + 1]);
		    }
		    return res;
		  }
	};
};

template<const int MOD>
struct modular_int{
	int x;
	static vector<int> inverse_list ;
	const static int inverse_limit;
	const static bool is_prime;
	modular_int(){
		x = 0;
	}
	template<typename T>  
	modular_int(const T z){
		x = (z%MOD);
		if (x < 0) x += MOD; 	
	}
	modular_int(const modular_int<MOD>* z){
		x = z->x;
	}
	modular_int(const modular_int<MOD>& z){
		x = z.x;
	}
	modular_int operator - (const modular_int<MOD>& m) const{
		modular_int<MOD> U;
		U.x = x - m.x;
		if (U.x < 0) U.x += MOD;
		return U;
	}
	modular_int operator + (const modular_int<MOD>& m) const{
		modular_int<MOD> U;
		U.x = x + m.x;
		if (U.x >= MOD) U.x -= MOD;
		return U;
	}
	modular_int& operator -= (const modular_int<MOD>& m){
		x -= m.x;
		if (x < 0) x += MOD;
		return *this;
	}	
	modular_int& operator += (const modular_int<MOD>& m){
		x += m.x;
		if (x >= MOD) x -= MOD;
		return *this;
	}	
	modular_int operator * (const modular_int<MOD>& m) const{
		modular_int<MOD> U;
		U.x = (x* 1ull * m.x) %MOD;
		return U;
	}
	modular_int& operator *= (const modular_int<MOD>& m){
		x = (x * 1ull * m.x)%MOD;
		return *this;
	}
	template<typename T>
	friend modular_int operator + (const T &l, const modular_int<MOD>& p){
		return (modular_int<MOD>(l) + p);
	}
	template<typename T>
	friend modular_int operator - (const T &l, const modular_int<MOD>& p){
		return (modular_int<MOD>(l) - p);
	}
	template<typename T>
	friend modular_int operator * (const T &l, const modular_int<MOD>& p){
		return (modular_int<MOD>(l) * p);
	}
	template<typename T>
	friend modular_int operator / (const T &l, const modular_int<MOD>& p){
		return (modular_int<MOD>(l) / p);
	}

	int value() const{
		return x;
	}

	modular_int operator ^ (const modular_int<MOD>& cpower) const{
		modular_int<MOD> ans;
		ans.x = 1;
		modular_int<MOD> curr(this);
		int power = cpower.x;

		if (curr.x <= 1){
			if (power == 0) curr.x = 1;
			return curr;
		}
		while( power > 0){
			if (power&1){
				ans *= curr;
			}
			power >>= 1;
			if (power) curr *= curr;
		}
		return ans;
	}


	modular_int operator ^ (long long power) const{
		modular_int<MOD> ans;
		ans.x = 1;
		modular_int<MOD> curr(this);
		if (curr.x <= 1){
			if (power == 0) curr.x = 1;
			return curr;
		}
		// Prime Mods
		if (power >= MOD && is_prime){
			power %= (MOD - 1);
		}

		while( power > 0){
			if (power&1){
				ans *= curr;
			}
			power >>= 1;
			if (power) curr *= curr;

		}
		return ans;
	}

	modular_int operator ^ (int power) const{
		modular_int<MOD> ans;
		ans.x = 1;
		modular_int<MOD> curr(this);
		
		if (curr.x <= 1){
			if (power == 0) curr.x = 1;
			return curr;
		}
		while( power > 0){
			if (power&1){
				ans *= curr;
			}
			power >>= 1;
			if (power) curr *= curr;

		}
		return ans;
	}
	
	template<typename T>
	modular_int& operator ^= (T power) {
		modular_int<MOD> res = (*this)^power;
		x = res.x;
		return *this;
	}


	template<typename T>
	modular_int pow(T x){
		return (*this)^x;
	}

	
	pair<long long,long long> gcd(const int a, const int b) const {
		if (b==0) return {1,0}; 
		pair<long long,long long> c = gcd(b , a%b);
		return { c.second , c.first - (a/b)*c.second}; 
	}

	inline void init_inverse_list() const {
		
		vector<int>& dp = modular_int<MOD>::inverse_list;
		dp.resize(modular_int<MOD>::inverse_limit + 1);
		int n = modular_int<MOD>::inverse_limit;
		dp[0] = 1;
		if (n > 1) dp[1] = 1;
		for(int i = 2; i <= n; ++i){
			dp[i] = (dp[MOD%i] * 1ull *(MOD - MOD/i))%MOD;
		}
	
	}
	modular_int<MOD> get_inv() const {
		if (modular_int<MOD>::inverse_list.size() < modular_int<MOD>::inverse_limit + 1) init_inverse_list();

		if (this->x <= modular_int<MOD>::inverse_limit){
			return modular_int<MOD>::inverse_list[this->x];
		}
		pair<long long,long long> G = gcd(this->x,MOD);
		return modular_int<MOD>(G.first);
	}
	modular_int<MOD> operator - () const {
		modular_int<MOD> v(0);
		v -= (*this);
		return v;
	}
	modular_int operator / (const modular_int<MOD>& m) const{
		modular_int<MOD> U(this);
		U *= m.get_inv();
		return U;
	}
	modular_int& operator /= (const modular_int<MOD>& m){
		(*this) *= m.get_inv();
		return *this;
	}
	bool operator==(const modular_int<MOD>& m) const{
		return x == m.x;
	}

	bool operator < (const modular_int<MOD>& m) const {
		return x < m.x;
	}


	template<typename T>
	bool operator == (const T& m) const{
		return (*this)== (modular_int<MOD>(m));
	}

	template<typename T>
	bool operator < (const T& m) const {
		return x < (modular_int<MOD>(m)).x;
	}
	template<typename T>
	bool operator > (const T& m) const {
		return x > (modular_int<MOD>(m)).x;
	}
	template<typename T>
	friend bool operator == (const T& x, const modular_int<MOD>& m) {
		return (modular_int<MOD>(x)).x == m.x;
	}
	template<typename T> 
	friend bool operator < (const T& x, const modular_int<MOD>& m){
		return (modular_int<MOD>(x)).x < m.x;
	}
	template<typename T> 
	friend bool operator > (const T& x, const modular_int<MOD>& m){
		return (modular_int<MOD>(x)).x > m.x;
	}

	friend istream& operator >> (istream& is, modular_int<MOD>& p){
		int64_t val;
		is >> val;
		p.x = (val%MOD);
		if (p.x < 0) p.x += MOD;
		return is;
	}
	friend ostream& operator << (ostream& os, const modular_int<MOD>& p) {return os<<p.x;}



};


const int mod = 998244353;

using mint = modular_int<mod>;
template<const int MOD>
vector<int> modular_int<MOD>::inverse_list ;
template<const int MOD>
const int modular_int<MOD>::inverse_limit = -1;
template<const int MOD>
const bool modular_int<MOD>::is_prime = true;
// template<>   //-> useful if computing inverse fact = i_f[i-1] / i;
// const int modular_int<mod>::inverse_limit = 100000;


/*/-----------------------------Code begins----------------------------------/*/


void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    cin >> a;


    vector<vector<int>> adj(n);
    for(int i = 0; i < m; ++i){
    	int u, v;
    	cin >> u >> v; --u; --v;
    	adj[u].push_back(v);    	
    }
    Graphs::DAG G(adj);

    vector<int> order = G.toposort();

    const int T = n + 2;

    vector<vector<bool>> alive(n, vector<bool>(T, false));

    vector<mint> dp(n);
    vector<bool> large(n, false);

    for(int u: order){

    	{
    		int64_t v = dp[u].value();
    		v += a[u];
    		if (v >= T){
    			large[u] = true;
    		}
    	}
    	dp[u] += a[u];
    	for(int x = 0; x < T && x < a[u]; ++x){
    		alive[u][x] = true;
    	}

    	for(int v: adj[u]){
    		{
    			int64_t x = dp[v].value();
    			x += (dp[u].value());

    			if (large[u] || x >= T) {
    				large[v] = true;
    			}
    		}
    		dp[v] += dp[u];

    		for(int x = 1; x < T; ++x){
    			if (alive[u][x - 1])
    				alive[v][x] = true;
    		}
    	}
    }
    int64_t ans = 0;
    for(int i = 0; i < n; ++i){
    	if (!adj[i].empty()){
    		continue;
    	}
    	int64_t cur = (dp[i].value());
    	for(int j = 0; j < T; ++j){
    		if (!alive[i][j])
    			++cur;
    	}
    	if (!large[i]){
    		for(int j = T - 1; j >= 0; --j){
    			if (!alive[i][j]){
    				--cur;
    			}
    			else{
    				break;
    			}
    		}
    	}
    	ans = max(ans, cur);
    }
    cout << ans % mod << '\n';
}  

int main(){
    
    cin.tie(nullptr) -> sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(25);
    std::cerr << std::fixed << std::setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();

    int t = 1;
    cin >> t;

    for(int testcase = 1; testcase <= t; ++testcase) {
        // cout << "Case #" << testcase << ": ";
        solve();
    }
    
    #ifdef __LOCAL_KAL013__
    auto stop = std::chrono::high_resolution_clock::now(); 
    long double duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
        std::cerr << "Time taken : " << duration / 1e9 << "s" << std::endl;     
    #endif
}