/*/ Author: kal013 /*/
// #pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;


#ifndef _MSC_VER
#   include <cxxabi.h>
#endif

template <class T>
std::string type_name() {
    typedef typename std::remove_reference<T>::type TR;
    std::unique_ptr<char, void(*)(void*)> own
           (
	#ifndef _MSC_VER
                abi::__cxa_demangle(typeid(TR).name(), nullptr,
                                           nullptr, nullptr),
	#else
                nullptr,
	#endif
                std::free
           );
    std::string r = own != nullptr ? own.get() : typeid(TR).name();
    if (std::is_const<TR>::value)
        r += " const";
    if (std::is_volatile<TR>::value)
        r += " volatile";
    if (std::is_lvalue_reference<T>::value)
        r += "&";
    else if (std::is_rvalue_reference<T>::value)
        r += "&&";
    return r;
}


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


namespace Graphs{
	struct forest;
	// using rmq_helper_t = std::_Bind<unsigned int (*(forest, std::_Placeholder<1>, std::_Placeholder<2>))(forest const&, unsigned int const&, unsigned int const&)>;
	using rmq_helper_t = std::_Bind<unsigned int (*(forest const*, std::_Placeholder<1>, std::_Placeholder<2>))(forest const*, unsigned int const&, unsigned int const&)>;

	uint32_t __rmq_forest_helper(const forest* a, const uint32_t& x, const uint32_t& y);

	rmq_helper_t __binder_rmq_forest(const forest* a);

	struct forest{ // Adapted from neal's submission: https://codeforces.com/contest/1632/submission/144568771	
	public:
		int n;
		vector<vector<int>> adj;
		vector<int> hld_euler, hld_tin, hld_tout;
		vector<int> depth, subtree_size, parent;
		vector<int> heavy_root;

	private:
		indexed_rmq<rmq_helper_t> rmq;
		bool built = false;
		vector<int> lca_euler, lca_tin;

	public:
		inline uint32_t latest_minimum_depth(const uint32_t& x, const uint32_t& y) const { // returns latest occurence of minimum depth node.
			int a = this -> lca_euler[x], b = this -> lca_euler[y];
			a = (a == -1 ? -1 : depth[a]), b = (b == -1 ? b : depth[b]);
			if (a == b)
				assert (x <= y);
			return (a == b ? max(x, y) : (a < b ? x : y));
		}


		forest(int _n = 0): rmq(__binder_rmq_forest(this)){
			init(_n);
		}
		
		forest(const vector<vector<int>>& _adj): rmq(__binder_rmq_forest(this)){
			init(static_cast<int>(_adj.size()));
			adj = _adj;
		}

		void init(int _n){
			n = _n;
			adj.assign(n, {});
			parent.resize(n); depth.resize(n);
			subtree_size.resize(n); heavy_root.resize(n);

			hld_tin.resize(n); hld_tout.resize(n);
			lca_tin.resize(n);
			built = false;
		}

		void add_edge(int a, int b){
			adj[a].push_back(b);
			adj[b].push_back(a);
		}


		void dfs(int node, int p){ // removes parent, heaviest child first.
			parent[node] = p;
			depth[node] = (p < 0 ? 0 : depth[p] + 1);
			subtree_size[node] = 1;
			adj[node].erase(remove(adj[node].begin(), adj[node].end(), p), adj[node].end());

			int max_idx = 0;
			for(int i = 0; i < static_cast<int>(adj[node].size()); ++i){
				int child = adj[node][i];
				dfs(child, node);
				subtree_size[node] += subtree_size[child];
				if (subtree_size[child] > subtree_size[adj[node][max_idx]]){
					max_idx = i;
				}
			}
			if (max_idx != 0){
				swap(adj[node][0], adj[node][max_idx]);
			}
		}

		void tour_dfs(int node, bool heavy){
			lca_tin[node] = static_cast<int>(lca_euler.size());
			lca_euler.push_back(node);

			hld_tin[node] = static_cast<int>(hld_euler.size());
			hld_euler.push_back(node);

			heavy_root[node] = heavy ? heavy_root[parent[node]] : node;
			heavy = true;

			for(auto child: adj[node]){
				tour_dfs(child, heavy);
				lca_euler.push_back(node);
				heavy = false;
			}

			hld_tout[node] = static_cast<int>(hld_euler.size()) - 1;
		}

