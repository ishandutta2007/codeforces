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
const int BIGM = 1e5;



/*Okay for -ve costs, but not for negative cycles
Complexity: O(min(E^2 *V log V, E logV * flow)) 
****INF is used in both flow_type and cost_type 
so change accordingly ****for double cost type add
EPS conditions in all inequalities.*/
const ll INF = 99999999;	//vertices are 0-indexed
struct graph {
	typedef ll flow_type; // **** flow type ****
	typedef ll cost_type; // **** cost type ****
	struct edge {
		int src, dst; flow_type capacity, flow;
		cost_type cost; size_t rev;
	};
	vector<edge> edges;
	void add_edge(int src, int dst, flow_type cap, cost_type cost) {
		// trace(src, dst, cap, cost);
		adj[src].push_back({src, dst, cap, 0, cost, adj[dst].size()});
		adj[dst].push_back({dst, src, 0, 0, -cost, adj[src].size()-1});
	}
	int n; vector<vector<edge>> adj;
	graph(int n) : n(n), adj(n) { }
	pair<flow_type, cost_type> min_cost_max_flow(int s, int t, int brk) {



		flow_type flow = 0; cost_type cost = 0;


		for (int u = 0; u < n; ++u) // initialize
			for (auto &e: adj[u]) e.flow = 0;


		vector<cost_type> p(n, 0);
		auto rcost = [&](edge e) { return e.cost + p[e.src] - p[e.dst]; };


		for (int iter = 0; ; ++iter) {
			// trace(iter);
			vector<int> prev(n, -1); prev[s] = 0;
			vector<cost_type> dist(n, INF); dist[s] = 0;
			if (iter == 0) { // use Bellman-Ford to remove negative cost edges
				vector<int> count(n);count[s]=1;
				queue<int> que; 
				for (que.push(s); !que.empty(); ) {
					// trace(que);
					int u = que.front(); que.pop();
					count[u] = -count[u];
					for (auto &e: adj[u]) {
						if (e.capacity > e.flow && dist[e.dst] > dist[e.src] + rcost(e)) {
							dist[e.dst] = dist[e.src] + rcost(e);
							prev[e.dst] = e.rev;
							if (count[e.dst] <= 0) {
								count[e.dst] = -count[e.dst] + 1;
								que.push(e.dst);
				}}}}
				for(int i=0;i<n;i++) p[i] = dist[i]; // added it
				continue;
			} else { // use Dijkstra 
				// trace("hksvbnjf");
				typedef pair<cost_type, int> node;
				priority_queue<node, vector<node>, greater<node>> que;
				que.push({0, s});
				while (!que.empty()) {
					node a = que.top(); que.pop();
					if (a.second == t) break;
					if (dist[a.second] < a.first) continue;
					for (auto e: adj[a.second]) {
						if (e.capacity > e.flow && dist[e.dst] > dist[e.src] + rcost(e)) {
							dist[e.dst] = dist[e.src] + rcost(e);
							prev[e.dst] = e.rev;
							que.push({dist[e.dst], e.dst});
			}}}}
			if (prev[t] == -1) break;
			for (int u = 0; u < n; ++u) 
				if (dist[u]<dist[t]) p[u]+=dist[u]-dist[t];

			function<flow_type(int,flow_type)> augment = [&](int u, flow_type cur) {
				if (u == s) return cur;
				// trace(u);
				edge &r = adj[u][prev[u]], &e = adj[r.dst][r.rev];
				flow_type f = augment(e.src, min(e.capacity - e.flow, cur));
				e.flow += f; r.flow -= f; return f; };

				// trace("-----");
			flow_type f = augment(t, INF); flow += f;
			cost += f * (p[t] - p[s]);
			if (cost < (-(brk - 1) * BIGM)){
				return {flow, cost};
			}
			// trace(iter, flow, cost);
		}
		return {flow, cost};
	}
};

/*/-----------------------------Code begins----------------------------------/*/

void solve(){
    int d, n;
    cin >> d >> n;
    vector<int> cur(1 << d);

    auto get_val = [&] (const string& S){
    	int ans = 0;
    	for(int i = 0; i < S.size(); ++i){
    		if (S[i] == '1'){
    			ans |= (1LL << i);
    		}
    	}
    	return ans;
    };

    int M = (1 << d);
    graph G(2 * M + 10);

    for(int i = 0; i < n; ++i){
    	string s;
    	cin >> s;

    	int z = get_val(s);
    	cur[z] = 1;

    	G.add_edge(z, z + M, 1, -BIGM);
    	// G.add_edge(z + M, z, 1, 0);

    }

    int snk = 2 * M + 3;

    for(int i = 0; i < M; ++i){
    	for(int j = 0; j < d; ++j){
    		if (i & (1 << j))
    			continue;

    		G.add_edge(i, i | (1 << j), M + 10, 1);
    		G.add_edge(M + i, i | (1 << j), M + 10, 1);

    	}
    	G.add_edge(i, snk, 1, 1);
    	G.add_edge(M + i, snk, 1, 1);

    }

    // cout << G.min_cost_max_flow(0, snk, n) << endl;

    auto [f, c] = G.min_cost_max_flow(0, snk, n);
    // trace(f, c);

    c += n * BIGM;

    cout << c - 1 << endl;


    vector<vector<int>> paths;


    for(int i = 0; i < f; ++i){
		vector<int> cur;

		int s = 0;

		while(s < snk){
			int k = s % M;
			if (cur.size() == 0 || cur.back() != k){
				cur.push_back(k);
			}
			// cur.push_back(s );

			for(auto &e: G.adj[s]){
				if (e.flow > 0){
					assert(e.src == s);
					--e.flow;
					s = e.dst;
					break;
				}

			}
		}
		paths.push_back(cur);
    }


    for(int i = 0; i < paths.size(); ++i){
    	if (i > 0){
    		cout << "R ";
    	}
    	for(int j = 1; j < paths[i].size(); ++j){
    		int x = paths[i][j - 1] ^ paths[i][j];
    		int z = 0;
    		while(x > 1){
    			x >>= 1;
    			++z;
    		}
    		cout << z << " ";
    	}
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