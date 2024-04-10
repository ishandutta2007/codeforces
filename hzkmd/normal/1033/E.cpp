#include <bits/stdc++.h>

int query(std::vector<int> a) {
	if ((int)a.size() <= 1) {
		return 0;
	}
	std::cout << "? " << a.size() << "\n";
	for (int x : a) {
		std::cout << x + 1 << " ";
	}
	std::cout << std::endl;
	int res;
	std::cin >> res;
	return res;
}

void get_edges(int u, std::vector<int> S, std::vector<int> &E, bool one = false) {
	if ((int)E.size() >= 1 && one) {
		return;
	}
	int S_edges = query(S);
	S.push_back(u);
	int Su_edges = query(S);
	S.pop_back();
	if (S_edges == Su_edges) {
		return;
	}
	if ((int)S.size() == 1) {
		E.push_back(S[0]);
		return;
	}
	int mid = (S.size() + 1) / 2;
	get_edges(u, std::vector<int>(S.begin(), S.begin() + mid), E);
	get_edges(u, std::vector<int>(S.begin() + mid, S.end()), E);
}

std::pair<int, int> get_one_edge(std::vector<int> S) {
	while ((int)S.size() > 1) {
		int u = S.back();
		S.pop_back();
		std::vector<int> E;
		get_edges(u, S, E, true);
		if (!E.empty()) {
			return std::make_pair(u, E[0]);
		}
	}
	return std::make_pair(-1, -1);
}

int main() {
	std::ios_base::sync_with_stdio(false);

	int n;
	std::cin >> n;
	std::vector<int> Q;
	std::vector<bool> vis(n);
	std::vector<std::vector<int>> E(n);
	std::vector<int> dep(n), fa(n, -1);
	Q.push_back(0);
	vis[0] = true;
	dep[0] = 0;
	for (int i = 0; i < (int)Q.size(); ++i) {
		int u = Q[i];
		std::vector<int> S;
		for (int v = 0; v < n; ++v) {
			if (!vis[v]) {
				S.push_back(v);
			}
		}
		if (!S.empty()) {
			get_edges(u, S, E[u]);
		}
		for (int v : E[u]) {
			Q.push_back(v);
			fa[v] = u;
			vis[v] = true;
			dep[v] = dep[u] ^ 1;
		}
	}

	std::vector<int> odd, even;
	for (int i = 0; i < n; ++i) {
		if (dep[i] & 1) {
			odd.push_back(i);
		} else {
			even.push_back(i);
		}
	}
	std::pair<int, int> edge(-1, -1);
	if (query(odd)) {
		edge = get_one_edge(odd);
	} else if (query(even)) {
		edge = get_one_edge(even);
	}
	if (edge.first == -1) {
		std::cout << "Y " << even.size() << "\n";
		for (int v : even) {
			std::cout << v + 1 << " ";
		}
		std::cout << std::endl;
		return 0;
	}
	
	int u = edge.first, v = edge.second;
	std::vector<int> pu, pv;
	while (u != v) {
		pu.push_back(u);
		pv.push_back(v);
		u = fa[u], v = fa[v];
	}
	std::reverse(pv.begin(), pv.end());
	std::cout << "N " << pu.size() + pv.size() + 1 << "\n";
	for (int x : pu) {
		std::cout << x + 1 << " ";
	}
	std::cout << u + 1 << " ";
	for (int x : pv) {
		std::cout << x + 1 << " ";
	}
	std::cout << std::endl;
}