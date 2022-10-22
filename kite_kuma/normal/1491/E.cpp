#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, siz[N];
vector<int> fib;
vector<pair<int, bool>> G[N];

void NO() {
	cout << "NO\n";
	exit(0);
}

void GetSize(int u, int fa) {
	siz[u] = 1;
	for(pair<int, bool> e : G[u]) {
		if(e.second) continue;
		int v = e.first;
		if(v == fa) continue;
		GetSize(v, u);
		siz[u] += siz[v];
	}
}

void CutEdge(int u, int fa, int k, int &pu, int &pv, int &kd) {
	for(pair<int, bool> e : G[u]) {
		if(pu) return;
		if(e.second) continue;
		int v = e.first;
		if(v == fa) continue;
		if(siz[v] == fib[k - 1] || siz[v] == fib[k - 2]) {
			pu = u;
			pv = v;
			kd = (siz[v] == fib[k - 1]) ? k - 1 : k - 2;
			break;
		}
		CutEdge(v, u, k, pu, pv, kd);
	}
}

void Check(int u, int k) {
	if(k <= 1) return;
	GetSize(u, 0);
	int pu = 0, pv = 0, kd = 0;
	CutEdge(u, 0, k, pu, pv, kd);
	if(!pu) NO();
	for(pair<int, bool> &e : G[pu])
		if(e.first == pv) e.second = true;
	for(pair<int, bool> &e : G[pv])
		if(e.first == pu) e.second = true;
	Check(pv, kd);
	Check(pu, (kd == k - 1) ? k - 2 : k - 1);
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	fib.push_back(1);
	fib.push_back(1);
	for(int i = 1;; i++) {
		if(fib[i] >= n) break;
		int new_fib = fib[i] + fib[i - 1];
		fib.push_back(new_fib);
	}
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(make_pair(v, false));
		G[v].push_back(make_pair(u, false));
	}
	if(fib[fib.size() - 1] != n) NO();
	Check(1, fib.size() - 1);
	cout << "YES\n";
	return 0;
}