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


	vector<vector<int>> adj(2 * n);
	for(int i = 0; i < 2 * n; ++i){
		int x, y;
		cin >> x >> y;
		--x; --y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}



	auto cnt = [&] (const vector<int>& cycle, int n) {
		const int k = cycle.size();
		long long ways = 0;
		{
			int l = n, r = -1, L = 2 * n, R = n - 1;
			for(int x: cycle){
				if (x >= n){
					L = min(L, x);
					R = max(R, x);
				}
				else{
					l = min(l, x);
					r = max(r, x);
				}
			}
			assert (0 <= l && l <= r && r < n && n <= L && L <= R && R < 2 * n);
			ways += (k >> 1) * (l + 1) * 1LL * (n - r) * 1LL * (L - n + 1) * 1LL * (2 * n - R);
		}
		for(int i = 0; i < k; ++i){
			int l = n, r = -1, L = 2 * n, R = n - 1;

			const int prv_i = (i == 0 ? k - 1 : i - 1);
			for(int j = i, len = 1; len < k; ){
				if (cycle[j] >= n){
					L = min(L, cycle[j]);
					R = max(R, cycle[j]);
				}
				else{
					l = min(l, cycle[j]);
					r = max(r, cycle[j]);
				}
				const int next_j = (j + 1 == k ? 0 : j + 1);

				if ((len & 1) && (len > 1)){
					// trace(l, r, L, R, len);
					assert (0 <= l && l <= r && r < n && n <= L && L <= R && R < 2 * n);
					int cl = l, cr = r, cL = L, cR = R;

					vector<int> z = {cycle[prv_i], cycle[next_j]};
					sort(z.begin(), z.end());
					if (z[0] >= n){
						assert (z[1] >= n);
						if ((cL <= z[0] && z[0] <= cR) || (cL <= z[1] && z[1] <= cR)){
							cL = n - 1;
						}
						else if (z[0] < cL && z[1] > cR){
							cL -= z[0] - n + 1;
							cR += 2 * n - z[1];
						}
						else if (z[0] > cR){
							cR += 2 * n - z[0];
						}
						else{
							assert (z[1] < cL);
							cL -= z[1] - n + 1;
						}
					}
					else{
						assert (z[1] < n);
						if ((cl <= z[0] && z[0] <= cr) || (cl <= z[1] && z[1] <= cr)){
							cl = -1;
						}
						else if (z[0] < cl && z[1] > cr){
							cl -= z[0] + 1;
							cr += n - z[1];
						}
						else if (z[0] > cr){
							cr += n - z[0];
						}
						else{
							assert (z[1] < cl);
							cl -= z[1] + 1;
						}

					}
					ways += (len >> 1) * (cl + 1) * 1LL * (n - cr) * 1LL * (cL - n + 1) * 1LL * (2 * n - cR);

				}
				else if (~len & 1){
					assert (0 <= l && l <= r && r < n && n <= L && L <= R && R < 2 * n);
					int cl = l, cr = r, cL = L, cR = R;
					int total = 0;
					for(int x: {cycle[prv_i], cycle[next_j]}){
						if (x >= n){
							++total;
							if (cL <= x && x <= cR){
								cL = n - 1;
							}
							else if (x > cR){
								cR += (2 * n - x);
							}
							else {
								cL -= x - n + 1;
							}
						}
						else{
							--total;
							if (cl <= x && x <= cr){
								cl = -1;
							}
							else if (x > cr){
								cr += n - x;
							}
							else{
								cl -= x + 1;
							}
						}
					}
					assert (total == 0);
					ways += (len >> 1) * (cl + 1) * 1LL * (n - cr) * 1LL * (cL - n + 1) * 1LL * (2 * n - cR);


				}
				len += 1;
				j = next_j;
			}
		}
		return ways;
	};


	vector<bool> vis(2 * n, false);

	long long ans = 0;
	for(int i = 0; i < 2 * n; ++i){
		if (vis[i])
			continue;
		vector<int> cyc;
		int x = i;
		while (!vis[x]){
			cyc.push_back(x);
			vis[x] = true;
			for(auto e: adj[x]){
				if (!vis[e]){
					x = e;
					break;
				}
			}
		}
		ans += cnt(cyc, n);
	}
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
    // cin >> t;
    while (t--) {
        solve();
    }

    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     
}