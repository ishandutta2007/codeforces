#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



template<size_t SZ = 26>
struct trie{
	int n = 1; // # of active nodes(cnt != 0)
	vector<array<int, SZ>> next;
	vector<int> cnt{1};
	trie(){ next.emplace_back(), next.back().fill(-1); }
	trie(const vector<array<int, SZ>> next, const vector<int> &cnt): n((int)next.size()), next(next), cnt(cnt){ }
	int extend(){
		next.emplace_back();
		next.back().fill(-1);
		cnt.push_back(0);
		return (int)next.size() - 1;
	}
	void insert(const string &s, char starting_char = 'a', int u = 0){
		vector<int> v(s.begin(), s.end());
		for(auto &x: v) x -= starting_char;
		insert(v, u);
	}
	void insert(const vector<int> &v, int u = 0){
		if(!cnt[u] ++) ++ n;
		for(auto c: v){
			if(!~next[u][c]) next[u][c] = extend();
			u = next[u][c];
			if(!cnt[u] ++) ++ n;
		}
	}
	void erase(const string &s, char starting_char = 'a', int u = 0){
		vector<int> v(s.begin(), s.end());
		for(auto &x: v) x -= starting_char;
		erase(v, u);
	}
	void erase(const vector<int> &v, int u = 0){
		assert(cnt[u]);
		if(!-- cnt[u]) -- n;
		for(auto c: v){
			u = next[u][c];
			assert(~u && cnt[u]);
			if(!-- cnt[u]) -- n;
		}
	}
	void insert(const trie &tr, int v, int u = 0){ // insert into u a trie rooted at v
		if(!cnt[u] ++) ++ n;
		for(int c = 0; c < SZ; ++ c){
			if(~tr.next[v][c] && tr.cnt[tr.next[v][c]]){
				if(!~next[u][c]) next[u][c] = extend();
				insert(tr, next[v][c], next[u][c]);
			}
		}
	}
	void erase(const trie &tr, int v, int u = 0){ // delete from u a trie rooted at v
		assert(cnt[u]);
		if(!-- cnt[u]) -- n;
		for(int c = 0; c < SZ; ++ c){
			if(~tr.next[v][c] && tr.cnt[tr.next[v][c]]){
				assert(~next[u][c]);
				erase(tr, next[v][c], next[u][c]);
			}
		}
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<array<int, 26>> next(n);
	vector<int> cnt(n, 1);
	for(auto u = 0; u < n; ++ u){
		next[u].fill(-1);
	}
	for(auto i = 1; i < n; ++ i){
		int u, v;
		char w;
		cin >> u >> v >> w, -- u, -- v;
		next[u][w - 'a'] = v;
	}
	trie tr(next, cnt);
	vector<int> sz(n, 1), depth(n);
	function<void(int)> dfs_sz = [&](int u){
		for(auto v: next[u]){
			if(~v){
				depth[v] = depth[u] + 1;
				dfs_sz(v);
				sz[u] += sz[v];
			}
		}
	};
	dfs_sz(0);
	vector<vector<int>> dlist(n);
	for(auto u = 0; u < n; ++ u){
		dlist[depth[u]].push_back(u);
	}
	array<int, 2> res{numeric_limits<int>::max(), -1};
	for(auto d = 0; d < n - 1; ++ d){
		if(!dlist[d].empty()){
			int cur = 0;
			for(auto r: dlist[d]){
				if(any_of(next[r].begin(), next[r].end(), [&](int x){ return ~x; })){
					++ cur;
					int u = *find_if(next[r].begin(), next[r].end(), [&](int x){ return ~x; });
					assert(~u);
					for(auto v: next[r]){
						if(~v && sz[u] < sz[v]){
							u = v;
						}
					}
					for(auto c = 0; c < 26; ++ c){
						int v = next[r][c];
						if(~v && u != v){
							cur += sz[v];
							tr.insert(tr, v, u);
						}
					}
				}
			}
			ctmin(res, array{tr.n - cur, d + 1});
			for(auto r: dlist[d]){
				if(any_of(next[r].begin(), next[r].end(), [&](int x){ return ~x; })){
					int u = *find_if(next[r].begin(), next[r].end(), [&](int x){ return ~x; });
					assert(~u);
					for(auto v: next[r]){
						if(~v && sz[u] < sz[v]){
							u = v;
						}
					}
					for(auto c = 0; c < 26; ++ c){
						int v = next[r][c];
						if(~v && u != v){
							tr.erase(tr, v, u);
						}
					}
				}
			}
		}
	}
	cout << res[0] << "\n" << res[1] << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////