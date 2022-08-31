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

const int N = 1e5  + 10;
vector<int> adj[N];
int cnt[N];
int curr[N];


template<typename T>
void switch_vec(vector<T>& A,int x){
	if (x == 0) return;

	assert(x >= 0 && x < A.size());

	vector<T> U;
	for(int i = x; i < A.size(); ++i){
		U.push_back(A[i]);
	}

	for(int i = 0; i < x; ++i)
		U.push_back(A[i]);
	A.swap(U);
}
void solve(){
	int n,x,y; 
	cin >> n >> x >> y;

	for(int i = 1; i <= n + 1; ++i){
		adj[i].clear();
		cnt[i] = 0;
		curr[i] = 0;
	}

	vector<int> b(n);
	cin >> b;
	assert(0 <= x && x <= y && y <= n);

	if (x == n){
		assert( y == n);
		cout << "YES\n";
		for(auto e: b){
			cout << e << " ";
		}
		cout << endl;
		return;
	}


	for(int i = 0; i < n; ++i){
		adj[b[i]].push_back(i);
		++cnt[b[i]];
	}

	int col = -1;
	for(int i = 1; i <= n+1 ; ++i){
		if (cnt[i] == 0)
			col = i;
	}

	vector<int> a(n,col);


	set<pair<int,int> > U;
	for(int i = 1; i <= n + 1; ++i){
		if (cnt[i] > 0){
			U.insert({cnt[i],i});
		}
	}

	int done = 0;

	while(done < x){
		auto it = U.rbegin();

		auto X = *it;

		int idx = X.second;
		--cnt[idx];

		U.erase(X);

		a[adj[idx].back()] = idx;
		adj[idx].pop_back();

		if (cnt[idx] > 0) U.insert({cnt[idx],idx});
		++done;
	}



	vector<pair<int,int> > left;
	for(int i = 0; i < n; ++i){
		if (a[i] == col){
			left.push_back({b[i],i});
		}
	}
	assert(left.size() == n - x && left.size() > 0);

	sort(all(left));
	int cur = 0;
	for(int i = 1; i <= n + 1; ++i){
		if (cnt[i] > cnt[cur]){
			cur = i;
		}
	}

	int ids = 0;
	while(left[ids].first != cur) ++ids;

	switch_vec(left,ids);


	int j = 1;

	while(j < left.size() && left[j].first == left[0].first){
		++j;

	}
	if (j >= left.size()){
		if (y > x){
			cout << "NO\n";
			return;	
		}
		else{
			j = 0;
		}
		
	}



	vector<int> M(left.size());


	for(int i = 0; i < left.size(); ++i){
		assert(j < left.size());

		M[j] = left[i].first;
		++j;

		if (j == left.size()) 
			j = 0;

	}

	int extr = 0;
	for(int i = 0; i < left.size(); ++i){
		if (M[i] == left[i].first){
			++extr;
			M[i] = col;
		}

		a[left[i].second] = M[i];
	}

	if (extr + y > n){
		cout << "NO\n";
		return;
	}
	int i = 0;
	while(extr + y < n && i < n){
		if (M[i] == col){
			++i;
			continue;
		}
		M[i] = col;
		a[left[i].second] = M[i];
		++extr;
		++i;
	}
	if (y + extr < n){
		assert(false);
	}
	cout << "YES" << endl;

	for(auto e: a){
		cout << e << " ";
	}
	cout << endl;


	// queue<int> Q;
	// for(int i = 1; i <= n + 1; ++i){
	// 	if (cnt[i] > 0){
	// 		Q.push(i);
	// 	}
	// }

	// vector<int> newQ;
	// while(newQ.size() < y && !Q.empty()){
	// 	auto X = Q.front();
	// 	newQ.push_back(X);
	// 	Q.pop();
	// 	++curr[X];
	// 	if (curr[X] < cnt[X]){
	// 		Q.push(X);
	// 	}
	// }
	// trace(n,x,y);
	// trace(b);
	// trace(newQ);

}
int main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Or use gp_hash_table<X,null_type>
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cout<<fixed<<setprecision(25);
    cerr<<fixed<<setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start); 
    
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     
}