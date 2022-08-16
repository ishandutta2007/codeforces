#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())
#define ld long double

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<", "<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"{";
	for(int i = 0;i < (int)v.size(); i++){
		if(i)os<<", ";
		os<<v[i];
	}
	os<<"}";
	return os;
}

#ifdef LOCAL
#define cerr cout
#else
#endif

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

const int N = 250005, logN = 20;
int sz[N], nxt[N], in[N], rin[N], out[N], depth[N], timer;
int par[logN][N];
vector<int> g[N];

void dfs_sz(int v = 1, int p = 0){
    sz[v] = 1;
    nxt[v] = v;
	depth[v] = depth[p] + 1;
	par[0][v] = p;
    for(auto &u: g[v]){
        if(u == p) continue;    
        dfs_sz(u, v);
        sz[v] += sz[u];
        if(sz[u] >= sz[g[v][0]])
            swap(u, g[v][0]);
    }
}

void dfs_hld(int v = 1, int p = 0){
    in[v] = ++timer;
    rin[in[v]] = v;
    for(auto u: g[v]){
        if(u == p) continue;
        nxt[u] = (u == g[v][0] ? nxt[v] : u);
        dfs_hld(u, v);
    }
    out[v] = timer;
}


int A[N], B[N], C[N], D[N];
int fmax(int u, int v, int type){
	if(u == 0) return v;
	if(v == 0) return u;
	return (min(depth[A[u]], depth[B[u]]) > min(depth[A[v]], depth[B[v]])) ^ type ? u : v;
}
template<class T>
struct segtree{
	vector<T> tree;
	int n;
	int type;
	segtree(){}
	segtree(int _n, int type) : type(type){
		n = _n;
		tree.resize(4 * n + 10);
	}
	void update(int i, T val, int s, int e, int ind = 1){
		if(s > i || e < i) return;
		if(s == e){
			tree[ind] = val;
			return;
		}
		int mid = (s + e) >> 1;
		update(i, val, s, mid, ind << 1);
		update(i, val, mid + 1, e, ind << 1 | 1);
		tree[ind] = fmax(tree[ind << 1], tree[ind << 1 | 1], type);
	}

	void update(int i, T val){
		update(i, val, 1, n);
	}

	T get_max(int l, int r, int s, int e, int ind = 1){
		if(s > r || e < l) return T();
		if(s >= l && e <= r) return tree[ind];
		int mid = (s + e) >> 1;
		return fmax(get_max(l, r, s, mid, ind << 1), get_max(l, r, mid + 1, e, ind << 1 | 1), type);
	}

	int get_max(int l, int r){
		return get_max(l, r, 1, n);
	}
};


map<pii, int> ID;

inline int get_id(int u, int v){
	if(u > v) swap(u, v);
	return ID[{u, v}];
}

vector<pair<pii, pii>> output;

void pre(int n){
    for(int j = 1;j<logN;j++)
        for(int i = 1;i<=n;i++)
            par[j][i] = par[j-1][par[j-1][i]];
}

int lca(int a, int b){
    if(depth[a]<depth[b])
        swap(a,b);
    int l = depth[a]-depth[b];
    for(int i = 0;i<logN;i++) if(l&(1<<i)) a = par[i][a];    
    if(a==b) return a;
    assert(depth[a] == depth[b]);
    for(int i = logN-1;i>=0;i--)
        if(par[i][a]!=par[i][b])
            a = par[i][a],b = par[i][b];
    return par[0][a];
}
vector<int> adj[N];
int d2[N], p2[N];
void dfs2(int s = 1, int p = 0){
	d2[s] = d2[p] + 1;
	p2[s] = p;
	for(int ind : adj[s]){
		int v = C[ind] ^ D[ind] ^ s;
		if(v != p) dfs2(v, s);
	}
}

int main(){
	int n; sd(n);

	for(int i = 1; i < n; i++){
		sd(A[i]); sd(B[i]);
		if(A[i] > B[i]) swap(A[i], B[i]);
		ID[{A[i], B[i]}] = i;
		g[A[i]].push_back(B[i]);
		g[B[i]].push_back(A[i]);
	}
	dfs_sz();
	dfs_hld();
	pre(n);
	segtree<int> st(n + 1, 0), st2(n + 1, 1);
	for(int i = 1; i <= n; i++){
		int u = rin[i];
		int id = get_id(u, par[0][u]);
		st.update(i, id);
		st2.update(i, id);
	}

	function<int(int, int, int)> get_max = [&](int u, int l, int type){
		int now = u;
		int ret = 0;
		while(depth[now] > depth[l]){
			int up = nxt[now];
			if(depth[up] > depth[l]){
				ret = fmax(ret, type ? st2.get_max(in[up], in[now]) : st.get_max(in[up], in[now]), type);
			} else{
				ret = fmax(ret, type ? st2.get_max(in[l] + 1, in[now]) : st.get_max(in[l] + 1, in[now]), type);
			}
			now = par[0][up];
		}
		return ret;
	};

	function<int(int, int)> get_path_max = [&](int u, int v){
		int l = lca(u, v);
		int p = get_max(u, l, 0);
		if(p != 0) return p;
		return get_max(v, l, 1);
	};
	
	for(int i = 1; i < n; i++){
		sd(C[i]); sd(D[i]);
		adj[C[i]].push_back(i);
		adj[D[i]].push_back(i);
	}
	dfs2();
	vector<int> perm(n);
	iota(all(perm), 1);
	sort(all(perm), [&](int i, int j){return d2[i] > d2[j];});

	for(int i = 0; i + 1 < n; i++){
		int u = perm[i], v = p2[u];
		int mx = get_path_max(u, v);
		output.push_back({{A[mx], B[mx]}, {u, v}});
		int lower = A[mx];
		if(par[0][B[mx]] == A[mx]) lower = B[mx];
		st.update(in[lower], 0);
		st2.update(in[lower], 0);
	}
	printf("%d\n", n - 1);
	for(auto it : output) printf("%d %d %d %d\n", it.F.F, it.F.S, it.S.F, it.S.S);
}