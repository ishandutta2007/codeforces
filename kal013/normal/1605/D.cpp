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
const int N = 2e5 + 100;
vector<int> adj[N];

int mark[N], P[N];
int sub[N];
int d[N];
void dfs(int n, int p){
	sub[n] = 1;
	d[n] = d[p] ^ 1;
	for(auto e: adj[n]){
		if (e != p && mark[e] == -1){
			dfs(e, n);
			sub[n] += sub[e];
		}
	}
}

// int get_centre(int n, int p, int tot){
// 	for(auto e: adj[n]){
// 		if (e == p || mark[e] >= 0)
// 			continue;
// 		if (sub[e] * 2 > tot){
// 			return get_centre(e, n, tot);
// 		}
// 	}
// 	return n;
// }

// void centroid_decomp(int n, vector<int> values){
// 	dfs(n, -1);
// 	int c = get_centre(n, -1, sub[n]);
// 	dfs(c, -1);

// 	mark[c] = 1;
// 	P[c] = values[0];

// 	vector<int> children;
// 	vector<vector<int>> distr;
// 	for(auto e: adj[c]){	
// 		if (mark[e] >= 0)
// 			continue;
// 		children.push_back(e);
// 		vector<int> tmp; tmp.reserve(sub[e]);
// 		distr.push_back(tmp);
// 	}

// 	vector<int> ids(children.size()); iota(all(ids), 0);

// 	reverse(all(values));
// 	values.pop_back();
// 	vector<int> tmp; int idx = 0;

// 	while (!values.empty()){
// 		assert (idx < ids.size());

// 		if (distr[ids[idx]].size() == sub[children[ids[idx]]]){
// 			++idx;
// 			if (idx == ids.size()){
// 				ids = tmp; tmp.clear();
// 				idx = 0;
// 			}
// 			continue;
// 		}

// 		assert (ids.size() > 0 && idx >= 0 && idx < ids.size());
// 		auto X = values.back();
// 		values.pop_back();
// 		distr[ids[idx]].push_back(X);
// 		tmp.push_back(ids[idx]);
// 		++idx;

// 		if (idx == ids.size()){
// 			ids = tmp; tmp.clear();
// 			idx = 0;
// 		}
// 	}


// 	for(int i = 0; i < children.size(); ++i){
// 		centroid_decomp(children[i], distr[i]);
// 	}

// }
void solve(){
	int n;
	cin >> n;    

	for(int i = 1; i <= n; ++i){
		adj[i].clear();
		mark[i] = -1;
		P[i] = -1;
	}
	for(int i = 1; i < n; ++i){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);

	vector<vector<int>> values;
	vector<int> tmp;
	for(int i = 1; i <= n; ++i){
		if (tmp.empty()){
			tmp.push_back(i);
		}
		else{
			if ((tmp.back() ^ i) > min(i, tmp.back())){
				values.push_back(tmp);
				tmp.clear();
			}
			tmp.push_back(i);
		}
	}
	values.push_back(tmp);

	// sort(all(values), [&] (const vector<int>& A, const vector<int>& B){
	// 	return A.size() < B.size();
	// });
	
	vector<int> colored[2];
	for(int i = 1; i <= n; ++i){
		colored[d[i]].push_back(i);
	}
	if (colored[0].size() > colored[1].size())
		swap(colored[0], colored[1]);

	vector<int> fin[2];
	int tot =  colored[0].size();

	for(auto e: values){
		if (tot & (e.size())){
			assert (e.size() <= tot);
			tot -= e.size();
			for(auto z: e)
				fin[0].push_back(z);
		}
		else{
			for(auto z: e){
				fin[1].push_back(z);
			}
		}
	}
	for(int j = 0; j < 2; ++j){
		assert (fin[j].size() == colored[j].size());
		for(int t = 0; t < fin[j].size(); ++t){
			P[colored[j][t]] = fin[j][t];
		}
	}
	for(int i = 1; i <= n; ++i){
		cout << P[i] << " " ;
	}
	cout << endl;
	// assert (values.back().size() <= colored[0].size());
	// for(auto v: values.back()){
	// 	auto X = colored[0].back(); colored[0].pop_back();
	// 	P[X] = v;
	// }
	// values.pop_back();



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