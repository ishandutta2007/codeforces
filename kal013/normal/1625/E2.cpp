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
template<class T, size_t N> istream& operator >> (istream &is, array<T, N>& V) {
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
template<class P> ostream& operator << (ostream& out, queue<P> const& M){
    static queue<P> U;
    U = M;
    out << "{ ";
    while(!U.empty())
        out << U.front() << " ", U.pop();
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
        return splitmix64(Y.first * 31ull + Y.second + FIXED_RANDOM);
    }
};

/*/---------------------------Defines----------------------/*/
#define ll long long
#define endl "\n"
#define all(v) (v).begin(),(v).end()
/*/-----------------------Modular Arithmetic---------------/*/
const int mod = 1e9 + 7;

/*/-----------------------------Code begins----------------------------------/*/
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
	segtree() {}
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
    long long add = -1;
    long long mn = -1;

    void apply(int l, int r, int v) {
    	if (v != -1){
		    mn = v;
	    	add = v;
    	}
    }
    void apply(int l, int r, const node& b) {
    	if (b.add != -1){
    	  mn = b.add;
	      add = b.add;
    	}
    }
    void reset_lazy(){
      add = -1;
    }
    void unite(const node &a, const node &b) {
      assert (add == -1);
      mn = min(a.mn, b.mn);  
    }
};

struct node2{
	long long ans, pref, suff;
	node2(): ans{}, pref{}, suff{}{}



	void apply(int l, int r, const array<long long, 3> x){
		ans = x[0];
		pref = x[1];
		suff = x[2];
	}
	void apply(int l, int r, const node2& x){

	}
	void reset_lazy(){

	}
	void unite(const node2& a, const node2& b){
		ans = a.ans + b.ans + a.suff * b.pref;
		pref = a.pref  + b.pref;
		suff = b.suff + a.suff;
	}
};

struct node3{
    long long add = 0;
    long long sum = 0;

    void apply(int l, int r, int v) {
    	sum += (r - l + 1) * 1LL * v;
    	add += v;
    }
    void apply(int l, int r, const node3& b) {
    	sum += (r - l + 1) * b.add;
    	add += b.add;
    }
    void reset_lazy(){
      add = 0;
    }
    void unite(const node3 &a, const node3 &b) {
      assert (add == 0);
      sum = a.sum + b.sum;
    }
};

// const int B = 100;

// struct ret{
// 	long long ans = 0, pref = 0, suff = 0;

// 	void merge(const ret& l, const ret& r){

// 	}
// };

// struct ds{


// 	void build(const string& s){
// 		int n = s.size();

// 	}
// };

