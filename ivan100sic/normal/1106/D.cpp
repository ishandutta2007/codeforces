#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
basic_string<int> e[100005], sol;
bool v[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	set<int> pq;
	pq.insert(1);

	while (pq.size()) {
		int x = *pq.begin();
		v[x] = 1;
		pq.erase(x);
		sol += x;
		for (int y : e[x]) {
			if (!v[y]) {
				pq.insert(y);
				v[y] = 1;
			}
		}
	}

	for (int x : sol)
		cout << x << ' ';
	cout << '\n';

}