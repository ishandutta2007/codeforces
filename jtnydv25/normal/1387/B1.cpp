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

#define fst first
#define snd second

typedef int value_type;
const value_type inf = 1 << 21;
vector<int> matchL, matchR;
value_type min_assignment(const vector<vector<value_type>> &c) {
  const int n = c.size(), m = c[0].size(); // assert(n <= m);
  vector<value_type> v(m), dist(m);        // v: potential
  matchL.assign(n, -1);
  matchR.assign(m, -1);
//   vector<int> matchL(n,-1), matchR(m,-1);  // matching pairs
  vector<int> index(m), prev(m);
  iota(all(index), 0);

  auto residue = [&](int i, int j) { return c[i][j] - v[j]; };
  for (int f = 0; f < n; ++f) {
    for (int j = 0; j < m; ++j) {
      dist[j] = residue(f, j);
      prev[j] = f;
    }
    value_type w;
    int j, l;
    for (int s = 0, t = 0;;) {
      if (s == t) {
        l = s; w = dist[index[t++]]; 
        for (int k = t; k < m; ++k) {
          j = index[k];
          value_type h = dist[j];
          if (h <= w) {
            if (h < w) { t = s; w = h; }
            index[k] = index[t]; index[t++] = j;
          }
        }
        for (int k = s; k < t; ++k) {
          j = index[k];
          if (matchR[j] < 0) goto aug;
        }
      }
      int q = index[s++], i = matchR[q];
      for (int k = t; k < m; ++k) {
        j = index[k];
        value_type h = residue(i,j) - residue(i,q) + w;
        if (h < dist[j]) { 
          dist[j] = h; prev[j] = i;
          if (h == w) {
            if (matchR[j] < 0) goto aug;
            index[k] = index[t]; index[t++] = j;
          }
        }
      }
    }
aug:for(int k = 0; k < l; ++k) 
      v[index[k]] += dist[index[k]] - w;
    int i;
    do {
      matchR[j] = i = prev[j]; 
      swap(j, matchL[i]);
    } while (i != f);
  }
  value_type opt = 0;
  for (int i = 0; i < n; ++i) 
    opt += c[i][matchL[i]]; // (i, matchL[i]) is a solution
  return opt;
}

struct tree {
	int n, block_size, num_blocks;
	vector<vector<int>> adj, val;
	vector<int> num, floorlog, par;
	tree(){}
	tree(int n) : n(n), adj(n), par(n){ }
	void add_edge(int s, int t) {
		adj[s].push_back(t);
		adj[t].push_back(s);
	}
	vector<int> pos, tour, depth, pos_end;
	vector<vector<int>> table;
	int argmin(int i, int j) { return depth[i] < depth[j] ? i : j; }
	// O(n) preprocessing, O(1) lca query
	void rootify(int r) {
		pos.resize(n);
		pos_end.resize(n);
		// euler tour
		function<void (int,int,int)> dfs = [&](int u, int p, int d) {
			pos[u] = pos_end[u] = depth.size();
			par[u] = p;
			tour.push_back(u);
			depth.push_back(d);
			for (int v: adj[u]) {
				if (v != p) {
					dfs(v, u, d+1);
					pos_end[u] = (int)depth.size();
					tour.push_back(u);
					depth.push_back(d);
				}
			}
		}; 

		dfs(r, -1, 0);

		floorlog.resize(tour.size() + 1);

		for(int i = 0; (1 << i) <= tour.size(); i++)
			for(int j = (1 << i); j < (1 << (i + 1)) && j <= tour.size(); j++)
				floorlog[j] = i;

		int logn = floorlog[tour.size()];
		block_size = logn / 2 + 1;
		num_blocks = ((int)tour.size() - 1) / block_size + 1;
		table.resize(logn+1, vector<int>(num_blocks));
		num.resize(num_blocks);
		val.resize(block_size + 1, vector<int>(1 << block_size));

		for(int i = 0; i < tour.size(); i += block_size){
			int mn = i;
			int v = 0;
			int block = i / block_size;
			int j = i;
			for(; j < tour.size() && j < i + block_size; j++){
				mn = argmin(mn, j);
				if(j != i){
					v = 2 * v + (depth[j] == depth[j - 1] + 1);
				}
			}
			table[0][block] = mn;
			num[block] = v << (block_size - j + i);
		}

		for (int h = 1; (1 << h) <= num_blocks; ++h) 
			for (int i = 0; i + (1<<h) <= num_blocks; ++i)
				table[h][i] = argmin(table[h - 1][i], table[h - 1][i+(1<<(h - 1))]);

		for(int i = 0; i < (1 << block_size); i++){
			int prefix = 0, mn = 0, curr = 0;
			for(int j = 0; j < block_size; j++){
				prefix += 2 * (i >> (block_size - 1 - j) & 1) - 1;
				if(mn > prefix){
					mn = prefix;
					curr = j + 1;
				}
				val[j + 1][i >> (block_size - 1 - j)] = curr;
			}
		}
	}

