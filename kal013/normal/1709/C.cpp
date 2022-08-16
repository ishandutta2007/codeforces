/*/ Author: kal013 /*/
// #pragma GCC optimize ("O3")
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
	string s;
	cin >> s;
    int n = s.size();
    if (n & 1){
    	cout << "NO\n";
    	return;
    }
    auto check = [] (const string& S) {
    	int c = 0;
    	for(const auto& x: S){
    		assert (x != '?');
    		c += (x == '(' ? 1 : -1);
    		if (c < 0)
    			return false;
    	}
    	return true;
    };


    int open = count(s.begin(), s.end(), '('), close = count(s.begin(), s.end(), ')');
    int question = n - open - close;
	string t = s;

    {
    	int ropen = (n >> 1) - open, rclose = (n >> 1) - close;
    	if (ropen < 0 || rclose < 0){
    		cout << "NO\n";
    		return;
    	}
    	for(auto &e: t){
    		if (e == '?'){
    			if (ropen > 0)
    				e = '(', --ropen;
    			else
    				e = ')', --rclose;
    		}
    	}
    	assert (ropen == 0 && rclose == 0);
		if (!check(t)){
			cout << "NO\n";
			return;
		}    	
    }
    if (question <= 1 || (close == (n >> 1)) || (open == (n >> 1))){
    	cout << "YES\n";
    	return;
    }
    int lo = -1, rc = n + 1;
    for(int i = 0; i < n; ++i){
    	if (s[i] == '?'){
    		if (t[i] == '(')
    			lo = i;
    		else
    			rc = min(rc, i);
    	}
    }
    assert (lo >= 0 && lo < rc && rc < n);
    swap(t[lo], t[rc]);
    if (check(t)){
    	cout << "NO\n";
    }
    else{
    	cout << "YES\n";
    }


    
}  

int main(){
    
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); 
    std::cout << std::fixed << std::setprecision(25);
    std::cerr << std::fixed << std::setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();

    int t = 1;
    cin >> t;

    for(int testcase = 1; testcase <= t; ++testcase) {
        // std::cout << "Case #" << testcase << ": ";
        solve();
    }

    auto stop = std::chrono::high_resolution_clock::now(); 
    long double duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
    #ifdef __LOCAL_KAL013__
        std::cerr << "Time taken : " << duration / 1e9 << "s" << std::endl;     
    #endif
}