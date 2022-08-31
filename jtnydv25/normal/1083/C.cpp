#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())


template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"{";
	for(int i = 0;i < (int)v.size(); i++){
		if(i)os<<",";
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

struct path{
	int u, v;
	path(){}
	path(int u) : u(u), v(u){}
	path(int u, int v) : u(u), v(v){}
	bool valid() const {return u != -1;}
};

struct tree {
	int n, block_size, num_blocks;
	vector<vector<int>> adj, val;
	vector<int> num, floorlog;
	tree(){}
	tree(int n) : n(n), adj(n) { }
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
		function<void (int,int,int)> dfs = [&](int u, int p, int d) {
			pos[u] = pos_end[u] = depth.size();
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

		dfs(r, r, 0);

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

	int same_block_lca(int block, int i, int j){
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

	inline bool isAncestor(int a, int b){
		return pos[b] >= pos[a] && pos[b] <= pos_end[a];
	}

	inline bool isOn(int c, int a, int b){
		return isAncestor(lca(a, b), c) && (isAncestor(c, a) || isAncestor(c, b));
	}

	path merge(path & p1, path & p2){
		if(!p1.valid() || !p2.valid()) return path(-1);

		vector<int> v = {p1.u, p1.v, p2.u, p2.v};
		vector<int> depths = {getDepth(v[0]), getDepth(v[1]), getDepth(v[2]), getDepth(v[3])};
		int must = 0, maxd = 0;
		for(int i = 0; i < 4; i++) if(depths[i] > maxd){
			must = i;
			maxd = depths[i];
		}
		maxd = 0;
		int other = 0;
		for(int j = 0; j < 4; j++) if(j != must){
			int _d = dist(v[j], v[must]);
			if(_d > maxd){
				maxd = _d;
				other = j;
			}
		}

		bool ok = true;
		for(int j1 = 0; j1 < 4; j1++) if(j1 != must && j1 != other && !isOn(v[j1], v[other], v[must])){
			ok = false;
			break;
		}
		if(ok) return path(v[other], v[must]);
		return path(-1);
	}
};

const int N = 200005;

int ip[N];
int p[N];

tree T;

struct segtree{
	int n;
	vector<path> vec;
	segtree(int n): n(n), vec(4 * n){}
	void make(int s, int e, int ind){
		if(s == e){
			vec[ind] = path(ip[s]);
			return;
		}
		int mid = (s + e) >> 1;
		make(s, mid, ind << 1);
		make(mid + 1, e, ind << 1 | 1);
		vec[ind] = T.merge(vec[ind << 1], vec[ind << 1 | 1]);
	}

	void update(int i, int s, int e, int ind){
		if(i > e || i < s) return;
		if(s == e){
			vec[ind] = path(ip[s]);
			return;
		}
		int mid = (s + e) >> 1;
		update(i, s, mid, ind << 1);
		update(i, mid + 1, e, ind << 1 | 1);
	 	vec[ind] = T.merge(vec[ind << 1], vec[ind << 1 | 1]);
	}

	int getMax(){
		int s = 0, e = n - 1, ind = 1;
		path p = {ip[0], ip[0]};
		while(1){
			path q = T.merge(p, s == e ? vec[ind] : vec[2 * ind]);
			if(s == e){
				if(q.valid()){
					return s;
				}
				return s - 1;
			}
			int mid = (s + e) >> 1;
			if(q.valid()){
				p = q;
				s = mid + 1;
				ind = 2 * ind + 1;
			} else{
				e = mid;
				ind <<= 1;
			}
		}
	}
};
int main(){
	int n; sd(n);	
	for(int i = 0; i < n; i++){
		sd(p[i]);
		ip[p[i]] = i;
	}

	T = tree(n);
	for(int i = 1; i < n; i++){
		int d;
		sd(d);
		d--;
		T.add_edge(i, d);
	}

	T.rootify(0);
	
	segtree st(n);
	st.make(0, n - 1, 1);
	int q;
	sd(q);
	while(q--){
		int t;
		sd(t);
		if(t == 1){
			int i, j;
			sd(i); sd(j); i--; j--;
			if(i==j) continue;
			int pi = p[i], pj = p[j];
			swap(ip[pi], ip[pj]);
			swap(p[i], p[j]);
			st.update(pi, 0, n - 1, 1);
			st.update(pj, 0, n - 1, 1);
		} else{
			printf("%d\n", st.getMax() + 1);
		}
	}
}