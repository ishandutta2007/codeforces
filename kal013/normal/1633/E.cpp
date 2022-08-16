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



struct dsu{
	vector<int> par;
	void init(int n){
		par.assign(n, -1);
	}
	int find(int x){
		return (par[x] < 0 ? x : par[x] = find(par[x]));
	}

	bool merge(int x, int y){
		x = find(x);
		y = find(y);
		if (x == y)
			return false;

		if (par[x] > par[y])
			swap(x, y);
		par[x] += par[y];
		par[y] = x;
		return true;
	}
};

const long long INF = 1e15;
void solve(){
	int n, m;
	cin >> n >> m;

	vector<array<long long, 3>> edges(m);
	cin >> edges;
	for(auto &[u, v, w]: edges){
		--u; --v;
	}
	sort(all(edges), [&] (const array<long long, 3>& X, const array<long long, 3>& Y){
		return X[2] < Y[2];
	});

	dsu T;


	vector<vector<array<long long, 3> >> dp_l(m + 1), dp_r(m + 1); 

	auto self_merge = [&] (vector<array<long long, 3>>& v){
		if (v.empty())
			return;
		sort(all(v));

		int idx = 0;

		for(int i = 1; i < v.size(); ++i){
			if (v[idx][0] == v[i][0]){
				v[idx][1] += v[i][1];
				v[idx][2] += v[i][2];
			}
			else{
				++idx;
				if (idx != i){
					v[idx] = v[i];
				}
			}
		}
		v.resize(idx + 1);
	};
	auto coster = [&] (const vector<array<long long, 3>>& l, const vector<array<long long, 3>>& r, long long lo, long long hi, int id){
		long long tot = 0;

		vector<array<long long, 3>> smaller, bigger;
		int n1 = l.size(), n2 = r.size();
		for(int i = 0; i < n1; ++i){
			T.init(n);
			for(int j = 0; j < i; ++j){
				assert (T.merge(l[j][0], l[j][1]));
			}
			auto [a, b, c] = l[i];
			assert (T.find(a) != T.find(b));

			long long cur_range = hi;
			for(int j = 0; j < n2; ++j){
				auto [u, v, w] = r[j];
				T.merge(u, v);
				if (T.find(a) == T.find(b)){
					cur_range = min(cur_range, (w + c) >> 1);
					break;
				}
			}
			if (cur_range > lo)
				smaller.push_back({cur_range, -c, 1});
		}

		for(int i = 0; i < n2; ++i){
			T.init(n);

			for(int j = 0; j < i; ++j){
				T.merge(r[j][0], r[j][1]);
			}

			auto [a, b, c] = r[i];
			assert (T.find(a) != T.find(b));

			long long cur_range = lo;
			for(int j = 0; j < n1; ++j){
				auto [u, v, w] = l[j];
				T.merge(u, v);
				if (T.find(a) == T.find(b)){
					cur_range = max(cur_range, (w + c) >> 1);
					break;
				}
			}
			if (cur_range < hi)
				bigger.push_back({cur_range + 1, c, -1});
		}

		self_merge(smaller);
		self_merge(bigger);


		for(int i = (int)(smaller.size()) - 2; i >= 0; --i){
			smaller[i][1] += smaller[i + 1][1];
			smaller[i][2] += smaller[i + 1][2];
		}
		for(int i = 1; i < bigger.size(); ++i){
			bigger[i][1] += bigger[i - 1][1];
			bigger[i][2] += bigger[i - 1][2];
		}

		dp_l[id] = smaller;
		dp_r[id] = bigger;

	};

	auto preprocess = [&] (vector<array<long long, 3>>& x){
		T.init(n);
		vector<array<long long, 3>> K;
		for(auto& [u, v, w]: x){
			if (T.merge(u, v))
				K.push_back({u, v, w});
		}
		x = K;
	};


	vector<long long> values;
	for(int i = 0; i <= m; ++i){
		vector<array<long long, 3>> _left(edges.begin(), edges.begin() + i), _right(edges.begin() + i, edges.end());
		reverse(all(_left));

		preprocess(_left);
		preprocess(_right);

		
		long long lo = (i == 0 ? -1 : edges[i - 1][2]), hi = (i == m ? INF: edges[i][2]);

		values.push_back(hi);
		coster(_left, _right, lo, hi, i);
		// (lo, hi]
	}


	auto ans_query = [&] (long long x){
		auto it = lower_bound(all(values), x) - values.begin();
		long long ans = 0;

		int cnt = 0;
		{
			auto it2 = lower_bound(all(dp_l[it]), array<long long, 3>{x, -INF, -INF});
			if (it2 != dp_l[it].end()){
				auto Y = *it2;
				ans += Y[1] + Y[2] * x;
				cnt += abs(Y[2]);
			}
		}
		
		{
			auto it2 = lower_bound(all(dp_r[it]), array<long long, 3>{x + 1, -INF, -INF});
			if (it2 != dp_r[it].begin()){
				--it2;
				auto Y = *it2;
				ans += Y[1] + Y[2] * x;
				cnt += abs(Y[2]);
			}
		}

		// assert (cnt == n - 1);
		return ans;

	};

	long long p, k, a, b, c;
	cin >> p >> k >> a >> b >> c;
	long long q;

	long long ret = 0;
	for(int i = 0; i < p; ++i){
		cin >> q;

		ret ^= ans_query(q);
		// cout << ans_query(q) << endl;
	}

	for(int i = p; i < k; ++i){
		q = (q *  a  + b) % c;
		ret ^= ans_query(q);
		// trace(q);
		// cout << ans_query(q) << endl;

	}
	cout << ret << endl;

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