#include <bits/stdc++.h>
using namespace std;

template<int lim = 26>
struct aho_corasic_automaton_fixed{
	function<int(int)> convert;
	struct node{
		array<int, lim> next;
		int link = -1, exit_link = -1; // longest proper suffix, longest porper suffix which is also a leaf
		int leafcnt = 0;
	};
	vector<node> states = {{}};
	aho_corasic_automaton_fixed(function<int(int)> convert = [](int c)->int{ return tolower(c) - 'a'; }): convert(convert){ }
	template<class Str>
	aho_corasic_automaton_fixed(const vector<Str> &a, function<int(int)> convert = [](int c)->int{ return tolower(c) - 'a'; }): convert(convert){
		insert(a), build();
	}
	void clear(){
		states = {{}};
	}
	template<class Str>
	void insert(const vector<Str> &a){
		for(auto &s: a) insert(s);
	}
	template<class Str>
	int insert(const Str &s){ // add word
		int u = 0;
		for(auto C: s){
			int c = convert(C);
			if(!states[u].next[c]){
				states[u].next[c] = (int)states.size();
				states.emplace_back();
			}
			u = states[u].next[c];
		}
		++ states[u].leafcnt;
		return u;
	}
	int next_state(int u, int c){
		return states[u].next[c];
	}
	void build(){ // generate links
		deque<int> dq{0};
		while(!dq.empty()){
			int u = dq.front(); dq.pop_front();
			for(auto c = 0; c < lim; ++ c) if(states[u].next[c]){
				int v = states[u].next[c];
				states[v].link = !~states[u].link ? 0 : states[states[u].link].next[c];
				states[v].exit_link = states[states[v].link].leafcnt ? states[v].link : states[states[v].link].exit_link;
				dq.push_back(v); 
			}
			if(u) for(auto c = 0; c < lim; ++ c) if(!states[u].next[c]) states[u].next[c] = states[states[u].link].next[c];
		}
	}
};

struct dfs_bipartite_matching{
	int n, m, flow = 0;
	vector<vector<int>> adj;
	vector<int> pu, pv; // u is matched with pu[u] and v with pv[v], -1 if no match
	dfs_bipartite_matching(int n, int m): n(n), m(m), pu(n, -1), pv(m, -1), cur(n), adj(n){ }
	int insert(int from, int to){
		adj[from].push_back(to);
		return (int)adj[from].size() - 1;
	}
	int id = 0;
	vector<int> cur;
	bool dfs(int u){
		cur[u] = id;
		for(auto v: adj[u]) if(!~pv[v]){
			pu[u] = v, pv[v] = u;
			return true;
		}
		for(auto v: adj[u]) if(cur[pv[v]] != id && dfs(pv[v])){
			pu[u] = v, pv[v] = u;
			return true;
		}
		return false;
	}
	int solve(){ // O(VE)
		while(true){
			int augment = 0;
			++ id;
			for(auto u = 0; u < n; ++ u) if(pu[u] == -1 && dfs(u)) ++ augment;
			if(!augment) break;
			flow += augment;
		}
		return flow;
	}
	int run_once(int v){
		if(pu[v] != -1) return 0;
		++ id;
		return dfs(v);
	}
	pair<vector<int>, vector<int>> minimum_vertex_cover(){
		solve();
		vector<int> L, R, visL(n), visR(m);
		function<void(int)> dfs = [&](int u){
			visL[u] = true;
			for(auto v: adj[u]) if(v != pu[u] && !visR[v]){
				visR[v] = true, R.push_back(v);
				if(~pv[v]) dfs(pv[v]);
			}
		};
		for(auto u = 0; u < n; ++ u) if(!visL[u] && pu[u] == -1) dfs(u);
		for(auto u = 0; u < n; ++ u) if(!visL[u]) L.push_back(u);
		return {L, R};
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	aho_corasic_automaton_fixed<2> aut;
	vector<int> pos(n);
	vector<string> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
		pos[i] = aut.insert(a[i]);
	}
	aut.build();
	int sz = (int)aut.states.size();
	vector<int> flag(sz, -1);
	for(auto i = 0; i < n; ++ i){
		flag[pos[i]] = i;
	}
	vector<vector<int>> adj(n);
	for(auto i = 0; i < n; ++ i){
		int u = 0;
		for(auto c: a[i]){
			u = aut.next_state(u, c - 'a');
			if(~flag[u]){
				adj[i].push_back(flag[u]);
			}
			if(~aut.states[u].exit_link){
				adj[i].push_back(flag[aut.states[u].exit_link]);
			}
		}
	}
	dfs_bipartite_matching M(n, n);
	for(auto u = 0; u < n; ++ u){
		vector<int> vis(n);
		function<void(int)> dfs = [&](int u){
			vis[u] = true;
			for(auto v: adj[u]){
				if(!vis[v]){
					dfs(v);
				}
			}
		};
		dfs(u);
		for(auto v = 0; v < n; ++ v){
			if(v != u && vis[v]){
				M.insert(u, v);
			}
		}
	}
	auto [l, r] = M.minimum_vertex_cover();
	vector<int> ok(n, true);
	for(auto vv: {l, r}){
		for(auto u: vv){
			ok[u] = false;
		}
	}
	vector<int> res;
	for(auto u = 0; u < n; ++ u){
		if(ok[u]){
			res.push_back(u);
		}
	}
	cout << (int)res.size() << "\n";
	for(auto u: res){
		cout << u + 1 << " ";
	}
	cout << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////