#include "bits/stdc++.h"
using namespace std;

void radix_sort(vector<pair<int, vector<int>>> &arr){
	int n = int(arr.size()), mxval = 0, mxsz = 1 + accumulate(arr.begin(), arr.end(), 0, [](int x, const pair<int, vector<int>> &y){return max(x, int(y.second.size()));});
	vector<vector<int>> occur(mxsz);
	for(int i = 0; i < n; ++ i){
		occur[arr[i].second.size()].push_back(i);
		for(auto x: arr[i].second) mxval = max(mxval, x);
	}
	++ mxval;
	for(int size = 1; size < mxsz; ++ size) for(int d = size - 1; d >= 0; -- d){
		vector<vector<int>> bucket(mxval);
		for(auto i: occur[size]) bucket[arr[i].second[d]].push_back(i);
		occur[size].clear();
		for(auto &b: bucket) for(auto i: b) occur[size].push_back(i);
	}
	vector<pair<int, vector<int>>> res;
	res.reserve(n);
	for(auto &b: occur) for(auto i: b) res.push_back(arr[i]);
	swap(res, arr);
}
bool isomorphic(const vector<vector<vector<int>>> &adj, const vector<int> &root){
	int n = int(adj[0].size());
	if(int(adj[1].size()) != n) return false;
	vector<vector<vector<int>>> occur(2);
	vector<vector<int>> depth(2, vector<int>(n)), par(2, vector<int>(n, -1));
	for(int k = 0; k < 2; ++ k){
		function<void(int, int)> dfs = [&](int u, int p){
			par[k][u] = p;
			for(auto v: adj[k][u]) if(v != p){
				depth[k][v] = depth[k][u] + 1;
				dfs(v, u);
			}
		};
		dfs(root[k], -1);
		int mxdepth = 1 + accumulate(depth[k].begin(), depth[k].end(), 0, [](int x, int y){return max(x, y);});
		occur[k].resize(mxdepth);
		for(int u = 0; u < n; ++ u) occur[k][depth[k][u]].push_back(u);
	}
	int mxdepth = int(occur[0].size());
	if(mxdepth != int(occur[1].size())) return false;
	for(int d = 0; d < mxdepth; ++ d) if(occur[0][d].size() != occur[1][d].size()) return false;
	vector<vector<int>> label(2, vector<int>(n)), pos(2, vector<int>(n));
	vector<vector<vector<int>>> sorted_list(mxdepth, vector<vector<int>>(2));
	for(int k = 0; k < 2; ++ k){
		sorted_list[mxdepth - 1][k].reserve(occur[k][mxdepth - 1].size());
		for(auto u: occur[k][mxdepth - 1]) sorted_list[mxdepth - 1][k].push_back(u);
	}
	for(int d = mxdepth - 2; d >= 0; -- d){
		vector<vector<pair<int, vector<int>>>> tuples(2);
		for(int k = 0; k < 2; ++ k){
			tuples[k].reserve(occur[k][d].size());
			for(auto u: occur[k][d]){
				pos[k][u] = int(tuples[k].size());
				tuples[k].emplace_back(u, vector<int>());
			}
			for(auto v: sorted_list[d + 1][k]){
				int u = par[k][v];
				tuples[k][pos[k][u]].second.push_back(label[k][v]);
			}
			radix_sort(tuples[k]);
		}
		for(int i = 0; i < int(tuples[0].size()); ++ i) if(tuples[0][i].second != tuples[1][i].second) return false;
		for(int k = 0; k < 2; ++ k){
			int cnt = 0;
			sorted_list[d][k].reserve(occur[k][d].size());
			sorted_list[d][k].push_back(tuples[k][0].first);
			for(int i = 1; i < int(tuples[k].size()); ++ i){
				int u = tuples[k][i].first;
				label[k][u] = (tuples[k][i - 1].second == tuples[k][i].second ? cnt : ++ cnt);
				sorted_list[d][k].push_back(u);
			}
		}
	}
	return true;
}
vector<int> centroid(const vector<vector<int>> &adj){
	int n = int(adj.size());
	vector<int> size(n, 1);
	function<void(int, int)> dfs_sz = [&](int u, int p){
		for(auto v: adj[u]) if(v != p){
			dfs_sz(v, u);
			size[u] += size[v];
		}
	};
	dfs_sz(0, -1);
	function<vector<int>(int, int)> dfs_cent = [&](int u, int p){
		for(auto v: adj[u]) if(v != p && size[v] > n / 2) return dfs_cent(v, u);
		for(auto v: adj[u]) if(v != p && n - size[v] <= n / 2) return vector<int>{u, v};
		return vector<int>{u};
	};
	return dfs_cent(0, -1);
}
bool isomorphic(const vector<vector<vector<int>>> &adj){
	vector<vector<int>> cent{centroid(adj[0]), centroid(adj[1])};
	if(cent[0].size() != cent[1].size()) return false;
	for(auto u: cent[0]) for(auto v: cent[1]) if(isomorphic(adj, vector<int>{u, v})) return true;
	return false;
}
template<typename asdf>
bool test_isomorphism(asdf p, asdf q){
	int n = int(p.size());
	vector<vector<int>> adj1(n), adj2(n);
	for(auto u = 0; u < n; ++ u){
		if(p[u] >= 0){
			adj1[u].push_back(p[u]), adj1[p[u]].push_back(u);
		}
	}
	for(auto u = 0; u < n; ++ u){
		if(q[u] >= 0){
			adj2[u].push_back(q[u]), adj2[q[u]].push_back(u);
		}
	}
	return isomorphic({adj1, adj2});
}

