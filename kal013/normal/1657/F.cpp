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
		static_rmq(const vector<T>& a, F _op):  op(_op) {build(a.size());}

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




namespace Graphs{
	struct forest;
	// using rmq_helper_t = std::_Bind<unsigned int (*(forest const*, std::_Placeholder<1>, std::_Placeholder<2>))(forest const*, unsigned int const&, unsigned int const&)>;
	using rmq_helper_t = function<uint32_t(const uint32_t&, const uint32_t&)>;
	rmq_helper_t __binder_rmq_forest(const forest* a);

	struct forest{ // Adapted from neal's submission: https://codeforces.com/contest/1632/submission/144568771	
		int n;
		vector<vector<int>> adj;
		vector<int> hld_euler, hld_tin, hld_tout;
		vector<int> depth, subtree_size, parent;
		vector<int> heavy_root;

		indexed_rmq<rmq_helper_t> rmq;
		bool built = false;
		vector<int> lca_euler, lca_tin;

		inline uint32_t latest_minimum_depth(const uint32_t& x, const uint32_t& y) const { // returns latest occurence of minimum depth node.
			int a = this -> lca_euler[x], b = this -> lca_euler[y];
			a = (a == -1 ? -1 : depth[a]), b = (b == -1 ? b : depth[b]);
			return (a == b ? max(x, y) : (a < b ? x : y));
		}


		forest(int _n = 0): rmq(__binder_rmq_forest(this)){ init(_n); }
		
		forest(const vector<vector<int>>& _adj): rmq(__binder_rmq_forest(this)){
			init(static_cast<int>(_adj.size())); adj = _adj;
		}

		inline void init(int _n){
			n = _n;
			adj.assign(n, {});
			parent.resize(n); depth.resize(n);
			subtree_size.resize(n); heavy_root.resize(n);

			hld_tin.resize(n); hld_tout.resize(n);
			lca_tin.resize(n);
			built = false;
		}

