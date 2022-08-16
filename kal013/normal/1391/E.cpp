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

/*/-----------------------------Code begins----------------------------------/*/
const int N = 5e5 + 100;
int dsu[N], sz[N], deg[N];
int maxd[N], cnt[N], sub[N], P[N], dep[N];

bool vis[N];
set<int> adj[N];
vector<int> ped[N];
int max_sz;
void dfs(int n,int d){
	vis[n] = true;
	dep[n] = d;
	maxd[n] = d;
	sub[n] = 1;
	cnt[n] = 0;
	for(auto e: adj[n]){
		if (!vis[e]){
			dfs(e, d + 1);
			P[e] = n;
			ped[n].push_back(e);
			sub[n] += sub[e];
			maxd[n] = max(maxd[n], maxd[e]);
			cnt[n] += cnt[e];
		}
	}	
	cnt[n] = max(cnt[n], min(sub[n], max_sz));
}

vector<int> path;
int req;
void add_path(int n, vector<int> & V){
	V.push_back(n);
	pair<int,int> k = {-1, -1};
	for(auto e: ped[n]){
		k = max(k, {maxd[e], e});
	}
	if (k.first == -1){
		return;
	}
	add_path(k.second, V);
}
void dfs2(int n){
	vector<pair<int,int>> U;
	for(auto e: ped[n]){
		U.push_back({maxd[e],e});
	}
	sort(all(U));
	reverse(all(U));

	if (U.size() >= 2 && U[0].first + U[1].first + 1 - 2 * dep[n] >= req){
		vector<int> p1, p2;
		add_path(U[0].second, p1);
		add_path(U[1].second, p2);
		reverse(all(p1));
		for(auto e: p1){
			path.push_back(e);
		}
		path.push_back(n);
		for(auto e: p2){
			path.push_back(e);
		}
		return;
	}
	if (U.size() >= 1 && U[0].first + 1 - dep[n] >= req){
		add_path(n, path);
		return;
	}

	for(auto e: ped[n]){
		if (path.size() > 0){
			assert(path.size() >= req);
			return;
		}
		dfs2(e);
	}
}

bool dpair = false;

vector<pair<int,int>> Q;
int cmp;

void get_sub_vert(int n, vector<int>& V,int& rem){
	if (rem <= 0){
		return;
	}
	V.push_back(n);
	--rem;
	for(auto e: ped[n]){
		get_sub_vert(e, V, rem);
	}
}
void mark_vert(int n){

	if (cnt[n] <= max_sz && sub[n] >= cnt[n]){
		vector<int> T;
		get_sub_vert(n, T, cnt[n]);
		for(auto e: T){
			Q.push_back({cmp,e});
		}
		++cmp;
	}
	else{
		for(auto e: ped[n]){
			mark_vert(e);
			++cmp;
		}
	}
}

void dfs3(int n){
	if (dpair)
		return;
	if (cnt[n] >= 2 * max_sz){
		dpair = true;
		Q.clear();
		cmp = 0;
		mark_vert(n);
		return;
	}
	for(auto e: ped[n]){
		if (dpair)
			return;

		dfs3(e);
	}
}


vector<int> comp[N];
int Find(int n){
	return (dsu[n] == n) ? n : dsu[n] = Find(dsu[n]);
}

void Merge(int x,int y){
	x = Find(x);
	y = Find(y);

	if (x == y){
		return;
	}

	if (sz[x] < sz[y]){
		swap(x, y);
	}
	sz[x] += sz[y];
	dsu[y] = x;
}

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		adj[i].clear();
		comp[i].clear();
		ped[i].clear();
		vis[i] = false;
	}

	path.clear();
	Q.clear();
	dpair =false;

	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
		deg[u]++;
		deg[v]++;
	}
	req = (n + 1) >> 1;
	max_sz = (req + 1) >> 1;
	dfs(1, 0);
	dfs3(1);

	if (Q.size() >= 2 * max_sz){
		sort(all(Q));
		cout << "PAIRING\n";
		vector<pair<int,int>> Tt;

		for(int i = 0; i < max_sz; ++i){
			Tt.push_back({Q[i].second, Q[i + max_sz].second});
		}
		cout << Tt.size() << endl;
		for(auto e: Tt){
			cout << e.first << " " << e.second << "\n";
		}
		return;
	}
	dfs2(1);

	if (path.size() >= req){
		cout << "PATH\n";
		cout << path.size() << endl;
		for(auto e: path){
			cout << e << " ";
		}
		cout << endl;
		return;
	}
	// vector<int> pairing, path;

	// set<pair<int,int>> Q;

	// for(int i = 1; i <= n; ++i){
	// 	Q.insert({deg[i],i});
	// }

	// while(!Q.empty()){
	// 	auto it = Q.begin();
	// 	auto X = *it;
	// 	Q.erase(it);
	// 	int idx = X.second;
	// 	assert(!vis[idx]);
	// 	vis[idx] = true;
	// 	for(auto e: adj[idx]){
	// 		path.push_back(e);
	// 		Q.erase({deg[e],e});
	// 		vis[e] = true;
	// 		adj[e].erase(idx);
	// 		for(auto k: adj[e]){
	// 			if (vis[k])
	// 				continue;
	// 			adj[k].erase(e);
	// 			Q.erase({deg[k],k});
	// 			--deg[k];
	// 			Q.insert({deg[k],k});
	// 		}
	// 	}
	// 	pairing.push_back(idx);

	// }

	// trace(pairing, path);


}
int main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Or use gp_hash_table<X,null_type>
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cout<<fixed<<setprecision(25);
    cerr<<fixed<<setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();
    int t=1;
    cin >> t;
    while(t--) {
        solve();
    }
    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start); 
    
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     
}