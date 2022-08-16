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


template<typename node>
struct segtree{
	// copied from tourist's submissions

	inline void push(int x, int l, int r) {
		int y = (l + r) >> 1;
		int z = x + ((y - l + 1) << 1);
		tree[x + 1].apply(l, y, tree[x]);
		tree[z].apply(y + 1, r, tree[x]);
		tree[x].reset_lazy();
	}
	inline void pull(int x, int z){
		tree[x].unite(tree[x + 1], tree[z]);
	}
	int n;
	vector<node> tree;

	
  	void build(int x, int l, int r) {
	    if (l == r) {
	      return;
	    }
	    int y = (l + r) >> 1;
	    int z = x + ((y - l + 1) << 1);
	    build(x + 1, l, y);
	    build(z, y + 1, r);
	    pull(x, z);
	}

	  template <typename M>
	  void build(int x, int l, int r, const vector<M> &v) {
	    if (l == r) {
	      tree[x].apply(l, r, v[l]);
	      return;
	    }
	    int y = (l + r) >> 1;
	    int z = x + ((y - l + 1) << 1);
	    build(x + 1, l, y, v);
	    build(z, y + 1, r, v);
	    pull(x, z);
	  }

	   node get(int x, int l, int r, int ql, int qr) {
	    if (ql <= l && r <= qr) {
	      return tree[x];
	    }
	    int y = (l + r) >> 1;
	    int z = x + ((y - l + 1) << 1);
	    push(x, l, r);
	    node res{};
	    if (qr <= y) {
	      res = get(x + 1, l, y, ql, qr);
	    } else {
	      if (ql > y) {
	        res = get(z, y + 1, r, ql, qr);
	      } else {
	        res.unite(get(x + 1, l, y, ql, qr), get(z, y + 1, r, ql, qr));
	      }
	    }
	    pull(x, z);
	    return res;
	  }

	   template <typename... M>
	  void modify(int x, int l, int r, int ql, int qr, const M&... v) {
	    if (ql <= l && r <= qr) {
	      tree[x].apply(l, r, v...);
	      return;
	    }
	    int y = (l + r) >> 1;
	    int z = x + ((y - l + 1) << 1);
	    push(x, l, r);
	    if (ql <= y) {
	      modify(x + 1, l, y, ql, qr, v...);
	    }
	    if (qr > y) {
	      modify(z, y + 1, r, ql, qr, v...);
	    }
	    pull(x, z);
	  }

