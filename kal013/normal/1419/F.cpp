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


struct DSU{
	vector<int> dsu, sz;
	int N;
	void init(int n){
		N = n;
		dsu.resize(n + 1);
		sz.resize(n + 1);

		for(int i = 0; i <= n; ++i){
			dsu[i] = i;
			sz[i] = 1;
		}
	}

	int find(int x){
		return (dsu[x] == x) ? x : dsu[x] = find(dsu[x]);
	}

	void merge(int x,int y){
		x = find(x);
		y = find(y);

		if (x == y){
			return;
		}

		if (sz[x] < sz[y])
			swap(x, y);


		dsu[y] = x;
		sz[x] += sz[y];
	}

	vector<vector<int>> get_components(){
		static vector<int> vis;
		vector<vector<int>> ans;

		vis.resize(N);

		for(int i = 0; i < N; ++i){
			vis[i] = -1;
		}

		for(int i = 0; i < N; ++i){
			int x = find(i);
			if (vis[x] == -1){
				vis[x] = ans.size();
				ans.push_back(vector<int>());
			}
			ans[vis[x]].push_back(i);
		}
		return ans;
	}
};

long long distance(const pair<int,int>& X, const pair<int,int>& Y){
	return abs(X.first - Y.first) + abs(X.second - Y.second);
}


bool nearby(vector<pair<int,int>>& A, vector<pair<int,int>>& B, long long tim){

	if (A.size() == 0 || B.size() == 0){
		return false;
	}
	sort(all(A));

	sort(all(B));


	int r = 0;


	for(int i = 0; i < A.size(); ++i){
		while(r < B.size() && B[r].first < A[i].first){
			++r;
		}

		if (r == B.size()){
			break;
		}
		while(r < B.size() && B[r].second < A[i].second && B[r].first == A[i].first){
			if (A[i].second - B[r].second <= tim){
				return true;
			}
			++r;
		}

		if (r < B.size() && B[r].first == A[i].first){
			if (abs(A[i].second - B[r].second) <= tim){
				return true;
			}
		}
		if (r > 0 && B[r - 1].first == A[i].first){
			--r;
		}
	}

	return false;
}

bool check(const vector<vector<pair<int,int> >>& comp, long long tim){
	assert(comp.size() > 2 && comp.size() <= 4);

	static gp_hash_table<pair<int,int>,null_type,custom_hash> P1, P2;
	P1.clear();
	P2.clear();

	int cnt = comp.size();

	for(auto e: comp[0]){
		for(auto j: comp[1]){
			pair<int,int> p1 = {e.first, j.second}, p2 = {j.first, e.second};
			if (distance( e, p1) <= tim && distance(j, p1) <= tim){
				P1.insert(p1);
			}		
			if (distance(e, p2) <= tim && distance(j, p2) <= tim){
				P1.insert(p2);
			}

		}

		for(auto j: comp[2]){
			pair<int,int> p1 = {e.first, j.second}, p2 = {j.first, e.second};
			if (distance( e, p1) <= tim && distance(j, p1) <= tim){
				P2.insert(p1);
			}		
			if (distance(e, p2) <= tim && distance(j, p2) <= tim){
				P2.insert(p2);
			}

		}

		// if (cnt == 4){
		// 	for(auto j: comp[3]){
		// 		pair<int,int> p1 = {e.first, j.second}, p2 = {j.first, e.second};
		// 		if (distance( e, p1) <= tim && distance(j, p1) <= tim){
		// 			P3.insert(p1);
		// 		}		
		// 		if (distance(e, p2) <= tim && distance(j, p2) <= tim){
		// 			P3.insert(p2);
		// 		}

		// 	}
		// }
	}


	if (P2.size() < P1.size()){
		swap(P1, P2);
	}

	if (cnt == 3){
		for(auto e: P1){
			if (P2.find(e) != P2.end()){
				return true;
			}
		}
		return false;
	}

	vector<pair<int,int>> A, B;

	for(auto e: P1){
		if (P2.find(e) != P2.end()){
			A.push_back(e);
		}
	}

	for(auto e: comp[3]){
		B.push_back(e);
	}


	if (nearby(A, B, tim)){
		return true;
	}

	for(auto &e: A){
		swap(e.first, e.second);
	}

	for(auto&e: B){
		swap(e.first, e.second);
	}

	return nearby(A, B, tim);
}

bool possible(const vector<pair<int,int>>& PTS, long long tim){
	static DSU dev;
	int n = PTS.size();
	dev.init(n);


	for(int i = 0; i < n; ++i){
		for(int j = i + 1; j < n; ++j){
			if (PTS[i].first == PTS[j].first){
				if (abs(PTS[j].second - PTS[i].second) <= tim){
					dev.merge(i, j);
				}
			}
			else if (PTS[i].second == PTS[j].second){
				if (abs(PTS[j].first - PTS[i].first) <= tim){
					dev.merge(i, j);
				}
			}
		}
	}
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		if (dev.find(i) == i){
			++cnt;
		}
	}

	if (cnt == 1){
		return true;
	}	

	vector<vector<int>> comp = dev.get_components();




	assert(comp.size() == cnt);

	if (cnt > 4){
		return false;
	}


	if (cnt == 2){
		// Pure O(N ^ 2)
		for(auto i: comp[0]){
			for(auto j: comp[1]){
				pair<int,int> p1 = {PTS[i].first, PTS[j].second}, p2 = {PTS[j].first, PTS[i].second};

				if (distance(PTS[i], p1) <= tim && distance(PTS[j], p1) <= tim){
					return true;
				}
				if (distance(PTS[i], p2) <= tim && distance(PTS[j], p2) <= tim){
					return true;
				}
				if (PTS[i].first == PTS[j].first && distance(PTS[i], PTS[j]) <= 2*tim){
					return true;
				}
				if (PTS[i].second == PTS[j].second && distance(PTS[i], PTS[j]) <= 2*tim){
					return true;
				}
			}
		}
		return false;

	}


	vector<vector<pair<int,int> >> fin_c(comp.size());


	for(int i = 0; i < comp.size(); ++i){
		for(auto e: comp[i]){
			fin_c[i].push_back(PTS[e]);
		}
	}
	
	if (cnt == 3){
		for(int k = 0; k < 3; ++k){
			swap(fin_c[k], fin_c[0]);

			if (check(fin_c, tim)){
				return true;
			}
		}
		return false;
	}

	



	for(int i = 0; i < 4; ++i){
		for(int j = 0; j < 4; ++j){
			if (i == j)
				continue;

			vector<vector<pair<int,int> >> T(4);
			vector<int> perm = {i};

			for(int z = 0; z < 4; ++z){
				if (z == i || z == j)
					continue;
				perm.push_back(z);
			}
			perm.push_back(j);

			// trace(perm);
			for(int z = 0; z < 4; ++z){
				for(auto x: fin_c[perm[z]]){
					T[z].push_back(x);
				}
			}

			// trace(T);

			if (check(T, tim)){
				return true;
			}
		}
	}



	
	return false;
}

const long long INF = 4e9 + 10;

void solve(){
	int n;
	cin >> n;

	vector<pair<int,int>> PTS(n);

	for(int i = 0; i < n; ++i)
		cin >> PTS[i].first  >> PTS[i].second;


	long long ans = -1;

	long long lo = 0, hi = INF;

	if (!possible(PTS, hi)){
		cout << -1 << endl;
		return;
	}

	while(lo <= hi){
		long long mid = (lo + hi) / 2;

		if (possible(PTS, mid)){
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