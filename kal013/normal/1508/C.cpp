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

/*/-----------------------------Code begins----------------------------------/*/

const int N = 2e5 + 10;
const int M = 18;
gp_hash_table<int, null_type, custom_hash> adj[N];
vector<bool> G[N];
set<pair<int,int>> rngs[N];

vector<array<int,2>> g[N];
int dep[N], P[N][M], rd[N];

void dfs(int n, int p, int l){
	dep[n] = dep[p] + l;
	rd[n] = rd[p] + 1;
	P[n][0] = p;
	for(int j = 1; j < M; ++j){
		P[n][j] = P[P[n][j - 1]][j - 1];
	}
	for(auto e: g[n]){
		if (e[0] == p){
			continue;
		}
		dfs(e[0], n, e[1]);
	}
}

int lca(int u, int v){
	if (rd[u] > rd[v]){
		swap(u, v);
	}
	int dif = rd[v] - rd[u];

	for(int k = 0; k < M; ++k){
		if (dif & (1LL << k)){
			v = P[v][k];
		}
	}
	assert(rd[v] == rd[u]);
	if (u == v)
		return u;


	for(int k = M - 1; k >= 0; --k){
		if (P[v][k] != P[u][k]){
			v = P[v][k];
			u = P[u][k];
		}
	}
	return P[u][0];
}


int dsu[N];

void add_range(set<pair<int,int>>& A, pair<int,int> X){
	auto it = A.lower_bound({X.second, X.second});
	if (it != A.end()){
		auto Y = *it;
		if (Y.first == X.second + 1){
			X.second = Y.second;
			A.erase(it);
		}
	}
	it = A.lower_bound(X);
	if (it != A.begin()){
		--it;
		auto Y = *it;
		if (Y.second + 1 == X.first){
			X.first = Y.first;
			A.erase(it);
		}
	}
	A.insert(X);
}


void merge_sets(set<pair<int,int>>& A, const set<pair<int,int>>& B){
	for(auto e: B){
		add_range(A, e);
	}
}

int Find(int n){
	return (dsu[n] < 0) ? n : dsu[n] = Find(dsu[n]);
}

bool Merge(int x, int y){
	x = Find(x);
	y = Find(y);
	assert(dsu[x] < 0 && dsu[y] < 0);

	if (x == y){
		return false;
	}

	if (dsu[x] > dsu[y])
		swap(x, y);

	dsu[x] += dsu[y];
	// trace(rngs[x], rngs[y]);
	merge_sets(rngs[x], rngs[y]);
	rngs[y].clear();
	// trace(rngs[x], rngs[y]);
	dsu[y] = x;
	return true;
}
long long MST(const vector<array<long long,3>>& edges, vector<array<int, 3>>& tree){
	long long ans = 0;
	for(auto e: edges){
		if (Merge(e[0], e[1])){
			tree.push_back({e[0], e[1], 0});
			ans += e[2];
			// trace(e);
		}
		else{
			// trace(",", e);
		}
	}
	// trace(ans);
	return ans;
}





void solve(){
    int n, m;
    cin >> n >> m;


    for(int i = 1; i <= n; ++i){
    	adj[i].clear();
    	rngs[i].clear();
    	rngs[i].insert({i, i});
    	g[i].clear();
    }
    long long tot = (n * 1LL * (n - 1)) >> 1;
    tot -= m;

    
    vector<array<long long,3>> edges(m);
    for(int i = 0; i < m; ++i){	
    	cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    	adj[edges[i][0]].insert(edges[i][1]);
    	adj[edges[i][1]].insert(edges[i][0]);
    }

    auto cmp = [&] (const array<long long, 3>& A, const array<long long, 3>& B){

    	return A[2] < B[2]; 
    };

    sort(all(edges), cmp);

    // trace(edges);
    for(int i = 1; i <= n; ++i){
    	dsu[i] = -1;
    }
    // trace(tot);

    if (tot > (n - 1)){
    	// All zero,

    	for(int i = 1; i <= n; ++i){
    		int l = i + 1;
    		while(l <= n){
    			if (adj[i].find(l) != adj[i].end()){
    				++l;
    				continue;
    			}
    			Merge(i, l);
    			int par = Find(l);
    			auto it = rngs[par].lower_bound({l + 1, -1});
    			assert(it != rngs[par].begin());
    			--it;
    			auto X = *it;
    			assert(X.first <= l && X.second >= l);
    			l = X.second + 1;
    		}
    	}
    	vector<array<int,3>> tree;
    	cout << MST(edges,tree) << endl;

    }
    else{
    	long long xs = 0;
    	for(auto e: edges){
    		xs ^= e[2];
    	}
    	for(int i = 1; i <= n; ++i){
    		G[i].resize(n + 1);
    		for(int j = 1; j <= n; ++j){
    			G[i][j] = (i != j) ? true : false;
    		}
    	}
    	for(auto [u, v, w]: edges){
    		G[u][v] = false;
    		G[v][u] = false;
    	}
    	int ct = 0;
    	vector<array<int, 3>> tree;

    	for(int i = 1; i <= n; ++i){
    		for(int j = i + 1; j <= n; ++j){
    			if (G[i][j]){
    				// trace(i, j);
    				if (Merge(i, j)){
    					tree.push_back({i, j, 1});
    				}
    				else{
    					++ct;
    				}
    			}
    		}
    	}


    	long long s1 = MST(edges, tree) + ((ct > 0) ? 0 : xs);

    	if (ct == 0){
    		for(auto e: tree){
    			g[e[0]].push_back({e[1], e[2]});
    			g[e[1]].push_back({e[0], e[2]});
    		}
    		dfs(1, 0, 0);

    		for(auto e: edges){
    			auto [u, v, w] = e;
    			if (P[u][0] == v || P[v][0] == u)
    				continue;
    			int l = lca(u, v);
    			if (dep[u] + dep[v] > 2 * dep[l]){
    				s1 = min(s1, s1 + w - xs);
    				break;
    			}
    		}

    	}

    	cout << s1 << endl;
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