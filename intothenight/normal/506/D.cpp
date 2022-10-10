#include <bits/stdc++.h>
using namespace std;

template<class F>
struct y_combinator_result{
	F f;
	template<class T> explicit y_combinator_result(T &&f): f(forward<T>(f)){ }
	template<class ...Args> decltype(auto) operator()(Args &&...args){ return f(ref(*this), forward<Args>(args)...); }
};
template<class F>
decltype(auto) y_combinator(F &&f){
	return y_combinator_result<decay_t<F>>(forward<F>(f));
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<map<int, vector<int>>> adj(n);
	vector<vector<int>> appear(n);
	vector<int> deg(n);
	for(auto i = 0; i < m; ++ i){
		int u, v, w;
		cin >> u >> v >> w, -- u, -- v;
		++ deg[u];
		++ deg[v];
		adj[u][w].push_back(v);
		adj[v][w].push_back(u);
		appear[u].push_back(w);
		appear[v].push_back(w);
	}
	vector<vector<int>> id(n);
	for(auto u = 0; u < n; ++ u){
		sort(appear[u].begin(), appear[u].end());
		appear[u].erase(unique(appear[u].begin(), appear[u].end()), appear[u].end());
		id[u].resize((int)appear[u].size(), -1);
	}
	auto get_ind = [&](int u, int c)->int{
		auto it = lower_bound(appear[u].begin(), appear[u].end(), c);
		if(it == appear[u].end() || *it != c){
			return -1;
		}
		return it - appear[u].begin();
	};
	vector<int> col_cnt(m);
	for(auto u = 0; u < n; ++ u){
		for(auto t = 0; t < (int)appear[u].size(); ++ t){
			if(~id[u][t]){
				continue;
			}
			int c = appear[u][t];
			y_combinator([&](auto self, int u, int c)->void{
				int t = get_ind(u, c);
				id[u][t] = col_cnt[c];
				for(auto v: adj[u][c]){
					int vt = get_ind(v, c);
					if(~id[v][vt]){
						continue;
					}
					self(v, c);
				}
			})(u, c);
			++ col_cnt[c];
		}
	}
	int qn;
	cin >> qn;
	vector<map<int, vector<int>>> qappear(n);
	for(auto qi = 0; qi < qn; ++ qi){
		int u, v;
		cin >> u >> v, -- u, -- v;
		if(deg[u] > deg[v]){
			swap(u, v);
		}
		qappear[u][v].push_back(qi);
	}
	vector<int> res(qn);
	for(auto u = 0; u < n; ++ u){
		for(auto &[v, queries]: qappear[u]){
			int cnt = 0;
			for(auto t = 0; t < (int)appear[u].size(); ++ t){
				int vt = get_ind(v, appear[u][t]);
				if(!~vt){
					continue;
				}
				cnt += id[u][t] == id[v][vt];
			}
			for(auto qi: queries){
				res[qi] = cnt;
			}
		}
	}
	for(auto x: res){
		cout << x << "\n";
	}
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////