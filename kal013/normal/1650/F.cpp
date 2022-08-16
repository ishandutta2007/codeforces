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
/*/-----------------------------Code begins----------------------------------/*/

const long long INF = 1e9 + 10;
void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	cin >> a;

	vector<array<int, 2>> opt(m);
	vector<vector<int>> adj(n);
	for(int i = 0; i < m; ++i){
		int e, p, t;
		cin >> e >> t >> p;
		opt[i] = {p, t};
		adj[e - 1].push_back(i);
	}

	auto process_ids = [&] (vector<int>& ids){
		// sort(all(ids), [&] (int i, int j){
		// 	return opt[i] < opt[j];
		// });
		// vector<int> stk;
		// for(int x: ids){
		// 	if (!stk.empty()){
		// 		int y = stk.back();
		// 		if (opt[x][0] == opt[y][0]){

		// 		}
		// 	}
		// }
	};

	vector<int> ans;
	auto min_time = [&] (const vector<int>& ids){

		const int M = ids.size();

		vector<vector<int>> dp(M + 1, vector<int>(101, INF));
		// vector<array<int, 2>> _prv(101, array<int, 2>{-1, -1});
		vector<vector<array<int, 2>>> _prv(M + 1, vector<array<int, 2>>(101, {-1, -1})); 
		dp[0][0] = 0;

		for(int i = 1; i <= M; ++i){
			int x = ids[i - 1];
			dp[i] = dp[i - 1];
			_prv[i] = _prv[i - 1];
			for(int j = 0; j <= 100; ++j){
				int k = min(100, opt[x][0] + j);
				if (dp[i - 1][j] < INF && dp[i][k] > dp[i - 1][j] + opt[x][1]){
					dp[i][k] = dp[i - 1][j] + opt[x][1];
					_prv[i][k] = {i - 1, j};
				}
			}
		}

		int i = M, j = 100;

		while (i > 0 && j > 0 && _prv[i][j][0] != -1){
			auto [x, y] = _prv[i][j];
			ans.push_back(ids[x]);
			assert (x < i && y < j);
			i = x;
			j = y;
		}
		// for(int x: ids){
		// 	for(int j = 99; j >= 0; --j){
		// 		int k = min(100, opt[x][0] + j);
		// 		if (dp[j] < INF && dp[k] > dp[j] + opt[x][1]){
		// 			dp[k] = dp[j] + opt[x][1];
		// 			_prv[k] = {x, j};
		// 		}
		// 	}
		// 	trace(dp, _prv);
		// 	// for(int j = 99; j >= 0; --j){
		// 	// 	if (dp[j] > dp[j + 1]){
		// 	// 		dp[j] = dp[j + 1];
		// 	// 		_prv[j] = _prv[j + 1];
		// 	// 	}
		// 	// }
		// 	// trace(dp, _prv);
		// }
		// int cur = 100;
		// while (cur > 0 && _prv[cur][0] != -1){
		// 	ans.push_back(_prv[cur][0]);
		// 	cur = _prv[cur][1];
		// }
		return dp[M][100];
	};
	long long done = 0;
	for(int i = 0; i < n; ++i){
		done += min_time(adj[i]);
		// trace(ans);
		if (done > a[i]){
			cout << -1 << endl;
			return;
		}
	}
	cout << ans.size() << endl;
	for(int x: ans){
		cout << x + 1 << " ";
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