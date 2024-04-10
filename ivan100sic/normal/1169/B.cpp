#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int u[300005], v[300005];

void proveri(int x) {
	map<int, int> occ;
	occ[0] = 0;
	int e = 0;
	for (int i=1; i<m; i++) {
		if (u[i] == x || v[i] == x) {
			;
		} else {
			occ[u[i]]++, occ[v[i]]++;
			e++;
		}
	}
	for (auto p : occ)
		if (p.second == e) {
			cout << "YES\n";
			exit(0);
		}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		cin >> u[i] >> v[i];
	}

	proveri(u[0]);
	proveri(v[0]);
	cout << "NO\n";
}