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
int mod = 1e9 + 7;

/*/-----------------------------Code begins----------------------------------/*/

const int NN = 105;
vector<int> dp[NN][NN];
bool vis[NN][NN];

void solve(){
	int n, m, k;
	cin >> n >> m >> k >> mod;

	auto add = [&] (int x, int y){
		x += y;
		if (x >= mod)
			return x - mod;
		return x;
	};
	auto mul = [&] (int x, int y){
		return (x * 1LL * y) % mod;
	};
	vector<vector<int>> ncr(n + 1, vector<int>(n + 1));
	vector<int> fact(n + 1, 1 % mod);
	for(int i = 0; i <= n; ++i){
		ncr[i][0] = ncr[i][i] = 1 % mod;
		for(int j = 1; j < i; ++j){
			ncr[i][j] = add(ncr[i - 1][j],ncr[i - 1][j - 1]);
		}
	}
	for(int i = 1; i <= n; ++i){
		fact[i] = mul(fact[i - 1], i);
	}

    // auto cnt = [&] (int x, const vector<int>& v){
    // 	int idx = -1;
    // 	for(int i = 0; i < v.size(); ++i)
    // 		if (v[i] == x)
    // 			idx = i;
    // 	assert (idx != -1);

    // 	gp_hash_table<int, null_type, custom_hash> r;
    // 	int cur = -1;
    // 	for(int i = idx; i < v.size(); ++i){
    // 		cur = max(cur, v[i]);
    // 		r.insert(cur);
    // 	}
    // 	cur = -1;
    // 	for(int i = idx; i >= 0; --i){
    // 		cur = max(cur, v[i]);
    // 		r.insert(cur);
    // 	}
    // 	return r.size();
    // };
    // do{
    // 	vector<int> tot(n);
    // 	for(int i = 0; i < n; ++i){
    // 		tot[i] = cnt(i, perm);
    // 	}
    // 	trace(tot, perm);
    // }while(next_permutation(all(perm)));
 		


	// for(int i = 1; i <= n; ++i){
	// 	for(int j = 1; j <= i; ++j){
	// 		int lft = j - 1, rgt = i - j;
	// 		int ways = ncr[i - 1][j - 1];

	// 		for(int level = 0; level < n; ++level){
				
	// 		}
	// 	}
	// }

	auto solver = [&] (const auto& self, int N, int M) -> vector<int>{
		if (vis[N][M]){
			return dp[N][M];
		}
		// m - lvl unique values;
		vis[N][M] = true;
		dp[N][M].resize(N + 1, 0);
		if (M == 0){
			dp[N][M][0] = fact[N];
			return dp[N][M];
		}
		if (N == 0 || M > N){
			dp[N][M][0] = fact[N];
			return dp[N][M];
		}
		for(int i = 1; i <= N; ++i){
			int left = i - 1, rgt = N - i;
			int ways = ncr[N - 1][rgt];

			vector<int> t1 = self(self, left, M - 1);
			vector<int> t2 = self(self, rgt, M - 1);

			for(int i = 0; i < t1.size(); ++i){
				for(int j = 0; j < t2.size(); ++j){
					dp[N][M][i + j] = add(dp[N][M][i + j], mul(t1[i], mul(t2[j], ways)));
				}
			}
		}


		if (M == 1){
			dp[N][M].insert(dp[N][M].begin(), 0);
			assert (dp[N][M].back() == 0);
			dp[N][M].pop_back();
		}

		return dp[N][M];

	};


	cout << solver(solver, n, m)[k] % mod << endl;





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