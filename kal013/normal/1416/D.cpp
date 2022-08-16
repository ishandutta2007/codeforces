/*/ Author: kal013 /*/
// #pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

template<class T> 
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

template<class T>
using min_heap = priority_queue<T,vector<T>,greater<T> >; 

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
    size_t operator()(pair<int64_t,int64_t> Y) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(Y.first * 31 + Y.second + FIXED_RANDOM);
    }
};

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ ";
    for(auto v : V) os << v << " ";
    return os << "]";
}
template<class T> istream& operator>>(istream &is, vector<T>& V) {
    for(auto &e : V)
        is >> e;
    return is;
}

#ifdef __SIZEOF_INT128__
ostream& operator << (ostream &os, __int128 T){
    const static long long N = (1'000'000'000'000'000'000);
    if (T < 0){
        os << '-';
        T *= -1;
    }

    unsigned long long b = T%N;
    T /= N;
    if (T == 0)
        return os << b ;
    unsigned long long a = T % N;
    T /= N;
    if (T == 0){
        os << a;
        __int128 mul = 10;
        int cnt = 0;
        while( mul*b < N && cnt < 17){
            os << '0';
            mul *= 10;
            ++cnt;
        }
        return os << b;
    }
    os << ((long long) T);
    
     __int128 mul = 10;
      int cnt = 0;
    while( mul*a < N && cnt < 17){
        os << '0';
        mul *= 10;
        ++cnt;
    }
    os << a;
    mul = 10;
    cnt = 0;
    while( mul*b < N && cnt < 17){
        os << '0';
        mul *= 10;
        ++cnt;
    }
    return os << b;

}
istream& operator >> (istream& is, __int128& T){
    string U;
    is >> U;
    T = 0;
    size_t pos = 0;
    int mul = 1;
    if (U[pos] == '-'){
        ++pos;
        mul *= -1;
    }
    for(; pos < U.size(); ++pos){
        T *= 10;
        T += (U[pos] - '0');
    }
    T *= mul;

    return is;
}
#endif
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class T> ostream& operator<<(ostream &os, unordered_set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class T> ostream& operator << (ostream& os, multiset<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class T> ostream& operator<<(ostream &os, ordered_set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.first<<":"<<m.second<<") ";
    return os<<"}";
}
template<class L, class R, class chash = std::hash<R>> ostream& operator<<(ostream &os, unordered_map<L,R,chash> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.first<<":"<<m.second<<") ";
    return os<<"}";
}
template<class L, class R, class chash = std::hash<R> > ostream& operator<<(ostream &os, gp_hash_table<L,R,chash> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.first<<":"<<m.second<<") ";
    return os<<"}";
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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline int64_t random_long(long long l,long long r){
    uniform_int_distribution<int64_t> generator(l,r);
    return generator(rng);
}
inline int64_t random_long(){
    uniform_int_distribution<int64_t> generator(LLONG_MIN,LLONG_MAX);
    return generator(rng);
}


/*/---------------------------Defines----------------------/*/
typedef vector<int> vi;
typedef pair<int,int> pii;

#define For(i,n) for(int i = 0; i < (int) n; ++i)
#define Rep(i,n) for(int i = 1; i <= (int) n; ++i)
#define ll long long
#define F first
#define S second
#define pb push_back
#define endl "\n"
#define all(v) (v).begin(),(v).end()
/*/-----------------------Modular Arithmetic---------------/*/

const int mod=1e9+7;
struct dsu_save {
    int v, rnkv, u, rnku;
    dsu_save() {}

    dsu_save(int _v, int _rnkv, int _u, int _rnku)
        : v(_v), rnkv(_rnkv), u(_u), rnku(_rnku){}
};

struct dsu_with_rollbacks {
    vector<int> p, rnk, mx;
    vector<set<int>> value;
    // int comps;
    stack<dsu_save> op;

    dsu_with_rollbacks() {}

    dsu_with_rollbacks(int n, const vector<int>& val) {
    	assert(val.size() == n + 1);
        p.resize(n + 1);
        rnk.resize(n + 1);
        mx.resize(n + 1);
        value.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            p[i] = i;
            rnk[i] = 0;
            mx[i] = val[i];
            value[i].insert(mx[i]);
        }
        // comps = n;
    }

    int find_set(int v) {
        return (v == p[v]) ? v : find_set(p[v]);
    }

    bool unite(int v, int u) {
        v = find_set(v);
        u = find_set(u);
        if (v == u)
            return false;
        // comps--;
        if (value[v].size() > value[u].size())
            swap(v, u);
        op.push(dsu_save(v, rnk[v], u, rnk[u] ));
        p[v] = u;

        for(auto e: value[v]){
        	value[u].insert(e);
        }
        mx[u] = max(mx[u], mx[v]);
        if (rnk[u] == rnk[v])
            rnk[u]++;
        return true;
    }
    int get_value(int x){
    	x = find_set(x);
    	if (value[x].size() == 0){
    		return 0;
    	}
    	auto it = value[x].rbegin();
    	int ans = *it;
    	value[x].erase(ans);
    	// trace(x, value[x]);
    	return ans;
    }

    void rollback() {
        if (op.empty())
            return;
        dsu_save x = op.top();

        op.pop();
        // comps++;
        p[x.v] = x.v;
        rnk[x.v] = x.rnkv;
        vector<int> ext;
        for(auto e: value[x.v]){
        	// trace(e);
        	auto it = value[x.u].find(e);

        	if (it == value[x.u].end()){
        		ext.push_back(e);
        	}
        	else{
        		value[x.u].erase(it);
        	}
        }
        for(auto e: ext){
        	value[x.v].erase(e);
        }
        // trace(value[x.v], value[x.u]);

        p[x.u] = x.u;
        rnk[x.u] = x.rnku;
    }
};

// struct query {
//     int v, u;
//     bool united;
//     query(int _v, int _u) : v(_v), u(_u) {
//     }
// };

// struct QueryTree {
//     vector<vector<query>> t;
//     dsu_with_rollbacks dsu;
//     int T;

//     QueryTree() {}

//     QueryTree(int _T, int n, const vector<int>& val) : T(_T) {
//     	trace(T, n, val);
//         dsu = dsu_with_rollbacks(n, val);

//         t.resize(4 * T + 4);
//     }

//     void add_to_tree(int v, int l, int r, int ul, int ur, query& q) {
//         if (ul > ur)
//             return;
//         if (l == ul && r == ur) {
//             t[v].push_back(q);
//             return;
//         }
//         int mid = (l + r) / 2;
//         add_to_tree(2 * v, l, mid, ul, min(ur, mid), q);
//         add_to_tree(2 * v + 1, mid + 1, r, max(ul, mid + 1), ur, q);
//     }

//     void add_query(query q, int l, int r) {
//         add_to_tree(1, 0, T - 1, l, r, q);
//     }

//     void dfs(int v, int l, int r, vector<int>& ans, const vector<int>& queries) {
//         for (query& q : t[v]) {
//             q.united = dsu.unite(q.v, q.u);
//         }
//         if (l == r && queries[l] != -1){
//             ans[l] = dsu.mx[dsu.find_set(queries[l])];
//         }
//         else {
//             int mid = (l + r) / 2;
//             dfs(2 * v, l, mid, ans, queries);
//             dfs(2 * v + 1, mid + 1, r, ans, queries);
//         }
//         for (query q : t[v]) {
//             if (q.united)
//                 dsu.rollback();
//         }
//     }

//     vector<int> solve(const vector<int>& queries) {
//         vector<int> ans(T);
//         dfs(1, 0, T - 1, ans, queries);
//         return ans;
//     }
// };

/*/-----------------------------Code begins----------------------------------/*/


struct DSU{
	vector<int> dsu, sz;

	void init(int n){
		dsu.resize(n + 1);
		sz.resize(n + 1);
		for(int i = 0; i <= n; ++i){
			dsu[i] = i;
			sz[i] = 1;
		}
	}

	int find(int x){
		return (x == dsu[x]) ? x : dsu[x] = find(dsu[x]);
	}

	bool merge(int x, int y){
		x = find(x);
		y = find(y);

		if (x == y){
			return false;
		}

		if (sz[x] < sz[y]){
			swap(x, y);
		}
		sz[x] += sz[y];
		dsu[y] = x;
		return true;
	}
};



void solve(){
	int n, m, q;
	cin >> n >> m >> q;
	vector<int> par(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> par[i];
	}
	vector<pair<int,int>> edges(m);
	vector<bool> done(m , false);

	for(int i = 0; i < m; ++i){
		cin >> edges[i].first >> edges[i].second;
	}
	vector<int> ordr;

	vector<pair<int,int>> queries;

	for(int i = 0; i < q; ++i){
		int u, v;
		cin >> u >> v;
		if (u == 2){
			--v;
			done[v] = true;
			ordr.push_back(v);
		}
		queries.push_back({u, v});
	}
	reverse(all(ordr));

	DSU checker;
	checker.init(n);
	vector<bool> useful(m, false);

	vector<int> adding;
	for(int i = 0; i < m; ++i){
		if (!done[i]){
			if (checker.merge(edges[i].first, edges[i].second)){
				useful[i] = true;
				adding.push_back(i);
			}
		}
	}

	for(int i: ordr){
		if (checker.merge(edges[i].first, edges[i].second)){
			useful[i] = true;
			adding.push_back(i);
		}	

	}


	

	for(int i = 0; i < m; ++i){
		if (!useful[i])
			continue;

		int u = edges[i].first, v = edges[i].second;

		// assert(find_root(u) != find_root(v));
		// link(u, v);
		// assert(find_root(u) == find_root(v));

	}

	vector<int> revid(n + 1, -1);

	for (int i = 1; i <= n; ++i){
		revid[par[i]] = i;
	}

	dsu_with_rollbacks device(n, par);

	for(auto e: adding){	
		device.unite(edges[e].first, edges[e].second);
	}

	// QueryTree(q, num_n, par);
	// trace(revid);

	// trace(device.value);
	for(auto e: queries){
		if (e.first == 2){
			if (!useful[e.second]){
				continue;
			}
			device.rollback();
			// trace(device.value);

			// int u = edges[e.second].first, v = edges[e.second].second;
			// cut(u, v);
		}
		else{

			int u = e.second;

			cout << device.get_value(u) << endl;

			// int u = e.second;
			// u = find_root(u);

			// // update(u);
			// int v = G[u].sub_sz;
			// cout << v << endl;
			// if (v != 0){
			// 	v = revid[v];
			// 	makeroot(v);
			// 	G[v].own = 0;
			// 	update(v);
			// }
			

		}
	}



	// trace("Acj");


}
int main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Or use gp_hash_table<X,null_type>
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cout<<fixed<<setprecision(25);
    cerr<<fixed<<setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();
    int t=1;
    //cin >> t;
    while(t--) {
        solve();
    }
    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start); 
    
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     
}