	inline int same_block_lca(int block, int i, int j){
		if(i == j) return i + block * block_size;
		int l = j - i;
		int mask = (num[block] >> (block_size - j - 1)) & ((1 << l) - 1);
		return block * block_size + i + val[l][mask];
	}

	int lca(int a, int b){
		a = pos[a]; b = pos[b];
		if(a > b) swap(a, b);
		int block_a = a / block_size;
		int block_b = b / block_size;
		int ind_a = a - block_a * block_size;
		int ind_b = b - block_b * block_size;
		if(block_a == block_b) return tour[same_block_lca(block_a, ind_a, ind_b)];
		int ans = argmin(same_block_lca(block_a, ind_a, block_size - 1), same_block_lca(block_b, 0, ind_b));
		if(block_b > block_a + 1){
			int h = floorlog[block_b - block_a - 1];
			int t = argmin(table[h][block_a + 1], table[h][block_b- (1<<h)]);
			ans = argmin(ans, t);
		}
		return tour[ans];
	}

	inline int dist(int i, int j){
		return depth[pos[i]] + depth[pos[j]] - 2 * depth[pos[lca(i, j)]];
	}

	inline int getDepth(int u){
		return depth[pos[u]];
	}

	void input(){
        for(int i = 1; i < n; i++){
            int x, y;
            scanf("%d %d", &x, &y);
            add_edge(x - 1, y - 1);
        }
    }

	void go(int type){
		set<pii> st;
		vector<set<int>> adj_set(n);
		vector<int> perm(n);

		for(int i = 0; i < n; i++){
			for(int v : adj[i]){
				adj_set[i].insert(v);
			}
			if(sz(adj[i]) == 1) st.insert({-getDepth(i), i});
		}

		int rem = n;
		int cost = 0;
		while(!st.empty()){
			auto it = st.begin();
			int l = it->S;
			int u = par[l];
			vector<int> L;
			for(int x : adj_set[u]){
				if(sz(adj_set[x]) == 1) L.push_back(x);
			}
			int k = sz(L);
			for(int h : L) 
				st.erase({-getDepth(h), h});
			st.erase({-getDepth(u), u});
			

			cost += 2 * k;

			if(k == 1){
				perm[u] = l;
				perm[l] = u;
			}
			else if(k == 2){
				int a = L[0], b = L[1];
				perm[a] = u; perm[u] = b; perm[b] = a;
			}
			else{
				perm[L.back()] = u;
				perm[u] = L.back();
				for(int i = 0; i + 1 < k; i++) perm[L[i]] = L[(i + 1) % (k - 1)];
			}

			int p = par[u];

			if(p != -1){
				adj_set[p].erase(u);
				if(sz(adj_set[p]) == 1) st.insert({-getDepth(p), p});
			}
		}
		printf("%d\n", cost);
		for(int i = 0; i < n; i++) printf("%d ", perm[i] + 1);
		printf("\n");
	}
};

int main(){
	int n; sd(n);
	tree T(n);
	T.input();
	T.rootify(0);
	T.go(0);
}