		inline void add_edge(int a, int b){
			adj[a].push_back(b); adj[b].push_back(a);
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

		inline bool is_root(int u) const {
			return parent[u] == -1;
		}
		inline bool is_leaf(int u) const {
			return (adj[u].empty());
		}
		inline bool is_ancestor(int u, int v) const {
			return hld_tin[u] <= hld_tin[v] && hld_tout[v] <= hld_tout[u];
		}
		inline int num_children(int u) const {
			return adj[u].size();
		}
		inline bool on_path(int x, int a, int b) const { // O(1)
			return (is_ancestor(x, a) || is_ancestor(x, b)) && is_ancestor(get_lca(a, b), x);
		}

		inline int get_lca(int u, int v) const { // O(1)
			assert (built);
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
	        pair<int, int> u_max = {-n, -1};
	        pair<int, int> ux_max = {-n, -1};
	        pair<int, array<int, 2>> uxv_max = {-n, {-1, -1}};
	        for (int node : lca_euler) {
	            if (node < 0) {
	            	u_max = {-n, -1};
	            	ux_max = {-n, -1};
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
	        inplace_merge(nodes.begin(), nodes.begin() + k, nodes.end(), compare_tour);  // TODO: Might be O(k log k), replace with merge?

	        nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
	        vector<pair<int, int>> result = {{nodes[0], -1}};
	 
	        for (int i = 1; i < int(nodes.size()); i++)
	            result.emplace_back(nodes[i], get_lca(nodes[i], nodes[i - 1]));	 
	        return result;
	    }

	};
	inline uint32_t __rmq_forest_helper(const forest* a, const uint32_t& x, const uint32_t& y){
		return a -> latest_minimum_depth(x, y);
	}
	function<uint32_t(const uint32_t&, const uint32_t&)> __binder_rmq_forest(const forest* a){
		return bind(__rmq_forest_helper, a, placeholders::_1, placeholders::_2);
	}
};



struct dsu{
	vector<int> a;

	void init(int n) {
		a.assign(n, -1);
	}

	int find(int x){
		return (a[x] < 0 ? x : a[x] = find(a[x]));
	}
	bool merge(int x, int y) {
		x = find(x); y = find(y);
		if (x == y)
			return false;
		if (a[x] > a[y])
			swap(x, y);
		a[x] += a[y];
		a[y] = x;
		return true;
	}
	bool same(int x, int y){
		return (find(x) == find(y));
	}
};

/*/-----------------------------Code begins----------------------------------/*/


void solve(){
	int n, q;
	cin >> n >> q;

	Graphs::forest tree(n);
	vector<int> mask(n, (1 << 26) - 1);

	for(int i = 1; i < n; ++i){
		int u, v;
		cin >> u >> v;
		--u; --v;
		tree.add_edge(u, v);
	}
	tree.build();


	vector<tuple<int, int, string>> queries(q); 
	for(int _z = 0; _z < q; ++_z){
		int u, v;
		string s;
		cin >> u >> v >> s; --u; --v;

		assert (tree.get_distance(u, v) + 1 == s.size());
		int k = s.size();

		int U = u;
		for(int i = 0; i < k; ++i){
			int msk = (1 << (s[i] - 'a')) | (1 << (s[k - 1 - i] - 'a'));
			mask[U] &= msk; 

			if (i + 1 < k){
				U = tree.get_next_on_path(U, v);
			}
		}
		queries[_z] = {u, v, s};
	}
	string ans(n, '$');

	vector<array<int, 2>> nodes; nodes.reserve(2 * n);

	for(int i = 0; i < n; ++i){
		if (mask[i] == 0){
			cout << "NO\n";
			return;
		}
		if (__builtin_popcount(mask[i]) == 26){
			ans[i] = 'a';
		}
		else if (__builtin_popcount(mask[i]) == 1){
			int z = __builtin_ctz(mask[i]);
			ans[i] = ('a' + z);
			nodes.push_back({i, z});
		}
		else{
			assert (__builtin_popcount(mask[i]) == 2);
			int x = __builtin_ctz(mask[i]), y = 31 - __builtin_clz(mask[i]);
			assert (x < y);

			nodes.push_back({i, x});
			nodes.push_back({i, y});
		}
	}

	auto get_idx = [&] (int i, int j){
		assert (0 <= i && i < n);
		assert (0 <= j && j < 26);
		int it = lower_bound(nodes.begin(), nodes.end(), array<int, 2>{i, j}) - nodes.begin();
		if (it == nodes.size() || nodes[it] != array<int, 2>{i, j}){
			return -1;
		}
		return it;
	};

	// dsu device;
	const int m = nodes.size();

	vector<vector<int>> adj(m + 2 * q), adj_t(m + 2 * q);;
	// device.init(m + 2 * q + 1);

	auto add_edge = [&] (int u, int v, bool both){
		assert (u != v);
		adj[u].push_back(v);
		adj_t[v].push_back(u);
		if (both){
			adj[v].push_back(u);
			adj_t[u].push_back(v);
		}
	};

	for(int z = 0; z < q; ++z){
		int u = get<0>(queries[z]), v = get<1>(queries[z]);
		string s = get<2>(queries[z]);

		int pos = 3;

		int U = u;
		const int k = s.size();
		for(int i = 0; i < k; ++i){
			if (s[i] == s[k - 1 - i]){
				int idx = get_idx(U, s[i] - 'a');
				if (idx == -1){
					assert (false);
					cout << "NO\n";
					return;
				}
			}
			else{


				{
					int idx = get_idx(U, s[i] - 'a');
					if (idx == -1){
						add_edge(m + 2 * z, m + 2 * z + 1, false);
					}
					else{
						add_edge(m + 2 * z, idx, true);
					}
				}
				{
					int idx = get_idx(U, s[k - 1 - i] - 'a');
					if (idx == -1){

						add_edge(m + 2 * z + 1, m + 2 * z, false);
					}
					else{
						add_edge(m + 2 * z + 1, idx, true);
					}
				}
			}

			if (i + 1 < k){
				U = tree.get_next_on_path(U, v);
			}
		}
	}

	vector<int> used(m + 2 * q, false);
	vector<int> order, comp;

	function<void(int)> dfs1 = [&] (int v) {
		used[v] = true;
		for(int u: adj[v]){
			if (!used[u]){
				dfs1(u);
			}
		}
		order.push_back(v);
	};


	function<void(int, int)> dfs2 = [&] (int v, int cl) {
	    comp[v] = cl;
	    for (int u : adj_t[v]) {
	        if (comp[u] == -1)
	            dfs2(u, cl);
	    }
	};

	order.clear();

	for(int i = 0; i < m + 2 * q; ++i){
		if (!used[i])
			dfs1(i);
	}
	comp.assign(m + 2 * q, -1);
	for(int i = 0, j = 0; i < m + 2 * q; ++i){
		int v = order[m + 2 * q - i - 1];
		if (comp[v] == -1){
			dfs2(v, j++);
		}
	}
	vector<int> choose(q);
	for(int i = m; i < m + 2 * q; i += 2){
		if (comp[i] == comp[i + 1]){
			cout << "NO\n";
			return;
		}
		choose[(i - m) >> 1] = comp[i] > comp[i + 1] ? 0 : 1;
	}

	for(int z = 0; z < q; ++z){
		int u = get<0>(queries[z]), v = get<1>(queries[z]);
		string s = get<2>(queries[z]);
		if (choose[z] == 1){
			swap(u, v);
		}
		int U = u;
		const int k = s.size();

		for(int i = 0; i < k; ++i){
			ans[U] = s[i];
			if (i + 1 < k){
				U = tree.get_next_on_path(U, v);
			}
		}
	}
	cout << "YES\n";
	cout << ans << endl;

}  

int main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Or use gp_hash_table<X,null_type>
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << fixed << setprecision(25);
    cerr << fixed << setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     
}