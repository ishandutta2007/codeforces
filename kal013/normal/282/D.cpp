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


string ans[2] = {"BitLGM", "BitAryo"};

const int N = 305;
int dp2[N][N];

bool vis[N][N], vis2[N][N][N];
int dp3[N][N][N];

inline void norm(int & x,int& y,int& z){
	int u = min({x, y,z}), v = max({x, y, z});
	y ^= (x ^ z ^ u ^ v);
	x = u;
	z = v;

}

int state(int x,int y){
	assert(x >= 0 && y >= 0);
	if (vis[x][y]){
		return dp2[x][y];
	}
	vis[x][y] = true;

	if (min(x,y) == 0){
		dp2[x][y] = (max(x,y) > 0) ? 1 : 0;
		return dp2[x][y];
	}

	dp2[x][y] = 0;
	for(int j = 1; j <= x && !dp2[x][y]; ++j){
		int k = state(x - j, y);
		dp2[x][y] |= (k ^ 1);
	}

	for(int j = 1; j <= y; ++j){
		int k = state(x, y - j);
		dp2[x][y] |= (k ^ 1);
	}

	for(int j = 1; j <= min(x, y); ++j){
		int k = state(x - j, y - j);
		dp2[x][y] |= (k ^1);
	}
	return dp2[x][y];
}


int state3(int x,int y,int z){
	assert(x >= 0 && y >= 0 && z >= 0);
	norm(x, y, z);

	if (vis2[x][y][z]){
		return dp3[x][y][z];
	}
	vis2[x][y][z] = true;
	dp3[x][y][z] = 0;


	if (x == 0){
		
		dp3[x][y][z] = (y == z) ? 0: 1;
			return dp3[x][y][z];

	}

	for(int j = x; j >= 1 && !dp3[x][y][z]; --j){
		int k = state3(x - j, y - j, z - j);
		dp3[x][y][z] |= (k ^ 1);
	}
	for(int j = x; j >= 1 && !dp3[x][y][z]; --j){
		int k = state3(x - j, y, z);
		dp3[x][y][z] |= (k ^ 1);
	}
	for(int j = y; j >= 1 && !dp3[x][y][z]; --j){
		int k = state3(x, y- j, z);
		dp3[x][y][z] |= (k ^ 1);
	}
	for(int j = z; j >= 1 && !dp3[x][y][z]; --j){
		int k = state3(x , y, z - j);
		dp3[x][y][z] |= (k ^ 1);
	}
	return dp3[x][y][z];
}


int dp[N][N][N];

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	cin >> a;

	if (n == 1){
		if (a[0] > 0){
			cout << ans[0] << endl;
		}
		else{
			cout << ans[1] << endl;
		}
		return;
	}

	if (n == 2){
		int z = state(a[0], a[1]);

		cout << ans[z ^ 1] << endl;
		return;
	}

	for(int i = 0; i < 300; ++i){
		for(int j = 0; j < 300; ++j){
			for(int k = 0; k < 300; ++k){
				dp[i][j][k] = 0;
			}
		}
	}
	for(int i = 0; i < 300; ++i){
		for(int j = 0; j < 300; ++j){
			for(int k = 0; k < 300; ++k){
				if (dp[i][j][k])
					continue;

				for(int z = 1; z <= 300; ++z){
					if (i + z <= 300){
						dp[i + z][j][k] = 1;
					}
					if (j + z <= 300){
						dp[i][j + z][k] = 1;
					}
					if (k + z <= 300){
						dp[i][j][k + z] = 1;
					}
					if (i + z <= 300 && j + z <= 300 && k + z <= 300){
						dp[i + z][j + z][k + z] = 1;
					}
				}
			}
		}
	}
	int z = dp[a[0]][a[1]][a[2]];
	cout << ans[z ^ 1] << endl;

}
int main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Or use gp_hash_table<X,null_type>
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cout<<fixed<<setprecision(25);
    cerr<<fixed<<setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();
    int t=1;
    int cnt = 0;
    // for(int i = 10; i < 300; ++i){
    // 	for(int j = i; j < 300; ++j){
    // 		for(int k = j; k < 300; ++k){
    // 			if (!state3(i,j,k)){
    // 				++cnt;
    // 			}
    // 		}
    // 	}
    // }
    trace(cnt);
    // cin >> t;
    while(t--) {
        solve();
    }
    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start); 
    
    cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     
}