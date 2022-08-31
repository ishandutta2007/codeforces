#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#endif

// 0-indexed
template<class T>
struct segtree{
	int n;
	vector<T> t;
	T def;
	inline T combine(T a, T b){
		return a + b;
	}
	segtree(vector<T> & inp, T def = T()) : n(sz(inp)), def(def){
		t.resize(2 * n, def);
		for(int i = 0; i < n; i++) t[n + i] = inp[i];
		for(int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
	}

	void modify(int p, T value) { // modify a[p] = value
		// value = combine(value, t[p + n]); // if a[p] = combine(a[p], value)
		for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
	}

	T query(int l, int r) {  // compute on interval [l, r]
    r++;
		T resl = def, resr = def;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l&1) resl = combine(resl, t[l++]);
			if (r&1) resr = combine(t[--r], resr);
		}
		return combine(resl, resr);
	}
};


int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int n; cin >> n;
	vector<int> a(n), b(n), st(n), en(n), par(n), depth(n), node(n);
	int timer = 0;
	vector<vector<int>> children(n);
	int where = 0;
	for(int & x : a){
		cin >> x; x--;
	}

	for(int i = 1; i < n; i++){
		int u, v; cin >> u >> v;
		u--; v--;
		par[v] = u;
		children[u].push_back(v);
	}

	for(int i = 0; i < n; i++) sort(all(children[i]), [&](int p, int q){return a[p] < a[q];});
	vector<int> post_order;
	function<void(int, int)> dfs = [&](int s, int p){
		depth[s] = s == 0 ? 0 : depth[p] + 1;
		node[timer] = s;
		st[s] = timer++;
		for(int v : children[s]) dfs(v, s);
		en[s] = timer - 1;
		post_order.push_back(s);
	};
	dfs(0, 0);
	int i = 0;
	vector<int> done(n);
	segtree<int> stree(done, 0);
	int _v = -1;
	ll ops = 0;
	for(int v : post_order){
		if(a[v] != i){
			_v = v;
			break;
		} else{
			done[v] = 1;
			b[v] = i;
			ops += depth[v];

			stree.modify(st[v], 1);
		}
		i++;
	}
	for(int v = 0; v < n; v++) if(!done[v]){
		b[v] = st[v] + stree.query(st[v], en[v]);
	}
	vector<int> V = {_v};
	int u = _v;
	while(u > 0){
		u = par[u];
		V.push_back(u);
	}
	reverse(all(V));
	int pos = 0;
	while(pos < sz(V) - 1){
		if(a[V[pos]] == i){
			break;
		}
		swap(b[V[pos]], b[V[pos + 1]]);
		ops++;
		pos++;
	}
	for(int i = 0; i < n; i++) if(a[i] != b[i]){
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";
	cout << ops << endl;
	for(int i = 0; i < n; i++) cout << st[i] + 1 << " ";
	cout << endl;
}