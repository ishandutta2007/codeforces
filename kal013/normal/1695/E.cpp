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

const int N = 3e5 + 100;

struct DSU{
	vector<int> dsu;

	DSU(int n) : dsu(n, -1) {};

	int find(int x){
		return dsu[x] < 0 ? x : dsu[x] = find(dsu[x]);
	}
	bool merge(int x, int y){
		x = find(x);
		y = find(y);
		if (x == y){
			return false;
		}

		if (dsu[x] > dsu[y]) swap(x, y);
		dsu[x] += dsu[y];
		dsu[y] = x;
		return true;
	}

	bool same(int x, int y){
		return find(x) == find(y);
	}
};

void solve(){
	int n;
	cin >> n;
	vector<array<int, 2>> edges;

	DSU Q(2 * n);

	vector<vector<int>> adj(2 * n);

	vector<int> deg(2 * n);

	vector<bool> alive(n, true);
	for(int i = 0; i < n; ++i){
		int x, y;
		cin >> x >> y;
		--x; --y;
		++deg[x]; ++deg[y];
		Q.merge(x, y);

		edges.push_back({x, y});
		adj[x].push_back(i);

		if (x != y){
			adj[y].push_back(i);
		}
	}

	vector<vector<int>> comps(2 * n);

	for(int i = 0; i < 2 * n; ++i){
		comps[Q.find(i)].push_back(i);
	}


	vector<array<int, 2>> ans;

	vector<bool> vis(2 * n, false);

	vector<vector<int>> nadj(2 * n), extra(2 * n);
	

	string poly[2], mono[2];


	auto add2edges = [&] (int x, int y){
		assert (alive[x] && alive[y] && x != y);
		auto [a, b] = edges[x];
		auto [c, d] = edges[y];

		if (a != c && a != d){
			swap(a, b);

		}
		assert (a == c || a == d);
		if (a != c){
			swap(c, d);
		}

		ans.push_back({a, b});
		ans.push_back({d, c});

		poly[0] += "LR";
		poly[1] += "LR";

		mono[0] += "UU";
		mono[1] += "DD";

		alive[x] = false;
		alive[y] = false;
	};


	auto add3edges_common = [&] (int x, int y, int z){
		assert (alive[x] && alive[y] && alive[z] && x != y && y != z && z != x);
		auto [a, b] = edges[x];
		auto [c, d] = edges[y];
		auto [e, f] = edges[z];

		int r = -1;
		for(int k: {a, b}){
			int cnt = ((e == k || f == k) ? 1 : 0) + ((c == k || d == k) ? 1 : 0);
			if (cnt == 2){
				r = k;
				break;
			}
		}
		if (a != r){
			swap(a, b);
		}
		if (c != r){
			swap(c, d);
		}
		if (e != r){
			swap(e, f);
		}

		assert (a == c && c == e);
		ans.push_back({a, d}); ans.push_back({b, a}); ans.push_back({a, f});

		poly[0] += "LRU"; poly[1] += "LRD";
		mono[0] += "ULR"; mono[1] += "DLR";

		alive[x] = false;
		alive[y] = false;
		alive[z] = false;
	
	};


	auto common = [&] (int x, int y){
		auto [a, b] = edges[x];
		auto [c, d] = edges[y];

		if (a == c || a == d)
			return a;
		if (b == c || b == d)
			return b;

		return -1;
	};


	auto add3edges_chain = [&] (int x, int y, int z){
		assert (alive[x] && alive[y] && alive[z] && x != y && y != z && z != x);
		


		if (common(x, y) == -1){
			assert (common(x, z) != -1 && common(z, y) != -1);
			swap(z, y);
		}
		else if (common(y, z) == -1){
			assert(common(x, z) != -1);
			swap(x, y);
		}

		auto [a, b] = edges[x];
		auto [c, d] = edges[y];
		auto [e, f] = edges[z];

		if (a == common(x, y)){
			swap(a, b);
		}
		if (b != c)
			swap(c, d);
		assert (b == c);

		assert (d == e || d == f);
		if (e != d)
			swap(e, f);

		assert (b == c && d == e);


		ans.push_back({a, b}); ans.push_back({b, e}); ans.push_back({e, f});

		poly[0] += "LRU"; poly[1] += "LRD";
		mono[0] += "ULR"; mono[1] += "DLR";


		alive[x] = false;
		alive[y] = false;
		alive[z] = false;

	};



	auto dfs = [&] (const auto& self, int n, int p_edge, int& remaining) -> void{
		vis[n] = true;


		for(int e: adj[n]){
			int v = n ^ edges[e][0] ^ edges[e][1];

			if (!vis[v]){
				self(self, v, e, remaining);				
			}
		}
		vector<int> cur;			

		if (p_edge != -1) {
			assert (alive[p_edge]);
			cur.push_back(p_edge);
		}
		for(int e: adj[n]){
			if (alive[e] && e != p_edge){
				cur.push_back(e);
			}
		}

		while (((~remaining & 1) || remaining > 3) && cur.size() > 1){
			int e1 = cur.back();
			cur.pop_back();
			int e2 = cur.back();
			cur.pop_back();

			remaining -= 2;

			add2edges(e1, e2);
		}

		if (cur.size() == 3){
			assert (remaining == 3);
			add3edges_common(cur[0], cur[1], cur[2]);
			cur.clear();
			remaining -= 3;

		}
		assert (cur.size() <= 2);

	};

	

	for(const auto& v: comps){
		if (v.empty())
			continue;
		int degree = 0;
		for(int x: v){
			degree += deg[x];
		}
		assert (~ degree & 1);
		degree /= 2;
		if (degree == 0){
			continue;
		}
		if (degree == 1){
			cout << "-1\n";
			return;
		}

		dfs(dfs, v[0], -1, degree);

		assert (degree == 0 || degree == 3);
		if (degree == 0)
			continue;


		vector<int> edges;

		for(int x: v){
			for(int e: adj[x]){
				if (alive[e]){
					edges.push_back(e);
					alive[e] = false;
				}
			}
		}
		assert (edges.size() == 3);
		for(int e: edges){
			alive[e] = true;
		}
		add3edges_chain(edges[0], edges[1], edges[2]);



	}
	cout << "2 " << n << "\n";

	for(int i = 0; i < ans.size(); ++i){
		cout << ans[i][0] + 1 << " ";
	}
	cout << "\n";

	for(int i = 0; i < ans.size(); ++i){
		cout << ans[i][1] + 1 << " ";
	}
	cout << "\n\n";

	cout << poly[0] << "\n" << poly[1] << "\n\n";
	cout << mono[0] << "\n" << mono[1] << "\n\n";



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