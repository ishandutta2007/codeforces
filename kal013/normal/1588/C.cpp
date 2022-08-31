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
    int n;
    cin >> n;
    vector<long long> a(n);
    cin >> a;

    auto is_good = [&] (int l, int r){
    	--l; --r;

    	int k = a[l];

    	for(int j = l + 1; j <= r; ++j){
    		if (k > a[j])
    			return false;
    		k = a[j] - k;
    	}
    	return k == 0;
    };

    auto tot_c = [&] (){
    	int ans = 0;
    	for(int i = 1; i <= n; ++i){
    		for(int j = i; j <= n; ++j){
    			ans += is_good(i, j);
    		}
    	}
    	return ans;
    };


    vector<long long> pref(n + 1);
    for(int i = 1; i <= n; ++i){
    	pref[i] = a[i - 1] - pref[i - 1];
    }


    auto get_sum = [&] (int l, int r){
    	if ((l^r) & 1)
    		return pref[r] - pref[l - 1];
    	return pref[r] + pref[l - 1];
    };

    // vector<int> r_ids[2];
    {
    	long long ans = 0;
    	vector<array<long long, 2>> stks[2];
    	gp_hash_table<long long, ordered_set<int>, custom_hash> o[2];

    	for(int i = n; i >= 1; --i){
    		// same idx;

    		long long  r = n + 1;


    		int idx = i & 1;

    		while (!stks[idx].empty()){
    			if (stks[idx].back() > array<long long, 2>{pref[i], i}){
    				stks[idx].pop_back();
    			}
    			else{
    				break;
    			}
    		}
    		stks[idx].push_back({pref[i], i});

    		o[idx][pref[i]].insert(i);

    		auto it = lower_bound(all(stks[idx]), array<long long, 2>{-pref[i - 1], -1});
    		if (it == stks[idx].begin()){

    		}
    		else{
    			--it;
    			r = min(r, (*it)[1]);
    		}

    		auto it2 = lower_bound(all(stks[idx ^ 1]), array<long long, 2>{pref[i - 1], -1});
    		if (it2 == stks[idx ^ 1].begin()){

    		}
    		else{
    			--it2;
    			r = min(r, (*it2)[1]);
    		}


    		for(int j = 0; j < 2; ++j){
    			if (j == idx){
    				ans += o[j][-pref[i - 1]].order_of_key(r);
    			}
    			else{
    				ans += o[j][pref[i - 1]].order_of_key(r);
    			}
    		}
    	}

    	cout << ans << endl;
    	return;
    }
    int lo = 0;
    ordered_set<array<long long, 2>> o[2];
    o[0].insert({0, 0});


    auto update_lo = [&] (int x){
    	while (lo < x){
    		o[lo & 1].erase({pref[lo], lo});
    		++lo;
    	}
    };


    vector<int> best_ids(n + 1,1);

    vector<int> q(n + 1);
    for(int i = 2; i <= n; ++i){
    	if (a[i - 1] > a[i - 2]){
    		best_ids[i] = i;
    		continue;
    	}
    	else{
    		int z = best_ids[i - 2];
    		while (z > 1 && get_sum(z - 1, i) <= 0){
    			--z;
    		}
    		best_ids[i] = z;
    	}
    }

    long long ans = 0;
    for(int i = 1; i <= n; ++i){
    	int idx = i & 1;
    	while (!o[idx ^ 1].empty()){
    		//
    		auto it = o[idx ^ 1].lower_bound({-pref[i], -1});
    		if (it != o[idx ^ 1].begin()){
    			--it;
    			auto X = *it;
    			assert (get_sum(X[1] + 1, i) < 0 && get_sum(X[1] + 2, i) < 0);

    			update_lo(X[1] + 2);
    		}
    		else
    			break;
    	}
    	assert (lo < i);
    	// ans += i - max(lo, best_ids[i] - 1);
    	// q[i] = max(lo + 1, best_ids[i]);
    	best_ids[i] = max(best_ids[i], lo + 1);
    	long long val = pref[i];
    	// trace(idx);
    	for(int j = 0; j < 2; ++j){
    		ans +=  o[idx].order_of_key({val, n + 100}) - o[idx].order_of_key({val, best_ids[i] - 1});
    		// if (ans > 0)
    			// trace(j, i, idx, val, best_ids[i], o[idx]);

    		val *= -1;
    		idx ^= 1;
    	}
    	o[i & 1].insert({pref[i], i});
    }

    assert (ans == tot_c());

    // trace(best_ids);
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
    cin >> t;
    while (t--) {
        solve();
    }

    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     
}