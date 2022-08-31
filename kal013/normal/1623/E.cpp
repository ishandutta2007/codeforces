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
#define endl "\n"
#define all(v) (v).begin(),(v).end()
/*/-----------------------Modular Arithmetic---------------/*/
const int mod = 1e9 + 7;

/*/-----------------------------Code begins----------------------------------/*/

const int N = 2e5 + 100;
int P[N];

vector<int> euler;
int tin[N], tout[N];
vector<int> adj[N];
int depth[N];

void dfs(int n){
	if (n == 0)
		return;
	tin[n] = euler.size();
	depth[n] = depth[P[n]] + 1;
	dfs(adj[n][0]);
	euler.push_back(n);
	dfs(adj[n][1]);
	tout[n] = euler.size() - 1;
}

// struct segtree{
// 	vector<int> seg; /*O based */  int n;
// 	segtree() {};
// 	void clear(){ n=0; seg.clear(); }
// 	void build(const vector<int>& val){ 
// 		n = val.size();
// 		seg.resize(2*n);
// 		for(int i = n; i < 2*n; ++i){ 
// 			seg[i] = val[i-n]; 
// 		}
// 		for(int i = n - 1; i > 0; --i) 
// 			seg[i] = seg[i<<1] + seg[(i<<1)|1];
// 	}
// 	void update(int p,int v){ 
// 		p+=n; 
// 		seg[p]=v;
// 		for(int i = p; i > 1 ; i >>= 1)
// 			seg[i>>1] = seg[i] + seg[i^1];
// 	}
// 	int query(int l,int r){
// 		/*assert(l<=r);*/ int ans=0;
// 		for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
// 			if(l&1)ans+=seg[l++]; if(r&1) ans+=seg[--r];
// 		} return ans;
// } };


class segtree {
 public:
  struct node {
    int add = 0;
    int mn = 0;
    int idx = -1;
    void apply(int l, int r, int v) {
      mn += v;
      add += v;
    }
  };

  node unite(const node &a, const node &b) const {
    node res;
    res.mn = min(a.mn, b.mn);
    if (a.mn < b.mn){
    	res.idx = a.idx;
    }
    else{
    	res.idx = b.idx;
    }
    return res;
  }

  inline void push(int x, int l, int r) {
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    if (tree[x].add != 0) {
      tree[x + 1].apply(l, y, tree[x].add);
      tree[z].apply(y + 1, r, tree[x].add);
      tree[x].add = 0;
    }
  }

  inline void pull(int x, int z) {
    tree[x] = unite(tree[x + 1], tree[z]);
  }

  int n;
  vector<node> tree;

