#include "bits/stdc++.h"
using namespace std;

template<typename T, typename C>
struct mcmf{
	static constexpr T eps = (T) 1e-9;
	struct Edge{
		int from, to;
		T capacity, flow;
		C cost;
	};
	vector<vector<int>> adj;
	vector<Edge> edge;
	vector<C> d;
	vector<bool> in_queue;
	vector<int> q, pe;
	int n, source, sink;
	T flow = 0;
	C cost = 0;
	mcmf(int n, int source, int sink): n(n), source(source), sink(sink), adj(n), d(n), in_queue(n), pe(n){ }
	void clear(){
		for(auto &e: edge) e.flow = 0;
		flow = 0;
	}
	int insert(int from, int to, T forward_cap, T backward_cap, C cost){
		assert(0 <= from && from < n && 0 <= to && to < n);
		int ind = int(edge.size());
		adj[from].push_back((int)edge.size());
		edge.push_back({from, to, forward_cap, 0, cost});
		adj[to].push_back((int)edge.size());
		edge.push_back({to, from, backward_cap, 0, -cost});
		return ind;
	}
	bool expath(){
		fill(d.begin(), d.end(), numeric_limits<C>::max());
		q.clear();
		q.push_back(source);
		d[source] = 0;
		in_queue[source] = true;
		int beg = 0;
		bool found = false;
		while(beg < (int)q.size()){
			int i = q[beg ++];
			if(i == sink) found = true;
			in_queue[i] = false;
			for(int id : adj[i]){
				const auto &e = edge[id];
				if(e.capacity - e.flow > eps && d[i] + e.cost < d[e.to]){
					d[e.to] = d[i] + e.cost;
					pe[e.to] = id;
					if(!in_queue[e.to]){
						q.push_back(e.to);
						in_queue[e.to] = true;
					}
				}
			}
		}
		if(found){
			T push = numeric_limits<T>::max();
			int v = sink;
			while(v != source){
				const auto &e = edge[pe[v]];
				push = min(push, e.capacity - e.flow);
				v = e.from;
			}
			v = sink;
			while(v != source){
				auto &e = edge[pe[v]];
				e.flow += push;
				auto &back = edge[pe[v] ^ 1];
				back.flow -= push;
				v = e.from;
			}
			flow += push;
			cost += push * d[sink];
		}
		return found;
	}
	pair<T, C> get_mcmf(){
		while(expath()){ }
		return {flow, cost};
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<int> win(n);
	vector<vector<int>> match_res(n, vector<int>(n, -1)), id(n, vector<int>(n, -1));
	vector<array<int, 2>> match_type;
	for(auto i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		match_res[u][v] = 1, match_res[v][u] = 0;
		++ win[u];
	}
	for(auto u = 0; u < n; ++ u){
		for(auto v = u + 1; v < n; ++ v){
			if(!~match_res[u][v]){
				id[u][v] = int(match_type.size());
				match_type.push_back({u, v});
			}
		}
	}
	int source = n + int(match_type.size()), sink = source + 1;
	mcmf<int, int> F(n + int(match_type.size()) + 2, source, sink);
	for(auto i = 0; i < int(match_type.size()); ++ i){
		F.insert(source, i, 1, 0, 0);
		F.insert(i, int(match_type.size()) + match_type[i][0], 1, 0, 0);
		F.insert(i, int(match_type.size()) + match_type[i][1], 1, 0, 0);
	}
	for(auto u = 0; u < n; ++ u){
		for(auto c = 2 * win[u] + 1; c <= 2 * n - 1; c += 2){
			F.insert(int(match_type.size()) + u, sink, 1, 0, c);
		}
	}
	F.get_mcmf();
	for(auto e: F.edge){
		if(e.from < int(match_type.size()) && e.to != source && e.flow){
			auto [u, v] = match_type[e.from];
			int winner = e.to - int(match_type.size());
			match_res[u][v] = winner == u;
			match_res[v][u] = winner == v;
		}
	}
	for(auto u = 0; u < n; ++ u){
		for(auto v = 0; v < n; ++ v){
			cout << (u != v && match_res[u][v] == 1);
		}
		cout << "\n";
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