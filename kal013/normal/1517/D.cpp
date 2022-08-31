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
template<class T> istream& operator >> (istream &is, vector<T>& V) {
    for(auto &e : V)
        is >> e;
    return is;
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
template<typename CharT, typename Traits, typename T>
ostream& _containerprint(std::basic_ostream<CharT, Traits> &out, T const &val) {
    return (out << val << " ");
}
template<typename CharT, typename Traits, typename T1, typename T2>
ostream& _containerprint(std::basic_ostream<CharT, Traits> &out, pair<T1, T2> const &val) {
    return (out << "(" << val.first << "," << val.second << ") ");
}
template<typename CharT, typename Traits, template<typename, typename...> class TT, typename... Args>
ostream& operator << (std::basic_ostream<CharT, Traits> &out, TT<Args...> const &cont) {
    out << "[ ";
    for(auto&& elem : cont) _containerprint(out, elem);
    return (out << "]");
}
template<class L, class R> ostream& operator << (ostream& out, pair<L, R> const &val){
    return (out << "(" << val.first << "," << val.second << ") ");
}
template<typename L, size_t N> ostream& operator << (ostream& out, array<L, N> const &cont){
    out << "[ ";
    for(auto&& elem : cont) _containerprint(out, elem);
    return (out << "]");    
}
template<class T> ostream& operator<<(ostream &out, ordered_set<T> const& S){
    out << "{ ";
    for(const auto& s:S) out << s << " ";
    return (out << "}");
}
template<class L, class R, class chash = std::hash<L> > ostream& operator << (ostream &out, gp_hash_table<L, R, chash> const& M) {
    out << "{ ";
    for(const auto& m: M) out << "(" << m.first << ":" << m.second << ") ";
    return (out << "}");
}
template<class P, class Q = vector<P>, class R = less<P> > ostream& operator << (ostream& out, priority_queue<P, Q, R> const& M){
    static priority_queue<P, Q, R> U;
    U = M;
    out << "{ ";
    while(!U.empty())
        out << U.top() << " ", U.pop();
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
        const char* comma = strchr(names + 1, ',');
        cerr.write(names, comma - names) << " : " << arg1<<" | ";
        __f(comma+1, args...);
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
    template<typename L, typename R>
    size_t operator()(pair<L,R> const& Y) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(Y.first * 31 + Y.second + FIXED_RANDOM);
    }
};

/*/---------------------------Defines----------------------/*/
#define ll long long
#define pb push_back
#define endl "\n"
#define all(v) (v).begin(),(v).end()
/*/-----------------------Modular Arithmetic---------------/*/
const int mod = 1e9 + 7;
namespace IO {
    const int BUFFER_SIZE = 1 << 15;
    char input_buffer[BUFFER_SIZE];
    int input_pos = 0, input_len = 0;
    char output_buffer[BUFFER_SIZE];
    int output_pos = 0;
    char number_buffer[100];
    uint8_t lookup[100];
    void _update_input_buffer() {
        input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
        input_pos = 0;
        if (input_len == 0)
            input_buffer[0] = EOF;
    }

    inline char next_char(bool advance = true) {
        if (input_pos >= input_len)
            _update_input_buffer();

        return input_buffer[advance ? input_pos++ : input_pos];
    }

    template<typename T>
        inline void read_int(T &number) {
            bool negative = false;
            number = 0;

            while (!isdigit(next_char(false)))
                if (next_char() == '-')
                    negative = true;

            do {
                number = 10 * number + (next_char() - '0');
            } while (isdigit(next_char(false)));

            if (negative)
                number = -number;
        }

    template<typename T, typename... Args>
        inline void read_int(T &number, Args &... args) {
            read_int(number);
            read_int(args...);
        }

    void _flush_output() {
        fwrite(output_buffer, sizeof(char), output_pos, stdout);
        output_pos = 0;
    }

    inline void write_char(char c) {
        if (output_pos == BUFFER_SIZE)
            _flush_output();

        output_buffer[output_pos++] = c;
    }

    inline void write_string(string s){
        for(auto e: s) 
            write_char(e);
    }

    template<typename T>
        inline void write_int(T number, char after = '\0') {
            if (number < 0) {
                write_char('-');
                number = -number;
            }
            int length = 0;
            while (number >= 10) {
                uint8_t lookup_value = lookup[number % 100];
                number /= 100;
                number_buffer[length++] = (lookup_value & 15) + '0';
                number_buffer[length++] = (lookup_value >> 4) + '0';
            }
            if (number != 0 || length == 0)
                write_char(number + '0');
            for (int i = length - 1; i >= 0; i--)
                write_char(number_buffer[i]);
            if (after)
                write_char(after);
        }

