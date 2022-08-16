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
const int M = 19;
vector<int> adj[N];
int sub[N], depth[N], A[N], pos[N];
int P[N][M];
int cnt[N];
int A2[N];

void dfs(int n, int p){
	depth[n] = depth[p] + 1;
	sub[n] = 1;
	P[n][0] = p;
	for(int j = 1; j < M; ++j){
		P[n][j] = P[P[n][j - 1]][j - 1];
	}
	for(auto e: adj[n]){
		if (e == p){
			continue;
		}
		dfs(e, n);
		sub[n] += sub[e];
	}
}

int lca(int u, int v){
	if (depth[u] > depth[v]){
		swap(u, v);
	}
	int dif = depth[v] - depth[u];

	for(int k = 0; k < M; ++k){
		if (dif & (1LL << k)){
			v = P[v][k];
		}
	}
	// assert(depth[v] == depth[u]);
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
vector<int> ordr;
void chk(int n, int p){
	ordr.push_back(n);

	
	for(auto e: adj[n]){
		if (e != p)
			chk(e, n);
	}
}


bool isLeaf(int x){
	return (sub[x] == 1);
}

bool sofar = true;
vector<int> upd;
void go(int cur, int brk, vector<int>& path){

	if (cur > brk){
		return;
	}
	if (path.size() == 0){
		// sofar = false;
		return;
	}
	int nxt = pos[cur], r = path.back();
	vector<int> extr;
	while(depth[nxt] > depth[r]){
		extr.push_back(nxt);
		nxt = P[nxt][0];
	}
	if (nxt != r){
		// if (extr.size() == 0){

		// }
		// sofar = false;
		return;
	}
	while(extr.size() > 0){
		path.push_back(extr.back());
		upd.push_back(extr.back());
		extr.pop_back();
	}
	path.pop_back();
	
	go(cur + 1, brk, path);	
}

void go2(int i, long long d, vector<int>& path, int lim){
	if (i > lim){
		if (d != 0)
			sofar = false;
		return;
	}
	// trace(i, d, path, lim);


	if (path.size() == 0){
		sofar = false;
		return;
	}
	if (d < path.size()){
		for(int k = 0; k < path.size(); ++k){
			A[path[k]] = i + k;
			// trace(A[1], A[3], A[4]);
		}
		int u = A[path[0]];
		for(int j = 0; j < d; ++j){
			A[path[j]] = A[path[j + 1]];
			// trace(A[1], A[3], A[4], j, u);

		}
		A[path[d]] = u;
			// trace(A[1], A[3], A[4]);

		return;
	}
	assert(d > 0);

	int z = path.back();
	int j = cnt[z];
	
	if (j == adj[z].size()){
		d -= (path.size() - 1);
		A[path.back()] = i;
		path.pop_back();
		go2(i + 1, d, path, lim);
		return;
	}

	d -= (path.size() - 1);
	int nx = adj[z][j];
	++cnt[z];
	while(d > 0){
		path.push_back(nx);
		--d;
		if (cnt[nx] == adj[nx].size()){
			break;
		}
		int u = nx;
		nx = adj[nx][cnt[nx]];
		++cnt[u];
	}
	A[path.back()] = i;
	path.pop_back();
	go2(i + 1, d, path, lim);

	// if (cur > brk){
	// 	return;
	// }
	// if (path.size() == 0){
	// 	sofar = false;
	// 	return;
	// }
	// int nxt = pos[cur], r = path.back();
	// vector<int> extr;
	// while(depth[nxt] > depth[r]){
	// 	extr.push_back(nxt);
	// 	nxt = P[nxt][0];
	// }
	// if (nxt != r){
	// 	// if (extr.size() == 0){

	// 	// }
	// 	sofar = false;
	// 	return;
	// }
	// while(extr.size() > 0){
	// 	path.push_back(extr.back());
	// 	upd.push_back(extr.back());
	// 	extr.pop_back();
	// }
	// path.pop_back();
	
	// go(cur + 1, brk, path);	
}

void changeAdj(int n){
	auto cmp = [&] (int i, int j){
		return A[i] < A[j];
	};
	for(int i = 1; i <= n; ++i){
		sort(all(adj[i]), cmp);
	}
}

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i<= n; ++i){
    	cin >> A[i];
    	pos[A[i]] = i;
    	A2[i] = A[i];
    }

    for(int i = 1; i < n; ++i){
    	int u, v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	// adj[v].push_back(u);
    }
    dfs(1, 0);
    int k = pos[1];
    int brk = n + 1;
    for(int j = 1; j <= n; ++j){
		if (!isLeaf(pos[j]) && P[pos[j - 1]][0] != pos[j]){
			// trace(j, pos[j], sub[pos[j]], pos[j - 1]);
			// cout << -1 << endl;
			brk = j;
			break;
			// return;
		}    	
    }
    // trace(brk);
   
   	long long days = 0;
   	int unf = -1;
    for(int i = 1; i <= n; ++i){
    	days += depth[pos[i]] - depth[1];
    	if (pos[i] == 1){
    		unf = i;
    		break;
    	}
    }
   	vector<int> pth = {1};
   	upd.push_back(1);
   	go(1, unf, pth);
   	// int z = unf.size();
   	// if (!sofar){
   	// 	cout << "NO" << endl;
   	// 	return;
   	// }
   	for(int i = 0; i < upd.size(); ++i){
   		A[upd[i]] = i + 1;
   	}
   	changeAdj(n);
    chk(1, 0);
    vector<int> b(n + 1, 0);
    for(int i = 0; i < n; ++i){
    	b[ordr[i]] = i + 1;
    	// trace(A[i], ordr[i - 1]);
    }
    for(int i = 1; i <= n; ++i){
    	if (b[i] != A[i]){
    		cout << "NO" << endl;
    		return;
    	}
    }
    // trace(b, days);
    pth = {1};
    go2(1, days, pth, n);
    	
    for(int i = 1; i <= n; ++i){
    	if (A2[i] != A[i]){
    		cout << "NO" << endl;
    		return;
    	}
    }
    if (!sofar){
    	cout << "NO" << endl;
    	return;
    }
    cout << "YES" << endl;
    cout << days << endl;
    for(int i = 1; i <= n; ++i){
    	cout << b[i] << " ";
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