// DEBUG BEGIN
template<typename L, typename R>
ostream &operator<<(ostream &out, pair<L, R> p){
	return out << "(" << p.first << ", " << p.second << ")";
}
template<typename Tuple, size_t ...Is>
void print_tuple(ostream &out, Tuple t, index_sequence<Is...>){
	((out << (Is ? ", " : "") << get<Is>(t)), ...);
}
template<typename ...Args>
ostream &operator<<(ostream &out, tuple<Args...> t){
	out << "(", print_tuple(out, t, index_sequence_for<Args...>{}); return out << ")";
}
template<typename ...Args, template<typename...> typename T>
ostream &operator<<(enable_if_t<!is_same_v<T<Args...>, string>, ostream> &out, T<Args...> arr){
	out << "{"; for(auto &x: arr) out << x << ", ";
	return out << (arr.size() ? "\b\b" : "") << "}";
}
template<typename T, size_t N>
ostream &operator<<(ostream &out, array<T, N> arr){
	out << "{"; for(auto &x: arr) out << x << ", ";
	return out << (arr.size() ? "\b\b" : "") << "}";
}
template<size_t S>
ostream &operator<<(ostream &out, bitset<S> b){
	for(int i = 0; i < S; ++ i) out << b[i];
	return out;
}
void debug_out(){ cerr << "\b\b " << endl; }
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T){ cerr << H << ", ", debug_out(T...); }
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
// DEBUG END

