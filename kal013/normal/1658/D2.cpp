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
	int l, r;
	cin >> l >> r;
	vector<int> a(r - l + 1);
	cin >> a;

	sort(a.begin(), a.end());
	int n = a.size();


	for(int i = 1; i < n; ++i){
		if (a[i] == a[i - 1]){
			assert (false);
			return;
		}
	}

	auto intersect = [] (const vector<int>& x, const vector<int>& y) {
		gp_hash_table<int, null_type, custom_hash> t;
		for(auto e: x){
			t.insert(e);
		}
		vector<int> ans;
		for(auto e: y){
			if (t.find(e) != t.end())
				ans.push_back(e);
		}
		return ans;
	};


	auto simple_solver = [] (int l, int r, vector<int> a) {
		assert (l == 0);

		int x = 0;
		vector<int> ans;
		while (true){
			assert (a.size() == (r + 1));
			if ((r & (r + 1)) == 0){
				ans = a;
				for(auto &e: ans){
					e ^= x;
				}
				break;
			}
			int msb = 31 - __builtin_clz(r);
			vector<vector<int>> nw(2);

			for(auto e: a){
				if (e & (1 << msb)){
					nw[1].push_back(e ^ (1 << msb));
				}
				else{
					nw[0].push_back(e);
				}
			}

			int mx_idx = (nw[0].size() > nw[1].size() ? 0 : 1);
			assert (nw[mx_idx].size() == (1 << msb));
			
			if (mx_idx == 1){
				x ^= (1 << msb);
			} 
			a = nw[mx_idx ^ 1];
			r -= (1 << msb);
		}	

		return ans;


	};

	vector<int> ans;
	if (l == 0){
		ans = simple_solver(l, r, a);
	}
	else if (l == r){
		ans = {a[0] ^ l};
	}
	else{
		int x = 0;
		while (true){
			if (l == 0){
				auto ret = simple_solver(l, r, a);
				for(auto &e: ret){
					ans.push_back(e ^ x);
				}
				break;
			}

			int msb = 31 - __builtin_clz(r);

			if (l & (1 << msb)){

				int k = a[0] & (1 << msb);
				for(auto &e: a){
					assert ((e & (1 << msb)) == k);
					e ^= k;
				}

				x ^= (k ^ (1 << msb));

				l ^= (1 << msb);
				r ^= (1 << msb);
				continue;
			}
			vector<vector<int>> nw(2);

			for(auto &e: a){
				if (e & (1 << msb)){
					nw[1].push_back(e ^ (1 << msb));
				}
				else{
					nw[0].push_back	(e);
				}
			}	
			array<int, 2> cnt = {(1 << msb) - l, r - (1 << msb) + 1};	
			for(int j = 0; j < 2; ++j){
				if (cnt[0] == nw[j].size()){

					vector<int> v1 = nw[j], v2 = nw[j ^ 1];
					int mask = (1 << msb) - 1;
					for(auto &e: v1){
						e ^= mask;
					}
					auto ret = intersect(simple_solver(0, mask ^ l, v1), simple_solver(0, r ^ (1 << msb), v2));


					for(auto &e: ret){
						e ^= (j << msb);
						ans.push_back(e ^ x);
					}
				}
			}
			break;
		}
	}


	assert (!ans.empty());
	cout << ans[0] << endl;
	// auto dfs = [&intersect] (const auto& self, int l, int r, int msb, vector<int> a) -> vector<int> {

	// 	assert ((1 << (msb + 1)) > r);
	// 	assert (a.size() == (r - l + 1));
	// 	assert (l <= r);

	// 	if (l == r){
	// 		return vector<int>(a[0]);
	// 	}

	// 	int x1 = (r & (1 << msb)), y1 = (l & (1 << msb));

	// 	if (x1 != y1){
	// 		vector<int> ans;

	// 		vector<int> cnt(2), own(2);

	// 		for(int i = l; i <= r; ++i){
	// 			if (i & (1 << msb)){
	// 				++own[1];
	// 			}
	// 			else{
	// 				++own[0];
	// 			}
	// 		}

	// 		vector<int> nw(2);

	// 		for(int e: a){
	// 			if (e & (1 << msb)){
	// 				nw[1].push_back(e ^ (1 << msb));
	// 			}
	// 			else{
	// 				nw[0].push_back(e ^ (1 << msb));
	// 			}
	// 		}

	// 		if (cnt[0] != cnt[1]){
	// 		}

	// 		return ans;	
	// 	}
	// 	else{
	// 		int k = (a[0] & (1 << msb));

	// 		for(auto &e: a){
	// 			assert ((e & k) == k);
	// 			e ^= k;
	// 		}
	// 		vector<int> ans = self(self, l ^ x1, r ^ x1, msb - 1, a);
	// 		for(auto &e: ans){
	// 			e ^= k ^ x1;
	// 		}
	// 		return ans;
	// 	}
	// };

	// dfs(dfs, l, r, 16, a);

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