  void build(int x, int l, int r) {
    if (l == r) {
    	tree[x].mn = 0;
    	tree[x].add = 0;
    	tree[x].idx = l;
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

  node get(int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[x];
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    node res{};
    if (rr <= y) {
      res = get(x + 1, l, y, ll, rr);
    } else {
      if (ll > y) {
        res = get(z, y + 1, r, ll, rr);
      } else {
        res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
      }
    }
    pull(x, z);
    return res;
  }

  template <typename... M>
  void modify(int x, int l, int r, int ll, int rr, const M&... v) {
    if (ll <= l && r <= rr) {
      tree[x].apply(l, r, v...);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    if (ll <= y) {
      modify(x + 1, l, y, ll, rr, v...);
    }
    if (rr > y) {
      modify(z, y + 1, r, ll, rr, v...);
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

  int find_first(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_first_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (ll <= y) {
      res = find_first(x + 1, l, y, ll, rr, f);
    }
    if (rr > y && res == -1) {
      res = find_first(z, y + 1, r, ll, rr, f);
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

  int find_last(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_last_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (rr > y) {
      res = find_last(z, y + 1, r, ll, rr, f);
    }
    if (ll <= y && res == -1) {
      res = find_last(x + 1, l, y, ll, rr, f);
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

  node get(int ll, int rr) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return get(0, 0, n - 1, ll, rr);
  }

  node get(int p) {
    assert(0 <= p && p <= n - 1);
    return get(0, 0, n - 1, p, p);
  }

  template <typename... M>
  void modify(int ll, int rr, const M&... v) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    modify(0, 0, n - 1, ll, rr, v...);
  }

  // find_first and find_last call all FALSE elements
  // to the left (right) of the sought position exactly once

  int find_first(int ll, int rr, const function<bool(const node&)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_first(0, 0, n - 1, ll, rr, f);
  }

  int find_last(int ll, int rr, const function<bool(const node&)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_last(0, 0, n - 1, ll, rr, f);
  }
};


void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    for(int i = 1; i <= n; ++i){
    	int l, r;
    	cin >> l >> r;
		adj[i].push_back(l);
		adj[i].push_back(r);

		P[l] = i;
		P[r] = i;
    }

    dfs(1);
    segtree st(n);
    for(int i = 1; i <= n; ++i){
    	st.modify(tin[i], tout[i], 1);
    }
    // trace(euler);


    string ret;
    for(int x: euler){
    	ret += s[x - 1];
    }
    int i = 0;

    vector<int> incre(n + 1, 0);

    // auto chk_node = [&] (const auto &self, int x) -> int{
    // 	if (incre[x] == 1)
    // 		return 0;
    // 	if (incre[x] == -1)
    // 		return -1;
    // 	if (x != 1){
    // 		int z = self(self, P[x]);
    // 		if (z == -1){
    // 			incre[x] = -1;
    // 			return -1;
    // 		}
    // 		return z + 1;
    // 	}
    // 	return 1;
    // };
    auto add_node = [&] (const auto &self, int x) -> int{
    	if (incre[x] == 1)
    		return 1;
    	if (incre[x] == -1)
    		return -1;
    	if (x != 1) {
    		if (self(self, P[x]) == -1){
    			incre[x] = -1;
    			return -1;
    		}
    	}
    	--k;
    	incre[x] = 1;
    	st.modify(tin[x], tout[x], -1);
    	return 1;
    };

    vector<bool> relevant(n + 1, false);
    auto dfs2 = [&] (const auto &self, int x) -> void{
    	assert (incre[x] == 1 && relevant[x]);
    	if (k > 0 && adj[x][1] > 0 && relevant[adj[x][1]]){
    		add_node(add_node, adj[x][1]);
    		self(self, adj[x][1]);
    	}

    	if (k > 0 && adj[x][0] > 0 && relevant[adj[x][0]]){
    		add_node(add_node, adj[x][0]);
    		self(self, adj[x][0]);
    	}
    };
    while (i < n){
	    vector<int> ids;
	    bool incr = false;
	    for(int j = i; j < n; ++j){
	    	if (ret[j] == ret[i]){
	    		ids.push_back(j);
	    	}
	    	else{
	    		if (ret[j] > ret[i])
	    			incr = true;
	    		break;
	    	}
	    }
	    i += ids.size();
	    if (!incr){
	    	for(int j: ids){
		    	if (incre[euler[j]] == 0){
		    		incre[euler[j]] = -1;
		    	}
		    }
		    continue;
	    }

	    for(int u = 0; u < ids.size(); ++u){
	    	auto T = st.get(ids[0], ids.back());
	    	if (T.mn > k)
	    		break;
	    	add_node(add_node, euler[T.idx]);
	    	st.modify(T.idx, T.idx, n + 100);
	    }

	    // sort(all(ids), [&] (int x, int y){
	    // 	return depth[euler[x]] < depth[euler[y]];
	    // });
	    // if (st.get(ids[0]).mn <= k && add_node(add_node, euler[ids[0]]) != -1){    	
	    // 	for(int j: ids){
	    // 		relevant[euler[j]] = true;
	    // 	}
	    // 	dfs2(dfs2, euler[ids[0]]);
	    // 	for(int j: ids){
	    // 		relevant[euler[j]] = false;
	    // 	}
	    // }
    }
    assert (k >= 0);
    string ans;
    for(int k: euler){
    	ans += s[k - 1];
    	if (incre[k] == 1)
    		ans += s[k - 1];
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
    //cin >> t;
    while (t--) {
        solve();
    }

    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     
}