int main(){
	cin.tie(0)->sync_with_stdio(0);
	/*
	int n;
	cin >> n;
	vector<int> par(2 * n - 1, -1), judge_ans(2 * n - 1), depth(2 * n - 1, -1);
	for(auto &x: judge_ans) cin >> x;
	debug(judge_ans);
	for(auto &x: judge_ans) if(~x) -- x;
	for(auto u = 0; u < 2 * n - 1; ++ u){
		if(!~depth[u]){
			function<int(int)> get_depth = [&](int u){
				if(~depth[u]) return depth[u];
				if(judge_ans[u] < 0) return depth[u] = 0;
				return get_depth(judge_ans[u]) + 1;
			};
			depth[u] = get_depth(u);
		}
	}
	auto lca = [&](int u, int v){
		if(depth[u] < depth[v]) swap(u, v);
		while(depth[u] != depth[v]) u = judge_ans[u];
		while(u != v) u = judge_ans[u], v = judge_ans[v];
		return u;
	};
	int query_cnt = 0;
	auto query = [&](int u, int v, int w){
		++ query_cnt;
		debug(query_cnt);
		cout << u + 1 << " " << v + 1 << " " << w + 1 << endl;
		int x = depth[lca(u, v)], y = depth[lca(v, w)], z = depth[lca(w, u)], mx = max({x, y, z});
		cout << "judge replies: ";
		if(x == mx){
			cout << "X" << endl;
			return 0;
		}
		else if(y == mx){
			cout << "Y" << endl;
			return 1;
		}
		else{
			cout << "Z" << endl;
			return 2;
		}
	};
	auto answer = [&](){
		cout << "-1\n";
		for(auto p: par) cout << p + !!~p << " ";
		cout << "\n";
		cout << "Are they isomorphic?: " << test_isomorphism(judge_ans, par) << endl;
		exit(0);
	};
	*/
	///*
	int n;
	cin >> n;
	vector<int> par(2 * n - 1, -2);
	int query_cnt = 0;
	auto query = [&](int u, int v, int w){
		++ query_cnt;
		cout << u + 1 << " " << v + 1 << " " << w + 1 << endl;
		char resp;
		cin >> resp;
		return resp - 'X';
	};
	auto answer = [&](){
		cout << "-1\n";
		for(auto p: par) cout << p + 1 << " ";
		cout << "\n";
		exit(0);
	};
	//*/
	auto get_node = [&](){
		static int cntr = n;
		return cntr ++;
	};
	vector<array<int, 2>> child(2 * n - 1, {-1, -1}), leaf_child(2 * n - 1);
	for(auto u = 0; u < n; ++ u){
		leaf_child[u] = {u, u};
	}
	for(auto root = 0, new_leaf = 1; new_leaf < n; ++ new_leaf){ // currently 2 * s - 1 nodes
		int new_par = get_node(), qval;
		auto insert_nodes = [&](int pp, int dir){
			int qq = child[pp][dir];
			par[qq] = par[new_leaf] = new_par, par[new_par] = pp;
			child[pp][dir] = new_par, child[new_par][dir] = qq, child[new_par][!dir] = new_leaf;
			leaf_child[new_par][dir] = leaf_child[qq][dir], leaf_child[new_par][!dir] = leaf_child[new_leaf][!dir];
		};
		if(!~child[root][0] || (qval = query(leaf_child[root][0], new_leaf, leaf_child[root][1])) == 2){
			leaf_child[new_par] = {leaf_child[root][0], new_leaf};
			par[root] = par[new_leaf] = new_par;
			child[new_par] = {root, new_leaf};
			root = new_par;
			continue;
		}
		static vector<int> ded, sz;
		ded.assign(2 * n - 1, 0), sz.assign(2 * n - 1, 0);
		ded[root] = true;
		for(auto cur_root = child[root][qval]; ; ){
			function<void(int, int)> dfs_sz = [&](int u, int p){
				sz[u] = 1;
				for(auto v: child[u]){
					if(~v && !ded[v] && v ^ p){
						dfs_sz(v, u);
						sz[u] += sz[v];
					}
				}
				int v = par[u];
				if(~v && !ded[v] && v ^ p){
					dfs_sz(v, u);
					sz[u] += sz[v];
				}
			};
			dfs_sz(cur_root, cur_root);
			function<int(int, int)> dfs_centroid = [&](int u, int p){
				for(auto v: child[u]){
					if(~v && !ded[v] && v ^ p && sz[v] > sz[cur_root] / 2){
						return dfs_centroid(v, u);
					}
				}
				int v = par[u];
				if(~v && !ded[v] && v ^ p && sz[v] > sz[cur_root] / 2){
					return dfs_centroid(v, u);
				}
				return u;
			};
			int c = dfs_centroid(cur_root, cur_root);
			if(!~child[c][0]){
				insert_nodes(par[c], c == child[par[c]][1]);
				break;
			}
			int qval = query(leaf_child[c][0], new_leaf, leaf_child[c][1]);
			if(qval == 2){
				if(ded[par[c]]){
					insert_nodes(par[c], c == child[par[c]][1]);
					break;
				}
				cur_root = par[c];
			}
			else{
				if(ded[child[c][qval]]){
					insert_nodes(c, qval);
					break;
				}
				cur_root = child[c][qval];
			}
			ded[c] = true;
		}
	}
	answer();
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////