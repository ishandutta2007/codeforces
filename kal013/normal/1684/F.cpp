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
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<array<int, 2>> q(m);
	cin >> a >> q;
	{
		vector<int> b = a;
		sort(b.begin(), b.end());
		b.erase(unique(b.begin(), b.end()), b.end());

		for(auto &e: a){
			e = lower_bound(b.begin(), b.end(), e) - b.begin();
		}
		assert ((*max_element(a.begin(), a.end())) < n);
	}

	vector<int> min_left(n, n), max_right(n, -1);
	{
		sort(q.begin(), q.end(), [] (const array<int, 2>& X, const array<int, 2>& Y){
			return make_pair(X[0], -X[1]) < make_pair(Y[0], -Y[1]);
		});

		for(auto &e: q){
			--e[0]; --e[1];
		}
		vector<array<int, 2>> stk;

		for(auto [l, r]: q){
			if (!stk.empty() && stk.back()[1] >= r){
				continue;
			}
			stk.push_back({l, r});
		}
		swap(q, stk);
	}
	int done = -1;
	for(auto [l, r]: q){
		done = max(done, l - 1);
		while (done < r){
			++done;
			assert (min_left[done] == n);
			min_left[done] = l;
		}
	}

	vector<vector<int>> prv(n);



	int left_range = n + 1, right_range = -1;


	vector<vector<int>> adj(n);


	int tot_edges = 0;
	auto add_edge = [&] (int a, int b){
		assert (a < b && 0 <= a && b < n);
		left_range = min(left_range, b);
		right_range = max(right_range, a);

		++tot_edges;
		adj[a].push_back(b);

	};


	for(int i = 0; i < n; ++i){
		if (min_left[i] >= i){
			prv[a[i]].push_back(i);
			continue;
		}

		int x = a[i];
		int idx = min_left[i];


		if (!prv[x].empty()){
			{
				int y = prv[x].back();
				if (y >= idx){
					// ADD EDGE;
					add_edge(y, i);
				}
			}
			{
				auto it = lower_bound(prv[x].begin(), prv[x].end(), idx);
				if (it != prv[x].end()){
					int z = *it;
					assert (z >= idx && z < i);
					if (z != prv[x].back()){
						// ADD EDGE;
						add_edge(z, i);
					}
				}
			}

		}
		prv[x].push_back(i);
	}


	if (left_range > n){
		assert (right_range == -1 && tot_edges == 0);
		cout << 0 << "\n";
		return;
	}


	auto pos = [&] (int len){
		int covered = 0;

		for(int i = 0; i < len; ++i){
			covered += (adj[i].size());
		}

		vector<int> point(n);

		for(int i = 0; i + len <= n; ++i){
			if (covered == tot_edges){
				return true;
			}

			covered -= point[i] + adj[i].size();
			for(int x: adj[i]){
				if (x < i + len){
					++covered;
				}
				point[x]++;
			}

			if (i + len < n){
				covered += point[i + len];
				covered += adj[i + len].size();
			}
		}
		return false;
	};

	int lo = 1, hi = n, ans = n;
	while (lo <= hi){
		int mid = (lo + hi) >> 1;
		if (pos(mid)){
			ans = mid;
			hi = mid - 1;
		}
		else{
			lo = mid + 1;
		}
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
    cin >> t;
    while (t--) {
        solve();
    }

    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     
}