		void build(int root = -1){
			parent.assign(n, -1);
			
			if (root != -1)
				dfs(root, -1);

			for(int i = 0; i < n; ++i){
				if (i != root && parent[i] == -1)
					dfs(i, -1);
			}

			lca_euler.clear(); lca_euler.reserve(2 * n);
			hld_euler.clear(); hld_euler.reserve(n);

			for(int i = 0; i < n; ++i){
				if (parent[i] == -1){
					tour_dfs(i, false);
					lca_euler.push_back(-1);
				}
			}

			assert (static_cast<int>(lca_euler.size()) == 2 * n && static_cast<int>(hld_euler.size()) == n);
			rmq.build(2 * n);
			built = true;
		}
		inline bool is_leaf(int u) const {
			return (adj[u].empty());
		}
		inline bool is_ancestor(int u, int v) const {
			return hld_tin[u] <= hld_tin[v] && hld_tout[v] <= hld_tout[u];
		}

		inline bool on_path(int x, int a, int b) const { // O(1)
			return (is_ancestor(x, a) || is_ancestor(x, b)) && is_ancestor(get_lca(a, b), x);
		}

		inline int get_lca(int u, int v) const { // O(1)
			u = lca_tin[u], v = lca_tin[v];
			if (u > v)
				swap(u, v);
			return lca_euler[rmq.query(u, v)];
		}

		int get_distance(int u, int v) const { // O(1)
			return depth[u] + depth[v] - 2 * depth[get_lca(u, v)];
		}

	    int child_ancestor(int a, int b) const { // O(1)
	        assert(a != b && is_ancestor(a, b));
	        int child = lca_euler[rmq.query(lca_tin[a], lca_tin[b]) + 1];
	        assert(parent[child] == a && is_ancestor(child, b));
	        return child;
	    }
	    int get_next_on_path(int u, int v) const { // O(1)
	    	assert (u != v);
	    	if (is_ancestor(u, v))
	    		return child_ancestor(u, v);
	    	return parent[u];
	    } 

        int get_kth_ancestor(int a, int k) const { // O(log n)
	        while (a >= 0) {
	            int root = heavy_root[a];	 
	            if (depth[root] <= depth[a] - k)
	                return hld_euler[hld_tin[a] - k];
	 
	            k -= depth[a] - depth[root] + 1;
	            a = parent[root];
	        }
	        return a;
	    }

	    int get_kth_on_path(int a, int b, int k) const { // O(log n)
	        int anc = get_lca(a, b);
	        int first_half = depth[a] - depth[anc];
	        int second_half = depth[b] - depth[anc];
	        assert(0 <= k && k <= first_half + second_half);
	 
	        if (k < first_half)
	            return get_kth_ancestor(a, k);
	        else
	            return get_kth_ancestor(b, first_half + second_half - k);
	    }

	    pair<int, array<int, 2>> get_diameter() const {
	        assert(built);
	        // We find the maximum of depth[u] - 2 * depth[x] + depth[v] where u, x, v occur in order in the Euler tour.
	        pair<int, int> u_max = {-1, -1};
	        pair<int, int> ux_max = {-1, -1};
	        pair<int, array<int, 2>> uxv_max = {-1, {-1, -1}};
	        for (int node : lca_euler) {
	            if (node < 0) {
	            	u_max = {-1, -1};
	            	ux_max = {-1, -1};
	            	continue;
	            }
	            u_max = max(u_max, {depth[node], node});
	            ux_max = max(ux_max, {u_max.first - 2 * depth[node], u_max.second});
	            uxv_max = max(uxv_max, {ux_max.first + depth[node], {ux_max.second, node}});
	        }
	        return uxv_max;
	    }

	    array<int, 2> get_center(const pair<int, array<int, 2>>& diam) const {
	    	int length = diam.first, a = diam.second[0], b = diam.second[1];
	        return {get_kth_on_path(a, b, length / 2), get_kth_on_path(a, b, (length + 1) / 2)};
	    }
        array<int, 2> get_center() const {
	        pair<int, array<int, 2>> diam = get_diameter();
	        return get_center(diam);
	    }

        // Given a subset of k tree nodes, computes the minimal subtree that contains all the nodes (at most 2k - 1 nodes).
    	// Returns a list of {node, parent} for every node in the subtree sorted by tour index. Runs in O(k log k).
    	// parent == -1 , if it is a root of a tree. nodes[0].second == -1 guaranteed.
	    vector<pair<int, int>> compress_forest(vector<int> nodes) const {
	        if (nodes.empty())
	            return {};
	 
	        auto compare_tour = [&](const int& a, const int& b) { return lca_tin[a] < lca_tin[b]; };
	        sort(nodes.begin(), nodes.end(), compare_tour);
	        int k = int(nodes.size());
	 
	        for (int i = 0; i < k - 1; i++){
	        	int x = get_lca(nodes[i], nodes[i + 1]);
	        	if (x != -1)
	            	nodes.push_back(x);
	        }
	 
	        sort(nodes.begin() + k, nodes.end(), compare_tour);
	        inplace_merge(nodes.begin(), nodes.begin() + k, nodes.end(), compare_tour);

	        nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
	        vector<pair<int, int>> result = {{nodes[0], -1}};
	 
	        for (int i = 1; i < int(nodes.size()); i++)
	            result.emplace_back(nodes[i], get_lca(nodes[i], nodes[i - 1]));	 
	        return result;
	    }

	};
	uint32_t __rmq_forest_helper(const forest* a, const uint32_t& x, const uint32_t& y){
		return a -> latest_minimum_depth(x, y);
	}
	rmq_helper_t __binder_rmq_forest(const forest* a){
		return bind(__rmq_forest_helper, a, placeholders::_1, placeholders::_2);
	}

};