// #define LOCAL
void solve(){
    int n, q;
    string s;

    #ifndef LOCAL
    cin >> n >> q;
    cin >> s;

    #else
    cin >> n;
    int c = 0;
    for(int i = 0; i < n; ++i){
    	// if (c == 0){
    	// 	s += '(';
    	// 	++c;
    	// }
    	// else{
    	// 	int z = random_long(0, 1);
    	// 	if (z){
    	// 		++c;
    	// 		s += '(';
    	// 	}
    	// 	else{
    	// 		--c;
    	// 		s += ')';
    	// 	}
    	// }
    	s += random_long(0, 1) ? '(' : ')';
    }
    s = "()(((())((((()()()((()))()())())()()(())()((())()()(()(()((())))))(()(()())())))()((()(()(()))()(()()(((())((((((()((((())(()))()))))())((()(()()((())())))()((()))(()))))())))())((()())()))())()()()))";
    s = s.substr(12, 16);
    n = s.size();
    // s = "()))()())())()()";
    #endif

    vector<int> stk;

    vector<int> match(n, -1);
    vector<int> par(n, -1);

 	vector<array<int, 2>> ordr;
    vector<int> ids(n, -1);
    gp_hash_table<int, segtree<node2>, custom_hash> f;
    vector<vector<int>> adj(n + 1);

	auto is_sub = [&] (int l, int r){
 		if (par[l] != par[r]){
 			return false;
 		}
 		while (r > l){
 			if (match[r] > r)
 				return false;
 			if (match[r] == l)
 				return true;
 			r = match[r] - 1;
 		}
 		return false;
 	};

 	auto cntr = [&] (int l, int r){
 		long long ans = 0;
 		for(int z = l; z <= r; ++z){
 			for(int j = z + 1; j <= r; ++j){
 				if (is_sub(z, j)){
 					++ans;
 				}
 			}
 		}
 		return ans;
 	};

 	auto get_ans = [&] (int l, int r){
 		int z = par[l];
    	int i1 = ids[l], i2 = ids[r];
    	return f[z].get(i1, i2).ans;
 	};
    for(int i = 0; i < n; ++i){
    	if (s[i] == '(')
    		stk.push_back(i);
    	else{
    		if (!stk.empty()){
    			int j = stk.back();
    			stk.pop_back();
    			match[i] = j; match[j] = i;
    			ordr.push_back({j, i});
    		}
    	}
    }
    sort(all(ordr));

    vector<ordered_set<int>> child_ids(n + 1);

    {
    	segtree<node> st(n);


	    for(auto &[x, y]: ordr){
	    	auto j = st.get(x).mn;
	    	if (j == - 1){
	    		j = n;
	    	}
			par[x] = par[y] = j;
			ids[x] = ids[y] = adj[j].size();
			adj[j].push_back(x);
			child_ids[j].insert(ids[x]);

			assert (x < y);
	    	st.modify(x, y, x);
	    }
	    
	    vector<array<long long, 3>> ans(n, {0, 0, 0});
	    reverse(all(ordr));
	    
	    for(auto &[x, y]: ordr){
	    	vector<array<long long, 3>> cur;
	    	for(auto z: adj[x]){
	    		assert (ans[z][0] != 0 && ans[z][1] != 0 && ans[z][2] != 0);
	    		cur.push_back(ans[z]);
	    	}

	    	if (!cur.empty()){
	    		f[x] = segtree<node2>(cur);
	    		ans[x] = {f[x].get(0, cur.size() - 1).ans + 1, 1, 1};
	    	}
	    	else{
	    		ans[x] = {1, 1, 1};
	    	}
	    	ans[y] = ans[x];
	    }

	    {
	    	vector<array<long long, 3>> cur;
	    	for(auto z: adj[n]){
	    		cur.push_back(ans[z]);
	    	}

	    	if (!cur.empty()){
	    		f[n] = segtree<node2>(cur);
	    	}
	    	else
	    		assert (f.empty());
	    }
    }

    vector<int> children(n + 1);
    for(int i = 0; i <= n; ++i){
    	children[i] = adj[i].size();
    }


    segtree<node3> st(n + 1);


    // for(int i = 0; i < n; ++i){
    // 	if (match[i] > i){
    // 		trace(i, ans[i]);
    // 	}
    // }

    #ifdef LOCAL
    int jj  = 0;
    array<int, 2> Ans = {-1, -1};
    for(int i = 0; i < n; ++i){
    	for(int j = i + 1; j < n; ++j){
    		if (is_sub(i, j)){
    			++jj;
    		}
    		if (is_sub(i, j) && cntr(i, j) != get_ans(i, j)){
    			if (Ans[0] == -1 || Ans[1] - Ans[0] > j - i){
    				Ans = {i, j};
    			}
    			// trace(s, i, j, s.substr(i, j));
    		}
    	}
    }
    trace(Ans, s);
    if (Ans[0] != -1){
    	cout << s.substr(Ans[0], Ans[1] - Ans[0] + 1) << endl;

    	auto [x, y] = Ans;
    	trace(cntr(x, y));
    	trace(get_ans(x, y));
    }
    trace(jj);
    #else

    auto calc = [&] (int x){
    	return (x * 1LL * (x + 1)) / 2;
    };
    for(int ii = 0; ii < q; ++ii){
    	int t, l, r;
    	cin >> t >> l >> r;
    	--l; --r;
    	assert (match[l] != -1 && match[r] >= l && l < r);
    	assert (par[r] == par[l]);
    	int z = par[l];

    	if (t == 1){
    		st.modify(z, z, -children[z]);
    		--children[z];
    		assert (match[l] == r);
    		child_ids[z].erase(ids[l]);

    		assert (children[l] == 0);
    	}
    	else{
    		assert (t == 2);
    		int i1 = ids[l], i2 = ids[r];

    		int len1 = i2 - i1 + 1;

    		int len2 = child_ids[z].order_of_key(i2) - child_ids[z].order_of_key(i1) + 1;
    		cout << f[z].get(i1, i2).ans + st.get(l, r).sum - calc(len1) + calc(len2) << endl;    		
    	}

    }
    #endif
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
        solve();
    }

    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     
}