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

inline int dist(int x1,int y1,int x2, int y2){
	return max({x2 - x1, y2 - y1, 0}) + max({x1 - x2, y1 - y2, 0});
}

pair<int,int> get_val(const string& s){
	pair<int,int> cur = {0,0};
	for(auto e: s){
		if (e == 'B'){
			cur.first += 1;
		}
		else{
			cur.second += 1;
		}
	}
	return cur;	
}


const int N = 5e5 + 100;

set<int> T[N];


void print_ans(int score, int x,int y){
	assert(x >= 0 && y >= 0 && x + y > 0 && score >= 0);
	cout << score << endl;
	for(int i = 0; i < x; ++i){
		cout << 'B';
	}
	for(int i = 0; i < y; ++i){
		cout << 'N';
	}
	cout << endl;
}	

inline int get_k(int l,int r){
	if (l > r){
		return -1;
	}
	return (r - l) >> 1;
}

void solve(){
	int n;
	cin >> n;
	map<pair<int,int>,int> cnt;
	int max_x = 0, min_x = INT_MAX, max_y = 0, min_y = INT_MAX;
	for(int i = 0; i < n; ++i){
		string s;
		cin >> s;
		pair<int,int> cur = get_val(s);
		T[cur.first].insert(cur.second);
		max_x = max(max_x, cur.first);
		min_x = min(min_x, cur.first);
		max_y = max(max_y, cur.second);
		min_y = min(min_y, cur.second);
		cnt[cur] += 1;
	}
	if (max_x == min_x){
		int cur_y = (max_y + min_y + 1) >> 1;
		int score = cur_y - min_y;
		print_ans(score,max_x,cur_y);
		return;
	}

	if (min_y == max_y){
		int cur_x = (max_x + min_x + 1) >> 1;
		int score = cur_x - min_x;
		print_ans(score,cur_x,max_y);
		return;
	}
	pair<int, pair<int,int>> ans;

	ans = {INT_MAX, {-1, -1}};


	set<pair<int,int>> gl, gr;
	set<int>  lessl, lessr;
	for(int x = min_x; x <= max_x; ++x){
		for(auto e: T[x]){
			gl.insert({e, x});
			gr.insert({e - x, x});
		}
	}

	for(int x = min_x; x <= max_x; ++x){
		assert(gr.size() == gl.size());
		assert(gl.size() > 0);
		// assert(lessl.size() == lessr.size());

		auto itr = (*gr.begin()).first;
		auto itl = (*gl.rbegin()).first;
		itr += x;


		
		if (lessl.size() != 0){
			auto it2l = *lessl.rbegin();
			auto it2r = *lessr.begin();
			it2l += x;

			itl = max(itl, it2l);
			itr = min(itr, it2r);
		}

		// itl - k <= itr + k

		int ck = (max(itl - itr + 1, 0)) >> 1;
		ck = max(ck, max_x - x);
		ck = max(ck, x - min_x);
		assert(itl - ck <= itr + ck);
		if (itr + ck < 0){
			ck = max(ck, -itr);
		} 
		if (x + itr + ck == 0){
			ck++;
		}
		ans = min(ans, {ck, {x, itr + ck}});
		for(auto e: T[x]){
			gr.erase({e - x, x});
			gl.erase({e, x});
			lessl.insert(e - x);
			lessr.insert(e);
		}
	}

	int score = ans.first, cx = ans.second.first, cy = ans.second.second;

	int cur = 0;
	assert(score >= 0 && cx >= 0 && cy >= 0);

	for(int x = min_x; x <= max_x; ++x){
		for(auto e: T[x]){
			cur = max(cur, dist(cx, cy, x, e));
		}
	}
	assert(cur == score);

	print_ans(ans.first, ans.second.first, ans.second.second);
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