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
const int N = 4e5 + 100;
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

ordered_set<pair<int,int>> bit[2][N];

int M;
void update_bit(int l,int val,int idx,bool add){
	int x = l + 1;
	while(x <= M){
		if (add){
			bit[idx][x].insert({val,l});
		}
		else{
			bit[idx][x].erase({val,l});
		}
		x += (x&(-x));
	}
}

int query_bit_less(int l,int idx,pair<int,int> T){
	int z = 0;
	while(l > 0){
		z += bit[idx][l].order_of_key(T);
		l -= (l&(-l));
	}
	return z;
}

int query_bit_more(int l,int idx,pair<int,int> T){
	int z = 0;
	while(l > 0){
		z += bit[idx][l].size() - bit[idx][l].order_of_key(T);
		l -= (l&(-l));
	}
	return z;
}
int query_bit_odd(int l,int r,int val){
	++l; ++r;
	return query_bit_more(r , 0, {val,-1}) - query_bit_more(l - 1, 0, {val,-1});
}

int query_bit_even(int l,int r,int val){
	++l; ++r;
	return query_bit_less(r, 1, {val, N}) - query_bit_less(l - 1, 1,{val,N});
}

void solve(){
	int n,m,q;
	read_int(n,m,q);
	// cin >> n >> m >> q;

	gp_hash_table<pair<int,int>,null_type,custom_hash > Q;


	long long cnt = 0;

	// n <<= 1;
	// m <<= 1;

	M = n + 1;
	for(int i = 0; i < q; ++i){
		int l,r;
		read_int(l,r);
		// cin >> l >> r;
		// assert(1 <= l && l <= (n << 1) && 1 <= r && r <= (m << 1));

		assert( (l & 1) == (r & 1) );
		if (Q.find({l,r}) == Q.end()){
			Q.insert({l,r});
			update_bit(l>>1,r,(l&1),true);
			// update(1,0 , n, (l >> 1) , r, (l&1), true);
			if (l&1){
				cnt += query_bit_odd((l >> 1) + 1,n,r);
			}
			else{
				cnt += query_bit_even(0,(l >> 1) - 1,r);
			}
		}
		else{
			Q.erase({l,r});
			update_bit(l>>1,r,(l&1),false);

			// update(1, 0, n, (l >> 1), r, (l&1), false);	
			if (l&1){
				cnt -= query_bit_odd((l >> 1) + 1,n,r);
			}
			else{
				cnt -= query_bit_even(0,(l >> 1) - 1,r);
			}
		}
		if (cnt == 0){
			write_string("YES\n");
		}
		else{
			write_string("NO\n");
		}

	}

}
int main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Or use gp_hash_table<X,null_type>
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cout<<fixed<<setprecision(25);
    cerr<<fixed<<setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();
    int t=1;
    IOinit();
    // cin>>t;
    while(t--) {
        solve();
    }
    _flush_output();
    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start); 
    
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     
}