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

void solve(){
    int n, m, q;
    cin >> n >> m >> q;
    bool swp = false;
    if (n > m){
    	swp = true;
    	swap(n, m);
    }
    vector<gp_hash_table<int, null_type, custom_hash>> T(n + 1);
    for(int i = 0; i < q; ++i){
    	int a, b;
    	cin >> a >> b;
    	if (swp)
    		swap(a, b);
    	T[a].insert(b); 
    }
    


    auto is_special = [&] (int x, int y){
    	return (x <= n && T[x].find(y) != T[x].end());
    };

    vector<int> ans(m + 1, INT_MAX);
    {
    	ans[m] = 0;
    	for(int z = m - 1; z >= 1; --z){
    		int s = n + z + (is_special(n, z) ? 1 : 0);
    		ans[z] = ans[min(s, m)] + 1;
 			assert (ans[z] >= ans[z + 1]);
    	}
    }
    int J = max(n, m);

    vector<int> X(n + 1, -1), Y(m + 1, -1);
    int ret = INT_MAX;
    X[1] = 1;
    Y[1] = 1;

    auto upd = [&] (int a, int b){
    	a = min(a, n); b = min(b, m);
    	X[a] = max(X[a], b);
    	Y[b] = max(Y[b], a);
    };
    int lim = INT_MAX;
    for(int z = 0; z < min(lim, ret) ; ++z){
    	if (X[n] == m){
    		assert (Y[m] == n);
    		ret = min(z, ret);
    		break;
    	}
    	if (X[n] != -1){
    		lim = min(lim, z + 5);
    		ret = min(ret, z + ans[X[n]]);
    	}
    	vector<int> nx = X, ny = Y;
    	for(int k = 1; k <= J; ++k){
    		if (k <= n && nx[k] >= 1){
    			assert (nx[k] <= m);
    			long long s = k + nx[k] + (is_special(k, nx[k]) ? 1 : 0);
    			upd(s, nx[k]);
    			upd(k, s);
    		}

    		if (k <= m && ny[k] >= 1){
    			assert (ny[k] <= n);
    			long long s = min(ny[k] + k + (is_special(ny[k], k) ? 1 : 0), J);
    			upd(s, k);
    			upd(ny[k], s);
    		}
    	}

    	for(int j = m - 1; j >= 1; --j){
    		Y[j] = max(Y[j], Y[j + 1]);
    	}
    	for(int j = n - 1; j >= 1; --j){
    		X[j] = max(X[j], X[j + 1]);
    	}
    }

    cout << ret << endl;

    // auto flat_distance = [&] (const array<int, 2>& X, const array<int, 2>& Y){
    // 	long long ans = INT_MAX;
    // 	{
    // 		long long cans = 0;
    // 		if (Y[0] > X[0])
    // 			cans += (Y[0] - X[0] + X[1] - 1)/ X[1];
    // 		else if (Y[0] < X[0])
    // 			cans += 1;

    // 		if (Y[1] > X[1])
    // 			cans += (Y[1] - X[1] + max(X[0], Y[0]) - 1)/ max(X[0], Y[0]);
    // 		else if (Y[1] < X[1])
    // 			cans += 1;

    // 		ans = min(ans, cans);
    // 	}

    // 	{
    // 		long long cans = 0;
    // 		if (Y[1] > X[1])
    // 			cans += (Y[1] - X[1] + X[0] - 1)/ X[0];
    // 		else if (Y[1] < X[1])
    // 			cans += 1;

    // 		if (Y[0] > X[0])
    // 			cans += (Y[0] - X[0] + max(X[1], Y[1]) - 1)/ max(X[1], Y[1]);
    // 		else if (Y[0] < X[0])
    // 			cans += 1;

    // 		ans = min(ans, cans);	
    // 	}
    // 	return ans;
    // };


    // auto one_distance = [&] (const array<int, 2>& X, const array<int, 2>& Y){
    // 	long long s = X[0] + X[1] + (is_special(X[0], X[1]) ? 1 : 0);
    // 	return min({flat_distance(X, Y), 1 + flat_distance({s, X[1]}, Y), 1 + flat_distance({X[0],s }, Y)});
    // };

    // auto process_vec = [] (vector<array<int,2>>& V){
    // 	long long s = 0;
    // 	for(auto &e: V){
    // 		s = max(s, e[0] + e[1] + 0LL);
    // 	}
    // 	sort(all(V));
    // 	int idx = 0;
    // 	for(int i = 0; i < V.size(); ++i){
    // 		if (V[i][0] + V[i][1] == s){
    // 			if (i > idx)
    // 				swap(V[i], V[idx]);
    // 			++idx;
    // 		}
    // 	}
    // 	V.resize(idx);
    // 	int n = V.size();
    // 	while (n > 2){
    // 		swap(V[n - 1], V[n - 2]);
    // 		--n;
    // 		V.pop_back();
    // 	}
    // };


    // vector<vector<array<int, 2>>> dist(200);
    // dist[0].push_back({1, 1});
    // map<array<int, 2>, int> vis; vis[{1, 1}] = 0;
    // Q.erase({1, 1});

    // for(int j = 0; vis.find({n, m}) == vis.end(); ++j){
    // 	auto &cur = dist[j];
    // 	assert (cur.size() <= 2);
    	
    // 	for(auto x: cur){
    // 		long long s = x[0] + x[1] + (is_special(x[0], x[1]) ? 1 : 0);
    // 		dist[j + 1].push_back({x[0], s});
    // 		dist[j + 1].push_back({s, x[0]});
    // 	}	

    // 	for(auto Z: Q){
    // 		long long d1 = INT_MAX;
    // 		for(auto x: cur){
	   //  		d1 = min(d1, one_distance(x, Z));
    // 		}
    // 		if (d1 == 0)
    // 			continue;
    // 		if (j + d1 < 200)
    // 			dist[j + d1].push_back(Z);
    // 	}


    // 	for(auto &e: dist[j + 1]){
    // 		if (Q.find(e) != Q.end()){
    // 			vis[e] = j + 1;
    // 			Q.erase(e);
    // 		}
    // 	}
    // 	process_vec(dist[j + 1]);
    // }

    // cout << vis[{n, m}] << endl;



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