    void IOinit() {
        // Make sure _flush_output() is called at the end of the program.
        bool exit_success = atexit(_flush_output) == 0;
        assert(exit_success);
        for (int i = 0; i < 100; i++)
            lookup[i] = (i / 10 << 4) + i % 10;
    }
}

using namespace IO;
/*/-----------------------------Code begins----------------------------------/*/

// #define BENCH
void solve(){
    int n, m, k;
    // cin >> n >> m >> k;
    read_int(n, m, k);
    #ifdef BENCH
    n = 300;
    m = 300;
    k = 20;
    #endif

    vector<vector<int>> rt(n, vector<int> (m, INT_MAX)), dn(n, vector<int>(m, INT_MAX));
    vector<vector<int>> minedge(n, vector<int>(m, INT_MAX));
    for(int i = 0; i < n; ++i){
    	for(int j = 0; j + 1 < m; ++j){
    		// cin >> rt[i][j];
    		#ifndef BENCH
    		read_int(rt[i][j]);
    		#else
    		rt[i][j] = random_long(1, 1000000);
    		#endif
    	}
    }

    for(int i = 0; i + 1 < n; ++i){
    	for(int j = 0; j < m; ++j){
    		// cin >> dn[i][j];
    		#ifndef BENCH
    		read_int(dn[i][j]);
    		#else
    		dn[i][j] = random_long(1, 1000000);
    		#endif

    	}
    }
    if (k & 1){
    	for(int i = 0; i < n; ++i){
    		for(int j = 0; j < m; ++j){
    			cout << "-1 ";
    		}
    		cout << endl;
    	}
    	return;
    }
    for(int i = 0; i < n; ++i){
    	for(int j = 0; j < m; ++j){
    		minedge[i][j] = min(minedge[i][j], dn[i][j]);
    		minedge[i][j] = min(minedge[i][j], rt[i][j]);
    		if (i > 0){
    			minedge[i][j] = min(minedge[i][j], dn[i - 1][j]);
    		}
    		if (j > 0){
    			minedge[i][j] = min(minedge[i][j], rt[i][j - 1]);
    		}
    	}
    }
    // trace(minedge);
    auto get_dist = [] (const pair<int,int>& a, const pair<int,int>& b){
    	return abs(a.first - b.first) + abs(a.second - b.second);
    };
    auto get_wt = [&] (const pair<int,int>& a, const pair<int,int>& b){
    	assert(get_dist(a, b) == 1);

    	if (a.first < b.first){
    		return dn[a.first][a.second];
    	}
    	if (a.second < b.second){
    		return rt[a.first][a.second];
    	}
    	if (b.first < a.first){
    		return dn[b.first][b.second];
    	}
    	if (b.second < a.second){
    		return rt[b.first][b.second];
    	}
    };
    gp_hash_table<int, int,custom_hash> cur[2]; 
    // cur[{i, j}] = 0;
    // cur[make_pair(i, j)] = 0;

    vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
    int v2 = 0;
    vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
    auto conv = [&] (int i, int j){
    	return i * 501 + j;
    };
    auto get_back = [&] (int z){
    	return make_pair(z / 501, z % 501);
    };	
 	
 	auto djikstra = [&] (int x, int y){
 		static gp_hash_table<pair<int, int>, int, custom_hash> vis;
 		vis.clear();
 		int l = minedge[x][y];
 		ans[x][y] = min(ans[x][y], k * l);

 		vis[{x, y}] = 0;

 		min_heap<pair<int, pair<int,int>>> q;
 		q.push({0, {x, y}});
 		while(!q.empty()){
 			auto X = q.top();
 			q.pop();
 			auto dist = X.first;
 			auto ptr = X.second;
 			if (vis[X.second] < X.first){
 				continue;
 			}

 			ans[ptr.first][ptr.second] = min(ans[ptr.first][ptr.second], k * l + 2 * dist);

 			for(int z = 0; z < 4; ++z){
 				int nx = ptr.first + dx[z], ny = ptr.second + dy[z];
 				if (nx >= 0 && nx < n && ny >= 0 && ny < m){
 					auto key = make_pair(nx, ny);
 					int w = get_wt({ptr.first, ptr.second}, {nx, ny});

 					if (get_dist({nx, ny}, {x, y}) > (k >> 1)){
 						continue;
 					}
 					if (w <= l)
 						continue;
 					w -= l;

 					if (vis.find(key) == vis.end() || vis[key] > dist + w){
 						vis[key] = dist + w;
 						q.push({w, key});
 					}

 				}
 			}
 		}

 	};

    // for(int i = 0; i < n; ++i){
    // 	for(int j = 0; j < m; ++j){
    // 		int z = 0;
    // 		ans[i][j] = k * minedge[i][j];
    // 		cur[z][{i, j}] = 0;
    // 		for(int t = 0; t < (k >> 1); ++t, z ^= 1){
    // 			cur[z ^ 1].clear();
    // 			for(auto e: cur[z]){
    // 				auto [x, y] = e.first;
    // 				for(int jj = 0; jj < 4; ++jj){
    // 					int nx = x + dx[jj], ny = y + dy[jj];
    // 					if (nx < 0 || nx >= n || ny < 0 || ny >= m){
    // 						continue;
    // 					}
    // 					if (get_dist({i, j}, {nx, ny}) ){
    // 						// trace(i, j, nx, ny);
    // 						continue;
    // 					}
    // 					auto key = make_pair(nx, ny);
    // 					if (cur[z ^ 1].find(key) == cur[z ^ 1].end()){
    // 						cur[z ^ 1][key] = e.second + get_wt(e.first, key);
    // 					}
    // 					else{
    // 						int t = cur[z ^ 1][key];
    // 						cur[z ^ 1][key] = min(t, e.second + get_wt(e.first, key));
    // 					}
    // 				}
    // 			}
    // 			// trace(i, j, "");
    // 			for(auto e: cur[z ^ 1]){
    // 				// trace(e);
    // 				ans[i][j] = min(ans[i][j], 2 * e.second + (k - 2 * t - 2) * (minedge[e.first.first][e.first.second]));
    // 			}
    // 		}
    // 	}
    // }



    // for(int i = 0; i < n; ++i){
    // 	for(int j = 0; j < m; ++j){
    // 		int z = 0;
    // 		cur[z].clear();
    // 		cur[z][conv(i, j)] = 0;

    // 		// trace(i, j);
    // 		for(int t = 0; t < (k >> 1); ++t, z ^= 1){
    // 			cur[z ^ 1].clear();

    // 			for(auto e: cur[z]){
    // 				auto [x, y] = get_back(e.first);
    // 				auto key1 = make_pair(x, y);
    // 				for(int jj = 0; jj < 4; ++jj){
    // 					int nx = x + dx[jj], ny = y + dy[jj];
    // 					if (nx < 0 || nx >= n || ny < 0 || ny >= m){
    // 						continue;
    // 					}
    // 					if (get_dist({i, j}, {nx, ny}) > (k - t - 1)){
    // 						// trace(i, j, nx, ny);
    // 						continue;
    // 					}
    // 					auto key = conv(nx, ny);
    // 					if (cur[z ^ 1].find(key) == cur[z ^ 1].end()){
    // 						cur[z ^ 1][key] = e.second + get_wt(key1, make_pair(nx, ny));
    // 					}
    // 					else{
    // 						int t = cur[z ^ 1][key];
    // 						cur[z ^ 1][key] = min(t, e.second + get_wt(key1, make_pair(nx, ny)));
    // 					}
    // 				}
    // 			}
    // 			// v2 = max(v2, (int) cur[z ^ 1].size());
    // 			// trace(cur[z ^ 1], z, t, k);
    // 		}
    // 		ans[i][j] = INT_MAX;
    // 		for(auto e: cur[z]){
    // 			ans[i][j] = min(ans[i][j], 2 * e.second);
    // 		}
    // 		// ans[i][j] = 2 * cur[z][{i, j}];
    // 		// trace(ans[i][j]);

    // 		// return;

    // 	}
    // }
    // trace(v2);
    // trace(ans);
    for(int i = 0; i < n; ++i){
    	for(int j = 0; j < m; ++j){
    		// djikstra(i, j);
    		ans[i][j] = 0;

    	}
    }

    for(int t = 0; t < (k >> 1); ++t){
    	vector<vector<int>> prv(n, vector<int>(m, INT_MAX));
    	for(int i = 0; i < n; ++i){
    		for(int j = 0; j < m; ++j){
    			for(int z = 0; z < 4; ++z){
    				int nx = i + dx[z], ny = j + dy[z];
    				if (nx >= 0 && nx < n && ny >= 0 && ny < m){
    					int w = get_wt({i, j}, {nx, ny});
    					prv[nx][ny] = min(ans[i][j] + w, prv[nx][ny]);
    				}
    			}
    		}	
    	}
    	swap(ans, prv);
    }
    for(int i = 0; i < n; ++i){
    	for(int j = 0; j < m; ++j){
    		// cout << ans[i][j] << " ";
    		#ifndef BENCH
    		write_int(2 * ans[i][j], ' ');
    		#endif
    	}
    	// cout << endl;
    	#ifndef BENCH
    	write_char('\n');
    	#endif
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
    //cin >> t;
    IOinit();
    while (t--) {
        solve();
    }
    _flush_output();

    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     
}