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
	vector<vector<int>> a(n, vector<int> (m));
	cin >> a;

	vector<vector<bool>> ok(n, vector<bool>(m, true));

	int cnt = 0;
	
	const vector<int> dx = {-1, 1, 0, 0};
	const vector<int> dy = {0, 0, -1, 1};

	auto inGrid = [&] (int x, int y){
		return 0 <= x && x < n && 0 <= y && y < m;
	};

	auto calculate = [&] (int i, int j) {
		if (i < 0 || i >= n || j < 0 || j >= m)
			return;


		if (ok[i][j]){
			++cnt;
		}
		ok[i][j] = false;
		if (a[i][j] == 1){
			ok[i][j] = true;
			--cnt;
			return;
		}
		for(int k = 0; k < 4 && !ok[i][j]; ++k){
			int nx = i + dx[k], ny = j + dy[k];
			if (inGrid(nx, ny) && a[nx][ny] < a[i][j]){
				ok[i][j] = true;
				--cnt;
				return;
			}
		}
	};

	auto around = [&] (int x, int y, bool inc = true){
		assert (inGrid(x, y));

		vector<array<int, 2>> adj;
		if (inc)  adj.push_back({x, y});
		
		for(int k = 0; k < 4; ++k){
			int nx = x + dx[k], ny = y + dy[k];
			if (inGrid(nx, ny))
				adj.push_back({nx, ny});
		}
		return adj;
	};
	

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			calculate(i, j);
		}
	}

	if (cnt == 0){
		cout << "0\n";
		return;
	}

	if (cnt > 10){
		cout << "2\n";
		return;
	}

	auto swapper = [&] (int x1, int y1, int x2, int y2){
		assert(inGrid(x1, y1) && inGrid(x2, y2));


		if ((array<int, 2>{x1, y1}) == (array<int, 2>{x2, y2})){
			return;
		}

		swap(a[x1][y1], a[x2][y2]);
		for(const auto& [x, y]: around(x1, y1)) calculate(x, y);
		for(const auto& [x, y]: around(x2, y2)) calculate(x, y);

	};


	vector<array<int, 2>> pts;

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if (!ok[i][j]){
				pts.push_back({i, j});
			}
		}
	}

	const int M = min(1, (int)pts.size());


	auto hash1 = [&] (const array<int, 2>& A){
		return A[0] * m + A[1];
	};
	auto hash2 = [&] (const array<int, 2>& A, const array<int, 2>& B){
		assert (A != B);
		if (A > B){
			return hash1(B) + (n * 1LL * m * 1LL * hash1(A));
		}
		return hash1(A) + (n * 1LL * m * 1LL * hash1(B));
	};


	// gp_hash_table<long long, null_type, custom_hash> ret;

	// set<array<int, 4>> q;
	long long ret = 0;
	for(int i = 0; i < M; ++i){
		auto [x1, y1] = pts[i];
		
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				if (a[i][j] > a[x1][y1]){

					swapper(x1, y1, i, j);
					if (cnt == 0){
						++ret;
					}
					swapper(x1, y1, i, j);
					continue;
				}

				if (a[i][j] == a[x1][y1])
					continue;

				for(const auto& [x, y]: around(x1, y1, false)){
					swapper(x, y, i, j);
					if (cnt == 0){
						++ret;
						// ret.insert(hash2(array<int, 2>{x, y}, array<int, 2>{i,  j}));
					}
					swapper(x, y, i, j);
				}
			}
		}
	}
	if (ret == 0){
		cout << "2\n";
	}
	else{
		cout << 1 << " " << ret << "\n";
	}



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