void solve(){
    int n;
 
    cin >> n;
 	
 	Graphs::forest T(n);
 
    for(int i = 1; i < n; ++i){
    	int u, v;
    	cin >> u >> v;
    	--u; --v;
    	T.add_edge(u, v);
    }

    T.build(0);

    vector<int> leaves;

    for(int i = 0; i < n; ++i){
    	if (T.is_leaf(i)){
    		leaves.push_back(i);
    	}
    }
   	
    sort(all(leaves), [&] (int x, int y){
    	return T.depth[x] > T.depth[y];
    });
 
	int max_depth = T.depth[leaves[0]] - T.depth[0];
    vector<int> f(n + 1, max_depth);
 
 
    int centre = leaves[0], farthest = leaves[0];
    int distance = 0;
    bool equal = true;
 
    int current_lowest = centre;
 
 
    vector<bool> done(n, false);
    done[centre] = true;
    auto add_node = [&] (int x){
    	int q = T.get_distance(centre, x);
    	// assert (q <= distance + 1);
    	if (done[x]){
    		// assert (false);
    		return;
    	}
    	done[x] = true;
    	if (q < distance){
    		return;
    	}
    	if (q == distance + 1){
    		if (equal){
    			distance += 1;
    			farthest = x;
    			equal = false;
    			return;
    		}
    		int v = T.get_next_on_path(centre, x);
    		// assert (T.get_distance(v, farthest) == distance - 1 && T.get_distance(v, x) == distance);
    		centre = v;
    		equal = true;
    		farthest = x;
    		return;
    	}
 
    	int v = T.get_next_on_path(centre, x);
    	{
    		int dd = T.get_distance(v, farthest);
 
    		// assert (abs(distance - dd) == 1);
 
    		if (dd == distance + 1){
    			equal = true;
    		}
    	}
    };
 
 
    auto add_path = [&] (int x){
    	int next_l = T.get_lca(current_lowest, x);
 
    	while (T.depth[current_lowest] > T.depth[next_l]){
    		current_lowest = T.parent[current_lowest];
    		add_node(current_lowest);
    	}
 
    	// assert (current_lowest == next_l);
    	vector<int> nodes;
    	while (!done[x]){
    		nodes.push_back(x);
    		x = T.parent[x];
    	}
 
    	reverse(all(nodes));
 
    	for(auto y: nodes){
    		add_node(y);
    	}
    };
    // trace(leaves);
    vector<int> g(n + 1, n + 10);
 
 
    auto update = [&] (int L, int z){
    	if (z <= L){
    		f[L - z] = min(f[L - z], L);
    	}
    	int idx = max(L - z, 0);
    	g[idx] = min(g[idx], z);
 
    };
    for(int i = 1; i < static_cast<int>(leaves.size()); ++i){
    	int L = T.depth[leaves[i]] ;
 
    	while (T.depth[current_lowest] > L + 1){
    		int cL = T.depth[current_lowest] - 1;
    		update(cL, distance);
    		current_lowest = T.parent[current_lowest];
    		add_node(current_lowest);
    	}	
 
    	update(L, distance);
    	add_path(leaves[i]);
    }
 
 
	while (true){
    	int L = max(T.depth[current_lowest] -  1, 0);
 
    	update(L, distance);
    	if (current_lowest == 0)
    		break;
    	current_lowest = T.parent[current_lowest];
    	add_node(current_lowest);
    }
 
    for(int i = n - 1; i >= 0; --i){
    	f[i] = min(f[i], f[i + 1]);
    }
 
    for(int i = 1; i <= n; ++i){
    	g[i] = min(g[i], g[i - 1]);
    }
 
    for(int i = 1; i <= n; ++i){
    	cout << min(f[i], g[i] + i) << " ";
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
    cin >> t;
    while (t--) {
        solve();
    }

    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     
}