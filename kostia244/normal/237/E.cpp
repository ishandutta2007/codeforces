#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}
struct Edge {
	int u, v, cap, flow, cost;
};
struct F {
	int n;
	vector<Edge> edges;
	vector<vector<int>> g;
	F(int N) : n(N), g(n) {}
	void add_edge(int u, int v, int cap, int cost) {
		edges.emplace_back(Edge{u, v, cap, 0, cost});
		edges.emplace_back(Edge{v, u, 0, 0, -cost});
		g[u].push_back(edges.size()-2);
		g[v].push_back(edges.size()-1);
	}
	pair<int, int> flow(int s, int t, int K) {
		int flow = 0, cost = 0;
		queue<int> q;
		vector<int> dist(n, 1<<30), p(n);
		auto add = [&](int v, int d, int pr) {
			if(dist[v] > d) {
				dist[v] = d;
				p[v] = pr;
				q.push(v);
			}
		};
		while(flow < K) {
			fill(all(dist), 1<<30);
			add(s, 0, -1);
			while(!q.empty()) {
				int u = q.front(); q.pop();
				for(auto id : g[u]) {
					if(edges[id].cap > edges[id].flow)
						add(edges[id].v, dist[u]+edges[id].cost, id);
				}
			}
			if(dist[t] == 1<<30) break;
			int v = t;
			while(v != s) {
				int id = p[v];
				edges[id].flow++;
				edges[id^1].flow--;
				v = edges[id].u;
			}
			flow++;
			cost += dist[t];
		}
		if(flow < K) cost = -1;
		return {flow, cost};
	}
};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
string str, tmp;
map<char, int> need, have;
int n;
	cin >> str >> n;
	F f(30+n);
	for(auto i : str) need[i]++;
	vector<Edge> e;
	for(auto i : need) {
		f.add_edge(3+i.first-'a', 2, i.second, 0);
	}
	for(int cc, i = 0; i < n; i++) {
		cin >> tmp >> cc;
		have.clear();
		for(auto j : tmp) have[j]++;
		for(auto j : have) {
			f.add_edge(30+i, 3+j.first-'a', j.second, i+1);
		}
		f.add_edge(1, 30+i, cc, 0);
	}
//	for(auto i : e) cout <<i.from << " " << i.to << "(" << i.capacity << " / " << i.cost<< ")\n";
	cout << f.flow(1, 2, str.size()).second << '\n';
}