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

template<const long long N, const int T>
struct block{
	array<array<long long, 2>, N> values;
	vector<array<long long, 3>> big_v;
	void add(int c, int r){
		int t = (c / r) + 1;
		values[0][0] += r;
		if (t < N){
			values[t][0] -= r;
			values[t][1] += c;
		}
		else if (t < T){
			big_v.push_back({t, -r, c});
		}
	}

	void finalize() {
		for(int i = 1; i < N; ++i){
			for(int j = 0; j < 2; ++j){
				values[i][j] += values[i - 1][j];
			}
		}
		sort(big_v.begin(), big_v.end());
		vector<array<long long, 3>> stk;

		for(auto [t, m, b]: big_v){
			if (!stk.empty() && stk.back()[0] == t){
				stk.back()[1] += m;
				stk.back()[2] += b;
			}
			else{
				stk.push_back({t, m, b});
			}
		}
		swap(big_v, stk);
		array<long long, 2> cur = values[N - 1];
		for(int i = 0; i < big_v.size(); ++i){
			big_v[i][1] += cur[0];
			big_v[i][2] += cur[1];
			cur = {big_v[i][1], big_v[i][2]};
		}
	}
	long long query(long long t) {
		if (big_v.empty() || t < big_v[0][0]){
			return values[min(t, N - 1)][0] * t + values[min(t, N - 1)][1];
		}
		auto it = upper_bound(big_v.begin(), big_v.end(), array<long long, 3>{t + 1, LLONG_MIN, LLONG_MIN});
		assert (it != big_v.begin());
		--it;
		auto [_, m, b] = *it;
		return m * t + b;
	}
};

void solve(){
	int n;
	cin >> n;
	vector<array<int, 2>> cost(n);
	cin >> cost;

	const int bsize = sqrt(n) + 2;
	int n_blocks = (n + bsize - 1) / bsize;
	vector<block<1'000, 2'00'005>> q(n_blocks);

	for(int i = 0, idx = 0; i < n; i += bsize, ++idx){
		for(int j = i; j < i + bsize && j < n; ++j){
			q[idx].add(cost[j][0], cost[j][1]);
		}
		q[idx].finalize();
	}

	vector<bool> is_zero(n_blocks, false);
	vector<int> time_done(n_blocks, 0);
	vector<long long> cur(n);
	for(int i = 0; i < n; ++i){
		cur[i] = cost[i][0];
	}
	int _q;
	cin >> _q;
	long long ans = 0;
	for(int i = 0; i < _q; ++i){
		long long t, h;
		cin >> t >> h;

		for(int i = 0; i < n_blocks && h > 0; ++i){
			if (is_zero[i]){
				long long extra = q[i].query(t - time_done[i]);

				if (extra <= h){
					time_done[i] = t;
					h -= extra;
					continue;
				}
				for(int j = i * bsize; j < (i + 1) * bsize && j < n; ++j){
					assert (cur[j] == 0);
					cur[j] = min(cost[j][0] + 0LL, cur[j] + (t - time_done[i]) * 1LL * cost[j][1]);
				}

				time_done[i] = t;

				for(int j = i * bsize; j < (i + 1) * bsize && j < n && h > 0; ++j){
					long long x = min(cur[j], h);
					h -= x;
					cur[j] -= x;
				}
				is_zero[i] = (h > 0);
				assert (!is_zero[i]);
			}
			else{

				for(int j = i * bsize; j < (i + 1) * bsize && j < n; ++j){
					cur[j] = min(cost[j][0] + 0LL, cur[j] + (t - time_done[i]) * 1LL * cost[j][1]);
				}
				time_done[i] = t;

				for(int j = i * bsize; j < (i + 1) * bsize && j < n && h > 0; ++j){
					long long x = min(cur[j], h);
					h -= x;
					cur[j] -= x;
				}
				is_zero[i] = (h > 0);
			}
		}
		ans += h;
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