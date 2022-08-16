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

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	{
		assert (s.size() == (2 * n));
		int c = 0, d = 0;
		for(auto e: s){
			c  += (e == '(' ? 1 : 0);
			d += (e == ')' ?  0 : 1);
		}
		assert (c == n && d == n);
	}

	vector<int> pref(2 * n + 1);

	for(int i = 1; i <= 2 * n; ++i){
		int z = (s[i - 1] == '(' ? 1 : -1);
		pref[i] = pref[i - 1] + z;
	}
	vector<int> stk;

	vector<int> negative;
	int min_negative = 2 * n + 1, max_negative = -1;


	for(int i = 0; i <= 2 * n; ++i){
		if (pref[i] < 0){
			min_negative = min(min_negative, i);
			max_negative = max(max_negative, i);
			negative.push_back(i);
			continue;
		}
		if (!stk.empty() && pref[stk.back()] >= pref[i])
			continue;
		stk.push_back(i);
	}
	if (negative.empty()){
		cout << "0\n";
		return;
	}

	assert (min_negative <= max_negative);

	int achieve = *max_element(pref.begin(), pref.end());


	array<int, 2> best_l = {-1, -1}, best_r = {-1, -1};

	for(int i = 0; i < min_negative; ++i){
		best_l = max(best_l, {pref[i], i});
	}
	for(int i = max_negative + 1; i <= 2 * n; ++i){
		best_r = max(best_r, {pref[i], i});
	}

	if (best_l[0] + best_r[0] >= achieve){
		cout << "1\n";
		cout << best_l[1] + 1 << " " << best_r[1] << "\n";
		return;
	}

	int idx = max_element(pref.begin(), pref.end()) - pref.begin();

	assert(min_negative < idx && idx < max_negative);
	cout << "2\n";

	cout << min_negative << " " << idx << "\n";
	cout << idx + 1 << " " << max_negative + 1 << "\n";

	// trace(negative, stk, pref);
	// vector<array<int, 2>> ans;
	// int r = -1;
	// while (!negative.empty()){
	// 	int x = negative.back();
	// 	assert (!stk.empty());

	// 	if (r == -1){
	// 		r = x;
	// 		while (stk.back() > r){
	// 			stk.pop_back();
	// 		}
	// 		assert (stk.back() <= r);
	// 	}

	// 	int l = stk.back();
	// 	if (l < x){
	// 		negative.pop_back();
	// 		continue;
	// 	}
	// 	else{
	// 		assert (l > x);
	// 		ans.push_back({l + 1, r + 1});
	// 		r = -1;
	// 	}
	// }
	// if (r != -1){
	// 	int l = stk.back();
	// 	ans.push_back({l + 1, r + 1});	
	// }

	// cout << ans.size() << "\n";
	// for(auto [x, y]: ans){
	// 	cout << x << " " << y << '\n';
	// }


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