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
const int N = 1e6 + 2;

int dsu[N];
vector<pair<int, int>> co[N], ce[N];

void init(int x){
	for(int i = 0; i <= x; ++i){
		dsu[x] = -1;
	}
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
	if (dsu[x] > dsu[y])
		swap(x, y);

	dsu[x] += dsu[y];
	for(auto e: co[y]){
		co[x].push_back(e);
	}
	for(auto e: ce[y]){
		ce[x].push_back(e);
	}
	dsu[y] = x;
	co[y].clear();
	ce[y].clear();
	return true;
}

void solve(){
    int m, k;
    cin >> m >> k;
    vector<pair<int, int>> a(k);
    for(int i = 0; i < k; ++i){
    	cin >> a[i].first;
    	a[i].second = i + 1;
    }
    sort(all(a));
	reverse(all(a));

	int mx = a[0].first;

	auto f = [] (int x){
		return (x * ((x + 1) >> 1));
	};
	auto g = [&] (int x){
		return f(x) + (((x + 1) >> 1) * (x >> 1));
	};

	
	int n = 1;
	while(f(n) < mx || g(n) < m)
		++n;

	auto conv = [&] (int i, int j){
		return i * n + j;
	};


	vector<vector<int>> mat(n, vector<int> (n, -1));
	auto print = [&] () {
		cout << mat.size()  << endl;
		for(auto e: mat){
			for(auto elem: e){
				cout << max(elem, 0) << " ";
			}
			cout << endl;
		}
	};
	for(int i = 1; i < n; i += 2)
		for(int k = 1; k < n; k += 2)
			mat[i][k] = 0;

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			int x = conv(i, j);
			dsu[x] = -1;
			co[x].clear();
			ce[x].clear();
			if (mat[i][j] == 0)
				continue;
			if (i & 1){
				co[x].push_back({i, j});
			}
			else{
				ce[x].push_back({i, j});
			}
		}
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if (mat[i][j] == 0)
				continue;
			int x = conv(i, j);
			// trace(x);
			if (i + 1 < n && j > 0 && mat[i  + 1][j - 1] != 0){
				Merge(x, conv(i + 1, j - 1));
			}
			if (i + 1 < n && j + 1 < n && mat[i + 1][j + 1] != 0){
				Merge(x, conv(i + 1, j + 1));
			}
		}
	}

	set<array<int, 4>> U;

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if (mat[i][j] == 0)
				continue;
			int x = conv(i, j);
			if (Find(x) == x){
				U.insert({-dsu[x], co[x].size(), ce[x].size(), x});
			}
		}
	}
	// trace(U);

	// trace(U);
	for(auto e: a){
		auto [cnt, val] = e;
		if (cnt == 0)
			break;
		// trace(e);
		set<array<int, 4>> add_after;

		while(cnt > 0){
			auto Z = *U.rbegin();
			U.erase(Z);
			auto [tot, oval, eval, pos] = Z;
			if (oval >= eval){
				while(cnt > 0 && !co[pos].empty()){
					auto [x1, y1] = co[pos].back();
					co[pos].pop_back();
					--cnt;
					mat[x1][y1] = val;
				}
				oval = co[pos].size();
			}
			else{
				while(cnt > 0 && !ce[pos].empty()){
					auto [x1, y1] = ce[pos].back();
					ce[pos].pop_back();
					--cnt;
					mat[x1][y1] = val;
				}
				eval = ce[pos].size();
			}
			tot = oval + eval;
			Z = {tot, oval, eval, pos};
			add_after.insert(Z);
		}
		for(auto k: add_after){
			U.insert(k);
		}
	}
	print();
	// if (n & 1){

	// }
	// else{
	// 	int j = 1;
	// 	for(int i = 0; i < n; i += 2){
	// 		for(int k = 1; k < n; k += 2){
	// 			mat[i + j][k] = 0;
	// 		}
	// 	}
	// 	print();
	// 	cout << endl;
	// 	return;
	// }
	// vector<int> tot;
	// for(auto e: a){
	// 	for(int z = 0; z < e.first; ++z){
	// 		tot.push_back(e.second);
	// 	}
	// }

	// int cc = 0;

	// for(int i = 0; i < n && cc < tot.size(); i += 2){
	// 	for(int j = 0; j < n && cc < tot.size(); ++j){

	// 		mat[i][j] = tot[cc++];
	// 	}
	// }	

	// print();
		
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