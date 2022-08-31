/*/ Author: kal013 /*/
#ifndef __LOCAL_KAL013__
    #pragma GCC optimize("O3,unroll-loops")
    // #pragma GCC target("avx,avx2,sse4.2,bmi,bmi2,popcnt,lzcnt") // Gives SIGILL on SPOJ
#endif

#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

template<class T> 
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

template<class T>
using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T> >; 

/*/---------------------------IO(Debugging)----------------------/*/

template<typename T_container, typename T = typename std::enable_if<!std::is_same<T_container, std::string>::value, typename T_container::value_type>::type> 
std::istream& operator >> (std::istream &is, T_container &v) { 
   for(T &x : v) {is >> x;} return is;
}
#ifdef __SIZEOF_INT128__
std::ostream& operator << (std::ostream &os, __int128 const& value){
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
std::istream& operator >> (std::istream& is, __int128& T){
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

#ifdef __LOCAL_KAL013__
    #include "debug.h"
#else
    #define trace(...) 1
#endif

/*/---------------------------RNG----------------------/*/
inline int64_t random_long(int64_t l = LLONG_MIN, int64_t r = LLONG_MAX){
    static std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int64_t> generator(l,r);
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
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    template<typename L, typename R>
    size_t operator()(std::pair<L,R> const& Y) const{
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(Y.first * 31ull + Y.second + FIXED_RANDOM);
    }
};
/*/-----------------------------Code begins----------------------------------/*/


void solve(){
    int n, m;
    cin >> n >> m;
	vector<array<int, 2>> rain(n);
	cin >> rain;

	vector<array<int, 3>> compressed(n);
	int mx = 0;

	vector<int64_t> t; t.reserve(3 * n);

	{
		for(auto [x, p]: rain){
			t.push_back(x - p);
			t.push_back(x);
			t.push_back(p + x);
		}
		sort(t.begin(), t.end());	
		t.erase(unique(t.begin(), t.end()), t.end());
		mx = t.size();
		for(int i = 0; i < n; ++i){
			auto [x, p] = rain[i];
			int a = lower_bound(t.begin(), t.end(), x - p) - t.begin();
			int b = lower_bound(t.begin(), t.end(), x ) - t.begin();
			int c = lower_bound(t.begin(), t.end(), p + x) - t.begin();
			// assert (c < mx);
			compressed[i] = {a, b, c};
		}
	}
	vector<int64_t> p1(mx + 1), p2(mx + 1);
	vector<int64_t> ans(mx);

	for(int i = 0; i < n; ++i) {
		auto [a, b, c] = compressed[i];
		auto [x, p] = rain[i];
		p2[a] += 1;
		p1[a] -= (x - p);

		p2[b + 1] -= 1;
		p1[b + 1] += x - p;

		p2[b] -= 1;
		p1[b] += x + p;
		ans[b] -= p;


		p2[c + 1] += 1;
		p1[c + 1] -= p + x;
	}


	for(int i = 0; i < mx; ++i){
		p1[i + 1] += p1[i];
		p2[i + 1] += p2[i];
		ans[i] += p1[i] + (t[i] * p2[i]);

	}
	assert (p1[mx] == 0 && p2[mx] == 0);

	if (*max_element(ans.begin(), ans.end()) <= m){
		cout << string(n, '1') << '\n';
		return;
	}

	string ret(n, '?');

	int min_id = mx + 10, max_id = -1;

	for(int i = 0; i < mx; ++i) {
		if (ans[i] > m){
			min_id = min(min_id, i);
			max_id = max(max_id, i);
		}
	}

	vector<int> ord(n); iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&] (int x, int y) {
		return rain[x] < rain[y];
	});
	int lset = -1;

	int64_t max_ls = INT_MIN;

	set<array<long long, 2>> rset;

	auto add = [&] (int idx) {
		if (ans[idx] <= m)
			return;
		max_ls = max(max_ls, ans[idx] - m - t[idx]);
	};
	auto remove = [&] (int idx) {
		if (ans[idx] <= m)
			return;
		rset.erase({ans[idx] - m + t[idx], idx});
	};
 	for(int i = 0; i < mx; ++i){
		if (ans[i] <= m){
			continue;
		}
		rset.insert({ans[i] - m + t[i], i});
	}
	int rptr = -1;
	for(int i : ord){
		auto [a, b, c] = compressed[i];
		if (a > min_id || c < max_id){
			ret[i] = '0';
			continue;
		}
		while(lset + 1 < b) {
			++lset;
			add(lset);
			remove(lset);
		}
		auto [x, p] = rain[i];
		if (max_ls + (x - p) > 0) {
			ret[i] = '0';
			continue;
		}
		if (!rset.empty()){
			auto X = *rset.rbegin();
			if (X[0] - (x + p) > 0) {
				ret[i] = '0';
				continue;
			}
		}
		ret[i] ='1';
 	}



	cout << ret << '\n';
}  

int main(){
    
    cin.tie(nullptr) -> sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(25);
    std::cerr << std::fixed << std::setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();

    int t = 1;
    cin >> t;

    for(int testcase = 1; testcase <= t; ++testcase) {
        // cout << "Case #" << testcase << ": ";
        solve();
    }
    
    #ifdef __LOCAL_KAL013__
    auto stop = std::chrono::high_resolution_clock::now(); 
    long double duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
        std::cerr << "Time taken : " << duration / 1e9 << "s" << std::endl;     
    #endif
}