	  int find_first_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
	    if (l == r) {
	      return l;
	    }
	    push(x, l, r);
	    int y = (l + r) >> 1;
	    int z = x + ((y - l + 1) << 1);
	    int res;
	    if (f(tree[x + 1])) {
	      res = find_first_knowingly(x + 1, l, y, f);
	    } else {
	      res = find_first_knowingly(z, y + 1, r, f);
	    }
	    pull(x, z);
	    return res;
	  }

	  int find_first(int x, int l, int r, int ql, int qr, const function<bool(const node&)> &f) {
	    if (ql <= l && r <= qr) {
	      if (!f(tree[x])) {
	        return -1;
	      }
	      return find_first_knowingly(x, l, r, f);
	    }
	    push(x, l, r);
	    int y = (l + r) >> 1;
	    int z = x + ((y - l + 1) << 1);
	    int res = -1;
	    if (ql <= y) {
	      res = find_first(x + 1, l, y, ql, qr, f);
	    }
	    if (qr > y && res == -1) {
	      res = find_first(z, y + 1, r, ql, qr, f);
	    }
	    pull(x, z);
	    return res;
	  }

	  int find_last_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
	    if (l == r) {
	      return l;
	    }
	    push(x, l, r);
	    int y = (l + r) >> 1;
	    int z = x + ((y - l + 1) << 1);
	    int res;
	    if (f(tree[z])) {
	      res = find_last_knowingly(z, y + 1, r, f);
	    } else {
	      res = find_last_knowingly(x + 1, l, y, f);
	    }
	    pull(x, z);
	    return res;
	  }

	int find_last(int x, int l, int r, int ql, int qr, const function<bool(const node&)> &f) {
	    if (ql <= l && r <= qr) {
	      if (!f(tree[x])) {
	        return -1;
	      }
	      return find_last_knowingly(x, l, r, f);
	    }
	    push(x, l, r);
	    int y = (l + r) >> 1;
	    int z = x + ((y - l + 1) << 1);
	    int res = -1;
	    if (qr > y) {
	      res = find_last(z, y + 1, r, ql, qr, f);
	    }
	    if (ql <= y && res == -1) {
	      res = find_last(x + 1, l, y, ql, qr, f);
	    }
	    pull(x, z);
	    return res;
	}

 	segtree(int _n) : n(_n) {
	    assert(n > 0);
	    tree.resize(2 * n - 1);
	    build(0, 0, n - 1);
	}

	  template <typename M>
	  segtree(const vector<M> &v) {
	    n = v.size();
	    assert(n > 0);
	    tree.resize(2 * n - 1);
	    build(0, 0, n - 1, v);
	  }

	node get(int ql, int qr) {
	    assert(0 <= ql && ql <= qr && qr <= n - 1);
	    return get(0, 0, n - 1, ql, qr);
	}

	node get(int p) {
	    assert(0 <= p && p <= n - 1);
	    return get(0, 0, n - 1, p, p);
	}

	template <typename... M>
	void modify(int ql, int qr, const M&... v) {
	    assert(0 <= ql && ql <= qr && qr <= n - 1);
	    modify(0, 0, n - 1, ql, qr, v...);
	}

	  // find_first and find_last call all FALSE elements
	  // to the left (right) of the sought position exactly once

  	int find_first(int ql, int qr, const function<bool(const node&)> &f) {
		assert(0 <= ql && ql <= qr && qr <= n - 1);
		return find_first(0, 0, n - 1, ql, qr, f);
	}

 	int find_last(int ql, int qr, const function<bool(const node&)> &f) {
	    assert(0 <= ql && ql <= qr && qr <= n - 1);
	    return find_last(0, 0, n - 1, ql, qr, f);
	 }
};

struct node {
    int mn = 0;

    void apply(int l, int r, int v) {
    	assert(l == r);
      mn += v;
    }
    void apply(int l, int r, const node& b) {
      // mn += b.add;
    }
    void reset_lazy(){

    }
    void unite(const node &a, const node &b) {
      // assert (add == 0);
      mn = min(a.mn, b.mn);  
    }
};
/*/-----------------------------Code begins----------------------------------/*/

void solve(){
	int n, m;
	cin >> n >> m;

	vector<int> a(n);

	cin >> a;

	segtree<node> dev(a);

	int cnt = 0;

	int mn = INT_MAX;


	for(int i = 0; i < n; ++i){
		if (mn > a[i]) ++cnt;
		mn = min(mn, a[i]);
	}

	for(int i = 0; i < m; ++i){
		int k, d;
		cin >> k >> d;
		--k;
		assert (a[k] >= d);
		int p_min = a[k];
		if (k > 0){
			auto f = dev.get(0, k - 1);
			p_min = min(p_min, f.mn);
			if (f.mn > a[k]){
				--cnt;
			}
			if (f.mn > a[k] - d){
				++cnt;
			}			
		}
		a[k] -= d;

		auto func = [&] (const node& J) {
			return (J.mn < p_min);
		};	


		while (p_min > a[k] && k + 1 < n){
			int l = dev.find_first(k + 1, n - 1, func);
			if (l == -1)
				break;
			assert (a[l] < p_min);
			if (a[l] < a[k]){
				break;
			}
			p_min = a[l];
			--cnt;


		}

		dev.modify(k, k, -d);

		cout << cnt << " ";
	}
	cout << "\n";

}  

int main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Or use gp_hash_table<X,null_type>
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << fixed << setprecision(25);
    cerr << fixed << setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     
}