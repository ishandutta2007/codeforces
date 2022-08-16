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

const int N = 1e5 + 100;
const int B = 750;
void solve(){
	int n, m;
	cin >> n >> m;

	vector<vector<int>> a;
	vector<int> w;
	int M;
	{
		vector<int> values;
		for(int i = 0; i < n; ++i){
			vector<int> t(m);
			cin >> t;
			int x;
			cin >> x;
			sort(all(t));
			bool eq = false;
			for(int j = 1; j < m; ++j){
				if (t[j] == t[j - 1])
					eq = true;
			}
			if (!eq){
				for(auto jj: t){
					values.push_back(jj);
				}
				a.push_back(t);
				w.push_back(x);
			}
		}


		sort(all(values));
		values.erase(unique(all(values)), values.end());
	
		n = a.size();

		vector<int> ord(n); iota(all(ord), 0);

		sort(all(ord), [&] (int x, int y){
			return w[x] < w[y];
		});

		vector<vector<int>> A;
		vector<int> W;

		for(int j: ord){
			W.push_back(w[j]);
			A.push_back({});
			for(auto zz: a[j]){
				A.back().push_back(lower_bound(all(values), zz) - values.begin());
			}
		}
		swap(a, A);
		swap(w, W);
		M = values.size();
	}

	for(auto &row: a){
		for(auto &val: row){
			assert (0 <= val && val < M);
		}
	}

	long long ans = LLONG_MAX;

	vector<vector<int>> pos(M);



	for(int i = 0; i < n; ++i){
		for(int x: a[i]){
			pos[x].push_back(i);
		}
	}

	vector<int> ids(M, -1);
	vector<bitset<N>> cur;
	for(int i = 0; i < M; ++i){
		if (pos[i].size() > B){
			ids[i] = cur.size();
			
			bitset<N> all_true;
			all_true.set();

			for(int x: pos[i]){
				all_true[x] = 0;
			}
			cur.push_back(all_true);
		}
	}



	for(int i = 0; i < n; ++i){
		vector<int> bits;
		vector<int> other;
		for(int x: a[i]){
			if (ids[x] != -1){
				bits.push_back(ids[x]);
			}
			else{
				other.push_back(x);
			}
		}


		if (bits.empty()){
			assert (other.size() == m);
			vector<int> lb(other.size());


			for(int j = 0; j < n; ++j){
				bool match = false;
				for(int k = 0; k < other.size(); ++k){
					int x = other[k], ptr = lb[k];
					if (ptr < pos[x].size()){
						assert (pos[x][ptr] >= j);
						if (pos[x][ptr] == j){
							++lb[k];
							match = true;
						}	
					}
				}
				if (!match){
					ans = min(ans, w[i] + 0LL + w[j]);
					break;
				}
			}

		}
		else{
			bitset<N> adj = cur[bits[0]];
			for(int i = 1; i < bits.size(); ++i){
				adj &= cur[bits[i]];
			}
			vector<int> lb(other.size());


			for(int j = adj._Find_first(); j < n; j = adj._Find_next(j)){
				bool match = false;
				for(int k = 0; k < other.size(); ++k){
					int x = other[k], ptr = lb[k];
					while (ptr < pos[x].size() && pos[x][ptr] < j){
						++ptr;
						++lb[k];
					}
					if (ptr < pos[x].size()){
						assert (pos[x][ptr] >= j);
						if (pos[x][ptr] == j){
							++lb[k];
							match = true;
						}	
					}
				}
				if (!match){
					ans = min(ans, w[i] + 0LL + w[j]);
					break;
				}
			}
		}
	}


	if (ans == LLONG_MAX){
		ans = -1;
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
    // cin >> t;
    while (t--) {
        solve();
    }

    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     
}