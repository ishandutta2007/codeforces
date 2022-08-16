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
template<typename T>
inline T random_real(T l, T r){
	long long x = random_long(0, LLONG_MAX);
	T s = x;
	s /= LLONG_MAX;
	s *= (r - l);
	s += l;
	return s;
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

/*/-----------------------------Code begins----------------------------------/*/




void solve(string s){
	auto print_vec = [&] (const vector<int>& ans){
		cout << ans.size() << endl;
		for(auto e: ans){
			cout << e << " ";
		}
		cout << endl;
	};

	auto parse_string = [&] (const string& s){
		vector<int> ans;
		int cnt = 0;
		int n = s.size();
		for(int i = 0; i < n; ++i){
			if (s[i] == '#'){
				++cnt;
			}
			else{
				if (cnt > 0)
					ans.push_back(cnt);
				cnt = 0;
			}
		}

		if (cnt > 0)
			ans.push_back(cnt);
		return ans;
	};

	auto possible = [&] (int n, int x){
		// trace(n, x);
    	assert(x > 0 && n >= -1);
    	if (n < 0)
    		return true;
    	if (n == 0)
    		return false;
    	if (x == 1){
    		return (n & 1) ? true : false;
    	}
    	return true;
    };


    auto fill = [&] (string& s, int l, int r, int x){
    	int n = r - l + 1;
    	assert(possible(n, x));
    	if (n < 0)
    		return;
    	if (x == 1){
    		for(int i = l; i <= r; i += 2){
    			s[i] = '#';
    		}
    		return;
    	}
    	while(n > 4){
    		s[l] = '#';
    		l += 2;
    		n -= 2;
    	}
    	if (n == 4){
    		s[l] = '#';
    		s[l + 1] = '#';
    		s[r] = '#';
    	}
    	else if (n >= 1){
    		s[l] = '#';
    		s[r] = '#';
    	}
    };

    auto profile = [&] (int n, const vector<int>& P){
    	string s(n, '_');
    	if (P.size() == 0)
    		return s;
    	int tot = P.size() - 1;
    	for(auto e: P){
    		tot += e;
    	}
    	int x = n - tot, cum = 0;
    	for(auto e: P){
    		// s[cum .. cum + e - 1]
    		// s[cum + x .. cum + ]
    		for(int j = cum + x; j <= cum + e - 1; ++j){
    			s[j] = '#';
    		}
    		cum += e + 1;

    	}
    	return s;
    };

    // string s;
    cin >> s;
    int n = s.size();
    // trace(n);
    int cnt = 0;
    for(auto e: s){
    	if (e == '#'){
    		++cnt;
    	}
    }
    if (cnt == 0){
    	cout << 0 << endl;
    	return;
    }

    if (s[0] == '#' && s.back() == '#'){
    	bool cor = true;
    	for(int i = 1; i < n; ++i){
    		if (s[i] == '_' && s[i - 1] == '_'){
    			cor = false;
    			break;
    		}
    	}
    	if (cor){
    			
    		
    		print_vec(parse_string(s));
    		return;
    	}
    }

    int max_x = n;
    vector<int> idx;
    for(int i = 0; i < n; ++i){
    	if (s[i] == '#'){
    		max_x = min(max_x, i);
    		max_x = min(max_x, n - 1 - i);

    		if (i > 0 && s[i - 1] == '#')
    			continue;
    		for(int l = 1; l <= i ; ++l){
    			if (s[i - l] == '#'){
    				// trace(i, l);
    				max_x = min(max_x, l - 2);
    				break;
    			}
    		}
    		// trace(i, max_x);
    	}
    }
    // trace(max_x);

    


    set<int> ignore;
    for(int i = 0; i < n; ++i){
    	if (s[i] == '#'){
    		ignore.insert(i - 1);
    		break;
    	}
    }
    for(int i = n - 1; i >= 0; --i){
    	if (s[i] == '#'){
    		ignore.insert(n - 2 - i);
    		break;
    	}
    }
    int f_x = -1;
    for(int x = max_x; x >= 1; --x){
    	if (ignore.find(x) != ignore.end())
    		continue;
    	string t = s;
    	int l = 0;
    	for(int i = x; i < n; ++i){
    		if (s[i] == '#'){
    			l = max(l, i - x);
    			for(; l < i; ++l){
    				t[l] = '#';
    			}
    		}
    	}
    	// trace(x, t);
    	int prv = -1;
    	bool pos = true;
    	for(int i = 0; i < n; ++i){

    		if (t[i] == '#'){
    			if (i > 0 && t[i - 1] == '#'){
    				prv = i + 1;
    				continue;
    			}

    			int rem = i - prv - 2;
    			// trace(i, rem);
    			pos &= possible(rem, x);


    			prv = i + 1;
    		}
    	}

    	for(int i = n - 1; i >= 0; --i){
    		if (t[i] == '#'){

    			int z = (n - x - 1) - (i + 2) + 1;
    			// trace(i, z);
    			pos &= possible(z, x);

    			break;
    		}
    	}
    	trace(x, t);
    	if (pos){
    		prv = -1;
			for(int i = 0; i < n; ++i){

	    		if (t[i] == '#'){
	    			if (i > 0 && t[i - 1] == '#'){
	    				prv = i + 1;
	    				continue;
	    			}

	    			int rem = i - prv - 2;
	    			fill(t, prv + 1, i - 2, x);

	    			// trace(i, rem);
	    			// pos &= possible(rem, x);


	    			prv = i + 1;
	    		}
	    	}

	    	for(int i = n - 1; i >= 0; --i){
	    		if (t[i] == '#'){

	    			fill(t, i + 2, n - x - 1, x);
	    			// int z = (n - x - 1) - (i + 2) + 1;
	    			// trace(i, z);
	    			// pos &= possible(z, x);

	    			break;
	    		}
	    	}
	    	// trace(t);
	    	vector<int> U = parse_string(t);
	    	// trace(U);
	    	string nx = profile(n, U);
	    	if (nx != s){
	    		trace(nx, U);
	    		trace(s, "regsvs");
	    		exit(0);
	    	}
	    	// 	// cout << x << " ";
	    	// 	bool u = 1;
	    	// 	for(int i = 0; i < n; ++i){
	    	// 		if (s[i] == '#')
	    	// 			u = false;
	    	// 		if (nx[i] != s[i]){
	    	// 			if (u)
	    	// 				cout << " First ";
	    	// 			cout << nx.substr(i, 20) << " " << s.substr(i, 20) << endl;
	    	// 			return;
	    	// 		}
	    	// 	}
	    	// }
	    	// trace(profile(n, parse_string(t)));
	    	print_vec(U);
	    	return;
    	}
    }


    cout << -1 << endl;

}

string gen(int n, double pr){
	string s(n, '_');
	for(int i = 0; i < n; ++i){
		if (random_real((long double)0, (long double)1) <= pr){
			s[i] = '#';
		}
	}
	return s;
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
    while (t--) {


        solve(gen(10, 0.2));
    }

    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     
}