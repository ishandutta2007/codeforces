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

const int N = 3e5 + 100;


int U[N], V[N];
bool done[N];


#define nbr(u, e) (U[e] ^ V[e] ^ u)

struct DSU{
	vector<int> dsu;
	int comp;
	void init(int n){
		dsu.resize(n);
		for(int i = 0; i < n; ++i){
			dsu[i] = -1;
		}
		comp = n;
	}

	int Find(int x){
		return (dsu[x] < 0) ? x: dsu[x] = Find(dsu[x]);
	}

	bool Merge(int x, int y){
		x = Find(x);
		y = Find(y);
		assert(dsu[x] < 0 && dsu[y] < 0);
		if (x == y)
			return false;

		--comp;
		if (dsu[x] > dsu[y])
			swap(x, y);
		dsu[x] += dsu[y];
		dsu[y] = x;
		return true;
	}
};


// int dsu[N];
long long tot[N], off[N];

// set<pair<long long, long long>> edges[N];



// set<pair<long long, long long>> hasedge;

long long delta;

// int Find(int x){
// 	return (dsu[x] < 0) ? x: dsu[x] = Find(dsu[x]);
// }


// int getWt(int i){
// 	U[i] = Find(U[i]);
// 	V[i] = Find(V[i]);
// 	return tot[U[i]] + tot[V[i]];

// }

// void remove(int z){
// 	if (edges[z].size() == 0){
// 		return;
// 	}
// 	auto X = *edges[z].rbegin();
// 	X.first += off[z];
// 	assert(hasedge.find(X) != hasedge.end());
// 	hasedge.erase(X);
// }

// void add(int z){
// 	if (edges[z].size() == 0){
// 		return;
// 	}
// 	auto X = *edges[z].rbegin();
// 	X.first += off[z];
// 	trace(X);
// 	assert(hasedge.find(X) == hasedge.end());
// 	hasedge.insert(X);
// }

// bool Merge(int x, int y){
// 	x = Find(x);
// 	y = Find(y);
// 	assert(dsu[x] < 0 && dsu[y] < 0);
// 	if (x == y)
// 		return false;

// 	if (dsu[x] > dsu[y])
// 		swap(x, y);


// 	remove(x);
// 	remove(y);

// 	tot[x] += tot[y] - delta;
// 	off[x] += tot[y] - delta;
// 	off[y] += tot[x] - delta;
// 	assert(tot[x] >= 0);
// 	dsu[x] += dsu[y];
// 	dsu[y] = x;
// 	for(auto X: edges[y]){
// 		edges[x].insert({X.first + off[y] - off[x], X.second});
// 	}
// 	add(x);
// 	// off[]
// 	return true;
// }


vector<int> rev, forw;
vector<int> adj[N];


long long dfs(int n, int p, int ed){


	for(auto e: adj[n]){
		int nb = nbr(n, e);
		if (nb == p)
			continue;
		long long z = dfs(nb, n, e);
		tot[n] += z;
	}
	if (ed == -1){
		return tot[n];
	}
	if (tot[n] >= delta){
		forw.push_back(ed);
		return tot[n] - delta;
	}
	else{
		rev.push_back(ed);
	}
	return 0;
}


void solve(){
    long long n, m, x;
    cin >> n >> m >> x;
    delta = x;


    vector<long long> a(n);
    cin >> a;
    DSU dev;
    dev.init(n);

    vector<int> ex;
    for(int i = 0; i < m; ++i){
    	cin >> U[i] >> V[i]; 
    	--U[i];
    	--V[i];
    	if (dev.Merge(U[i], V[i])){
    		ex.push_back(i);
    	}
    }
    if (dev.comp != 1){
    	cout << "NO" << endl;
    	return;
    }

    long long s = 0;
    for(auto e: a){
    	s += e;
    }
    if (s < ((n - 1) * x)){
    	cout << "NO" << endl;
    	return;
    }

    for(int i = 0; i < n; ++i){
    	tot[i] = a[i];
    }
    for(auto e: ex){
    	adj[U[e]].push_back(e);
    	adj[V[e]].push_back(e);

    }

    s -= dfs(0, 0, -1);

    cout << "YES" << endl;
    for(auto e: forw){
    	cout << e + 1<< "\n";
    }
    reverse(all(rev));
    for(auto e: rev){
    	cout << e + 1<< "\n";
    }


    // for(int i = 0; i < m; ++i){
    // 	int u = U[i], v = V[i];

    // 	edges[u].insert({a[u] + a[v], i});
    // 	edges[v].insert({a[u] + a[v], i});
    // }

    // for(int i = 0; i < n; ++i){
    // 	dsu[i] = (int)(edges[i].size());
    // 	dsu[i] *= -1;
    // 	dsu[i] -= 1;
    // 	off[i] = 0;
    // }

    // for(int i = 0; i < n; ++i){
    // 	add(i);
    // }
    // trace(hasedge);



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